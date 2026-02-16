#ifndef LV_KEYBOARD_HPP
#define LV_KEYBOARD_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/keyboard/lv_keyboard.h"
}

namespace lvgl {

class LvKeyboard {
public:
    explicit LvKeyboard() : obj(nullptr) {}

    explicit LvKeyboard(lv_obj_t* parent) : obj(lv_keyboard_create(parent)) {}

    void lv_set_textarea(lv_obj_t * ta) 
    { 
        lv_keyboard_set_textarea(obj, ta);
    }

    void lv_set_mode(lv_keyboard_mode_t mode) 
    { 
        lv_keyboard_set_mode(obj, mode);
    }

    void lv_set_popovers(bool en) 
    { 
        lv_keyboard_set_popovers(obj, en);
    }

    void lv_set_map(lv_keyboard_mode_t mode, const char * const map[], const lv_buttonmatrix_ctrl_t ctrl_map[]) 
    { 
        lv_keyboard_set_map(obj, mode, map, ctrl_map);
    }

    lv_obj_t * lv_get_textarea() 
    { 
        return lv_keyboard_get_textarea(obj);
    }

    lv_keyboard_mode_t lv_get_mode() 
    { 
        return lv_keyboard_get_mode(obj);
    }

    bool lv_get_popovers() 
    { 
        return lv_keyboard_get_popovers(obj);
    }

    const char * const * lv_get_map_array() 
    { 
        return lv_keyboard_get_map_array(obj);
    }

    uint32_t lv_get_selected_button() 
    { 
        return lv_keyboard_get_selected_button(obj);
    }

    const char * lv_get_button_text(uint32_t btn_id) 
    { 
        return lv_keyboard_get_button_text(obj, btn_id);
    }

    void lv_def_event_cb(lv_event_t * e) 
    { 
        lv_keyboard_def_event_cb(e);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_KEYBOARD_HPP */