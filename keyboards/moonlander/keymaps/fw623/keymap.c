#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "config.h"
#include "moonlander.h"

#define REGISTER_TAP(keycode) { register_code(keycode); unregister_code(keycode); }
#define REGISTER_TAP16(keycode) { register_code16(keycode); unregister_code16(keycode); }


static void repeat(keyrecord_t *record, int code, int times) {
  if (record->event.pressed) {
    for (int i = 0; i < times - 1; i++) { REGISTER_TAP(code); }
    register_code(code);
  } else {
    unregister_code(code);
  }
}

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_CIRC,
  ST_GRVE,
  ST_RPTU,
  ST_RPTD,
  ST_RPTL,
  ST_RPTR,
  ST_SFT,
  ST_SYMB,
};

enum layer {
  L_LOWER,
  L_FN,
  L_UPPER,
  L_SHCUT,
  L_NAV,
  L_SYMBOL,
  L_NUM,
  L_MOUSE,
  // L_GREEK_L,
  // L_GREEK_U,
  // L_MATH, // maybe latex instead of math
  L_QWERTZ,
  L_GAMING,
  L_CUBING,
  // L_KEYVAL,
};
#define MY_MAX_LAYER L_CUBING

#define TG_GAME TG(L_GAMING)
#define TG_QWTZ TG(L_QWERTZ)
#define TG_CUBE TG(L_CUBING)
#define TT_NAV  TT(L_NAV)
#define NUMCAPS LCTL_T(KC_ESC)
#define CTL_ESC LT(L_NUM, KC_CAPS)

