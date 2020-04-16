#include "ColorTools.h"

#include <QDebug>

#include <math.h>

ColorTools::ColorTools()
    : CIE2_A({109.850f, 100.0f, 35.585f}),
      CIE2_C({98.074f, 100.0f, 118.232f}),
      CIE2_D50({96.422f, 100.0f, 82.521f}),
      CIE2_D55({95.682f, 100.0f, 92.149f}),
      CIE2_D65({95.047f, 100.0f, 108.883f}),
      CIE2_D75({94.972f, 100.0f, 122.638f}),
      CIE2_F2({99.187f, 100.0f, 67.395f}),
      CIE2_F7({95.044f, 100.0f, 108.755f}),
      CIE2_F11({100.966f, 100.0f, 64.370f}),
      CIE10_A({111.144f, 100.0f, 35.200f}),
      CIE10_C({97.285f, 100.0f, 116.145f}),
      CIE10_D50({96.720f, 100.0f, 81.427f}),
      CIE10_D55({95.799f, 100.0f, 90.926f}),
      CIE10_D65({94.811f, 100.0f, 107.304f}),
      CIE10_D75({94.416f, 100.0f, 120.641f}),
      CIE10_F2({103.280f, 100.0f, 69.026f}),
      CIE10_F7({95.792f, 100.0f, 107.687f}),
      CIE10_F11({103.866f, 100.0f, 65.627f}) {

}

QList<float> ColorTools::RGBtoLAB(int red, int green, int blue, QList<float> tristimulus) const {
    QList<float> xyz = RGBtoXYZ(red, green, blue);
    QList<float> lab = XYZtoLAB(xyz.at(0), xyz.at(1), xyz.at(2), tristimulus);

    return lab;
}

QList<float> ColorTools::RGBtoXYZ(int red, int green, int blue) const {
    QList<float> xyz;

    float r = red / 255.0f;
    float g = green / 255.0f;
    float b = blue / 255.0f;

    // R
    if (r > 0.04045) {
        r = (float) pow(( (r + 0.055f) / 1.055f), 2.4f);
    } else {
        r /= 12.92f;
    }

    // G
    if (g > 0.04045) {
        g = (float) pow((( g + 0.055f ) / 1.055f), 2.4f);
    } else {
        g /= 12.92f;
    }

    //B
    if ( b > 0.04045) {
        b = (float) pow(( ( b + 0.055f ) / 1.055f ), 2.4f);
    } else {
        b /= 12.92f;
    }

    r *= 100;
    g *= 100;
    b *= 100;

    float x = 0.412453f * r + 0.35758f * g + 0.180423f * b;
    float y = 0.212671f * r + 0.71516f * g + 0.072169f * b;
    float z = 0.019334f * r + 0.119193f * g + 0.950227f * b;

    xyz.append(x);
    xyz.append(y);
    xyz.append(z);

    return xyz;
}

QList<float> ColorTools::XYZtoLAB(float x, float y, float z, QList<float> tristimulus) const {
    QList<float> lab;

    x /= tristimulus.at(0);
    y /= tristimulus.at(1);
    z /= tristimulus.at(2);

    if (x > 0.008856) {
        x = (float) pow(x, 0.33f);
    } else {
        x = (7.787f * x) + (0.1379310344827586f);
    }

    if (y > 0.008856) {
        y = (float) pow(y, 0.33f);
    } else {
        y = (7.787f * y) + (0.1379310344827586f);
    }

    if (z > 0.008856) {
        z = (float) pow(z,0.33f);
    } else {
        z = (7.787f * z) + (0.1379310344827586f);
    }

    lab.append((116 * y) - 16);
    lab.append(500 * (x - y));
    lab.append(200 * (y - z));

    return lab;
}

