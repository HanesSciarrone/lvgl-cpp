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
    explicit LvImePinyin() : obj(nullptr) {}

    explicit LvImePinyin(lv_obj_t* parent) : obj(parent) {}

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_IME_PINYIN_HPP */