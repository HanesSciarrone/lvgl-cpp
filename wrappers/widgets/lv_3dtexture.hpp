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
    explicit Lv3dtexture(lv_obj_t* parent) : obj(parent) {}


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_3DTEXTURE_HPP */