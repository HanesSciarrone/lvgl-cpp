#ifndef LV_IMAGEBUTTON_HPP
#define LV_IMAGEBUTTON_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/imagebutton/lv_imagebutton.h"
}

namespace lvgl {

class LvImagebutton {
public:
    explicit LvImagebutton() : obj(nullptr) {}

    explicit LvImagebutton(lv_obj_t* parent) : obj(lv_imagebutton_create(parent)) {}

    void lv_set_src(lv_imagebutton_state_t state, const void * src_left, const void * src_mid, const void * src_right) 
    { 
        lv_imagebutton_set_src(obj, state, src_left, src_mid, src_right);
    }

    void lv_set_src_left(lv_imagebutton_state_t state, const void * src_left) 
    { 
        lv_imagebutton_set_src_left(obj, state, src_left);
    }

    void lv_set_src_right(lv_imagebutton_state_t state, const void * src_right) 
    { 
        lv_imagebutton_set_src_right(obj, state, src_right);
    }

    void lv_set_src_mid(lv_imagebutton_state_t state, const void * src_mid) 
    { 
        lv_imagebutton_set_src_mid(obj, state, src_mid);
    }

    void lv_set_state(lv_imagebutton_state_t state) 
    { 
        lv_imagebutton_set_state(obj, state);
    }

    const void * lv_get_src_left(lv_imagebutton_state_t state) 
    { 
        return lv_imagebutton_get_src_left(obj, state);
    }

    const void * lv_get_src_middle(lv_imagebutton_state_t state) 
    { 
        return lv_imagebutton_get_src_middle(obj, state);
    }

    const void * lv_get_src_right(lv_imagebutton_state_t state) 
    { 
        return lv_imagebutton_get_src_right(obj, state);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_IMAGEBUTTON_HPP */