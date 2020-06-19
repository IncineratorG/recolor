#include "Stores.h"

#include <QDebug>

Stores* Stores::mInstance = nullptr;

Stores::Stores() {
    mTestStore = std::make_shared<TestStore>();
    mRecolorStore = std::make_shared<RecolorStore>();
    mJSCStore = std::make_shared<JSCStore>();
}

Stores* Stores::getInstance() {
    if (!mInstance) {
        mInstance = new Stores();
    }

    return mInstance;
}

std::shared_ptr<Store> Stores::getStore(int type) const {
    switch (type) {
        case Test: {
            return mTestStore;
        }

        case Recolor: {
            return mRecolorStore;
        }

        case JavaServerClient: {
            return mJSCStore;
        }
    }

    qDebug() << __PRETTY_FUNCTION__ << "->UNKNOWN_STORE_TYPE: " << type;

    return nullptr;
}
