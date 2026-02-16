#ifndef LV_LINE_HPP
#define LV_LINE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/line/lv_line.h"
}

namespace lvgl {

class LvLine {
public:
    explicit LvLine() : obj(nullptr) {}

    explicit LvLine(lv_obj_t* parent) : obj(lv_line_create(parent)) {}

    void lv_set_points(const lv_point_precise_t points[], uint32_t point_num) 
    { 
        lv_line_set_points(obj, points, point_num);
    }

    void lv_set_points_mutable(lv_point_precise_t points[], uint32_t point_num) 
    { 
        lv_line_set_points_mutable(obj, points, point_num);
    }

    void lv_set_y_invert(bool en) 
    { 
        lv_line_set_y_invert(obj, en);
    }

    const lv_point_precise_t * lv_get_points() 
    { 
        return lv_line_get_points(obj);
    }

    uint32_t lv_get_point_count() 
    { 
        return lv_line_get_point_count(obj);
    }

    bool lv_is_point_array_mutable() 
    { 
        return lv_line_is_point_array_mutable(obj);
    }

    lv_point_precise_t * lv_get_points_mutable() 
    { 
        return lv_line_get_points_mutable(obj);
    }

    bool lv_get_y_invert() 
    { 
        return lv_line_get_y_invert(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_LINE_HPP */