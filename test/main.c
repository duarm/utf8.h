// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org/>

#include "utf8.h"

const char data[] = {
  '\xce',
  '\x93',
  '\xce',
  '\xb1',
  '\xce',
  '\xb6',
  '\xce',
  '\xad',
  '\xce',
  '\xb5',
  '\xcf',
  '\x82',
  '\x20',
  '\xce',
  '\xba',
  '\xce',
  '\xb1',
  '\xe1',
  '\xbd',
  '\xb6',
  '\x20',
  '\xce',
  '\xbc',
  '\xcf',
  '\x85',
  '\xcf',
  '\x81',
  '\xcf',
  '\x84',
  '\xce',
  '\xb9',
  '\xe1',
  '\xbd',
  '\xb2',
  '\xcf',
  '\x82',
  '\x20',
  '\xce',
  '\xb4',
  '\xe1',
  '\xbd',
  '\xb2',
  '\xce',
  '\xbd',
  '\x20',
  '\xce',
  '\xb8',
  '\xe1',
  '\xbd',
  '\xb0',
  '\x20',
  '\xce',
  '\xb2',
  '\xcf',
  '\x81',
  '\xe1',
  '\xbf',
  '\xb6',
  '\x20',
  '\xcf',
  '\x80',
  '\xce',
  '\xb9',
  '\xe1',
  '\xbd',
  '\xb0',
  '\x20',
  '\xcf',
  '\x83',
  '\xcf',
  '\x84',
  '\xe1',
  '\xbd',
  '\xb8',
  '\x20',
  '\xcf',
  '\x87',
  '\xcf',
  '\x81',
  '\xcf',
  '\x85',
  '\xcf',
  '\x83',
  '\xce',
  '\xb1',
  '\xcf',
  '\x86',
  '\xe1',
  '\xbd',
  '\xb6',
  '\x20',
  '\xce',
  '\xbe',
  '\xce',
  '\xad',
  '\xcf',
  '\x86',
  '\xcf',
  '\x89',
  '\xcf',
  '\x84',
  '\xce',
  '\xbf',
  '\x0a',
  '\0'
};

int main(const int argc, const char* const argv[]) {
  if(53 != utf8len(data)) {
    return 1;
  }

  char cat[512] = {'\0'};
  if (53 != utf8len(utf8cat(cat, data))) {
    return 2;
  }

  cat[0] = 'a';
  cat[1] = '\0';

  if (54 != utf8len(utf8cat(cat, data))) {
    return 3;
  }

  cat[0] = '\xce';
  cat[1] = '\x93';
  cat[2] = '\0';

  if (54 != utf8len(utf8cat(cat, data))) {
    return 4;
  }

  cat[0] = '\xe1';
  cat[1] = '\xbd';
  cat[2] = '\xb6';
  cat[3] = '\0';

  if (54 != utf8len(utf8cat(cat, data))) {
    return 5;
  }

  cat[0] = '\xf0';
  cat[1] = '\x90';
  cat[2] = '\x8d';
  cat[3] = '\x88';
  cat[4] = '\0';

  if (54 != utf8len(utf8cat(cat, data))) {
    return 6;
  }

  cat[0] = '\0';

  if (106 != utf8len(utf8cat(utf8cat(cat, data), data))) {
    return 7;
  }

  const char cmp[] = { '\xce', '\xbc', '\xcf', '\x85', '\0' };

  if (data + 21 != utf8str(data, cmp)) {
    return 8;
  }

  if (0 != utf8str(data, "test")) {
    return 9;
  }

  if (data != utf8str(data, "")) {
    return 10;
  }

  if (data + 21 != utf8chr(data, 0x3bc)) {
    return 11;
  }

  if (0 != utf8chr(data, 0x20ac)) {
    return 12;
  }

  if (data + 104 != utf8chr(data, '\0')) {
    return 13;
  }

  const char lt[] = {
    '\xce',
    '\x93',
    '\xce',
    '\xb1',
    '\xce',
    '\xb6',
    '\xce',
    '\xac',
    '\0'};

  if (0 >= utf8cmp(data, lt)) {
    return 14;
  }

  if (0 != utf8cmp(data, data)) {
    return 15;
  }

  const char gt[] = {
    '\xce',
    '\x93',
    '\xce',
    '\xb1',
    '\xce',
    '\xb6',
    '\xce',
    '\xae',
    '\0'};

  if (0 <= utf8cmp(data, gt)) {
    return 16;
  }

  char cpy[512];

  if (53 != utf8len(utf8cpy(cpy, data))) {
    return 17;
  }

  const char spn[] = {
    '\xce',
    '\x93',
    '\xce',
    '\xb1',
    '\xce',
    '\xb6',
    '\xce',
    '\xad',
    '\xce',
    '\xb5',
    '\xcf',
    '\x82',
    '\x20',
    '\xce',
    '\xba',
    '\0'};

  if (7 != utf8spn(data, spn)) {
    return 18;
  }

  if (52 != utf8spn(data, data)) {
    return 19;
  }

  if (0 != utf8spn(data, "ab")) {
    return 20;
  }

  if (0 != utf8cspn(data, spn)) {
    return 21;
  }

  if (0 != utf8cspn(data, data)) {
    return 22;
  }

  if (53 != utf8cspn(data, "ab")) {
    return 23;
  }

  return 0;
}