/*
 * <= 1.0	Not perceptible by human eyes.
 * 1 - 2	Perceptible through close observation.
 * 2 - 10	Perceptible at a glance.
 * 11 - 49	Colors are more similar than opposite
 * 100	Colors are exact opposite
*/
double ColorTools::deltaE(const float L1, const float a1, const float b1,
                         const float L2, const float a2, const float b2) const {
    double Lmean = (L1 + L2) / 2.0; //ok
    double C1 =  sqrt(a1 * a1 + b1 * b1); //ok
    double C2 =  sqrt(a2 * a2 + b2 * b2); //ok
    double Cmean = (C1 + C2) / 2.0; //ok

    double G = (1 - sqrt(pow(Cmean, 7) / (pow(Cmean, 7) + pow(25, 7)))) / 2.0; //ok
    double a1prime = a1 * (1.0f + G); //ok
    double a2prime = a2 * (1.0f + G); //ok

    double C1prime =  sqrt(a1prime * a1prime + b1 * b1); //ok
    double C2prime =  sqrt(a2prime * a2prime + b2 * b2); //ok
    double Cmeanprime = (C1prime + C2prime) / 2.0; //ok

    double h1prime =  atan2(b1, a1prime) + 2 * M_PI * (atan2(b1, a1prime) < 0 ? 1.0 : 0.0);
    double h2prime =  atan2(b2, a2prime) + 2 * M_PI * (atan2(b2, a2prime) < 0 ? 1.0 : 0.0);
    double Hmeanprime =  ((abs(h1prime - h2prime) > M_PI) ? (h1prime + h2prime + 2 * M_PI) / 2 : (h1prime + h2prime) / 2); //ok

    double T =  1.0 - 0.17 * cos(Hmeanprime - M_PI / 6.0) + 0.24 * cos(2 * Hmeanprime) + 0.32 * cos(3 * Hmeanprime + M_PI / 30.0) - 0.2 * cos(4 * Hmeanprime - 21* M_PI / 60); //ok

    double deltahprime =  ((abs(h1prime - h2prime) <= M_PI) ? h2prime - h1prime : (h2prime <= h1prime) ? h2prime - h1prime + 2 * M_PI : h2prime - h1prime - 2 * M_PI); //ok

    double deltaLprime = L2 - L1; //ok
    double deltaCprime = C2prime - C1prime; //ok
    double deltaHprime =  2.0 * sqrt(C1prime * C2prime) * sin(deltahprime / 2.0); //ok
    double SL =  1.0 + ((0.015 * (Lmean - 50) * (Lmean - 50)) / (sqrt(20 + (Lmean - 50) * (Lmean - 50)))); //ok
    double SC =  1.0 + 0.045 * Cmeanprime; //ok
    double SH =  1.0 + 0.015 * Cmeanprime * T; //ok

    double deltaTheta =  (30 * M_PI / 180) * exp(-((180 / M_PI * Hmeanprime - 275) / 25) * ((180 / M_PI * Hmeanprime-275) / 25));
    double RC =  (2 * sqrt(pow(Cmeanprime, 7) / (pow(Cmeanprime, 7) + pow(25, 7))));
    double RT =  (-RC * sin(2 * deltaTheta));

    double KL = 1;
    double KC = 1;
    double KH = 1;

    double deltaE = sqrt(
            ((deltaLprime / (KL * SL)) * (deltaLprime / (KL * SL))) +
            ((deltaCprime / (KC * SC)) * (deltaCprime / (KC * SC))) +
            ((deltaHprime / (KH * SH)) * (deltaHprime / (KH * SH))) +
            (RT * (deltaCprime / (KC * SC)) * (deltaHprime / (KH * SH)))
            );

    return deltaE;
}

