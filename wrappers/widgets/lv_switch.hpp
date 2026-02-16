#ifndef LV_SWITCH_HPP
#define LV_SWITCH_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/switch/lv_switch.h"
}

namespace lvgl {

class LvSwitch {
public:
    explicit LvSwitch(lv_obj_t* parent) : obj(lv_switch_create(parent)) {}

    void lv_set_orientation(lv_switch_orientation_t orientation) 
    { 
        lv_switch_set_orientation(obj, orientation);
    }

    lv_switch_orientation_t lv_get_orientation() 
    { 
        return lv_switch_get_orientation(obj);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_SWITCH_HPP */