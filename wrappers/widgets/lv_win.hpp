#ifndef LV_WIN_HPP
#define LV_WIN_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/win/lv_win.h"
}

namespace lvgl {

class LvWin {
public:
    explicit LvWin() : obj(nullptr) {}

    explicit LvWin(lv_obj_t* parent) : obj(lv_win_create(parent)) {}

    lv_obj_t * lv_add_title(const char * txt) 
    { 
        return lv_win_add_title(obj, txt);
    }

    lv_obj_t * lv_add_button(const void * icon, int32_t btn_w) 
    { 
        return lv_win_add_button(obj, icon, btn_w);
    }

    lv_obj_t * lv_get_header() 
    { 
        return lv_win_get_header(obj);
    }

    lv_obj_t * lv_get_content() 
    { 
        return lv_win_get_content(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_WIN_HPP */