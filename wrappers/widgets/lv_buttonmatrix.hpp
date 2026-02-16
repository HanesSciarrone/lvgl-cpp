#ifndef LV_BUTTONMATRIX_HPP
#define LV_BUTTONMATRIX_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/buttonmatrix/lv_buttonmatrix.h"
}

namespace lvgl {

class LvButtonmatrix {
public:
    explicit LvButtonmatrix() : obj(nullptr) {}

    explicit LvButtonmatrix(lv_obj_t* parent) : obj(lv_buttonmatrix_create(parent)) {}

    void lv_set_map(const char * const map[]) 
    { 
        lv_buttonmatrix_set_map(obj, map);
    }

    void lv_set_ctrl_map(const lv_buttonmatrix_ctrl_t ctrl_map[]) 
    { 
        lv_buttonmatrix_set_ctrl_map(obj, ctrl_map);
    }

    void lv_set_selected_button(uint32_t btn_id) 
    { 
        lv_buttonmatrix_set_selected_button(obj, btn_id);
    }

    void lv_set_button_ctrl(uint32_t btn_id, lv_buttonmatrix_ctrl_t ctrl) 
    { 
        lv_buttonmatrix_set_button_ctrl(obj, btn_id, ctrl);
    }

    void lv_clear_button_ctrl(uint32_t btn_id, lv_buttonmatrix_ctrl_t ctrl) 
    { 
        lv_buttonmatrix_clear_button_ctrl(obj, btn_id, ctrl);
    }

    void lv_set_button_ctrl_all(lv_buttonmatrix_ctrl_t ctrl) 
    { 
        lv_buttonmatrix_set_button_ctrl_all(obj, ctrl);
    }

    void lv_clear_button_ctrl_all(lv_buttonmatrix_ctrl_t ctrl) 
    { 
        lv_buttonmatrix_clear_button_ctrl_all(obj, ctrl);
    }

    void lv_set_button_width(uint32_t btn_id, uint32_t width) 
    { 
        lv_buttonmatrix_set_button_width(obj, btn_id, width);
    }

    void lv_set_one_checked(bool en) 
    { 
        lv_buttonmatrix_set_one_checked(obj, en);
    }

    const char * const * lv_get_map() 
    { 
        return lv_buttonmatrix_get_map(obj);
    }

    uint32_t lv_get_selected_button() 
    { 
        return lv_buttonmatrix_get_selected_button(obj);
    }

    const char * lv_get_button_text(uint32_t btn_id) 
    { 
        return lv_buttonmatrix_get_button_text(obj, btn_id);
    }

    bool lv_has_button_ctrl(uint32_t btn_id, lv_buttonmatrix_ctrl_t ctrl) 
    { 
        return lv_buttonmatrix_has_button_ctrl(obj, btn_id, ctrl);
    }

    bool lv_get_one_checked() 
    { 
        return lv_buttonmatrix_get_one_checked(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_BUTTONMATRIX_HPP */