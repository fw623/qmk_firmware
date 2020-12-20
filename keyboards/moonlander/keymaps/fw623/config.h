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

/* config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file */

#define ORYX_CONFIGURATOR

#define TAPPING_FORCE_HOLD
#undef IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TOGGLE 1
#define TAPPING_TERM 200 // default 200

#define MOUSEKEY_DELAY 50 // default 300
#define MOUSEKEY_INTERVAL 3 // default 50
#define MOUSEKEY_MAX_SPEED 10 // default 10
#define MOUSEKEY_TIME_TO_MAX 100 // default 20

#define MOUSEKEY_WHEEL_DELAY 100 // default 300
#define MOUSEKEY_WHEEL_INTERVAL 100 // default 100
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define RGB_MATRIX_STARTUP_SPD 60

#define ONESHOT_TIMEOUT 1000
