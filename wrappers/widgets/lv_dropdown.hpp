#ifndef LV_DROPDOWN_HPP
#define LV_DROPDOWN_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/dropdown/lv_dropdown.h"
}

namespace lvgl {

class LvDropdown {
public:
    explicit LvDropdown(lv_obj_t* parent) : obj(lv_dropdown_create(parent)) {}

    void lv_set_text(const char * txt) 
    { 
        lv_dropdown_set_text(obj, txt);
    }

    void lv_set_options(const char * options) 
    { 
        lv_dropdown_set_options(obj, options);
    }

    void lv_set_options_static(const char * options) 
    { 
        lv_dropdown_set_options_static(obj, options);
    }

    void lv_add_option(const char * option, uint32_t pos) 
    { 
        lv_dropdown_add_option(obj, option, pos);
    }

    void lv_clear_options() 
    { 
        lv_dropdown_clear_options(obj);
    }

    void lv_set_selected(uint32_t sel_opt) 
    { 
        lv_dropdown_set_selected(obj, sel_opt);
    }

    void lv_set_dir(lv_dir_t dir) 
    { 
        lv_dropdown_set_dir(obj, dir);
    }

    void lv_set_symbol(const void * symbol) 
    { 
        lv_dropdown_set_symbol(obj, symbol);
    }

    void lv_set_selected_highlight(bool en) 
    { 
        lv_dropdown_set_selected_highlight(obj, en);
    }

    lv_obj_t * lv_get_list() 
    { 
        return lv_dropdown_get_list(obj);
    }

    const char * lv_get_text() 
    { 
        return lv_dropdown_get_text(obj);
    }

    const char * lv_get_options() 
    { 
        return lv_dropdown_get_options(obj);
    }

    uint32_t lv_get_selected() 
    { 
        return lv_dropdown_get_selected(obj);
    }

    uint32_t lv_get_option_count() 
    { 
        return lv_dropdown_get_option_count(obj);
    }

    void lv_get_selected_str(char * buf, uint32_t buf_size) 
    { 
        lv_dropdown_get_selected_str(obj, buf, buf_size);
    }

    int32_t lv_get_option_index(const char * option) 
    { 
        return lv_dropdown_get_option_index(obj, option);
    }

    const char * lv_get_symbol() 
    { 
        return lv_dropdown_get_symbol(obj);
    }

    bool lv_get_selected_highlight() 
    { 
        return lv_dropdown_get_selected_highlight(obj);
    }

    lv_dir_t lv_get_dir() 
    { 
        return lv_dropdown_get_dir(obj);
    }

    void lv_open() 
    { 
        lv_dropdown_open(obj);
    }

    void lv_close() 
    { 
        lv_dropdown_close(obj);
    }

    bool lv_is_open() 
    { 
        return lv_dropdown_is_open(obj);
    }

    lv_observer_t * lv_bind_value(lv_subject_t * subject) 
    { 
        return lv_dropdown_bind_value(obj, subject);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_DROPDOWN_HPP */