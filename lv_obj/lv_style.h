/**
 * @file lv_style.h
 *
 */

#ifndef LV_STYLE_H
#define LV_STYLE_H

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include "misc/others/color.h"
#include "../lv_misc/area.h"
#include "../lv_misc/font.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
    /*Object level styles*/
    color_t ccolor;     /*Content color (e.g. text or image re-color )*/
    opa_t opa;          /*Opacity of the object*/
    uint8_t opa_prop:1;   /*Opacity is proportional to the parent*/
    uint8_t empty :1;   /*Transparent background (border drawn)*/
    color_t mcolor;     /*Main color of background*/
    color_t gcolor;     /*Gradient color of background*/
    color_t bcolor;     /*Border color of background*/
    color_t lcolor;     /*Light color of background*/
    cord_t radius;      /*Corner radius of background*/
    cord_t bwidth;      /*Width of the background border*/
    cord_t lwidth;      /*Width of the background light effect*/
    cord_t vpad;        /*Vertical padding*/
    cord_t hpad;        /*Horizontal padding*/
    cord_t opad;        /*Object padding on the background*/
    opa_t bopa;         /*Opacity of background border*/
    const font_t * font;
    cord_t letter_space;
    cord_t line_space;
    uint8_t txt_align;
    opa_t img_recolor;
    cord_t line_width;

    struct {
        uint8_t _ccolor :1;      /*Content color (e.g. text or image re-color )*/
        uint8_t _opa :1;         /*Opacity of the object*/
        uint8_t _opa_prop:1;     /*Opacity is proportional to the parent*/
        uint8_t _mcolor :1;     /*Main color of background*/
        uint8_t _gcolor :1;     /*Gradient color of background*/
        uint8_t _bcolor :1;     /*Border color of background*/
        uint8_t _lcolor :1;     /*Light color of background*/
        uint8_t _radius :1;     /*Corner radius of background*/
        uint8_t _bwidth :1;     /*Width of the background border*/
        uint8_t _lwidth :1;     /*Width of the background light effect*/
        uint8_t _vpad :1;       /*Vertical padding*/
        uint8_t _hpad :1;       /*Horizontal padding*/
        uint8_t _opad :1;       /*Object padding on the background*/
        uint8_t _bopa :1;       /*Opacity of background border*/
        uint8_t _empty :1;      /*Transparent background (border drawn)*/
        uint8_t _font    :1;
        uint8_t _letter_space :1;
        uint8_t _line_space   :1;
        uint8_t _txt_align   :1;
        uint8_t _img_recolor   :1;
        uint8_t _line_width    :1;
    }set;

}lv_style_t;

typedef enum {
    LV_STYLE_DEF,
    LV_STYLE_WEAK,
    LV_STYLE_SCR,
    LV_STYLE_LIGHT,
    LV_STYLE_DARK,
    LV_STYLE_PAPER,
    LV_STYLE_BTN_REL,
    LV_STYLE_BTN_PR,
    LV_STYLE_BTN_TREL,
    LV_STYLE_BTN_TPR,
    LV_STYLE_BTN_INA,
}lv_style_name_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 *  Init the basic styles
 */
void lv_style_init (void);

/**
 * Get style from its name
 * @param style_name an element of the 'lv_style_name_t' enum
 * @return pointer to the requested style (lv_style_def by default)
 */
lv_style_t * lv_style_get(lv_style_name_t style_name);

/**
 * Inherit all not set attributes of child style from a parent style
 * @param result pointer to a 'lv_style_t' variable to store the result style
 * @param child pointer to a child style. (if NULL 'lv_style_def' will be used)
 * @param parent pointer to a parent style (if NULL 'lv_style_def' will be used)
 */
lv_style_t * lv_style_inherit(lv_style_t * result, const lv_style_t * child, const lv_style_t * parent );

/**
 * Set the content color of a style
 * @param style pointer to style
 * @param ccolor content color
 */
void lv_style_set_ccolor(lv_style_t * style, color_t ccolor);

/**
 * Clear the content color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_ccolor(lv_style_t * style);

/**
 * Set the opacity of a style
 * @param style pointer to style
 * @param opa opacity (OPA_COVER, OPA_TRANSP, OPA_10, OPA_20 ... OPA_90)
 */
void lv_style_set_opa(lv_style_t * style, opa_t opa);

/**
 * Clear the opacity of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_opa(lv_style_t * style);

/**
 * Set the proportional opacity attribute of a style (make the opacity relative to the parent)
 * @param style pointer to style
 * @param opa_prop true: enabled, false: disabled
 */
void lv_style_set_opa_prop(lv_style_t * style, bool opa_prop);

/**
 * Clear the proportional opacity attribute of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_opa_prop(lv_style_t * style);

/**
 * Set the container main color of a style
 * @param style pointer to style
 * @param mcolor main color of the background
 */
void lv_style_set_mcolor(lv_style_t * style, color_t mcolor);

