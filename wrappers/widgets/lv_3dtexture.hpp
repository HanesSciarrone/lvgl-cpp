#ifndef LV_3DTEXTURE_HPP
#define LV_3DTEXTURE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/3dtexture/lv_3dtexture.h"
}

namespace lvgl {

class Lv3dtexture {
public:
    explicit Lv3dtexture() : obj(nullptr) {}

    explicit Lv3dtexture(lv_obj_t* parent) : obj(parent) {}

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_3DTEXTURE_HPP */