// clang-format off
const uint16_t PROGMEM keymaps [][MATRIX_ROWS][MATRIX_COLS] = {
  [L_LOWER] = LAYOUT_moonlander(
    TG_GAME ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F11        ,KC_F12  ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,TG_QWTZ ,
    _______ ,KC_ENT  ,KC_DOT  ,KC_O    ,KC_U    ,DE_AE   ,_______       ,_______ ,KC_Q    ,KC_G    ,KC_C    ,KC_L    ,_______ ,TG_CUBE ,
    KC_TAB  ,KC_K    ,KC_A    ,KC_E    ,KC_I    ,DE_Y    ,DE_OE         ,_______ ,KC_B    ,KC_T    ,KC_R    ,KC_N    ,KC_F    ,KC_J    ,
    KC_BSPC ,KC_H    ,DE_Z    ,KC_X    ,KC_COMM ,DE_UE                           ,KC_P    ,KC_D    ,KC_W    ,KC_M    ,KC_S    ,KC_V    ,
    _______ ,KC_DEL  ,_______ ,NUMCAPS ,KC_SPC           ,KC_RSFT       ,_______          ,ST_SFT  ,TT_NAV  ,_______ ,DE_SS   ,_______ ,
                                        CTL_ESC ,KC_LALT ,KC_LGUI       ,_______ ,_______ ,ST_SYMB
  ),
  [L_FN] = LAYOUT_moonlander(
    _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F11        ,KC_F12  ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______                         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_UPPER] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,DE_QUOT ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,DE_DQOT ,_______                         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_SHCUT] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,DE_Z          ,_______ ,DE_Z    ,KC_U    ,KC_I    ,KC_O    ,_______ ,_______ ,
    _______ ,KC_Q    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_B          ,_______ ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_P    ,DE_UE   ,
    _______ ,KC_A    ,DE_Y    ,KC_X    ,KC_C    ,KC_V                            ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,DE_OE   ,DE_AE   ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,KC_MINS ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_SYMBOL] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,DE_COLN ,DE_EXLM ,ST_CIRC ,XXXXXXX ,_______       ,_______ ,XXXXXXX ,DE_EURO ,DE_HASH ,DE_MORE ,_______ ,_______ ,
    _______ ,ST_GRVE ,DE_EQL  ,DE_MINS ,DE_SLSH ,DE_ASTR ,XXXXXXX       ,_______ ,DE_AMPR ,DE_LCBR ,DE_LPRN ,DE_RPRN ,DE_PLUS ,DE_PIPE ,
    _______ ,DE_BSLS ,DE_SCLN ,DE_QST  ,DE_UNDS ,DE_AT                           ,DE_LESS ,DE_DLR  ,DE_LBRC ,DE_RBRC ,DE_RCBR ,DE_PERC ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,DE_TILD ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_NAV] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,KC_BTN3 ,KC_MS_U ,XXXXXXX ,XXXXXXX ,_______       ,_______ ,XXXXXXX ,ST_RPTL ,KC_UP   ,ST_RPTR ,_______ ,_______ ,
    _______ ,KC_BTN2 ,KC_MS_L ,KC_MS_D ,KC_MS_R ,XXXXXXX ,XXXXXXX       ,_______ ,KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
    _______ ,KC_BTN1 ,KC_WH_U ,KC_RSFT ,KC_WH_D ,XXXXXXX                         ,XXXXXXX ,ST_RPTU ,KC_BTN3 ,ST_RPTD ,KC_END  ,XXXXXXX ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,XXXXXXX ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_NUM] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,DE_DOT  ,XXXXXXX ,ST_CIRC ,XXXXXXX ,_______       ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
    _______ ,DE_MINS ,KC_4    ,KC_2    ,KC_0    ,KC_8    ,XXXXXXX       ,_______ ,KC_9    ,KC_1    ,KC_3    ,KC_5    ,DE_PLUS ,XXXXXXX ,
    _______ ,KC_6    ,DE_COLN ,DE_SLSH ,DE_COMM ,XXXXXXX                         ,XXXXXXX ,DE_ASTR ,DE_LPRN ,DE_RPRN ,KC_7    ,XXXXXXX ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,XXXXXXX ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_QWERTZ] = LAYOUT_moonlander(
    _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6          ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
    KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,DE_Z          ,_______ ,DE_Z    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,DE_UE   ,
    KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_B          ,_______ ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,DE_OE   ,DE_AE   ,
    KC_LSFT ,DE_LESS ,DE_Y    ,KC_X    ,KC_C    ,KC_V                            ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_MINS ,KC_RSFT ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                        _______ ,_______ ,_______       ,_______ ,_______ ,_______
  ),
  [L_CUBING] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______ ,_______                         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,_______ ,_______ ,_______          ,_______       ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                        _______ ,_______ ,KC_SPC        ,KC_SPC  ,_______ ,_______
  ),
  [L_GAMING] = LAYOUT_moonlander(
    _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6          ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
    KC_ESC  ,KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T          ,_______ ,DE_Z    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,DE_UE   ,
    KC_M    ,KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G          ,KC_B    ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,DE_OE   ,DE_AE   ,
    KC_PENT ,KC_LSFT ,DE_Y    ,KC_X    ,KC_C    ,KC_V                            ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_MINS ,KC_RSFT ,
    _______ ,KC_LCTL ,KC_B    ,KC_I    ,KC_SPC           ,_______       ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,
                                        KC_LALT ,KC_RCTL ,KC_LGUI       ,_______ ,_______ ,_______
  ),
  /*[L_KEYVAL] = LAYOUT_moonlander(
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,____       __ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
    _______ ,_______ ,KC_5    ,KC_3    ,KC_7    ,KC_8    ,____       __ ,_______ ,KC_8    ,KC_7    ,KC_3    ,KC_5    ,_______ ,_______ ,
    KC_4    ,KC_3    ,KC_0    ,KC_0    ,KC_0    ,KC_4    ,KC_9          ,KC_9    ,KC_4    ,KC_0    ,KC_0    ,KC_0    ,KC_3    ,KC_4    ,
    KC_4    ,KC_1    ,KC_4    ,KC_3    ,KC_2    ,KC_6                            ,KC_6    ,KC_2    ,KC_3    ,KC_4    ,KC_1    ,KC_4    ,
    _______ ,KC_5    ,_______ ,_______ ,KC_0             ,KC_8          ,KC_8             ,KC_0    ,_______ ,_______ ,KC_5    ,_______ ,
                                        KC_0    ,KC_4    ,KC_7          ,KC_7    ,KC_4    ,KC_0
  ),*/
};
// clang-format on

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


#define ooooooo {  0,  0,  0} // LED off
#define BLUE    {154,255,255}
#define YELLOW  { 35,255,255}
#define FLESH   {249,228,255}
#define CYAN    {105,255,255}
#define PINK    {205,255,255}
#define PINK_RGB 209,  0,255

// clang-format off
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [L_LOWER] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_UPPER] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_SHCUT] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_SYMBOL] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_NAV] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,PINK             ,ooooooo ,PINK    ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_NUM] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,PINK    ,ooooooo
  ),
  [L_QWERTZ] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,PINK    ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,BLUE    ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,CYAN    ,FLESH   ,YELLOW  ,BLUE    ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_GAMING] = LED_LAYOUT_moonlander(
    PINK    ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,BLUE    ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,YELLOW  ,FLESH   ,CYAN    ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
  [L_CUBING] = LED_LAYOUT_moonlander(
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,PINK    ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo                         ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
    ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo          ,ooooooo       ,ooooooo          ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,ooooooo ,
                                        ooooooo ,ooooooo ,ooooooo       ,ooooooo ,ooooooo ,ooooooo
  ),
};
// clang-format on

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
  if (!IS_LAYER_ON(L_GAMING) && host_keyboard_led_state().caps_lock) {
    rgb_matrix_set_color(19, PINK_RGB);
    rgb_matrix_set_color(35, PINK_RGB);
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }

  uint8_t layer = biton32(layer_state);
  if (L_LOWER <= layer && layer <= MY_MAX_LAYER) {
    set_layer_color(layer);
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) { rgb_matrix_set_color_all(0, 0, 0); }
  }
}

