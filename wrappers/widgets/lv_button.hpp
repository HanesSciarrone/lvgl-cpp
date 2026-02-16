#ifndef LV_BUTTON_HPP
#define LV_BUTTON_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/button/lv_button.h"
}

namespace lvgl {

class LvButton {
public:
    explicit LvButton(lv_obj_t* parent) : obj(lv_button_create(parent)) {}


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_BUTTON_HPP */