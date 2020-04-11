#include "Store.h"

Store::~Store() {

}

void Store::dispatch(std::shared_ptr<Action> action) {
    reduce(action);
    effect(action);
}
