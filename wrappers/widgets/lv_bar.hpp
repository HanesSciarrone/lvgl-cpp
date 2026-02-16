#ifndef LV_BAR_HPP
#define LV_BAR_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/bar/lv_bar.h"
}

namespace lvgl {

class LvBar {
public:
    explicit LvBar() : obj(nullptr) {}

    explicit LvBar(lv_obj_t* parent) : obj(lv_bar_create(parent)) {}

    void lv_set_value(int32_t value, lv_anim_enable_t anim) 
    { 
        lv_bar_set_value(obj, value, anim);
    }

    void lv_set_start_value(int32_t start_value, lv_anim_enable_t anim) 
    { 
        lv_bar_set_start_value(obj, start_value, anim);
    }

    void lv_set_range(int32_t min, int32_t max) 
    { 
        lv_bar_set_range(obj, min, max);
    }

    void lv_set_min_value(int32_t min) 
    { 
        lv_bar_set_min_value(obj, min);
    }

    void lv_set_max_value(int32_t max) 
    { 
        lv_bar_set_max_value(obj, max);
    }

    void lv_set_mode(lv_bar_mode_t mode) 
    { 
        lv_bar_set_mode(obj, mode);
    }

    void lv_set_orientation(lv_bar_orientation_t orientation) 
    { 
        lv_bar_set_orientation(obj, orientation);
    }

    int32_t lv_get_value() 
    { 
        return lv_bar_get_value(obj);
    }

    int32_t lv_get_start_value() 
    { 
        return lv_bar_get_start_value(obj);
    }

    int32_t lv_get_min_value() 
    { 
        return lv_bar_get_min_value(obj);
    }

    int32_t lv_get_max_value() 
    { 
        return lv_bar_get_max_value(obj);
    }

    lv_bar_mode_t lv_get_mode() 
    { 
        return lv_bar_get_mode(obj);
    }

    lv_bar_orientation_t lv_get_orientation() 
    { 
        return lv_bar_get_orientation(obj);
    }

    bool lv_is_symmetrical() 
    { 
        return lv_bar_is_symmetrical(obj);
    }

    lv_observer_t * lv_bind_value(lv_subject_t * subject) 
    { 
        return lv_bar_bind_value(obj, subject);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_BAR_HPP */