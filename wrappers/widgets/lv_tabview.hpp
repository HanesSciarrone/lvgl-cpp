#ifndef LV_TABVIEW_HPP
#define LV_TABVIEW_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/tabview/lv_tabview.h"
}

namespace lvgl {

class LvTabview {
public:
    explicit LvTabview() : obj(nullptr) {}

    explicit LvTabview(lv_obj_t* parent) : obj(lv_tabview_create(parent)) {}

    lv_obj_t * lv_add_tab(const char * name) 
    { 
        return lv_tabview_add_tab(obj, name);
    }

    void lv_set_tab_text(uint32_t idx, const char * new_name) 
    { 
        lv_tabview_set_tab_text(obj, idx, new_name);
    }

    void lv_set_active(uint32_t idx, lv_anim_enable_t anim_en) 
    { 
        lv_tabview_set_active(obj, idx, anim_en);
    }

    void lv_set_tab_bar_position(lv_dir_t dir) 
    { 
        lv_tabview_set_tab_bar_position(obj, dir);
    }

    void lv_set_tab_bar_size(int32_t size) 
    { 
        lv_tabview_set_tab_bar_size(obj, size);
    }

    uint32_t lv_get_tab_count() 
    { 
        return lv_tabview_get_tab_count(obj);
    }

    uint32_t lv_get_tab_active() 
    { 
        return lv_tabview_get_tab_active(obj);
    }

    lv_obj_t * lv_get_tab_button(int32_t idx) 
    { 
        return lv_tabview_get_tab_button(obj, idx);
    }

    lv_obj_t * lv_get_content() 
    { 
        return lv_tabview_get_content(obj);
    }

    lv_obj_t * lv_get_tab_bar() 
    { 
        return lv_tabview_get_tab_bar(obj);
    }

    lv_dir_t lv_get_tab_bar_position() 
    { 
        return lv_tabview_get_tab_bar_position(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_TABVIEW_HPP */