double ColorTools::deltaE_V2(const float L1, const float a1, const float b1,
                             const float L2, const float a2, const float b2) const {

    /*
     * "For these and all other numerical/graphical 􏰀delta E00 values
     * reported in this article, we set the parametric weighting factors
     * to unity(i.e., k_L = k_C = k_H = 1.0)." (Page 27).
     */
    const double k_L = 1.0, k_C = 1.0, k_H = 1.0;
    const double deg360InRad = deg2Rad(360.0);
    const double deg180InRad = deg2Rad(180.0);
    const double pow25To7 = 6103515625.0; /* pow(25, 7) */

    /*
     * Step 1
     */
    /* Equation 2 */
    double C1 = sqrt((a1 * a1) + (b1 * b1));
    double C2 = sqrt((a2 * a2) + (b2 * b2));
    /* Equation 3 */
    double barC = (C1 + C2) / 2.0;
    /* Equation 4 */
    double G = 0.5 * (1 - sqrt(pow(barC, 7) / (pow(barC, 7) + pow25To7)));
    /* Equation 5 */
    double a1Prime = (1.0 + G) * a1;
    double a2Prime = (1.0 + G) * a2;
    /* Equation 6 */
    double CPrime1 = sqrt((a1Prime * a1Prime) + (b1 * b1));
    double CPrime2 = sqrt((a2Prime * a2Prime) + (b2 * b2));
    /* Equation 7 */
    double hPrime1;
    if (b1 == 0 && a1Prime == 0) {
        hPrime1 = 0.0;
    } else {
        hPrime1 = atan2(b1, a1Prime);
        /*
         * This must be converted to a hue angle in degrees between 0
         * and 360 by addition of 2􏰏 to negative hue angles.
         */
        if (hPrime1 < 0)
            hPrime1 += deg360InRad;
    }
    double hPrime2;
    if (b2 == 0 && a2Prime == 0) {
        hPrime2 = 0.0;
    } else {
        hPrime2 = atan2(b2, a2Prime);
        /*
         * This must be converted to a hue angle in degrees between 0
         * and 360 by addition of 2􏰏 to negative hue angles.
         */
        if (hPrime2 < 0) {
            hPrime2 += deg360InRad;
        }
    }

    /*
     * Step 2
     */
    /* Equation 8 */
    double deltaLPrime = L2 - L1;
    /* Equation 9 */
    double deltaCPrime = CPrime2 - CPrime1;
    /* Equation 10 */
    double deltahPrime;
    double CPrimeProduct = CPrime1 * CPrime2;
    if (CPrimeProduct == 0) {
        deltahPrime = 0;
    } else {
        /* Avoid the fabs() call */
        deltahPrime = hPrime2 - hPrime1;
        if (deltahPrime < -deg180InRad)
            deltahPrime += deg360InRad;
        else if (deltahPrime > deg180InRad)
            deltahPrime -= deg360InRad;
    }
    /* Equation 11 */
    double deltaHPrime = 2.0 * sqrt(CPrimeProduct) *
        sin(deltahPrime / 2.0);

    /*
     * Step 3
     */
    /* Equation 12 */
    double barLPrime = (L1 + L2) / 2.0;
    /* Equation 13 */
    double barCPrime = (CPrime1 + CPrime2) / 2.0;
    /* Equation 14 */
    double barhPrime, hPrimeSum = hPrime1 + hPrime2;
    if (CPrime1 * CPrime2 == 0) {
        barhPrime = hPrimeSum;
    } else {
        if (fabs(hPrime1 - hPrime2) <= deg180InRad)
            barhPrime = hPrimeSum / 2.0;
        else {
            if (hPrimeSum < deg360InRad)
                barhPrime = (hPrimeSum + deg360InRad) / 2.0;
            else
                barhPrime = (hPrimeSum - deg360InRad) / 2.0;
        }
    }
    /* Equation 15 */
    double T = 1.0 - (0.17 * cos(barhPrime - deg2Rad(30.0))) +
        (0.24 * cos(2.0 * barhPrime)) +
        (0.32 * cos((3.0 * barhPrime) + deg2Rad(6.0))) -
        (0.20 * cos((4.0 * barhPrime) - deg2Rad(63.0)));
    /* Equation 16 */
    double deltaTheta = deg2Rad(30.0) *
        exp(-pow((barhPrime - deg2Rad(275.0)) / deg2Rad(25.0), 2.0));
    /* Equation 17 */
    double R_C = 2.0 * sqrt(pow(barCPrime, 7.0) /
        (pow(barCPrime, 7.0) + pow25To7));
    /* Equation 18 */
    double S_L = 1 + ((0.015 * pow(barLPrime - 50.0, 2.0)) /
        sqrt(20 + pow(barLPrime - 50.0, 2.0)));
    /* Equation 19 */
    double S_C = 1 + (0.045 * barCPrime);
    /* Equation 20 */
    double S_H = 1 + (0.015 * barCPrime * T);
    /* Equation 21 */
    double R_T = (-sin(2.0 * deltaTheta)) * R_C;

    /* Equation 22 */
    double deltaE = sqrt(
        pow(deltaLPrime / (k_L * S_L), 2.0) +
        pow(deltaCPrime / (k_C * S_C), 2.0) +
        pow(deltaHPrime / (k_H * S_H), 2.0) +
        (R_T * (deltaCPrime / (k_C * S_C)) * (deltaHPrime / (k_H * S_H))));

    return (deltaE);
}

double ColorTools::deg2Rad(const double deg) const {
    return (deg * (M_PI / 180.0));
}

double ColorTools::rad2Deg(const double rad) const {
    return ((180.0 / M_PI) * rad);
}