/**
 * Clear the container main color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_mcolor(lv_style_t * style);

/**
 * Set the container gradient color of a style
 * @param style pointer to style
 * @param gcolor gradient color of the background
 */
void lv_style_set_gcolor(lv_style_t * style, color_t gcolor);

/**
 * Clear the container gradient color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_gcolor(lv_style_t * style);

/**
 * Set the container border color of a style
 * @param style pointer to style
 * @param bcolor border color of the background
 */
void lv_style_set_bcolor(lv_style_t * style, color_t bcolor);

/**
 * Clear the container border color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_bcolor(lv_style_t * style);

/**
 * Set the container light (shadow effect) color of a style
 * @param style pointer to style
 * @param lcolor light (shadow) color of the background
 */
void lv_style_set_lcolor(lv_style_t * style, color_t lcolor);

/**
 * Clear the container light color of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_lcolor(lv_style_t * style);

/**
 * Set the container corner radius of a style
 * @param style pointer to style
 * @param radius corner radius of the background (>= 0)
 */
void lv_style_set_radius(lv_style_t * style, cord_t radius);

/**
 * Clear the container radius of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_radius(lv_style_t * style);

/**
 * Set the container border width of a style
 * @param style pointer to style
 * @param bwidth border width of the background (>= 0, 0 means no border)
 */
void lv_style_set_bwidth(lv_style_t * style, cord_t bwidth);

/**
 * Clear the container border width of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_bwidth(lv_style_t * style);

/**
 * Set the container light (shadow) width of a style
 * @param style pointer to style
 * @param lwidth light (shadow) width of the background (>= 0, 0 means no shadow)
 */
void lv_style_set_lwidth(lv_style_t * style, cord_t lwidth);

/**
 * Clear the container light (shadow) width of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_lwidth(lv_style_t * style);

/**
 * Set the container vertical padding of a style
 * @param style pointer to style
 * @param vpad vertical padding on the background
 */
void lv_style_set_vpad(lv_style_t * style, cord_t vpad);

/**
 * Clear the container vertical padding of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_vpad(lv_style_t * style);

/**
 * Set the container horizontal padding of a style
 * @param style pointer to style
 * @param hpad horizontal padding on the background
 */
void lv_style_set_hpad(lv_style_t * style, cord_t hpad);

/**
 * Clear the container horizontal padding of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_hpad(lv_style_t * style);

/**
 * Set the container object padding of a style
 * @param style pointer to style
 * @param opad padding between objects on the background
 */
void lv_style_set_opad(lv_style_t * style, cord_t opad);

/**
 * Clear the container object padding of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_opad(lv_style_t * style);

/**
 * Set the container border opacity of a style (relative to the object opacity)
 * @param style pointer to style
 * @param bopa border opacity of the background  (OPA_COVER, OPA_TRANSP, OPA_10, OPA_20 ... OPA_90)
 */
void lv_style_set_bopa(lv_style_t * style, opa_t bopa);

/**
 * Clear the container border opacity of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_bopa(lv_style_t * style);

/**
 * Set container empty attribute of a style (transparent background but border drawn)
 * @param style pointer to style
 * @param empty true: empty enable, false: empty disable
 */
void lv_style_set_empty(lv_style_t * style, bool empty);

/**
 * Clear the container empty attribute of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_empty(lv_style_t * style);

/**
 * Set the font of a style
 * @param style pointer to style
 * @param font pointer to a font
 */
void lv_style_set_font(lv_style_t * style, const font_t * font);

/**
 * Clear the font of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_font(lv_style_t * style);

/**
 * Set the letter space of a style
 * @param style pointer to style
 * @param letter_space new letter space
 */
void lv_style_set_letter_space(lv_style_t * style, cord_t letter_space);

/**
 * Clear the letter space of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_letter_space(lv_style_t * style);

/**
 * Set the line space of a style
 * @param style pointer to style
 * @param line_space new letter space
 */
void lv_style_set_line_space(lv_style_t * style, cord_t line_space);

/**
 * Clear the line space of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_line_space(lv_style_t * style);

/**
 * Set the text align of a style
 * @param style pointer to style
 * @param align TODO
 */
void lv_style_set_txt_align(lv_style_t * style, uint8_t align);

/**
 * Clear the text align of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_txt_align(lv_style_t * style);

/**
 * Set the image re-color intensity of a style
 * @param style pointer to style
 * @param recolor re-coloring intensity (OPA_TRANSP: do nothing, OPA_COVER: fully re-color, OPA_10: little re-color)
 */
void lv_style_set_img_recolor(lv_style_t * style, opa_t recolor);

/**
 * Clear the image recolor of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_img_recolor(lv_style_t * style);

/**
 * Set the line width of a style
 * @param style pointer to style
 * @param width new line width (>=0)
 */
void lv_style_set_line_width(lv_style_t * style, cord_t width);

/**
 * Clear the line width of a style (it will be inherited from the parent style)
 * @param style pointer to a style
 */
void lv_style_clear_line_width(lv_style_t * style);

/**********************
 *      MACROS
 **********************/

#endif
