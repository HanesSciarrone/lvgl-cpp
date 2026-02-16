#ifndef LV_SLIDER_HPP
#define LV_SLIDER_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/slider/lv_slider.h"
}

namespace lvgl {

class LvSlider {
public:
    explicit LvSlider() : obj(nullptr) {}

    explicit LvSlider(lv_obj_t* parent) : obj(lv_slider_create(parent)) {}

    void lv_set_value(int32_t value, lv_anim_enable_t anim) 
    { 
        lv_slider_set_value(obj, value, anim);
    }

    void lv_set_start_value(int32_t value, lv_anim_enable_t anim) 
    { 
        lv_slider_set_start_value(obj, value, anim);
    }

    void lv_set_range(int32_t min, int32_t max) 
    { 
        lv_slider_set_range(obj, min, max);
    }

    void lv_set_min_value(int32_t min) 
    { 
        lv_slider_set_min_value(obj, min);
    }

    void lv_set_max_value(int32_t max) 
    { 
        lv_slider_set_max_value(obj, max);
    }

    void lv_set_mode(lv_slider_mode_t mode) 
    { 
        lv_slider_set_mode(obj, mode);
    }

    void lv_set_orientation(lv_slider_orientation_t orientation) 
    { 
        lv_slider_set_orientation(obj, orientation);
    }

    int32_t lv_get_value() 
    { 
        return lv_slider_get_value(obj);
    }

    int32_t lv_get_left_value() 
    { 
        return lv_slider_get_left_value(obj);
    }

    int32_t lv_get_min_value() 
    { 
        return lv_slider_get_min_value(obj);
    }

    int32_t lv_get_max_value() 
    { 
        return lv_slider_get_max_value(obj);
    }

    bool lv_is_dragged() 
    { 
        return lv_slider_is_dragged(obj);
    }

    lv_slider_mode_t lv_get_mode() 
    { 
        return lv_slider_get_mode(obj);
    }

    lv_slider_orientation_t lv_get_orientation() 
    { 
        return lv_slider_get_orientation(obj);
    }

    bool lv_is_symmetrical() 
    { 
        return lv_slider_is_symmetrical(obj);
    }

    lv_observer_t * lv_bind_value(lv_subject_t * subject) 
    { 
        return lv_slider_bind_value(obj, subject);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_SLIDER_HPP */