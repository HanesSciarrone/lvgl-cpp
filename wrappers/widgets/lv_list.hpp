#ifndef LV_LIST_HPP
#define LV_LIST_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/list/lv_list.h"
}

namespace lvgl {

class LvList {
public:
    explicit LvList() : obj(nullptr) {}

    explicit LvList(lv_obj_t* parent) : obj(lv_list_create(parent)) {}

    lv_obj_t * lv_add_text(const char * txt) 
    { 
        return lv_list_add_text(obj, txt);
    }

    lv_obj_t * lv_add_button(const void * icon, const char * txt) 
    { 
        return lv_list_add_button(obj, icon, txt);
    }

    const char * lv_get_button_text(lv_obj_t * btn) 
    { 
        return lv_list_get_button_text(obj, btn);
    }

    void lv_set_button_text(lv_obj_t * btn, const char * txt) 
    { 
        lv_list_set_button_text(obj, btn, txt);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_LIST_HPP */