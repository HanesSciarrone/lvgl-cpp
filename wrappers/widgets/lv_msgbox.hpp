#ifndef LV_MSGBOX_HPP
#define LV_MSGBOX_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/msgbox/lv_msgbox.h"
}

namespace lvgl {

class LvMsgbox {
public:
    explicit LvMsgbox(lv_obj_t* parent) : obj(lv_msgbox_create(parent)) {}

    lv_obj_t * lv_add_title(const char * title) 
    { 
        return lv_msgbox_add_title(obj, title);
    }

    lv_obj_t * lv_add_header_button(const void * icon) 
    { 
        return lv_msgbox_add_header_button(obj, icon);
    }

    lv_obj_t * lv_add_text(const char * text) 
    { 
        return lv_msgbox_add_text(obj, text);
    }

    lv_obj_t * lv_add_footer_button(const char * text) 
    { 
        return lv_msgbox_add_footer_button(obj, text);
    }

    lv_obj_t * lv_add_close_button() 
    { 
        return lv_msgbox_add_close_button(obj);
    }

    lv_obj_t * lv_get_header() 
    { 
        return lv_msgbox_get_header(obj);
    }

    lv_obj_t * lv_get_footer() 
    { 
        return lv_msgbox_get_footer(obj);
    }

    lv_obj_t * lv_get_content() 
    { 
        return lv_msgbox_get_content(obj);
    }

    lv_obj_t * lv_get_title() 
    { 
        return lv_msgbox_get_title(obj);
    }

    void lv_close() 
    { 
        lv_msgbox_close(obj);
    }

    void lv_close_async() 
    { 
        lv_msgbox_close_async(obj);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_MSGBOX_HPP */