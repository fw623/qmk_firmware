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

/* transformation for LED_LAYOUT_moonlander macro (ugly, but works) */

const layoutMoonlander = [
  ['k00', 'k01', 'k02', 'k03', 'k04', 'k05', 'k06',   'k60', 'k61', 'k62', 'k63', 'k64', 'k65', 'k66'],
  ['k10', 'k11', 'k12', 'k13', 'k14', 'k15', 'k16',   'k70', 'k71', 'k72', 'k73', 'k74', 'k75', 'k76'],
  ['k20', 'k21', 'k22', 'k23', 'k24', 'k25', 'k26',   'k80', 'k81', 'k82', 'k83', 'k84', 'k85', 'k86'],
  ['k30', 'k31', 'k32', 'k33', 'k34', 'k35',  null,    null, 'k91', 'k92', 'k93', 'k94', 'k95', 'k96'],
  ['k40', 'k41', 'k42', 'k43', 'k44',  null, 'k53',   'kb3',  null, 'ka2', 'ka3', 'ka4', 'ka5', 'ka6'],
  [ null,  null,  null,  null, 'k50', 'k51', 'k52',   'kb4', 'kb5', 'kb6',  null,  null,  null,  null],
]

const macro = []
// left half
for (let c = 0; c < layoutMoonlander[0].length/2; c++) {
  for (let r = 0; r < layoutMoonlander.length - 1; r++) {
    if (![null, 'k53', 'kb3'].includes(layoutMoonlander[r][c])) { macro.push(layoutMoonlander[r][c]) }
  }
}
macro.push('k50', 'k51', 'k52', 'k53') // thumb cluster

// right half
for (let c = layoutMoonlander[0].length - 1; c >= layoutMoonlander[0].length / 2; c--) {
  for (let r = 0; r < layoutMoonlander.length - 1; r++) {
    if (![null, 'k53', 'kb3'].includes(layoutMoonlander[r][c])) { macro.push(layoutMoonlander[r][c]) }
  }
}
macro.push('kb6', 'kb5', 'kb4', 'kb3') // thumb cluster

console.log('{ ' + macro.join(', ') + ' }')
