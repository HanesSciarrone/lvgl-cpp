#ifndef LV_SPAN_HPP
#define LV_SPAN_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/span/lv_span.h"
}

namespace lvgl {

class LvSpan {
public:
    explicit LvSpan(lv_obj_t* parent) : obj(lv_spangroup_create(parent)) {}

    void lv_stack_init() 
    { 
        lv_span_stack_init();
    }

    void lv_stack_deinit() 
    { 
        lv_span_stack_deinit();
    }

    lv_span_t * lv_add_span() 
    { 
        return lv_spangroup_add_span(obj);
    }

    void lv_delete_span(lv_span_t * span) 
    { 
        lv_spangroup_delete_span(obj, span);
    }

    void lv_set_text(lv_span_t * span, const char * text) 
    { 
        lv_span_set_text(span, text);
    }

    template<typename... Args>
    void lv_set_text_fmt(lv_span_t * span, const char * fmt, Args&&... args) 
    { 
        lv_span_set_text_fmt(span, fmt, std::forward<Args>(args)...);
    }

    void lv_set_text_static(lv_span_t * span, const char * text) 
    { 
        lv_span_set_text_static(span, text);
    }

    void lv_set_span_text(lv_span_t * span, const char * text) 
    { 
        lv_spangroup_set_span_text(obj, span, text);
    }

    void lv_set_span_text_static(lv_span_t * span, const char * text) 
    { 
        lv_spangroup_set_span_text_static(obj, span, text);
    }

    template<typename... Args>
    void lv_set_span_text_fmt(lv_span_t * span, const char * fmt, Args&&... args) 
    { 
        lv_spangroup_set_span_text_fmt(obj, span, fmt, std::forward<Args>(args)...);
    }

    void lv_set_text_static(lv_span_t * span, const char * text) 
    { 
        lv_span_set_text_static(span, text);
    }

    void lv_set_span_style(lv_span_t * span, const lv_style_t * style) 
    { 
        lv_spangroup_set_span_style(obj, span, style);
    }

    void lv_set_align(lv_text_align_t align) 
    { 
        lv_spangroup_set_align(obj, align);
    }

    void lv_set_overflow(lv_span_overflow_t overflow) 
    { 
        lv_spangroup_set_overflow(obj, overflow);
    }

    void lv_set_indent(int32_t indent) 
    { 
        lv_spangroup_set_indent(obj, indent);
    }

    void lv_set_mode(lv_span_mode_t mode) 
    { 
        lv_spangroup_set_mode(obj, mode);
    }

    void lv_set_max_lines(int32_t lines) 
    { 
        lv_spangroup_set_max_lines(obj, lines);
    }

    lv_style_t * lv_get_style(lv_span_t * span) 
    { 
        return lv_span_get_style(span);
    }

    const char * lv_get_text(lv_span_t * span) 
    { 
        return lv_span_get_text(span);
    }

    lv_span_t * lv_get_child(int32_t id) 
    { 
        return lv_spangroup_get_child(obj, id);
    }

    uint32_t lv_get_span_count() 
    { 
        return lv_spangroup_get_span_count(obj);
    }

    lv_text_align_t lv_get_align() 
    { 
        return lv_spangroup_get_align(obj);
    }

    lv_span_overflow_t lv_get_overflow() 
    { 
        return lv_spangroup_get_overflow(obj);
    }

    int32_t lv_get_indent() 
    { 
        return lv_spangroup_get_indent(obj);
    }

    lv_span_mode_t lv_get_mode() 
    { 
        return lv_spangroup_get_mode(obj);
    }

    int32_t lv_get_max_lines() 
    { 
        return lv_spangroup_get_max_lines(obj);
    }

    int32_t lv_get_max_line_height() 
    { 
        return lv_spangroup_get_max_line_height(obj);
    }

    uint32_t lv_get_expand_width(uint32_t max_width) 
    { 
        return lv_spangroup_get_expand_width(obj, max_width);
    }

    int32_t lv_get_expand_height(int32_t width) 
    { 
        return lv_spangroup_get_expand_height(obj, width);
    }

    lv_span_coords_t lv_get_span_coords(const lv_span_t * span) 
    { 
        return lv_spangroup_get_span_coords(obj, span);
    }

    lv_span_t * lv_get_span_by_point(const lv_point_t * point) 
    { 
        return lv_spangroup_get_span_by_point(obj, point);
    }

    void lv_refresh() 
    { 
        lv_spangroup_refresh(obj);
    }

    lv_observer_t * lv_bind_span_text(lv_span_t * span, lv_subject_t * subject, const char * fmt) 
    { 
        return lv_spangroup_bind_span_text(obj, span, subject, fmt);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_SPAN_HPP */