#ifndef LV_LABEL_HPP
#define LV_LABEL_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/label/lv_label.h"
}

namespace lvgl {

class LvLabel {
public:
    explicit LvLabel(lv_obj_t* parent) : obj(lv_label_create(parent)) {}

    void lv_set_text(const char * text) 
    { 
        lv_label_set_text(obj, text);
    }

    template<typename... Args>
    void lv_set_text_fmt(const char * fmt, Args&&... args) 
    { 
        lv_label_set_text_fmt(obj, fmt, std::forward<Args>(args)...);
    }

    void lv_set_text_vfmt(const char * fmt, va_list args) 
    { 
        lv_label_set_text_vfmt(obj, fmt, args);
    }

    void lv_set_text_static(const char * text) 
    { 
        lv_label_set_text_static(obj, text);
    }

    void lv_set_long_mode(lv_label_long_mode_t long_mode) 
    { 
        lv_label_set_long_mode(obj, long_mode);
    }

    void lv_set_text_selection_start(uint32_t index) 
    { 
        lv_label_set_text_selection_start(obj, index);
    }

    void lv_set_text_selection_end(uint32_t index) 
    { 
        lv_label_set_text_selection_end(obj, index);
    }

    void lv_set_recolor(bool en) 
    { 
        lv_label_set_recolor(obj, en);
    }

    char * lv_get_text() 
    { 
        return lv_label_get_text(obj);
    }

    lv_label_long_mode_t lv_get_long_mode() 
    { 
        return lv_label_get_long_mode(obj);
    }

    void lv_get_letter_pos(uint32_t char_id, lv_point_t * pos) 
    { 
        lv_label_get_letter_pos(obj, char_id, pos);
    }

    uint32_t lv_get_letter_on(lv_point_t * pos_in, bool bidi) 
    { 
        return lv_label_get_letter_on(obj, pos_in, bidi);
    }

    bool lv_is_char_under_pos(lv_point_t * pos) 
    { 
        return lv_label_is_char_under_pos(obj, pos);
    }

    uint32_t lv_get_text_selection_start() 
    { 
        return lv_label_get_text_selection_start(obj);
    }

    uint32_t lv_get_text_selection_end() 
    { 
        return lv_label_get_text_selection_end(obj);
    }

    bool lv_get_recolor() 
    { 
        return lv_label_get_recolor(obj);
    }

    lv_observer_t * lv_bind_text(lv_subject_t * subject, const char * fmt) 
    { 
        return lv_label_bind_text(obj, subject, fmt);
    }

    void lv_ins_text(uint32_t pos, const char * txt) 
    { 
        lv_label_ins_text(obj, pos, txt);
    }

    void lv_cut_text(uint32_t pos, uint32_t cnt) 
    { 
        lv_label_cut_text(obj, pos, cnt);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_LABEL_HPP */