#ifndef LV_LED_HPP
#define LV_LED_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/led/lv_led.h"
}

namespace lvgl {

class LvLed {
public:
    explicit LvLed() : obj(nullptr) {}

    explicit LvLed(lv_obj_t* parent) : obj(lv_led_create(parent)) {}

    void lv_set_color(lv_color_t color) 
    { 
        lv_led_set_color(obj, color);
    }

    void lv_set_brightness(uint8_t bright) 
    { 
        lv_led_set_brightness(obj, bright);
    }

    void lv_on() 
    { 
        lv_led_on(obj);
    }

    void lv_off() 
    { 
        lv_led_off(obj);
    }

    void lv_toggle() 
    { 
        lv_led_toggle(obj);
    }

    uint8_t lv_get_brightness() 
    { 
        return lv_led_get_brightness(obj);
    }

    lv_color_t lv_get_color() 
    { 
        return lv_led_get_color(obj);
    }

    lv_obj_t* lv_get_obj() const { return obj; }

    void lv_set_obj(lv_obj_t* targetObj) { this->obj = targetObj; }


private:
    lv_obj_t* obj;
};

} // namespace lvgl
#endif /* LV_LED_HPP */