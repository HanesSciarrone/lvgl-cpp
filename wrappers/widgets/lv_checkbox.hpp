#ifndef LV_CHECKBOX_HPP
#define LV_CHECKBOX_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/checkbox/lv_checkbox.h"
}

namespace lvgl {

class LvCheckbox {
public:
    explicit LvCheckbox() : obj(nullptr) {}

    explicit LvCheckbox(lv_obj_t* parent) : obj(lv_checkbox_create(parent)) {}

    void lv_set_text(const char * txt) 
    { 
        lv_checkbox_set_text(obj, txt);
    }

    void lv_set_text_static(const char * txt) 
    { 
        lv_checkbox_set_text_static(obj, txt);
    }

    const char * lv_get_text() 
    { 
        return lv_checkbox_get_text(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_CHECKBOX_HPP */