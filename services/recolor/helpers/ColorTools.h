#ifndef COLORTOOLS_H
#define COLORTOOLS_H

#include <QList>

class ColorTools
{
public:
    ColorTools();

    // XYZ (Tristimulus) Reference values of a perfect reflecting diffuser

    // 2o Observer (CIE 1931)
    // X2, Y2, Z2
    QList<float> CIE2_A;        //Incandescent
    QList<float> CIE2_C;
    QList<float> CIE2_D50;
    QList<float> CIE2_D55;
    QList<float> CIE2_D65;      //Daylight
    QList<float> CIE2_D75;
    QList<float> CIE2_F2;       //Fluorescent
    QList<float> CIE2_F7;
    QList<float> CIE2_F11;

    //10o Observer (CIE 1964)
    // X2, Y2, Z2
    QList<float> CIE10_A;       //Incandescent
    QList<float> CIE10_C;
    QList<float> CIE10_D50;
    QList<float> CIE10_D55;
    QList<float> CIE10_D65;     //Daylight
    QList<float> CIE10_D75;
    QList<float> CIE10_F2;      //Fluorescent
    QList<float> CIE10_F7;
    QList<float> CIE10_F11;

    QList<float> RGBtoLAB(int red, int green, int blue,
                                 QList<float> tristimulus) const;

    QList<float> RGBtoXYZ(int red, int green, int blue) const;

    QList<float> XYZtoLAB(float x, float y, float z,
                                 QList<float> tristimulus) const;

    double deltaE(const float L1, const float a1, const float b1,
                 const float L2, const float a2, const float b2) const;
    double deltaE_V2(const float L1, const float a1, const float b1,
                     const float L2, const float a2, const float b2) const;

private:
    double deg2Rad(const double deg) const;
    double rad2Deg(const double rad) const;
};

#endif // COLORTOOLS_H
