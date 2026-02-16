#ifndef LV_OBJ_HPP
#define LV_OBJ_HPP

#pragma once

extern "C" {
#include "lvgl/src/core/lv_obj.h"
}

namespace lvgl {

class LvObj {
public:
    LvObj() : obj(nullptr) {}

    explicit LvObj(lv_obj_t* parent) : obj(lv_obj_create(parent)) {}

    void lv_add_flag(lv_obj_flag_t f) 
    { 
        lv_obj_add_flag(obj, f);
    }

    void lv_remove_flag(lv_obj_flag_t f) 
    { 
        lv_obj_remove_flag(obj, f);
    }

    void lv_set_flag(lv_obj_flag_t f, bool v) 
    { 
        lv_obj_set_flag(obj, f, v);
    }

    void lv_add_state(lv_state_t state) 
    { 
        lv_obj_add_state(obj, state);
    }

    void lv_remove_state(lv_state_t state) 
    { 
        lv_obj_remove_state(obj, state);
    }

    void lv_set_state(lv_state_t state, bool v) 
    { 
        lv_obj_set_state(obj, state, v);
    }

    void lv_set_user_data(void * user_data) 
    { 
        lv_obj_set_user_data(obj, user_data);
    }

    bool lv_has_flag(lv_obj_flag_t f) 
    { 
        return lv_obj_has_flag(obj, f);
    }

    bool lv_has_flag_any(lv_obj_flag_t f) 
    { 
        return lv_obj_has_flag_any(obj, f);
    }

    lv_state_t lv_get_state() 
    { 
        return lv_obj_get_state(obj);
    }

    bool lv_has_state(lv_state_t state) 
    { 
        return lv_obj_has_state(obj, state);
    }

    lv_group_t * lv_get_group() 
    { 
        return lv_obj_get_group(obj);
    }

    void * lv_get_user_data() 
    { 
        return lv_obj_get_user_data(obj);
    }

    void lv_allocate_spec_attr() 
    { 
        lv_obj_allocate_spec_attr(obj);
    }

    bool lv_check_type(const lv_obj_class_t * class_p) 
    { 
        return lv_obj_check_type(obj, class_p);
    }

    bool lv_has_class(const lv_obj_class_t * class_p) 
    { 
        return lv_obj_has_class(obj, class_p);
    }

    const lv_obj_class_t * lv_get_class() 
    { 
        return lv_obj_get_class(obj);
    }

    bool lv_is_valid() 
    { 
        return lv_obj_is_valid(obj);
    }

    void lv_null_on_delete(lv_obj_t * * obj_ptr) 
    { 
        lv_obj_null_on_delete(obj_ptr);
    }

    void lv_add_screen_load_event(lv_event_code_t trigger, lv_obj_t * screen, lv_screen_load_anim_t anim_type, uint32_t duration, uint32_t delay) 
    { 
        lv_obj_add_screen_load_event(obj, trigger, screen, anim_type, duration, delay);
    }

    void lv_add_screen_create_event(lv_event_code_t trigger, lv_screen_create_cb_t screen_create_cb, lv_screen_load_anim_t anim_type, uint32_t duration, uint32_t delay) 
    { 
        lv_obj_add_screen_create_event(obj, trigger, screen_create_cb, anim_type, duration, delay);
    }

    void lv_add_play_timeline_event(lv_event_code_t trigger, lv_anim_timeline_t * at, uint32_t delay, bool reverse) 
    { 
        lv_obj_add_play_timeline_event(obj, trigger, at, delay, reverse);
    }


    lv_obj_t* lv_get_obj() const { return this->obj; }


    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_OBJ_HPP */