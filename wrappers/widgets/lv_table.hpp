#ifndef LV_TABLE_HPP
#define LV_TABLE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/table/lv_table.h"
}

namespace lvgl {

class LvTable {
public:
    explicit LvTable(lv_obj_t* parent) : obj(lv_table_create(parent)) {}

    void lv_set_cell_value(uint32_t row, uint32_t col, const char * txt) 
    { 
        lv_table_set_cell_value(obj, row, col, txt);
    }

    template<typename... Args>
    void lv_set_cell_value_fmt(uint32_t row, uint32_t col, const char * fmt, Args&&... args) 
    { 
        lv_table_set_cell_value_fmt(obj, row, col, fmt, std::forward<Args>(args)...);
    }

    void lv_set_row_count(uint32_t row_cnt) 
    { 
        lv_table_set_row_count(obj, row_cnt);
    }

    void lv_set_column_count(uint32_t col_cnt) 
    { 
        lv_table_set_column_count(obj, col_cnt);
    }

    void lv_set_column_width(uint32_t col_id, int32_t w) 
    { 
        lv_table_set_column_width(obj, col_id, w);
    }

    void lv_set_cell_ctrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl) 
    { 
        lv_table_set_cell_ctrl(obj, row, col, ctrl);
    }

    void lv_clear_cell_ctrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl) 
    { 
        lv_table_clear_cell_ctrl(obj, row, col, ctrl);
    }

    void lv_set_cell_user_data(uint16_t row, uint16_t col, void * user_data) 
    { 
        lv_table_set_cell_user_data(obj, row, col, user_data);
    }

    void lv_set_selected_cell(uint16_t row, uint16_t col) 
    { 
        lv_table_set_selected_cell(obj, row, col);
    }

    const char * lv_get_cell_value(uint32_t row, uint32_t col) 
    { 
        return lv_table_get_cell_value(obj, row, col);
    }

    uint32_t lv_get_row_count() 
    { 
        return lv_table_get_row_count(obj);
    }

    uint32_t lv_get_column_count() 
    { 
        return lv_table_get_column_count(obj);
    }

    int32_t lv_get_column_width(uint32_t col) 
    { 
        return lv_table_get_column_width(obj, col);
    }

    bool lv_has_cell_ctrl(uint32_t row, uint32_t col, lv_table_cell_ctrl_t ctrl) 
    { 
        return lv_table_has_cell_ctrl(obj, row, col, ctrl);
    }

    void lv_get_selected_cell(uint32_t * row, uint32_t * col) 
    { 
        lv_table_get_selected_cell(obj, row, col);
    }

    void * lv_get_cell_user_data(uint16_t row, uint16_t col) 
    { 
        return lv_table_get_cell_user_data(obj, row, col);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_TABLE_HPP */