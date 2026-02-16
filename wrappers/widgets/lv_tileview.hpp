#ifndef LV_TILEVIEW_HPP
#define LV_TILEVIEW_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/tileview/lv_tileview.h"
}

namespace lvgl {

class LvTileview {
public:
    explicit LvTileview(lv_obj_t* parent) : obj(lv_tileview_create(parent)) {}

    lv_obj_t * lv_add_tile(uint8_t col_id, uint8_t row_id, lv_dir_t dir) 
    { 
        return lv_tileview_add_tile(obj, col_id, row_id, dir);
    }

    void lv_set_tile(lv_obj_t * tile_obj, lv_anim_enable_t anim_en) 
    { 
        lv_tileview_set_tile(obj, tile_obj, anim_en);
    }

    void lv_set_tile_by_index(uint32_t col_id, uint32_t row_id, lv_anim_enable_t anim_en) 
    { 
        lv_tileview_set_tile_by_index(obj, col_id, row_id, anim_en);
    }

    lv_obj_t * lv_get_tile_active() 
    { 
        return lv_tileview_get_tile_active(obj);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_TILEVIEW_HPP */