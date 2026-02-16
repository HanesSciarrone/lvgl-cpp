#ifndef LV_OBSERVER_HPP
#define LV_OBSERVER_HPP

#pragma once

extern "C" {
#include "lvgl/src/core/lv_observer.h"
}

namespace lvgl {

class LvObserver {
public:
    LvObserver() : obj(nullptr) {}

    void lv_init_int(lv_subject_t * subject, int32_t value) 
    { 
        lv_subject_init_int(subject, value);
    }

    void lv_set_int(lv_subject_t * subject, int32_t value) 
    { 
        lv_subject_set_int(subject, value);
    }

    int32_t lv_get_int(lv_subject_t * subject) 
    { 
        return lv_subject_get_int(subject);
    }

    int32_t lv_get_previous_int(lv_subject_t * subject) 
    { 
        return lv_subject_get_previous_int(subject);
    }

    void lv_set_min_value_int(lv_subject_t * subject, int32_t min_value) 
    { 
        lv_subject_set_min_value_int(subject, min_value);
    }

    void lv_set_max_value_int(lv_subject_t * subject, int32_t max_value) 
    { 
        lv_subject_set_max_value_int(subject, max_value);
    }

    void lv_init_string(lv_subject_t * subject, char * buf, char * prev_buf, size_t size, const char * value) 
    { 
        lv_subject_init_string(subject, buf, prev_buf, size, value);
    }

    void lv_copy_string(lv_subject_t * subject, const char * buf) 
    { 
        lv_subject_copy_string(subject, buf);
    }

    template<typename... Args>
    void lv_snprintf(lv_subject_t * subject, const char * format, Args&&... args) 
    { 
        lv_subject_snprintf(subject, format, std::forward<Args>(args)...);
    }

    const char * lv_get_string(lv_subject_t * subject) 
    { 
        return lv_subject_get_string(subject);
    }

    const char * lv_get_previous_string(lv_subject_t * subject) 
    { 
        return lv_subject_get_previous_string(subject);
    }

    void lv_init_pointer(lv_subject_t * subject, void * value) 
    { 
        lv_subject_init_pointer(subject, value);
    }

    void lv_set_pointer(lv_subject_t * subject, void * ptr) 
    { 
        lv_subject_set_pointer(subject, ptr);
    }

    const void * lv_get_pointer(lv_subject_t * subject) 
    { 
        return lv_subject_get_pointer(subject);
    }

    const void * lv_get_previous_pointer(lv_subject_t * subject) 
    { 
        return lv_subject_get_previous_pointer(subject);
    }

    void lv_init_color(lv_subject_t * subject, lv_color_t color) 
    { 
        lv_subject_init_color(subject, color);
    }

    void lv_set_color(lv_subject_t * subject, lv_color_t color) 
    { 
        lv_subject_set_color(subject, color);
    }

    lv_color_t lv_get_color(lv_subject_t * subject) 
    { 
        return lv_subject_get_color(subject);
    }

    lv_color_t lv_get_previous_color(lv_subject_t * subject) 
    { 
        return lv_subject_get_previous_color(subject);
    }

    void lv_init_group(lv_subject_t * group_subject, lv_subject_t * list[], uint32_t list_len) 
    { 
        lv_subject_init_group(group_subject, list, list_len);
    }

    void lv_deinit(lv_subject_t * subject) 
    { 
        lv_subject_deinit(subject);
    }

    lv_subject_t * lv_get_group_element(lv_subject_t * subject, int32_t index) 
    { 
        return lv_subject_get_group_element(subject, index);
    }

    lv_observer_t * lv_add_observer(lv_subject_t * subject, lv_observer_cb_t observer_cb, void * user_data) 
    { 
        return lv_subject_add_observer(subject, observer_cb, user_data);
    }

    lv_observer_t * lv_add_observer_obj(lv_subject_t * subject, lv_observer_cb_t observer_cb, lv_obj_t * obj, void * user_data) 
    { 
        return lv_subject_add_observer_obj(subject, observer_cb, obj, user_data);
    }

    lv_observer_t * lv_add_observer_with_target(lv_subject_t * subject, lv_observer_cb_t observer_cb, void * target, void * user_data) 
    { 
        return lv_subject_add_observer_with_target(subject, observer_cb, target, user_data);
    }

    void lv_remove(lv_observer_t * observer) 
    { 
        lv_observer_remove(observer);
    }

    void lv_remove_from_subject(lv_subject_t * subject) 
    { 
        lv_obj_remove_from_subject(obj, subject);
    }

    void * lv_get_target(lv_observer_t * observer) 
    { 
        return lv_observer_get_target(observer);
    }

    lv_obj_t * lv_get_target_obj(lv_observer_t * observer) 
    { 
        return lv_observer_get_target_obj(observer);
    }

