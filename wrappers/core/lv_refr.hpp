#ifndef LV_REFR_HPP
#define LV_REFR_HPP

#pragma once

extern "C" {
#include "lvgl/src/core/lv_refr.h"
}

namespace lvgl {

class LvRefr {
public:
    LvRefr() : obj(nullptr) {}

    void lv_now(lv_display_t * disp) 
    { 
        lv_refr_now(disp);
    }

    void lv_redraw(lv_layer_t * layer, lv_obj_t * obj) 
    { 
        lv_obj_redraw(layer, obj);
    }

    void lv_refr_timer(lv_timer_t * timer) 
    { 
        lv_display_refr_timer(timer);
    }


    lv_obj_t* lv_get_obj() const { return this->obj; }


    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_REFR_HPP */