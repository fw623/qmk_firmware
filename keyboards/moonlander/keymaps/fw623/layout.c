/* Copyright 2020 fw623 (https://github.com/fw623/)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "layout.h"

// clang-format off
const uint16_t PROGMEM keymaps [MY_MAX_LAYER + 1][MATRIX_ROWS][MATRIX_COLS] = {
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

const uint8_t PROGMEM ledmap[MY_MAX_LAYER + 1][DRIVER_LED_TOTAL][3] = {
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
