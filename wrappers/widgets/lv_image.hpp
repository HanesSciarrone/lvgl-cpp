#ifndef LV_IMAGE_HPP
#define LV_IMAGE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/image/lv_image.h"
}

namespace lvgl {

class LvImage {
public:
    explicit LvImage() : obj(nullptr) {}

    explicit LvImage(lv_obj_t* parent) : obj(lv_image_create(parent)) {}

    void lv_set_src(const void * src) 
    { 
        lv_image_set_src(obj, src);
    }

    void lv_set_offset_x(int32_t x) 
    { 
        lv_image_set_offset_x(obj, x);
    }

    void lv_set_offset_y(int32_t y) 
    { 
        lv_image_set_offset_y(obj, y);
    }

    void lv_set_rotation(int32_t angle) 
    { 
        lv_image_set_rotation(obj, angle);
    }

    void lv_set_pivot(int32_t x, int32_t y) 
    { 
        lv_image_set_pivot(obj, x, y);
    }

    void lv_set_pivot_x(int32_t x) 
    { 
        lv_image_set_pivot_x(obj, x);
    }

    void lv_set_pivot_y(int32_t y) 
    { 
        lv_image_set_pivot_y(obj, y);
    }

    void lv_set_scale(uint32_t zoom) 
    { 
        lv_image_set_scale(obj, zoom);
    }

    void lv_set_scale_x(uint32_t zoom) 
    { 
        lv_image_set_scale_x(obj, zoom);
    }

    void lv_set_scale_y(uint32_t zoom) 
    { 
        lv_image_set_scale_y(obj, zoom);
    }

    void lv_set_blend_mode(lv_blend_mode_t blend_mode) 
    { 
        lv_image_set_blend_mode(obj, blend_mode);
    }

    void lv_set_antialias(bool antialias) 
    { 
        lv_image_set_antialias(obj, antialias);
    }

    void lv_set_inner_align(lv_image_align_t align) 
    { 
        lv_image_set_inner_align(obj, align);
    }

    void lv_set_bitmap_map_src(const lv_image_dsc_t * src) 
    { 
        lv_image_set_bitmap_map_src(obj, src);
    }

    const void * lv_get_src() 
    { 
        return lv_image_get_src(obj);
    }

    int32_t lv_get_offset_x() 
    { 
        return lv_image_get_offset_x(obj);
    }

    int32_t lv_get_offset_y() 
    { 
        return lv_image_get_offset_y(obj);
    }

    int32_t lv_get_rotation() 
    { 
        return lv_image_get_rotation(obj);
    }

    void lv_get_pivot(lv_point_t * pivot) 
    { 
        lv_image_get_pivot(obj, pivot);
    }

    int32_t lv_get_scale() 
    { 
        return lv_image_get_scale(obj);
    }

    int32_t lv_get_scale_x() 
    { 
        return lv_image_get_scale_x(obj);
    }

    int32_t lv_get_scale_y() 
    { 
        return lv_image_get_scale_y(obj);
    }

    int32_t lv_get_src_width() 
    { 
        return lv_image_get_src_width(obj);
    }

    int32_t lv_get_src_height() 
    { 
        return lv_image_get_src_height(obj);
    }

    int32_t lv_get_transformed_width() 
    { 
        return lv_image_get_transformed_width(obj);
    }

    int32_t lv_get_transformed_height() 
    { 
        return lv_image_get_transformed_height(obj);
    }

    lv_blend_mode_t lv_get_blend_mode() 
    { 
        return lv_image_get_blend_mode(obj);
    }

    bool lv_get_antialias() 
    { 
        return lv_image_get_antialias(obj);
    }

    lv_image_align_t lv_get_inner_align() 
    { 
        return lv_image_get_inner_align(obj);
    }

    const lv_image_dsc_t * lv_get_bitmap_map_src() 
    { 
        return lv_image_get_bitmap_map_src(obj);
    }

    lv_observer_t * lv_bind_src(lv_subject_t * subject) 
    { 
        return lv_image_bind_src(obj, subject);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_IMAGE_HPP */