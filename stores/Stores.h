#ifndef STORES_H
#define STORES_H

#include "test/TestStore.h"
#include "recolor/RecolorStore.h"

#include <memory>

class Stores
{
public:
    static const int Test = 1;
    static const int Recolor = 2;

    static Stores* getInstance();

    std::shared_ptr<Store> getStore(int type) const;

private:
    static Stores* mInstance;

    std::shared_ptr<TestStore> mTestStore;
    std::shared_ptr<RecolorStore> mRecolorStore;

    Stores();
};

#endif // STORES_H
