#ifndef LV_SPINBOX_HPP
#define LV_SPINBOX_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/spinbox/lv_spinbox.h"
}

namespace lvgl {

class LvSpinbox {
public:
    explicit LvSpinbox() : obj(nullptr) {}

    explicit LvSpinbox(lv_obj_t* parent) : obj(lv_spinbox_create(parent)) {}

    void lv_set_value(int32_t v) 
    { 
        lv_spinbox_set_value(obj, v);
    }

    void lv_set_rollover(bool rollover) 
    { 
        lv_spinbox_set_rollover(obj, rollover);
    }

    void lv_set_digit_format(uint32_t digit_count, uint32_t sep_pos) 
    { 
        lv_spinbox_set_digit_format(obj, digit_count, sep_pos);
    }

    void lv_set_digit_count(uint32_t digit_count) 
    { 
        lv_spinbox_set_digit_count(obj, digit_count);
    }

    void lv_set_dec_point_pos(uint32_t dec_point_pos) 
    { 
        lv_spinbox_set_dec_point_pos(obj, dec_point_pos);
    }

    void lv_set_step(uint32_t step) 
    { 
        lv_spinbox_set_step(obj, step);
    }

    void lv_set_range(int32_t min_value, int32_t max_value) 
    { 
        lv_spinbox_set_range(obj, min_value, max_value);
    }

    void lv_set_min_value(int32_t min_value) 
    { 
        lv_spinbox_set_min_value(obj, min_value);
    }

    void lv_set_max_value(int32_t max_value) 
    { 
        lv_spinbox_set_max_value(obj, max_value);
    }

    void lv_set_cursor_pos(uint32_t pos) 
    { 
        lv_spinbox_set_cursor_pos(obj, pos);
    }

    void lv_set_digit_step_direction(lv_dir_t direction) 
    { 
        lv_spinbox_set_digit_step_direction(obj, direction);
    }

    bool lv_get_rollover() 
    { 
        return lv_spinbox_get_rollover(obj);
    }

    int32_t lv_get_value() 
    { 
        return lv_spinbox_get_value(obj);
    }

    int32_t lv_get_step() 
    { 
        return lv_spinbox_get_step(obj);
    }

    uint32_t lv_get_digit_count() 
    { 
        return lv_spinbox_get_digit_count(obj);
    }

    uint32_t lv_get_dec_point_pos() 
    { 
        return lv_spinbox_get_dec_point_pos(obj);
    }

    int32_t lv_get_min_value() 
    { 
        return lv_spinbox_get_min_value(obj);
    }

    int32_t lv_get_max_value() 
    { 
        return lv_spinbox_get_max_value(obj);
    }

    lv_dir_t lv_get_digit_step_direction() 
    { 
        return lv_spinbox_get_digit_step_direction(obj);
    }

    void lv_step_next() 
    { 
        lv_spinbox_step_next(obj);
    }

    void lv_step_prev() 
    { 
        lv_spinbox_step_prev(obj);
    }

    void lv_increment() 
    { 
        lv_spinbox_increment(obj);
    }

    void lv_decrement() 
    { 
        lv_spinbox_decrement(obj);
    }

    lv_observer_t * lv_bind_value(lv_subject_t * subject) 
    { 
        return lv_spinbox_bind_value(obj, subject);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_SPINBOX_HPP */