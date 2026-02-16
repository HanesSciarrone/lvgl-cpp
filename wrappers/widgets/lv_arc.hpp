#ifndef LV_ARC_HPP
#define LV_ARC_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/arc/lv_arc.h"
}

namespace lvgl {

class LvArc {
public:
    explicit LvArc(lv_obj_t* parent) : obj(lv_arc_create(parent)) {}

    void lv_set_start_angle(lv_value_precise_t start) 
    { 
        lv_arc_set_start_angle(obj, start);
    }

    void lv_set_end_angle(lv_value_precise_t end) 
    { 
        lv_arc_set_end_angle(obj, end);
    }

    void lv_set_angles(lv_value_precise_t start, lv_value_precise_t end) 
    { 
        lv_arc_set_angles(obj, start, end);
    }

    void lv_set_bg_start_angle(lv_value_precise_t start) 
    { 
        lv_arc_set_bg_start_angle(obj, start);
    }

    void lv_set_bg_end_angle(lv_value_precise_t end) 
    { 
        lv_arc_set_bg_end_angle(obj, end);
    }

    void lv_set_bg_angles(lv_value_precise_t start, lv_value_precise_t end) 
    { 
        lv_arc_set_bg_angles(obj, start, end);
    }

    void lv_set_rotation(int32_t rotation) 
    { 
        lv_arc_set_rotation(obj, rotation);
    }

    void lv_set_mode(lv_arc_mode_t type) 
    { 
        lv_arc_set_mode(obj, type);
    }

    void lv_set_value(int32_t value) 
    { 
        lv_arc_set_value(obj, value);
    }

    void lv_set_range(int32_t min, int32_t max) 
    { 
        lv_arc_set_range(obj, min, max);
    }

    void lv_set_min_value(int32_t min) 
    { 
        lv_arc_set_min_value(obj, min);
    }

    void lv_set_max_value(int32_t max) 
    { 
        lv_arc_set_max_value(obj, max);
    }

    void lv_set_change_rate(uint32_t rate) 
    { 
        lv_arc_set_change_rate(obj, rate);
    }

    void lv_set_knob_offset(int32_t offset) 
    { 
        lv_arc_set_knob_offset(obj, offset);
    }

    lv_value_precise_t lv_get_angle_start() 
    { 
        return lv_arc_get_angle_start(obj);
    }

    lv_value_precise_t lv_get_angle_end() 
    { 
        return lv_arc_get_angle_end(obj);
    }

    lv_value_precise_t lv_get_bg_angle_start() 
    { 
        return lv_arc_get_bg_angle_start(obj);
    }

    lv_value_precise_t lv_get_bg_angle_end() 
    { 
        return lv_arc_get_bg_angle_end(obj);
    }

    int32_t lv_get_value() 
    { 
        return lv_arc_get_value(obj);
    }

    int32_t lv_get_min_value() 
    { 
        return lv_arc_get_min_value(obj);
    }

    int32_t lv_get_max_value() 
    { 
        return lv_arc_get_max_value(obj);
    }

    lv_arc_mode_t lv_get_mode() 
    { 
        return lv_arc_get_mode(obj);
    }

    int32_t lv_get_rotation() 
    { 
        return lv_arc_get_rotation(obj);
    }

    int32_t lv_get_knob_offset() 
    { 
        return lv_arc_get_knob_offset(obj);
    }

    lv_observer_t * lv_bind_value(lv_subject_t * subject) 
    { 
        return lv_arc_bind_value(obj, subject);
    }

    void lv_align_obj_to_angle(lv_obj_t * obj_to_align, int32_t r_offset) 
    { 
        lv_arc_align_obj_to_angle(obj, obj_to_align, r_offset);
    }

    void lv_rotate_obj_to_angle(lv_obj_t * obj_to_rotate, int32_t r_offset) 
    { 
        lv_arc_rotate_obj_to_angle(obj, obj_to_rotate, r_offset);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_ARC_HPP */