#ifndef LV_TEXTAREA_HPP
#define LV_TEXTAREA_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/textarea/lv_textarea.h"
}

namespace lvgl {

class LvTextarea {
public:
    explicit LvTextarea() : obj(nullptr) {}

    explicit LvTextarea(lv_obj_t* parent) : obj(lv_textarea_create(parent)) {}

    void lv_add_char(uint32_t c) 
    { 
        lv_textarea_add_char(obj, c);
    }

    void lv_add_text(const char * txt) 
    { 
        lv_textarea_add_text(obj, txt);
    }

    void lv_delete_char() 
    { 
        lv_textarea_delete_char(obj);
    }

    void lv_delete_char_forward() 
    { 
        lv_textarea_delete_char_forward(obj);
    }

    void lv_set_text(const char * txt) 
    { 
        lv_textarea_set_text(obj, txt);
    }

    void lv_set_placeholder_text(const char * txt) 
    { 
        lv_textarea_set_placeholder_text(obj, txt);
    }

    void lv_set_cursor_pos(int32_t pos) 
    { 
        lv_textarea_set_cursor_pos(obj, pos);
    }

    void lv_set_cursor_click_pos(bool en) 
    { 
        lv_textarea_set_cursor_click_pos(obj, en);
    }

    void lv_set_password_mode(bool en) 
    { 
        lv_textarea_set_password_mode(obj, en);
    }

    void lv_set_password_bullet(const char * bullet) 
    { 
        lv_textarea_set_password_bullet(obj, bullet);
    }

    void lv_set_one_line(bool en) 
    { 
        lv_textarea_set_one_line(obj, en);
    }

    void lv_set_accepted_chars(const char * list) 
    { 
        lv_textarea_set_accepted_chars(obj, list);
    }

    void lv_set_accepted_chars_static(const char * list) 
    { 
        lv_textarea_set_accepted_chars_static(obj, list);
    }

    void lv_set_max_length(uint32_t num) 
    { 
        lv_textarea_set_max_length(obj, num);
    }

    void lv_set_insert_replace(const char * txt) 
    { 
        lv_textarea_set_insert_replace(obj, txt);
    }

    void lv_set_text_selection(bool en) 
    { 
        lv_textarea_set_text_selection(obj, en);
    }

    void lv_set_password_show_time(uint32_t time) 
    { 
        lv_textarea_set_password_show_time(obj, time);
    }

    void lv_set_align(lv_text_align_t align) 
    { 
        lv_textarea_set_align(obj, align);
    }

    const char * lv_get_text() 
    { 
        return lv_textarea_get_text(obj);
    }

    const char * lv_get_placeholder_text() 
    { 
        return lv_textarea_get_placeholder_text(obj);
    }

    lv_obj_t * lv_get_label() 
    { 
        return lv_textarea_get_label(obj);
    }

    uint32_t lv_get_cursor_pos() 
    { 
        return lv_textarea_get_cursor_pos(obj);
    }

    bool lv_get_cursor_click_pos() 
    { 
        return lv_textarea_get_cursor_click_pos(obj);
    }

    bool lv_get_password_mode() 
    { 
        return lv_textarea_get_password_mode(obj);
    }

    const char * lv_get_password_bullet() 
    { 
        return lv_textarea_get_password_bullet(obj);
    }

    bool lv_get_one_line() 
    { 
        return lv_textarea_get_one_line(obj);
    }

    const char * lv_get_accepted_chars() 
    { 
        return lv_textarea_get_accepted_chars(obj);
    }

    uint32_t lv_get_max_length() 
    { 
        return lv_textarea_get_max_length(obj);
    }

    bool lv_text_is_selected() 
    { 
        return lv_textarea_text_is_selected(obj);
    }

    bool lv_get_text_selection() 
    { 
        return lv_textarea_get_text_selection(obj);
    }

    uint32_t lv_get_password_show_time() 
    { 
        return lv_textarea_get_password_show_time(obj);
    }

    uint32_t lv_get_current_char() 
    { 
        return lv_textarea_get_current_char(obj);
    }

    void lv_clear_selection() 
    { 
        lv_textarea_clear_selection(obj);
    }

    void lv_cursor_right() 
    { 
        lv_textarea_cursor_right(obj);
    }

    void lv_cursor_left() 
    { 
        lv_textarea_cursor_left(obj);
    }

    void lv_cursor_down() 
    { 
        lv_textarea_cursor_down(obj);
    }

    void lv_cursor_up() 
    { 
        lv_textarea_cursor_up(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_TEXTAREA_HPP */