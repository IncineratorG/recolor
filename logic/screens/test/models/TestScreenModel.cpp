#include "TestScreenModel.h"
#include "stores/Stores.h"

#include <QDebug>

TestScreenModel::TestScreenModel() {
    auto stores = Stores::getInstance();

    auto makeColorTransparentStore = std::dynamic_pointer_cast<TestStore>(
                stores->getStore(Stores::Test));
    if (makeColorTransparentStore == nullptr) {
        qDebug() << __PRETTY_FUNCTION__ << "->TEST_STORE_IS_NULL";
        return;
    }
}
