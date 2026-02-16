#ifndef LV_CANVAS_HPP
#define LV_CANVAS_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/canvas/lv_canvas.h"
}

namespace lvgl {

class LvCanvas {
public:
    explicit LvCanvas(lv_obj_t* parent) : obj(lv_canvas_create(parent)) {}

    void lv_set_buffer(void * buf, int32_t w, int32_t h, lv_color_format_t cf) 
    { 
        lv_canvas_set_buffer(obj, buf, w, h, cf);
    }

    void lv_set_draw_buf(lv_draw_buf_t * draw_buf) 
    { 
        lv_canvas_set_draw_buf(obj, draw_buf);
    }

    void lv_set_px(int32_t x, int32_t y, lv_color_t color, lv_opa_t opa) 
    { 
        lv_canvas_set_px(obj, x, y, color, opa);
    }

    void lv_set_palette(uint8_t index, lv_color32_t color) 
    { 
        lv_canvas_set_palette(obj, index, color);
    }

    lv_draw_buf_t * lv_get_draw_buf() 
    { 
        return lv_canvas_get_draw_buf(obj);
    }

    lv_color32_t lv_get_px(int32_t x, int32_t y) 
    { 
        return lv_canvas_get_px(obj, x, y);
    }

    lv_image_dsc_t * lv_get_image() 
    { 
        return lv_canvas_get_image(obj);
    }

    const void * lv_get_buf() 
    { 
        return lv_canvas_get_buf(obj);
    }

    void lv_copy_buf(const lv_area_t * canvas_area, lv_draw_buf_t * dest_buf, const lv_area_t * dest_area) 
    { 
        lv_canvas_copy_buf(obj, canvas_area, dest_buf, dest_area);
    }

    void lv_fill_bg(lv_color_t color, lv_opa_t opa) 
    { 
        lv_canvas_fill_bg(obj, color, opa);
    }

    void lv_init_layer(lv_layer_t * layer) 
    { 
        lv_canvas_init_layer(obj, layer);
    }

    void lv_finish_layer(lv_layer_t * layer) 
    { 
        lv_canvas_finish_layer(obj, layer);
    }

    uint32_t lv_buf_size(int32_t w, int32_t h, uint8_t bpp, uint8_t stride) 
    { 
        return lv_canvas_buf_size(w, h, bpp, stride);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_CANVAS_HPP */