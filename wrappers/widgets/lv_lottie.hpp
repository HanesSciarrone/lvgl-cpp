#ifndef LV_LOTTIE_HPP
#define LV_LOTTIE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/lottie/lv_lottie.h"
}

namespace lvgl {

class LvLottie {
public:
    explicit LvLottie() : obj(nullptr) {}

    explicit LvLottie(lv_obj_t* parent) : obj(parent) {}

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_LOTTIE_HPP */