#ifndef LV_SCALE_HPP
#define LV_SCALE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/scale/lv_scale.h"
}

namespace lvgl {

class LvScale {
public:
    explicit LvScale() : obj(nullptr) {}

    explicit LvScale(lv_obj_t* parent) : obj(lv_scale_create(parent)) {}

    void lv_set_mode(lv_scale_mode_t mode) 
    { 
        lv_scale_set_mode(obj, mode);
    }

    void lv_set_total_tick_count(uint32_t total_tick_count) 
    { 
        lv_scale_set_total_tick_count(obj, total_tick_count);
    }

    void lv_set_major_tick_every(uint32_t major_tick_every) 
    { 
        lv_scale_set_major_tick_every(obj, major_tick_every);
    }

    void lv_set_label_show(bool show_label) 
    { 
        lv_scale_set_label_show(obj, show_label);
    }

    void lv_set_range(int32_t min, int32_t max) 
    { 
        lv_scale_set_range(obj, min, max);
    }

    void lv_set_min_value(int32_t min) 
    { 
        lv_scale_set_min_value(obj, min);
    }

    void lv_set_max_value(int32_t max) 
    { 
        lv_scale_set_max_value(obj, max);
    }

    void lv_set_angle_range(uint32_t angle_range) 
    { 
        lv_scale_set_angle_range(obj, angle_range);
    }

    void lv_set_rotation(int32_t rotation) 
    { 
        lv_scale_set_rotation(obj, rotation);
    }

    void lv_set_line_needle_value(lv_obj_t * needle_line, int32_t needle_length, int32_t value) 
    { 
        lv_scale_set_line_needle_value(obj, needle_line, needle_length, value);
    }

    void lv_set_image_needle_value(lv_obj_t * needle_img, int32_t value) 
    { 
        lv_scale_set_image_needle_value(obj, needle_img, value);
    }

    void lv_set_text_src(const char * txt_src[]) 
    { 
        lv_scale_set_text_src(obj, txt_src);
    }

    void lv_set_post_draw(bool en) 
    { 
        lv_scale_set_post_draw(obj, en);
    }

    void lv_set_draw_ticks_on_top(bool en) 
    { 
        lv_scale_set_draw_ticks_on_top(obj, en);
    }

    lv_scale_section_t * lv_add_section() 
    { 
        return lv_scale_add_section(obj);
    }

    void lv_section_set_range(lv_scale_section_t * section, int32_t min, int32_t max) 
    { 
        lv_scale_section_set_range(section, min, max);
    }

    void lv_set_section_range(lv_scale_section_t * section, int32_t min, int32_t max) 
    { 
        lv_scale_set_section_range(obj, section, min, max);
    }

    void lv_set_section_min_value(lv_scale_section_t * section, int32_t min) 
    { 
        lv_scale_set_section_min_value(obj, section, min);
    }

    void lv_set_section_max_value(lv_scale_section_t * section, int32_t max) 
    { 
        lv_scale_set_section_max_value(obj, section, max);
    }

    void lv_section_set_style(lv_scale_section_t * section, lv_part_t part, lv_style_t * section_part_style) 
    { 
        lv_scale_section_set_style(section, part, section_part_style);
    }

    void lv_set_section_style_main(lv_scale_section_t * section, const lv_style_t * style) 
    { 
        lv_scale_set_section_style_main(obj, section, style);
    }

    void lv_set_section_style_indicator(lv_scale_section_t * section, const lv_style_t * style) 
    { 
        lv_scale_set_section_style_indicator(obj, section, style);
    }

    void lv_set_section_style_items(lv_scale_section_t * section, const lv_style_t * style) 
    { 
        lv_scale_set_section_style_items(obj, section, style);
    }

    lv_scale_mode_t lv_get_mode() 
    { 
        return lv_scale_get_mode(obj);
    }

    int32_t lv_get_total_tick_count() 
    { 
        return lv_scale_get_total_tick_count(obj);
    }

    int32_t lv_get_major_tick_every() 
    { 
        return lv_scale_get_major_tick_every(obj);
    }

    int32_t lv_get_rotation() 
    { 
        return lv_scale_get_rotation(obj);
    }

    bool lv_get_label_show() 
    { 
        return lv_scale_get_label_show(obj);
    }

    uint32_t lv_get_angle_range() 
    { 
        return lv_scale_get_angle_range(obj);
    }

    int32_t lv_get_range_min_value() 
    { 
        return lv_scale_get_range_min_value(obj);
    }

    int32_t lv_get_range_max_value() 
    { 
        return lv_scale_get_range_max_value(obj);
    }

    lv_observer_t * lv_bind_section_min_value(lv_scale_section_t * section, lv_subject_t * subject) 
    { 
        return lv_scale_bind_section_min_value(obj, section, subject);
    }

    lv_observer_t * lv_bind_section_max_value(lv_scale_section_t * section, lv_subject_t * subject) 
    { 
        return lv_scale_bind_section_max_value(obj, section, subject);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_SCALE_HPP */