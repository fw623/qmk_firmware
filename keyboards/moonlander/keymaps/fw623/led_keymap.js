// very ugly code to get LED_LAYOUT_moonlander macro

const a = [
  ['k00', 'k01', 'k02', 'k03', 'k04', 'k05', 'k06',   'k60', 'k61', 'k62', 'k63', 'k64', 'k65', 'k66'],
  ['k10', 'k11', 'k12', 'k13', 'k14', 'k15', 'k16',   'k70', 'k71', 'k72', 'k73', 'k74', 'k75', 'k76'],
  ['k20', 'k21', 'k22', 'k23', 'k24', 'k25', 'k26',   'k80', 'k81', 'k82', 'k83', 'k84', 'k85', 'k86'],
  ['k30', 'k31', 'k32', 'k33', 'k34', 'k35',  null,    null, 'k91', 'k92', 'k93', 'k94', 'k95', 'k96'],
  ['k40', 'k41', 'k42', 'k43', 'k44',  null, 'k53',   'kb3',  null, 'ka2', 'ka3', 'ka4', 'ka5', 'ka6'],
  [ null,  null,  null,  null, 'k50', 'k51', 'k52',   'kb4', 'kb5', 'kb6',  null,  null,  null,  null],
]

let form = '{ '
for (let c = 0; c < a[0].length/2; c++) {
  for (let r = 0; r < a.length - 1; r++) {
    if (![null, 'k53', 'kb3'].includes(a[r][c])) { form += a[r][c] + ', ' }
  }
}

form += [
  'k50',
  'k51',
  'k52',
  'k53',
].join(', ') + ', '

for (let c = a[0].length - 1; c >= a[0].length / 2; c--) {
  for (let r = 0; r < a.length - 1; r++) {
    if (![null, 'k53', 'kb3'].includes(a[r][c])) { form += a[r][c] + ', ' }
  }
}

form += [
  'kb6',
  'kb5',
  'kb4',
  'kb3',
].join(', ')

form += ' }'
console.log(form)
