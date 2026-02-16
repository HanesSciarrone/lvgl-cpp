#ifndef LV_IME_PINYIN_HPP
#define LV_IME_PINYIN_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/ime/lv_ime_pinyin.h"
}

namespace lvgl {

class LvImePinyin {
public:
    explicit LvImePinyin(lv_obj_t* parent) : obj(parent) {}


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_IME_PINYIN_HPP */