// Custom One Shot Modifier (or Layer)
typedef struct cosm_t {
  const uint16_t trigger;
  const int layer; // ignored iff < 0
  const uint16_t keycode; // ignored iff == KC_NO
  uint16_t released_at;
  bool active;
  bool pressed;
  bool interrupted;
} cosm_t;

#define NUM_COSM 2
static cosm_t cosm_shift = { ST_SFT, L_UPPER, KC_RSFT, 0, false, false, false };
static cosm_t cosm_symb = { ST_SYMB, L_SYMBOL, KC_NO, 0, false, false, false };
static cosm_t *cosms[NUM_COSM] = { &cosm_shift, &cosm_symb };

static uint16_t prev_keycode = KC_NO, curr_keycode = KC_NO;


static void reset_cosm (cosm_t *cosm) {
  if (cosm->keycode != KC_NO) { unregister_code(cosm->keycode); }
  if (cosm->layer >= 0) { layer_off(cosm->layer); }
  cosm->active = false;
}

static void set_cosm (cosm_t *cosm) {
  if (cosm->layer >= 0) { layer_on(cosm->layer); }
  if (cosm->keycode != KC_NO) { register_code(cosm->keycode); }
  cosm->interrupted = false;
  cosm->active = true;

  // reset others
  for (int i = 0; i < NUM_COSM; i++) {
    if (cosms[i] != cosm) { reset_cosm(cosms[i]); }
  }
}

static void timeout_cosm (cosm_t *cosm) {
  if (cosm->active && !cosm->pressed && timer_elapsed(cosm->released_at) > ONESHOT_TIMEOUT) {
    reset_cosm(cosm);
  }
}

static bool handle_cosm (cosm_t *cosm, uint16_t keycode, keyrecord_t *record) {
  if (cosm->active && record->event.pressed && keycode != cosm->trigger) {
    // handle interrupts
    if (!cosm->pressed && cosm->interrupted) { reset_cosm(cosm); }
    cosm->interrupted = true;
  } else if (keycode == cosm->trigger) {
    // handle this key
    cosm->pressed = record->event.pressed;
    if (record->event.pressed) {
      if (cosm->active && !cosm->interrupted) {
        reset_cosm(cosm);
      } else {
        set_cosm(cosm);
      }
    } else {
      cosm->released_at = timer_read();
      if (cosm->interrupted) { reset_cosm(cosm); }
    }
    return false;
  }

  return true;
}

void matrix_scan_user(void) {
  timeout_cosm(&cosm_shift);
  timeout_cosm(&cosm_symb);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  prev_keycode = curr_keycode;
  curr_keycode = keycode;

  if (!handle_cosm(&cosm_shift, keycode, record)) { return false; }
  if (!handle_cosm(&cosm_symb, keycode, record)) { return false; }

  switch (keycode) {
    case ST_CIRC:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_SPACE));
      }
      break;
    case ST_GRVE:
      if (record->event.pressed) {
        REGISTER_TAP16(DE_GRV);
        REGISTER_TAP(KC_SPC);
      }
      break;
    case ST_RPTU:
      repeat(record, KC_UP, 8);
      break;
    case ST_RPTD:
      repeat(record, KC_DOWN, 8);
      break;
    case ST_RPTL:
      repeat(record, KC_LEFT, 12);
      break;
    case ST_RPTR:
      repeat(record, KC_RIGHT, 12);
      break;
    case LCTL_T(KC_ESC):
    case KC_LALT:
    case KC_LGUI:
      if (record->event.pressed) {
        layer_on(L_SHCUT);
      } else {
        layer_off(L_SHCUT);
      }
      // we need to call this here to get layer LEDs activated (for whatever reason)
      return process_action_kb(record);
    case KC_RSFT:
      if (record->event.pressed) {
        layer_on(L_UPPER);
      } else {
        layer_off(L_UPPER);
      }
      // we need to call this here to get layer LEDs activated (for whatever reason)
      return process_action_kb(record);
    case TG(L_GAMING):
      if (!record->event.pressed && host_keyboard_led_state().caps_lock) {
        REGISTER_TAP(KC_CAPS);
      }
      return true;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
