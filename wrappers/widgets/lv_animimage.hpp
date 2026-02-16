#ifndef LV_ANIMIMAGE_HPP
#define LV_ANIMIMAGE_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/animimage/lv_animimage.h"
}

namespace lvgl {

class LvAnimimage {
public:
    explicit LvAnimimage(lv_obj_t* parent) : obj(lv_animimg_create(parent)) {}

    void lv_set_src(const void * dsc[], size_t num) 
    { 
        lv_animimg_set_src(obj, dsc, num);
    }

    void lv_set_src_reverse(const void * dsc[], size_t num) 
    { 
        lv_animimg_set_src_reverse(obj, dsc, num);
    }

    void lv_start() 
    { 
        lv_animimg_start(obj);
    }

    bool lv_delete() 
    { 
        return lv_animimg_delete(obj);
    }

    void lv_set_duration(uint32_t duration) 
    { 
        lv_animimg_set_duration(obj, duration);
    }

    void lv_set_repeat_count(uint32_t count) 
    { 
        lv_animimg_set_repeat_count(obj, count);
    }

    void lv_set_reverse_duration(uint32_t duration) 
    { 
        lv_animimg_set_reverse_duration(obj, duration);
    }

    void lv_set_reverse_delay(uint32_t duration) 
    { 
        lv_animimg_set_reverse_delay(obj, duration);
    }

    void lv_set_start_cb(lv_anim_start_cb_t start_cb) 
    { 
        lv_animimg_set_start_cb(obj, start_cb);
    }

    void lv_set_completed_cb(lv_anim_completed_cb_t completed_cb) 
    { 
        lv_animimg_set_completed_cb(obj, completed_cb);
    }

    const void * * lv_get_src() 
    { 
        return lv_animimg_get_src(obj);
    }

    uint8_t lv_get_src_count() 
    { 
        return lv_animimg_get_src_count(obj);
    }

    uint32_t lv_get_duration() 
    { 
        return lv_animimg_get_duration(obj);
    }

    uint32_t lv_get_repeat_count() 
    { 
        return lv_animimg_get_repeat_count(obj);
    }

    lv_anim_t * lv_get_anim() 
    { 
        return lv_animimg_get_anim(obj);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_ANIMIMAGE_HPP */