    void * lv_get_user_data(const lv_observer_t * observer) 
    { 
        return lv_observer_get_user_data(observer);
    }

    void lv_notify(lv_subject_t * subject) 
    { 
        lv_subject_notify(subject);
    }

    lv_subject_increment_dsc_t * lv_add_subject_increment_event(lv_subject_t * subject, lv_event_code_t trigger, int32_t step) 
    { 
        return lv_obj_add_subject_increment_event(obj, subject, trigger, step);
    }

    void lv_set_subject_increment_event_min_value(lv_subject_increment_dsc_t * dsc, int32_t min_value) 
    { 
        lv_obj_set_subject_increment_event_min_value(obj, dsc, min_value);
    }

    void lv_set_subject_increment_event_max_value(lv_subject_increment_dsc_t * dsc, int32_t max_value) 
    { 
        lv_obj_set_subject_increment_event_max_value(obj, dsc, max_value);
    }

    void lv_set_subject_increment_event_rollover(lv_subject_increment_dsc_t * dsc, bool rollover) 
    { 
        lv_obj_set_subject_increment_event_rollover(obj, dsc, rollover);
    }

    void lv_add_subject_toggle_event(lv_subject_t * subject, lv_event_code_t trigger) 
    { 
        lv_obj_add_subject_toggle_event(obj, subject, trigger);
    }

    void lv_add_subject_set_int_event(lv_subject_t * subject, lv_event_code_t trigger, int32_t value) 
    { 
        lv_obj_add_subject_set_int_event(obj, subject, trigger, value);
    }

    void lv_add_subject_set_string_event(lv_subject_t * subject, lv_event_code_t trigger, const char * value) 
    { 
        lv_obj_add_subject_set_string_event(obj, subject, trigger, value);
    }

    lv_observer_t * lv_bind_flag_if_eq(lv_subject_t * subject, lv_obj_flag_t flag, int32_t ref_value) 
    { 
        return lv_obj_bind_flag_if_eq(obj, subject, flag, ref_value);
    }

    lv_observer_t * lv_bind_flag_if_not_eq(lv_subject_t * subject, lv_obj_flag_t flag, int32_t ref_value) 
    { 
        return lv_obj_bind_flag_if_not_eq(obj, subject, flag, ref_value);
    }

    lv_observer_t * lv_bind_flag_if_gt(lv_subject_t * subject, lv_obj_flag_t flag, int32_t ref_value) 
    { 
        return lv_obj_bind_flag_if_gt(obj, subject, flag, ref_value);
    }

    lv_observer_t * lv_bind_flag_if_ge(lv_subject_t * subject, lv_obj_flag_t flag, int32_t ref_value) 
    { 
        return lv_obj_bind_flag_if_ge(obj, subject, flag, ref_value);
    }

    lv_observer_t * lv_bind_flag_if_lt(lv_subject_t * subject, lv_obj_flag_t flag, int32_t ref_value) 
    { 
        return lv_obj_bind_flag_if_lt(obj, subject, flag, ref_value);
    }

    lv_observer_t * lv_bind_flag_if_le(lv_subject_t * subject, lv_obj_flag_t flag, int32_t ref_value) 
    { 
        return lv_obj_bind_flag_if_le(obj, subject, flag, ref_value);
    }

    lv_observer_t * lv_bind_state_if_eq(lv_subject_t * subject, lv_state_t state, int32_t ref_value) 
    { 
        return lv_obj_bind_state_if_eq(obj, subject, state, ref_value);
    }

    lv_observer_t * lv_bind_state_if_not_eq(lv_subject_t * subject, lv_state_t state, int32_t ref_value) 
    { 
        return lv_obj_bind_state_if_not_eq(obj, subject, state, ref_value);
    }

    lv_observer_t * lv_bind_state_if_gt(lv_subject_t * subject, lv_state_t state, int32_t ref_value) 
    { 
        return lv_obj_bind_state_if_gt(obj, subject, state, ref_value);
    }

    lv_observer_t * lv_bind_state_if_ge(lv_subject_t * subject, lv_state_t state, int32_t ref_value) 
    { 
        return lv_obj_bind_state_if_ge(obj, subject, state, ref_value);
    }

    lv_observer_t * lv_bind_state_if_lt(lv_subject_t * subject, lv_state_t state, int32_t ref_value) 
    { 
        return lv_obj_bind_state_if_lt(obj, subject, state, ref_value);
    }

    lv_observer_t * lv_bind_state_if_le(lv_subject_t * subject, lv_state_t state, int32_t ref_value) 
    { 
        return lv_obj_bind_state_if_le(obj, subject, state, ref_value);
    }

    lv_observer_t * lv_bind_checked(lv_subject_t * subject) 
    { 
        return lv_obj_bind_checked(obj, subject);
    }


    lv_obj_t* lv_get_obj() const { return this->obj; }


    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_OBSERVER_HPP */