#ifndef LV_GIF_HPP
#define LV_GIF_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/gif/lv_gif.h"
}

namespace lvgl {

class LvGif {
public:
    explicit LvGif() : obj(nullptr) {}

    explicit LvGif(lv_obj_t* parent) : obj(parent) {}

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_GIF_HPP */