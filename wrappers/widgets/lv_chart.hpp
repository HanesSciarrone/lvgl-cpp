#ifndef LV_CHART_HPP
#define LV_CHART_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/chart/lv_chart.h"
}

namespace lvgl {

class LvChart {
public:
    explicit LvChart(lv_obj_t* parent) : obj(lv_chart_create(parent)) {}

    void lv_set_type(lv_chart_type_t type) 
    { 
        lv_chart_set_type(obj, type);
    }

    void lv_set_point_count(uint32_t cnt) 
    { 
        lv_chart_set_point_count(obj, cnt);
    }

    void lv_set_axis_range(lv_chart_axis_t axis, int32_t min, int32_t max) 
    { 
        lv_chart_set_axis_range(obj, axis, min, max);
    }

    void lv_set_axis_min_value(lv_chart_axis_t axis, int32_t min) 
    { 
        lv_chart_set_axis_min_value(obj, axis, min);
    }

    void lv_set_axis_max_value(lv_chart_axis_t axis, int32_t max) 
    { 
        lv_chart_set_axis_max_value(obj, axis, max);
    }

    void lv_set_update_mode(lv_chart_update_mode_t update_mode) 
    { 
        lv_chart_set_update_mode(obj, update_mode);
    }

    void lv_set_div_line_count(uint32_t hdiv, uint32_t vdiv) 
    { 
        lv_chart_set_div_line_count(obj, hdiv, vdiv);
    }

    void lv_set_hor_div_line_count(uint32_t cnt) 
    { 
        lv_chart_set_hor_div_line_count(obj, cnt);
    }

    void lv_set_ver_div_line_count(uint32_t cnt) 
    { 
        lv_chart_set_ver_div_line_count(obj, cnt);
    }

    lv_chart_type_t lv_get_type() 
    { 
        return lv_chart_get_type(obj);
    }

    uint32_t lv_get_point_count() 
    { 
        return lv_chart_get_point_count(obj);
    }

    uint32_t lv_get_x_start_point(lv_chart_series_t * ser) 
    { 
        return lv_chart_get_x_start_point(obj, ser);
    }

    void lv_get_point_pos_by_id(lv_chart_series_t * ser, uint32_t id, lv_point_t * p_out) 
    { 
        lv_chart_get_point_pos_by_id(obj, ser, id, p_out);
    }

    void lv_refresh() 
    { 
        lv_chart_refresh(obj);
    }

    lv_chart_series_t * lv_add_series(lv_color_t color, lv_chart_axis_t axis) 
    { 
        return lv_chart_add_series(obj, color, axis);
    }

    void lv_remove_series(lv_chart_series_t * series) 
    { 
        lv_chart_remove_series(obj, series);
    }

    void lv_hide_series(lv_chart_series_t * series, bool hide) 
    { 
        lv_chart_hide_series(obj, series, hide);
    }

    void lv_set_series_color(lv_chart_series_t * series, lv_color_t color) 
    { 
        lv_chart_set_series_color(obj, series, color);
    }

    lv_color_t lv_get_series_color(const lv_chart_series_t * series) 
    { 
        return lv_chart_get_series_color(obj, series);
    }

    void lv_set_x_start_point(lv_chart_series_t * ser, uint32_t id) 
    { 
        lv_chart_set_x_start_point(obj, ser, id);
    }

    lv_chart_series_t * lv_get_series_next(const lv_chart_series_t * ser) 
    { 
        return lv_chart_get_series_next(obj, ser);
    }

    lv_chart_cursor_t * lv_add_cursor(lv_color_t color, lv_dir_t dir) 
    { 
        return lv_chart_add_cursor(obj, color, dir);
    }

    void lv_remove_cursor(lv_chart_cursor_t * cursor) 
    { 
        lv_chart_remove_cursor(obj, cursor);
    }

    void lv_set_cursor_pos(lv_chart_cursor_t * cursor, lv_point_t * pos) 
    { 
        lv_chart_set_cursor_pos(obj, cursor, pos);
    }

    void lv_set_cursor_pos_x(lv_chart_cursor_t * cursor, int32_t x) 
    { 
        lv_chart_set_cursor_pos_x(obj, cursor, x);
    }

    void lv_set_cursor_pos_y(lv_chart_cursor_t * cursor, int32_t y) 
    { 
        lv_chart_set_cursor_pos_y(obj, cursor, y);
    }

    void lv_set_cursor_point(lv_chart_cursor_t * cursor, lv_chart_series_t * ser, uint32_t point_id) 
    { 
        lv_chart_set_cursor_point(obj, cursor, ser, point_id);
    }

    lv_point_t lv_get_cursor_point(lv_chart_cursor_t * cursor) 
    { 
        return lv_chart_get_cursor_point(obj, cursor);
    }

    void lv_set_all_values(lv_chart_series_t * ser, int32_t value) 
    { 
        lv_chart_set_all_values(obj, ser, value);
    }

    void lv_set_next_value(lv_chart_series_t * ser, int32_t value) 
    { 
        lv_chart_set_next_value(obj, ser, value);
    }

    void lv_set_next_value2(lv_chart_series_t * ser, int32_t x_value, int32_t y_value) 
    { 
        lv_chart_set_next_value2(obj, ser, x_value, y_value);
    }

    void lv_set_series_values(lv_chart_series_t * ser, const int32_t values[], size_t values_cnt) 
    { 
        lv_chart_set_series_values(obj, ser, values, values_cnt);
    }

    void lv_set_series_values2(lv_chart_series_t * ser, const int32_t x_values[], const int32_t y_values[], size_t values_cnt) 
    { 
        lv_chart_set_series_values2(obj, ser, x_values, y_values, values_cnt);
    }

    void lv_set_series_value_by_id(lv_chart_series_t * ser, uint32_t id, int32_t value) 
    { 
        lv_chart_set_series_value_by_id(obj, ser, id, value);
    }

    void lv_set_series_value_by_id2(lv_chart_series_t * ser, uint32_t id, int32_t x_value, int32_t y_value) 
    { 
        lv_chart_set_series_value_by_id2(obj, ser, id, x_value, y_value);
    }

    void lv_set_series_ext_y_array(lv_chart_series_t * ser, int32_t array[]) 
    { 
        lv_chart_set_series_ext_y_array(obj, ser, array);
    }

    void lv_set_series_ext_x_array(lv_chart_series_t * ser, int32_t array[]) 
    { 
        lv_chart_set_series_ext_x_array(obj, ser, array);
    }

    int32_t * lv_get_series_y_array(lv_chart_series_t * ser) 
    { 
        return lv_chart_get_series_y_array(obj, ser);
    }

    int32_t * lv_get_series_x_array(lv_chart_series_t * ser) 
    { 
        return lv_chart_get_series_x_array(obj, ser);
    }

    uint32_t lv_get_pressed_point() 
    { 
        return lv_chart_get_pressed_point(obj);
    }

    int32_t lv_get_first_point_center_offset() 
    { 
        return lv_chart_get_first_point_center_offset(obj);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_CHART_HPP */