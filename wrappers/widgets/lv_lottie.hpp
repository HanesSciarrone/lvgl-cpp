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
    explicit LvLottie(lv_obj_t* parent) : obj(parent) {}


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_LOTTIE_HPP */