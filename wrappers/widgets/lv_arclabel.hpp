#ifndef LV_ARCLABEL_HPP
#define LV_ARCLABEL_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/arclabel/lv_arclabel.h"
}

namespace lvgl {

class LvArclabel {
public:
    explicit LvArclabel() : obj(nullptr) {}

    explicit LvArclabel(lv_obj_t* parent) : obj(lv_arclabel_create(parent)) {}

    void lv_set_text(const char * text) 
    { 
        lv_arclabel_set_text(obj, text);
    }

    template<typename... Args>
    void lv_set_text_fmt(const char * fmt, Args&&... args) 
    { 
        lv_arclabel_set_text_fmt(obj, fmt, std::forward<Args>(args)...);
    }

    void lv_set_text_static(const char * text) 
    { 
        lv_arclabel_set_text_static(obj, text);
    }

    void lv_set_angle_start(lv_value_precise_t start) 
    { 
        lv_arclabel_set_angle_start(obj, start);
    }

    void lv_set_angle_size(lv_value_precise_t size) 
    { 
        lv_arclabel_set_angle_size(obj, size);
    }

    void lv_set_offset(int32_t offset) 
    { 
        lv_arclabel_set_offset(obj, offset);
    }

    void lv_set_dir(lv_arclabel_dir_t dir) 
    { 
        lv_arclabel_set_dir(obj, dir);
    }

    void lv_set_recolor(bool en) 
    { 
        lv_arclabel_set_recolor(obj, en);
    }

    void lv_set_radius(uint32_t radius) 
    { 
        lv_arclabel_set_radius(obj, radius);
    }

    void lv_set_center_offset_x(uint32_t x) 
    { 
        lv_arclabel_set_center_offset_x(obj, x);
    }

    void lv_set_center_offset_y(uint32_t y) 
    { 
        lv_arclabel_set_center_offset_y(obj, y);
    }

    void lv_set_text_vertical_align(lv_arclabel_text_align_t align) 
    { 
        lv_arclabel_set_text_vertical_align(obj, align);
    }

    void lv_set_text_horizontal_align(lv_arclabel_text_align_t align) 
    { 
        lv_arclabel_set_text_horizontal_align(obj, align);
    }

    void lv_set_overflow(lv_arclabel_overflow_t overflow) 
    { 
        lv_arclabel_set_overflow(obj, overflow);
    }

    void lv_set_end_overlap(bool overlap) 
    { 
        lv_arclabel_set_end_overlap(obj, overlap);
    }

    lv_value_precise_t lv_get_angle_start() 
    { 
        return lv_arclabel_get_angle_start(obj);
    }

    lv_value_precise_t lv_get_angle_size() 
    { 
        return lv_arclabel_get_angle_size(obj);
    }

    lv_arclabel_dir_t lv_get_dir() 
    { 
        return lv_arclabel_get_dir(obj);
    }

    bool lv_get_recolor() 
    { 
        return lv_arclabel_get_recolor(obj);
    }

    uint32_t lv_get_radius() 
    { 
        return lv_arclabel_get_radius(obj);
    }

    uint32_t lv_get_center_offset_x() 
    { 
        return lv_arclabel_get_center_offset_x(obj);
    }

    uint32_t lv_get_center_offset_y() 
    { 
        return lv_arclabel_get_center_offset_y(obj);
    }

    lv_arclabel_text_align_t lv_get_text_vertical_align() 
    { 
        return lv_arclabel_get_text_vertical_align(obj);
    }

    lv_arclabel_text_align_t lv_get_text_horizontal_align() 
    { 
        return lv_arclabel_get_text_horizontal_align(obj);
    }

    lv_arclabel_overflow_t lv_get_overflow() 
    { 
        return lv_arclabel_get_overflow(obj);
    }

    bool lv_get_end_overlap() 
    { 
        return lv_arclabel_get_end_overlap(obj);
    }

    lv_value_precise_t lv_get_text_angle() 
    { 
        return lv_arclabel_get_text_angle(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_ARCLABEL_HPP */