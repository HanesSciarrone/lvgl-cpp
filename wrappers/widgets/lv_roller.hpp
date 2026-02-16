#ifndef LV_ROLLER_HPP
#define LV_ROLLER_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/roller/lv_roller.h"
}

namespace lvgl {

class LvRoller {
public:
    explicit LvRoller(lv_obj_t* parent) : obj(lv_roller_create(parent)) {}

    void lv_set_options(const char * options, lv_roller_mode_t mode) 
    { 
        lv_roller_set_options(obj, options, mode);
    }

    void lv_set_selected(uint32_t sel_opt, lv_anim_enable_t anim) 
    { 
        lv_roller_set_selected(obj, sel_opt, anim);
    }

    bool lv_set_selected_str(const char * sel_opt, lv_anim_enable_t anim) 
    { 
        return lv_roller_set_selected_str(obj, sel_opt, anim);
    }

    void lv_set_visible_row_count(uint32_t row_cnt) 
    { 
        lv_roller_set_visible_row_count(obj, row_cnt);
    }

    uint32_t lv_get_selected() 
    { 
        return lv_roller_get_selected(obj);
    }

    void lv_get_selected_str(char * buf, uint32_t buf_size) 
    { 
        lv_roller_get_selected_str(obj, buf, buf_size);
    }

    const char * lv_get_options() 
    { 
        return lv_roller_get_options(obj);
    }

    uint32_t lv_get_option_count() 
    { 
        return lv_roller_get_option_count(obj);
    }

    lv_result_t lv_get_option_str(uint32_t option, char * buf, uint32_t buf_size) 
    { 
        return lv_roller_get_option_str(obj, option, buf, buf_size);
    }

    lv_observer_t * lv_bind_value(lv_subject_t * subject) 
    { 
        return lv_roller_bind_value(obj, subject);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_ROLLER_HPP */