#ifndef LV_GROUP_HPP
#define LV_GROUP_HPP

#pragma once

extern "C" {
#include "lvgl/src/core/lv_group.h"
}

namespace lvgl {

class LvGroup {
public:
    LvGroup() : obj(nullptr) {}

    lv_group_t * lv_create() 
    { 
        return lv_group_create();
    }

    void lv_delete(lv_group_t * group) 
    { 
        lv_group_delete(group);
    }

    void lv_set_default(lv_group_t * group) 
    { 
        lv_group_set_default(group);
    }

    lv_group_t * lv_get_default() 
    { 
        return lv_group_get_default();
    }

    void lv_add_obj(lv_group_t * group, lv_obj_t * obj) 
    { 
        lv_group_add_obj(group, obj);
    }

    void lv_swap_obj(lv_obj_t * obj2) 
    { 
        lv_group_swap_obj(obj, obj2);
    }

    void lv_remove_obj() 
    { 
        lv_group_remove_obj(obj);
    }

    void lv_remove_all_objs(lv_group_t * group) 
    { 
        lv_group_remove_all_objs(group);
    }

    void lv_focus_obj() 
    { 
        lv_group_focus_obj(obj);
    }

    void lv_focus_next(lv_group_t * group) 
    { 
        lv_group_focus_next(group);
    }

    void lv_focus_prev(lv_group_t * group) 
    { 
        lv_group_focus_prev(group);
    }

    void lv_focus_freeze(lv_group_t * group, bool en) 
    { 
        lv_group_focus_freeze(group, en);
    }

    lv_result_t lv_send_data(lv_group_t * group, uint32_t c) 
    { 
        return lv_group_send_data(group, c);
    }

    void lv_set_focus_cb(lv_group_t * group, lv_group_focus_cb_t focus_cb) 
    { 
        lv_group_set_focus_cb(group, focus_cb);
    }

    void lv_set_edge_cb(lv_group_t * group, lv_group_edge_cb_t edge_cb) 
    { 
        lv_group_set_edge_cb(group, edge_cb);
    }

    void lv_set_refocus_policy(lv_group_t * group, lv_group_refocus_policy_t policy) 
    { 
        lv_group_set_refocus_policy(group, policy);
    }

    void lv_set_editing(lv_group_t * group, bool edit) 
    { 
        lv_group_set_editing(group, edit);
    }

    void lv_set_wrap(lv_group_t * group, bool en) 
    { 
        lv_group_set_wrap(group, en);
    }

    lv_obj_t * lv_get_focused(const lv_group_t * group) 
    { 
        return lv_group_get_focused(group);
    }

    lv_group_focus_cb_t lv_get_focus_cb(const lv_group_t * group) 
    { 
        return lv_group_get_focus_cb(group);
    }

    lv_group_edge_cb_t lv_get_edge_cb(const lv_group_t * group) 
    { 
        return lv_group_get_edge_cb(group);
    }

    bool lv_get_editing(const lv_group_t * group) 
    { 
        return lv_group_get_editing(group);
    }

    bool lv_get_wrap(lv_group_t * group) 
    { 
        return lv_group_get_wrap(group);
    }

    uint32_t lv_get_obj_count(lv_group_t * group) 
    { 
        return lv_group_get_obj_count(group);
    }

    lv_obj_t * lv_get_obj_by_index(lv_group_t * group, uint32_t index) 
    { 
        return lv_group_get_obj_by_index(group, index);
    }

    uint32_t lv_get_count() 
    { 
        return lv_group_get_count();
    }

    lv_group_t * lv_by_index(uint32_t index) 
    { 
        return lv_group_by_index(index);
    }


    lv_obj_t* lv_get_obj() const { return this->obj; }


    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_GROUP_HPP */