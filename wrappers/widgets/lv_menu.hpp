#ifndef LV_MENU_HPP
#define LV_MENU_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/menu/lv_menu.h"
}

namespace lvgl {

class LvMenu {
public:
    explicit LvMenu() : obj(nullptr) {}

    explicit LvMenu(lv_obj_t* parent) : obj(lv_menu_separator_create(parent)) {}

    void lv_set_page(lv_obj_t * page) 
    { 
        lv_menu_set_page(obj, page);
    }

    void lv_set_page_title(char const * const title) 
    { 
        lv_menu_set_page_title(obj, title);
    }

    void lv_set_page_title_static(char const * const title) 
    { 
        lv_menu_set_page_title_static(obj, title);
    }

    void lv_set_sidebar_page(lv_obj_t * page) 
    { 
        lv_menu_set_sidebar_page(obj, page);
    }

    void lv_set_mode_header(lv_menu_mode_header_t mode) 
    { 
        lv_menu_set_mode_header(obj, mode);
    }

    void lv_set_mode_root_back_button(lv_menu_mode_root_back_button_t mode) 
    { 
        lv_menu_set_mode_root_back_button(obj, mode);
    }

    void lv_set_load_page_event(lv_obj_t * obj, lv_obj_t * page) 
    { 
        lv_menu_set_load_page_event(obj, obj, page);
    }

    lv_obj_t * lv_get_cur_main_page() 
    { 
        return lv_menu_get_cur_main_page(obj);
    }

    lv_obj_t * lv_get_cur_sidebar_page() 
    { 
        return lv_menu_get_cur_sidebar_page(obj);
    }

    lv_obj_t * lv_get_main_header() 
    { 
        return lv_menu_get_main_header(obj);
    }

    lv_obj_t * lv_get_main_header_back_button() 
    { 
        return lv_menu_get_main_header_back_button(obj);
    }

    lv_obj_t * lv_get_sidebar_header() 
    { 
        return lv_menu_get_sidebar_header(obj);
    }

    lv_obj_t * lv_get_sidebar_header_back_button() 
    { 
        return lv_menu_get_sidebar_header_back_button(obj);
    }

    bool lv_back_button_is_root(lv_obj_t * obj) 
    { 
        return lv_menu_back_button_is_root(obj, obj);
    }

    lv_menu_mode_header_t lv_get_mode_header() 
    { 
        return lv_menu_get_mode_header(obj);
    }

    lv_menu_mode_root_back_button_t lv_get_mode_root_back_button() 
    { 
        return lv_menu_get_mode_root_back_button(obj);
    }

    void lv_clear_history() 
    { 
        lv_menu_clear_history(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_MENU_HPP */