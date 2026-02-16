#ifndef LV_SPINNER_HPP
#define LV_SPINNER_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/spinner/lv_spinner.h"
}

namespace lvgl {

class LvSpinner {
public:
    explicit LvSpinner(lv_obj_t* parent) : obj(lv_spinner_create(parent)) {}

    void lv_set_anim_params(uint32_t t, uint32_t angle) 
    { 
        lv_spinner_set_anim_params(obj, t, angle);
    }

    void lv_set_anim_duration(uint32_t t) 
    { 
        lv_spinner_set_anim_duration(obj, t);
    }

    void lv_set_arc_sweep(uint32_t angle) 
    { 
        lv_spinner_set_arc_sweep(obj, angle);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_SPINNER_HPP */