/**
 * @file lv_slider.h
 * 
 */

#ifndef LV_SLIDER_H
#define LV_SLIDER_H

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#if USE_LV_SLIDER != 0

#include "../lv_obj/lv_obj.h"
#include "lv_bar.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
/*Data of slider*/
typedef struct
{
    lv_bar_ext_t bar; /*Ext. of ancestor*/
    /*New data for this type */
    lv_action_t cb;     /*Function to call when a new value is set*/
    int16_t tmp_value;  /*Store temporal value during press until release (Handled by the library)*/
}lv_slider_ext_t;

/*Style of slider*/
typedef struct
{
	lv_bars_t  bar;     /*Style of ancestor*/
	/*New style element for this type */
	lv_rects_t knob;    /*Style of the knob*/
}lv_sliders_t;

/*Built-in styles of slider*/
typedef enum
{
	LV_SLIDERS_DEF,
}lv_sliders_builtin_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a slider objects
 * @param par pointer to an object, it will be the parent of the new slider
 * @param copy pointer to a slider object, if not NULL then the new object will be copied from it
 * @return pointer to the created slider
 */
lv_obj_t * lv_slider_create(lv_obj_t * par, lv_obj_t * copy);

/**
 * Signal function of the slider
 * @param slider pointer to a slider object
 * @param sign a signal type from lv_signal_t enum
 * @param param pointer to a signal specific variable
 * @return true: the object is still valid (not deleted), false: the object become invalid
 */
bool lv_slider_signal(lv_obj_t * slider, lv_signal_t sign, void * param);

/**
 * Return with a pointer to a built-in style and/or copy it to a variable
 * @param style a style name from lv_sliders_builtin_t enum
 * @param copy copy the style to this variable. (NULL if unused)
 * @return pointer to an lv_sliders_t style
 */
lv_sliders_t * lv_sliders_get(lv_sliders_builtin_t style, lv_sliders_t * copy);

/**********************
 *      MACROS
 **********************/

#endif

#endif