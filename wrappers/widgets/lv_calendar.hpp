#ifndef LV_CALENDAR_HPP
#define LV_CALENDAR_HPP

#pragma once

#include <utility> // Required for std::forward if it is used

extern "C" {
#include "lvgl/src/widgets/calendar/lv_calendar.h"
}

namespace lvgl {

class LvCalendar {
public:
    explicit LvCalendar(lv_obj_t* parent) : obj(lv_calendar_create(parent)) {}

    void lv_set_today_date(uint32_t year, uint32_t month, uint32_t day) 
    { 
        lv_calendar_set_today_date(obj, year, month, day);
    }

    void lv_set_today_year(uint32_t year) 
    { 
        lv_calendar_set_today_year(obj, year);
    }

    void lv_set_today_month(uint32_t month) 
    { 
        lv_calendar_set_today_month(obj, month);
    }

    void lv_set_today_day(uint32_t day) 
    { 
        lv_calendar_set_today_day(obj, day);
    }

    void lv_set_month_shown(uint32_t year, uint32_t month) 
    { 
        lv_calendar_set_month_shown(obj, year, month);
    }

    void lv_set_shown_year(uint32_t year) 
    { 
        lv_calendar_set_shown_year(obj, year);
    }

    void lv_set_shown_month(uint32_t month) 
    { 
        lv_calendar_set_shown_month(obj, month);
    }

    void lv_set_highlighted_dates(lv_calendar_date_t highlighted[], size_t date_num) 
    { 
        lv_calendar_set_highlighted_dates(obj, highlighted, date_num);
    }

    void lv_set_day_names(const char * * day_names) 
    { 
        lv_calendar_set_day_names(obj, day_names);
    }

    lv_obj_t * lv_get_btnmatrix() 
    { 
        return lv_calendar_get_btnmatrix(obj);
    }

    const lv_calendar_date_t * lv_get_today_date() 
    { 
        return lv_calendar_get_today_date(obj);
    }

    const lv_calendar_date_t * lv_get_showed_date() 
    { 
        return lv_calendar_get_showed_date(obj);
    }

    lv_calendar_date_t * lv_get_highlighted_dates() 
    { 
        return lv_calendar_get_highlighted_dates(obj);
    }

    size_t lv_get_highlighted_dates_num() 
    { 
        return lv_calendar_get_highlighted_dates_num(obj);
    }

    lv_result_t lv_get_pressed_date(lv_calendar_date_t * date) 
    { 
        return lv_calendar_get_pressed_date(obj, date);
    }


    lv_obj_t* lv_get_obj() const { return obj; }

private:
    lv_obj_t* obj;
};

} // namespace lvglcpp
#endif /* LV_CALENDAR_HPP */