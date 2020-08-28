/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Himanshi Mathur <himanshi18037@iiitd.ac.in>
 */

#define SIMDE_TEST_X86_AVX512_INSN cmpeq

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/cmpeq.h>

static int
test_simde_mm512_cmpeq_epi8_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i   a;
    simde__m512i   b;
    simde__mmask64 r;
  } test_vec[8] = {
    { simde_mm512_set_epi8(INT8_C(  73), INT8_C(  68), INT8_C( -71), INT8_C( -32),
                           INT8_C( 100), INT8_C( 125), INT8_C(  89), INT8_C(  95),
                           INT8_C( -23), INT8_C(  76), INT8_C(  84), INT8_C( -43),
                           INT8_C(  86), INT8_C(  29), INT8_C(  64), INT8_C(  30),
                           INT8_C( -17), INT8_C( -61), INT8_C( 115), INT8_C( -53),
                           INT8_C(-100), INT8_C( 104), INT8_C( 111), INT8_C( -59),
                           INT8_C( -31), INT8_C(  20), INT8_C(  31), INT8_C(-121),
                           INT8_C(  90), INT8_C(  18), INT8_C(   6), INT8_C(  39),
                           INT8_C(  15), INT8_C(  62), INT8_C(  39), INT8_C( -25),
                           INT8_C(  60), INT8_C( 110), INT8_C(  45), INT8_C( 113),
                           INT8_C(  81), INT8_C(  78), INT8_C( -53), INT8_C(  11),
                           INT8_C( -27), INT8_C(-113), INT8_C(  -3), INT8_C(  14),
                           INT8_C( 109), INT8_C(  43), INT8_C( -54), INT8_C( 111),
                           INT8_C( -91), INT8_C( -21), INT8_C( 102), INT8_C(   8),
                           INT8_C( -41), INT8_C( -47), INT8_C( -90), INT8_C(   3),
                           INT8_C(  18), INT8_C(  32), INT8_C(  89), INT8_C( -62)),
      simde_mm512_set_epi8(INT8_C(  73), INT8_C(  68), INT8_C( -71), INT8_C( -46),
                           INT8_C(  72), INT8_C(  42), INT8_C(  65), INT8_C( -27),
                           INT8_C( -37), INT8_C(  76), INT8_C(  84), INT8_C( -95),
                           INT8_C( -29), INT8_C(  29), INT8_C(  64), INT8_C(  75),
                           INT8_C( -17), INT8_C( -61), INT8_C(  76), INT8_C(  88),
                           INT8_C(-100), INT8_C( -91), INT8_C( 111), INT8_C( -59),
                           INT8_C( -31), INT8_C( -17), INT8_C(  31), INT8_C(  68),
                           INT8_C(  90), INT8_C(  18), INT8_C(-110), INT8_C(  39),
                           INT8_C(  15), INT8_C(  62), INT8_C(  24), INT8_C( -25),
                           INT8_C(  80), INT8_C( 122), INT8_C( 103), INT8_C(-115),
                           INT8_C(  81), INT8_C(  24), INT8_C(  32), INT8_C(  82),
                           INT8_C( -27), INT8_C( 105), INT8_C(  -3), INT8_C(  14),
                           INT8_C( 109), INT8_C(  43), INT8_C( -54), INT8_C(-121),
                           INT8_C( -91), INT8_C(-124), INT8_C( 102), INT8_C(  46),
                           INT8_C( -41), INT8_C( 101), INT8_C(  51), INT8_C(   3),
                           INT8_C(  18), INT8_C(  32), INT8_C( -12), INT8_C( -62)),
      UINT64_C(0xe066cbadd08bea9d) },
    { simde_mm512_set_epi8(INT8_C( -84), INT8_C(-108), INT8_C(  13), INT8_C( -97),
                           INT8_C( -34), INT8_C(  27), INT8_C( 124), INT8_C(-120),
                           INT8_C(   3), INT8_C(  26), INT8_C(  43), INT8_C( -96),
                           INT8_C( -63), INT8_C(  49), INT8_C( 127), INT8_C(   0),
                           INT8_C( -20), INT8_C( -31), INT8_C( 125), INT8_C(  14),
                           INT8_C( -53), INT8_C( -87), INT8_C( 115), INT8_C( -20),
                           INT8_C( -93), INT8_C(  70), INT8_C(  29), INT8_C( -90),
                           INT8_C( 105), INT8_C( -54), INT8_C(  96), INT8_C(-106),
                           INT8_C(  94), INT8_C( -52), INT8_C( -50), INT8_C( -79),
                           INT8_C( -54), INT8_C(  78), INT8_C(  17), INT8_C(  81),
                           INT8_C(  35), INT8_C( 120), INT8_C(  47), INT8_C( -25),
                           INT8_C( 110), INT8_C(  55), INT8_C(  40), INT8_C( -31),
                           INT8_C(  93), INT8_C( -23), INT8_C(   4), INT8_C(  45),
                           INT8_C(  59), INT8_C( -33), INT8_C( 124), INT8_C( -52),
                           INT8_C(  42), INT8_C( -14), INT8_C(-119), INT8_C(  88),
                           INT8_C( -38), INT8_C( -31), INT8_C(-113), INT8_C(  33)),
      simde_mm512_set_epi8(INT8_C(  25), INT8_C(-108), INT8_C(  13), INT8_C( -97),
                           INT8_C( -34), INT8_C( 119), INT8_C( 122), INT8_C(  82),
                           INT8_C(   3), INT8_C(-111), INT8_C(  60), INT8_C( -96),
                           INT8_C(  26), INT8_C(   3), INT8_C(  -7), INT8_C(  -8),
                           INT8_C(  94), INT8_C( -31), INT8_C( -71), INT8_C(  14),
                           INT8_C(-105), INT8_C( -87), INT8_C( 115), INT8_C( -68),
                           INT8_C( -93), INT8_C(  70), INT8_C( -47), INT8_C(-106),
                           INT8_C( 105), INT8_C( -54), INT8_C(  96), INT8_C( 105),
                           INT8_C(  94), INT8_C(  84), INT8_C( -50), INT8_C( -79),
                           INT8_C( -54), INT8_C(  78), INT8_C(  17), INT8_C(  39),
                           INT8_C(  35), INT8_C( -87), INT8_C( -83), INT8_C( -25),
                           INT8_C( 110), INT8_C(   2), INT8_C( -90), INT8_C( -31),
                           INT8_C(  19), INT8_C( -23), INT8_C(   4), INT8_C(  16),
                           INT8_C(  59), INT8_C( -33), INT8_C( 124), INT8_C( 127),
                           INT8_C( -60), INT8_C( -14), INT8_C(-119), INT8_C(  88),
                           INT8_C( -38), INT8_C( 109), INT8_C(-113), INT8_C(  25)),
      UINT64_C(0x789056cebe996e7a) },
    { simde_mm512_set_epi8(INT8_C(  93), INT8_C( 110), INT8_C( 120), INT8_C(  25),
                           INT8_C( -37), INT8_C( -25), INT8_C( -34), INT8_C(-108),
                           INT8_C( -77), INT8_C(-114), INT8_C(  79), INT8_C( -50),
                           INT8_C( -94), INT8_C(  22), INT8_C( -28), INT8_C(-105),
                           INT8_C( 110), INT8_C(  29), INT8_C(  -9), INT8_C( -13),
                           INT8_C( -71), INT8_C( 107), INT8_C(-115), INT8_C(  86),
                           INT8_C(-127), INT8_C(-100), INT8_C(   1), INT8_C(  21),
                           INT8_C( -55), INT8_C( -85), INT8_C( -55), INT8_C( -81),
                           INT8_C( -41), INT8_C(  39), INT8_C(  18), INT8_C( -92),
                           INT8_C(  11), INT8_C( -32), INT8_C( -53), INT8_C(  38),
                           INT8_C( -49), INT8_C(-118), INT8_C(  20), INT8_C(  66),
                           INT8_C(-106), INT8_C(-109), INT8_C(  45), INT8_C( -24),
                           INT8_C( -47), INT8_C(  95), INT8_C(  50), INT8_C( 105),
                           INT8_C(  58), INT8_C(  25), INT8_C( -53), INT8_C( -61),
                           INT8_C( -90), INT8_C(  92), INT8_C(  83), INT8_C( 120),
                           INT8_C( 107), INT8_C( -72), INT8_C(   3), INT8_C(  -1)),
      simde_mm512_set_epi8(INT8_C(  93), INT8_C( 110), INT8_C( 120), INT8_C( -75),
                           INT8_C( -37), INT8_C( -25), INT8_C(  14), INT8_C(-108),
                           INT8_C(   5), INT8_C(-114), INT8_C(  79), INT8_C(  57),
                           INT8_C( -94), INT8_C(  22), INT8_C(   4), INT8_C(   3),
                           INT8_C(  66), INT8_C(  29), INT8_C(  -9), INT8_C(  20),
                           INT8_C(  93), INT8_C( 107), INT8_C(   6), INT8_C(  86),
                           INT8_C(  84), INT8_C(-100), INT8_C(  81), INT8_C(  21),
                           INT8_C( 117), INT8_C(  22), INT8_C( -55), INT8_C( -81),
                           INT8_C( -41), INT8_C( -17), INT8_C(  19), INT8_C( 106),
                           INT8_C( 114), INT8_C( -32), INT8_C(  98), INT8_C( -16),
                           INT8_C( -49), INT8_C(-118), INT8_C(  20), INT8_C(  66),
                           INT8_C(-106), INT8_C(-109), INT8_C(  97), INT8_C(  29),
                           INT8_C( -47), INT8_C( -47), INT8_C(  50), INT8_C(-111),
                           INT8_C(  58), INT8_C( 115), INT8_C( -53), INT8_C(  93),
                           INT8_C( -90), INT8_C( -27), INT8_C(  41), INT8_C( 120),
                           INT8_C( 119), INT8_C(  86), INT8_C( -36), INT8_C(  -1)),
      UINT64_C(0xed6c655384fcaa91) },
    { simde_mm512_set_epi8(INT8_C(  10), INT8_C(  75), INT8_C(  91), INT8_C( -99),
                           INT8_C( -88), INT8_C(  99), INT8_C( -86), INT8_C(  96),
                           INT8_C(  14), INT8_C(  -1), INT8_C(  14), INT8_C( 100),
                           INT8_C(-114), INT8_C(  63), INT8_C(  68), INT8_C(-113),
                           INT8_C( -59), INT8_C( -42), INT8_C( -14), INT8_C(-111),
                           INT8_C(   6), INT8_C(  68), INT8_C(  11), INT8_C(-108),
                           INT8_C( -62), INT8_C(  87), INT8_C( -72), INT8_C( -23),
                           INT8_C(  78), INT8_C( -18), INT8_C( -36), INT8_C(  -6),
                           INT8_C( -68), INT8_C(-115), INT8_C( -24), INT8_C( 127),
                           INT8_C( -36), INT8_C(  21), INT8_C(  38), INT8_C(-106),
                           INT8_C(  33), INT8_C( -66), INT8_C(-121), INT8_C(  36),
                           INT8_C(  24), INT8_C(  61), INT8_C(  66), INT8_C(  20),
                           INT8_C(  63), INT8_C( -18), INT8_C(  11), INT8_C(-103),
                           INT8_C( -19), INT8_C( -42), INT8_C( -69), INT8_C(  53),
                           INT8_C( -40), INT8_C( 112), INT8_C(   8), INT8_C( -69),
                           INT8_C(-102), INT8_C(  62), INT8_C(  85), INT8_C(  62)),
      simde_mm512_set_epi8(INT8_C(  10), INT8_C(  75), INT8_C( -74), INT8_C( -47),
                           INT8_C( -88), INT8_C(  99), INT8_C( -86), INT8_C(-128),
                           INT8_C(  94), INT8_C(  -1), INT8_C(  99), INT8_C( 100),
                           INT8_C( -25), INT8_C(   7), INT8_C(  59), INT8_C(-113),
                           INT8_C( 119), INT8_C( -42), INT8_C( -14), INT8_C(  79),
                           INT8_C(   4), INT8_C(-111), INT8_C(  11), INT8_C(  80),
                           INT8_C( -78), INT8_C(  87), INT8_C( -72), INT8_C(-111),
                           INT8_C( -95), INT8_C( -18), INT8_C( -36), INT8_C( -40),
                           INT8_C( -68), INT8_C(-115), INT8_C( -24), INT8_C( -50),
                           INT8_C( -36), INT8_C(  10), INT8_C(  47), INT8_C(  62),
                           INT8_C( -15), INT8_C( -66), INT8_C(-122), INT8_C(  36),
                           INT8_C( -22), INT8_C(  61), INT8_C( -11), INT8_C(  20),
                           INT8_C(  63), INT8_C(  82), INT8_C(-113), INT8_C(-103),
                           INT8_C( -19), INT8_C( -42), INT8_C( -69), INT8_C(  53),
                           INT8_C( -40), INT8_C( 112), INT8_C(   8), INT8_C( -69),
                           INT8_C(-102), INT8_C(  23), INT8_C(  85), INT8_C(  62)),
      UINT64_C(0xce516266e8559ffb) },
    { simde_mm512_set_epi8(INT8_C(  -7), INT8_C(   2), INT8_C(-111), INT8_C(  64),
                           INT8_C(-100), INT8_C(  87), INT8_C( 100), INT8_C( -30),
                           INT8_C( -39), INT8_C( -38), INT8_C( 121), INT8_C(  55),
                           INT8_C( -64), INT8_C(  81), INT8_C(  -3), INT8_C(  79),
                           INT8_C( -41), INT8_C( 118), INT8_C( -37), INT8_C( -34),
                           INT8_C( -13), INT8_C(  63), INT8_C(  26), INT8_C( -81),
                           INT8_C(  90), INT8_C(  43), INT8_C( -31), INT8_C( -17),
                           INT8_C(-100), INT8_C( -71), INT8_C(-104), INT8_C( -66),
                           INT8_C( -94), INT8_C( -89), INT8_C( 100), INT8_C(  36),
                           INT8_C(  17), INT8_C( 116), INT8_C( -30), INT8_C(  16),
                           INT8_C( 110), INT8_C(  98), INT8_C(  11), INT8_C( -42),
                           INT8_C( -78), INT8_C( -68), INT8_C( -26), INT8_C( -35),
                           INT8_C(  12), INT8_C( -40), INT8_C( -27), INT8_C( -40),
                           INT8_C(-102), INT8_C(-109), INT8_C(  39), INT8_C(  29),
                           INT8_C(  21), INT8_C(   9), INT8_C(  49), INT8_C( -13),
                           INT8_C( -49), INT8_C(   7), INT8_C(  91), INT8_C(  15)),
      simde_mm512_set_epi8(INT8_C(  78), INT8_C(   2), INT8_C( -91), INT8_C(  64),
                           INT8_C(-100), INT8_C(  41), INT8_C( -34), INT8_C( -46),
                           INT8_C( -39), INT8_C(  31), INT8_C(  13), INT8_C(  55),
                           INT8_C( -42), INT8_C(  33), INT8_C(  -3), INT8_C(  79),
                           INT8_C( -41), INT8_C( 118), INT8_C( -37), INT8_C(  90),
                           INT8_C( -13), INT8_C(  63), INT8_C(  51), INT8_C( -81),
                           INT8_C(  90), INT8_C(  43), INT8_C( -31), INT8_C(-112),
                           INT8_C(-100), INT8_C(  41), INT8_C(-104), INT8_C( -66),
                           INT8_C( -94), INT8_C( -89), INT8_C( -85), INT8_C(-109),
                           INT8_C( 113), INT8_C( 116), INT8_C( 100), INT8_C(  16),
                           INT8_C(   5), INT8_C( -50), INT8_C( -51), INT8_C( -42),
                           INT8_C( -95), INT8_C( -68), INT8_C( -26), INT8_C( -35),
                           INT8_C( -73), INT8_C(  71), INT8_C(  65), INT8_C( -40),
                           INT8_C(-102), INT8_C(   7), INT8_C(  94), INT8_C(  29),
                           INT8_C(  65), INT8_C(   9), INT8_C(  49), INT8_C( -13),
                           INT8_C( -33), INT8_C(   7), INT8_C(-101), INT8_C(  15)),
      UINT64_C(0x5893edebc5171975) },
    { simde_mm512_set_epi8(INT8_C( -34), INT8_C( -12), INT8_C( 105), INT8_C(-124),
                           INT8_C( -33), INT8_C( -79), INT8_C(  -6), INT8_C(  54),
                           INT8_C(  81), INT8_C( -11), INT8_C(  67), INT8_C(  63),
                           INT8_C( 103), INT8_C( 119), INT8_C( -89), INT8_C(  40),
                           INT8_C(   8), INT8_C( -38), INT8_C(  71), INT8_C(  66),
                           INT8_C(-106), INT8_C( -45), INT8_C(  18), INT8_C( 100),
                           INT8_C( 122), INT8_C(  93), INT8_C( -42), INT8_C(   5),
                           INT8_C( -39), INT8_C(  37), INT8_C( -70), INT8_C(  13),
                           INT8_C(  99), INT8_C( -57), INT8_C( -88), INT8_C( -36),
                           INT8_C(-103), INT8_C(  25), INT8_C(  94), INT8_C(-107),
                           INT8_C( -32), INT8_C( -12), INT8_C( -14), INT8_C(  32),
                           INT8_C( -38), INT8_C(  10), INT8_C(  89), INT8_C( -69),
                           INT8_C(  -8), INT8_C(  69), INT8_C( -20), INT8_C(-122),
                           INT8_C( -75), INT8_C( -71), INT8_C(   3), INT8_C( 102),
                           INT8_C( 119), INT8_C( -58), INT8_C( -49), INT8_C(  80),
                           INT8_C( -15), INT8_C( -97), INT8_C(  45), INT8_C(  96)),
      simde_mm512_set_epi8(INT8_C( -34), INT8_C( -12), INT8_C(  81), INT8_C(-115),
                           INT8_C( -33), INT8_C( -79), INT8_C(-117), INT8_C( -34),
                           INT8_C(  81), INT8_C( -11), INT8_C( -63), INT8_C( -61),
                           INT8_C(  53), INT8_C( 119), INT8_C(  26), INT8_C(  40),
                           INT8_C(   8), INT8_C( -38), INT8_C(  25), INT8_C( -23),
                           INT8_C( -16), INT8_C( -45), INT8_C( -64), INT8_C( 100),
                           INT8_C(  91), INT8_C(  93), INT8_C( -42), INT8_C(   5),
                           INT8_C(  81), INT8_C( -76), INT8_C( -70), INT8_C(  13),
                           INT8_C(  26), INT8_C( -57), INT8_C( -88), INT8_C( -64),
                           INT8_C( -68), INT8_C( -91), INT8_C(-123), INT8_C(  38),
                           INT8_C( -32), INT8_C(  29), INT8_C(  82), INT8_C(  54),
                           INT8_C(-107), INT8_C(  10), INT8_C(  89), INT8_C(  28),
                           INT8_C( -27), INT8_C(  41), INT8_C( -20), INT8_C(-122),
                           INT8_C( -75), INT8_C( -71), INT8_C(   3), INT8_C( -30),
                           INT8_C(  97), INT8_C(  18), INT8_C( -90), INT8_C( 107),
                           INT8_C(  99), INT8_C(  10), INT8_C(  45), INT8_C(  96)),
      UINT64_C(0xccc5c57360863e03) },
    { simde_mm512_set_epi8(INT8_C(  48), INT8_C(  94), INT8_C( 112), INT8_C(-107),
                           INT8_C( -34), INT8_C( -86), INT8_C(  65), INT8_C(  92),
                           INT8_C(  97), INT8_C( -99), INT8_C(  28), INT8_C(  47),
                           INT8_C(-117), INT8_C( -22), INT8_C(-111), INT8_C( -67),
                           INT8_C( 113), INT8_C(-107), INT8_C( -23), INT8_C(  77),
                           INT8_C(  60), INT8_C( 104), INT8_C(-116), INT8_C( -86),
                           INT8_C(-113), INT8_C( -79), INT8_C( -64), INT8_C( -15),
                           INT8_C(-123), INT8_C(  99), INT8_C(  25), INT8_C(  27),
                           INT8_C( -40), INT8_C( 126), INT8_C( -66), INT8_C( -45),
                           INT8_C(  57), INT8_C( -30), INT8_C( -12), INT8_C(  16),
                           INT8_C( 122), INT8_C( 124), INT8_C( -75), INT8_C(  50),
                           INT8_C(  -6), INT8_C(  41), INT8_C( -47), INT8_C(  -3),
                           INT8_C(  29), INT8_C( -20), INT8_C( -45), INT8_C( -46),
                           INT8_C( -45), INT8_C( -14), INT8_C(  99), INT8_C(  84),
                           INT8_C( -62), INT8_C( -99), INT8_C(-104), INT8_C( -78),
                           INT8_C( 106), INT8_C(-117), INT8_C( -94), INT8_C(   3)),
      simde_mm512_set_epi8(INT8_C( -88), INT8_C( -74), INT8_C(   2), INT8_C( -83),
                           INT8_C(-112), INT8_C( -91), INT8_C(  65), INT8_C(  92),
                           INT8_C(  97), INT8_C(  52), INT8_C(  28), INT8_C( -65),
                           INT8_C(-117), INT8_C( -90), INT8_C(-111), INT8_C( -67),
                           INT8_C( 113), INT8_C(  16), INT8_C(-124), INT8_C(  77),
                           INT8_C(  60), INT8_C( -64), INT8_C(-116), INT8_C( -89),
                           INT8_C(  -7), INT8_C( -79), INT8_C(  46), INT8_C( 114),
                           INT8_C(-107), INT8_C(  99), INT8_C( -79), INT8_C(  80),
                           INT8_C( -40), INT8_C( -81), INT8_C( -66), INT8_C( -45),
                           INT8_C(  57), INT8_C( -30), INT8_C(  66), INT8_C(  71),
                           INT8_C( 122), INT8_C(  95), INT8_C( -43), INT8_C(  50),
                           INT8_C(  -6), INT8_C(  41), INT8_C( -47), INT8_C(  95),
                           INT8_C(   5), INT8_C( -20), INT8_C( -45), INT8_C(-118),
                           INT8_C(  70), INT8_C(  81), INT8_C(   0), INT8_C(  84),
                           INT8_C( -62), INT8_C(-101), INT8_C(  13), INT8_C(  33),
                           INT8_C(-104), INT8_C(-117), INT8_C( -11), INT8_C(  20)),
      UINT64_C(0x3ab9a44bc9e6184) },
    { simde_mm512_set_epi8(INT8_C(  67), INT8_C(  34), INT8_C( -33), INT8_C(  31),
                           INT8_C(-128), INT8_C(  55), INT8_C(  93), INT8_C(  58),
                           INT8_C(  57), INT8_C( 104), INT8_C(-110), INT8_C(  59),
                           INT8_C(  55), INT8_C(  33), INT8_C(-122), INT8_C(  69),
                           INT8_C(  57), INT8_C(  30), INT8_C( -13), INT8_C( -65),
                           INT8_C( -22), INT8_C(-100), INT8_C(  18), INT8_C( -65),
                           INT8_C( -60), INT8_C(-105), INT8_C(  27), INT8_C( -71),
                           INT8_C(  52), INT8_C(  12), INT8_C(  -4), INT8_C(  64),
                           INT8_C(  20), INT8_C(  51), INT8_C(  87), INT8_C(  43),
                           INT8_C(  26), INT8_C(   6), INT8_C( -66), INT8_C( -40),
                           INT8_C(  87), INT8_C(   1), INT8_C( -26), INT8_C(  92),
                           INT8_C( -33), INT8_C(   8), INT8_C(  42), INT8_C( -93),
                           INT8_C(  44), INT8_C( -55), INT8_C(-113), INT8_C( -43),
                           INT8_C(  32), INT8_C( 105), INT8_C( -27), INT8_C(  96),
                           INT8_C(  72), INT8_C(  48), INT8_C( -46), INT8_C(  24),
                           INT8_C( -10), INT8_C( -98), INT8_C( -56), INT8_C( -41)),
      simde_mm512_set_epi8(INT8_C(  67), INT8_C( -63), INT8_C( -33), INT8_C(  31),
                           INT8_C(-128), INT8_C(  55), INT8_C(  93), INT8_C(  -8),
                           INT8_C(  82), INT8_C( 104), INT8_C(-110), INT8_C(  59),
                           INT8_C(  55), INT8_C(   0), INT8_C( -25), INT8_C(  69),
                           INT8_C(  27), INT8_C(  30), INT8_C( -13), INT8_C( -65),
                           INT8_C(  -7), INT8_C( -28), INT8_C(  18), INT8_C( -65),
                           INT8_C(  67), INT8_C(  -3), INT8_C(  57), INT8_C( -68),
                           INT8_C(  52), INT8_C(  12), INT8_C(  -4), INT8_C(-128),
                           INT8_C(  20), INT8_C(  37), INT8_C(   9), INT8_C(  80),
                           INT8_C(  26), INT8_C(   6), INT8_C( -66), INT8_C(   9),
                           INT8_C( -98), INT8_C(   1), INT8_C( -26), INT8_C(  92),
                           INT8_C( -33), INT8_C(   8), INT8_C( -81), INT8_C( -93),
                           INT8_C( 116), INT8_C( -55), INT8_C(-113), INT8_C( -43),
                           INT8_C(  32), INT8_C( 105), INT8_C( -27), INT8_C(  37),
                           INT8_C(  72), INT8_C( -73), INT8_C( -19), INT8_C(  96),
                           INT8_C(  52), INT8_C( -98), INT8_C( -45), INT8_C( -41)),
      UINT64_C(0xbe79730e8e7d7e85) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask64 r = simde_mm512_cmpeq_epi8_mask(test_vec[i].a, test_vec[i].b);
    simde_assert_mmask64(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cmpeq_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( 1955445938), INT32_C( 1791143901), INT32_C(-1554982337), INT32_C(-1864115653),
                            INT32_C(-1774796435), INT32_C( 1168347531), INT32_C(  660969508), INT32_C( 1153796239),
                            INT32_C(  609464964), INT32_C( 1687040663), INT32_C( -477087011), INT32_C(  309017072),
                            INT32_C(-2144421691), INT32_C(  682838279), INT32_C( 1954361304), INT32_C( 1694661655)),
      simde_mm512_set_epi32(INT32_C( 1955445938), INT32_C( 1791143901), INT32_C(-1554982337), INT32_C(-1021004514),
                            INT32_C(-1774796435), INT32_C( 1168347531), INT32_C( 1662960443), INT32_C( 1153796239),
                            INT32_C(  609464964), INT32_C(  428287860), INT32_C(  954212709), INT32_C(  309017072),
                            INT32_C(-2144421691), INT32_C( 1263291650), INT32_C( 1954361304), INT32_C( 1694661655)),
      UINT16_C(60827) },
    { simde_mm512_set_epi32(INT32_C(-1966343749), INT32_C(  200215975), INT32_C(-1192030414), INT32_C(  122433675),
                            INT32_C( 2024442800), INT32_C(-1612503082), INT32_C( -352764842), INT32_C( -964919402),
                            INT32_C(  198779956), INT32_C(-1052322954), INT32_C(-2053476283), INT32_C( 1410443780),
                            INT32_C( -220052733), INT32_C( 1401656692), INT32_C(  344284159), INT32_C(  358488145)),
      simde_mm512_set_epi32(INT32_C(-1966343749), INT32_C(  200215975), INT32_C( 1606502639), INT32_C(  122433675),
                            INT32_C( 2024442800), INT32_C( 1676122341), INT32_C( 1013297923), INT32_C( 1764819720),
                            INT32_C(-1006160158), INT32_C(  500282446), INT32_C(-2053476283), INT32_C( 1410443780),
                            INT32_C( -891361692), INT32_C( 1401656692), INT32_C(-1666424273), INT32_C(  358488145)),
      UINT16_C(55349) },
    { simde_mm512_set_epi32(INT32_C( 2029514541), INT32_C(-1405121342), INT32_C( -922299669), INT32_C(-1157312309),
                            INT32_C(  348700274), INT32_C( 1888848128), INT32_C( -909115111), INT32_C(-1689020830),
                            INT32_C( -310128293), INT32_C(-2105034529), INT32_C( 1894199289), INT32_C( -520350707),
                            INT32_C( 2077151614), INT32_C(  947639177), INT32_C(  972348424), INT32_C(  688864219)),
      simde_mm512_set_epi32(INT32_C( 2029514541), INT32_C(-1405121342), INT32_C( -922299669), INT32_C(-1157312309),
                            INT32_C( -582496350), INT32_C(  321618555), INT32_C( -707023911), INT32_C(-1689020830),
                            INT32_C(-1223923200), INT32_C( -293312096), INT32_C( 1894199289), INT32_C(  -89856908),
                            INT32_C( 2077151614), INT32_C(  947639177), INT32_C(  352633301), INT32_C( -580477735)),
      UINT16_C(61740) },
    { simde_mm512_set_epi32(INT32_C(   63224893), INT32_C( -945243939), INT32_C( 1472177104), INT32_C(-1518639341),
                            INT32_C( 1244274955), INT32_C(-1053463974), INT32_C(  207788622), INT32_C( -375726536),
                            INT32_C( -219606791), INT32_C( -871332353), INT32_C( 2036105492), INT32_C( 1465626684),
                            INT32_C(  930923741), INT32_C(-1996202276), INT32_C(  336972805), INT32_C(-1729161210)),
      simde_mm512_set_epi32(INT32_C( 1739683658), INT32_C( -945243939), INT32_C( 1472177104), INT32_C( -959740920),
                            INT32_C( 1244274955), INT32_C(  236525659), INT32_C(  207788622), INT32_C( 1159372556),
                            INT32_C( -632841040), INT32_C( -871332353), INT32_C( 2036105492), INT32_C(-1821161401),
                            INT32_C(  626098659), INT32_C(-1099705903), INT32_C( 1892226777), INT32_C(  183269504)),
      UINT16_C(27232) },
    { simde_mm512_set_epi32(INT32_C( 1660264790), INT32_C( -188014963), INT32_C( 1960568786), INT32_C(  630575470),
                            INT32_C(-1560285386), INT32_C(-1080983958), INT32_C( -186614663), INT32_C(-1365084922),
                            INT32_C( 1687374482), INT32_C( 2091712477), INT32_C( 1770300152), INT32_C( 1222615684),
                            INT32_C(  987382002), INT32_C( -869689297), INT32_C( 1381156346), INT32_C(  352829646)),
      simde_mm512_set_epi32(INT32_C( 1495188549), INT32_C( -188014963), INT32_C( -879412194), INT32_C( 1172150075),
                            INT32_C( 1163780404), INT32_C(-1080983958), INT32_C( -186614663), INT32_C(-1365084922),
                            INT32_C( 1196042729), INT32_C( 2091712477), INT32_C( 1770300152), INT32_C( 1222615684),
                            INT32_C(  987382002), INT32_C( -453542339), INT32_C(-1460537486), INT32_C( 1311735715)),
      UINT16_C(18296) },
    { simde_mm512_set_epi32(INT32_C( -830898164), INT32_C( 2065530031), INT32_C( 1849339474), INT32_C( -161498764),
                            INT32_C(  726295410), INT32_C(-1366062470), INT32_C(  110025501), INT32_C(-2061598845),
                            INT32_C(-1911113344), INT32_C(-2008355607), INT32_C( 1140427951), INT32_C( 1963231912),
                            INT32_C( 1593065931), INT32_C( 1712671682), INT32_C(-2139143015), INT32_C(  330252777)),
      simde_mm512_set_epi32(INT32_C( -830898164), INT32_C(-2132024757), INT32_C( 1102342058), INT32_C( -161498764),
                            INT32_C(-2106128090), INT32_C(  648329890), INT32_C(-1284054768), INT32_C(-2061598845),
                            INT32_C(-1911113344), INT32_C(-2008355607), INT32_C( 1715485148), INT32_C(  155412419),
                            INT32_C( 1273550758), INT32_C( 1712671682), INT32_C(-1857983881), INT32_C( 1633779150)),
      UINT16_C(37316) },
    { simde_mm512_set_epi32(INT32_C( 1956746364), INT32_C( 1930323834), INT32_C(  923874794), INT32_C(  121318212),
                            INT32_C(-1375858452), INT32_C( -462992597), INT32_C( 1495829546), INT32_C(  697040437),
                            INT32_C(  727111035), INT32_C(-2061427382), INT32_C( -815432287), INT32_C(  913775211),
                            INT32_C(-1333809472), INT32_C(  114048073), INT32_C( 1312920985), INT32_C(-1819914035)),
      simde_mm512_set_epi32(INT32_C( 1659376087), INT32_C( 1930323834), INT32_C(  923874794), INT32_C(  121318212),
                            INT32_C(-1375858452), INT32_C(-1480844812), INT32_C(-1803673478), INT32_C(  697040437),
                            INT32_C( 1793922150), INT32_C(  391658500), INT32_C( -815432287), INT32_C(  913775211),
                            INT32_C(-1333809472), INT32_C( -169359358), INT32_C(  140424991), INT32_C(-1819914035)),
      UINT16_C(31033) },
    { simde_mm512_set_epi32(INT32_C( 1334496661), INT32_C(-1765072906), INT32_C(-1980138391), INT32_C(-1150536116),
                            INT32_C( -711226926), INT32_C( 1955166809), INT32_C( 1418224832), INT32_C( 1791996583),
                            INT32_C(-1305868646), INT32_C( -507537618), INT32_C(  272749509), INT32_C(-1826072492),
                            INT32_C( -629068596), INT32_C(-2142583585), INT32_C( 2048200365), INT32_C(-1377550438)),
      simde_mm512_set_epi32(INT32_C( 1334496661), INT32_C(-1765072906), INT32_C( -890751438), INT32_C(-1150536116),
                            INT32_C(  307879329), INT32_C( 1955166809), INT32_C(-1884386825), INT32_C( 1791996583),
                            INT32_C( 1128431085), INT32_C( -507537618), INT32_C(  272749509), INT32_C( 1579228324),
                            INT32_C( 1577134581), INT32_C(-2142583585), INT32_C( 1998674783), INT32_C(-1377550438)),
      UINT16_C(54629) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_cmpeq_epi32_mask(test_vec[i].a, test_vec[i].b);
    simde_assert_mmask16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { UINT16_C(15798),
      simde_mm512_set_epi32(INT32_C(-1396783922), INT32_C( 2147469122), INT32_C(  245941047), INT32_C(-1608794680),
                            INT32_C( 1508622706), INT32_C( -820009589), INT32_C(-2056933337), INT32_C( 1399160559),
                            INT32_C( -781782717), INT32_C( -745938688), INT32_C( 1376412239), INT32_C(  358147007),
                            INT32_C(-2141927311), INT32_C(  -13921241), INT32_C(  993767039), INT32_C( 1399506469)),
      simde_mm512_set_epi32(INT32_C(-1396783922), INT32_C( 1246457300), INT32_C( 1479047358), INT32_C(  -46329110),
                            INT32_C( 1508622706), INT32_C( -820009589), INT32_C( 2080173402), INT32_C( 1937046285),
                            INT32_C( 1642337112), INT32_C(  717149471), INT32_C(  913865239), INT32_C(  358147007),
                            INT32_C( 1535690363), INT32_C(  -13921241), INT32_C(  993767039), INT32_C(  520030741)),
      UINT16_C( 3094) },
    { UINT16_C(11237),
      simde_mm512_set_epi32(INT32_C( -503773363), INT32_C(-1842967576), INT32_C(  214407733), INT32_C( 2136243689),
                            INT32_C(  619563347), INT32_C(-2046647578), INT32_C( -882198373), INT32_C( -832110086),
                            INT32_C(  828288790), INT32_C( 1819046419), INT32_C(  292064966), INT32_C( -747926472),
                            INT32_C( -881463995), INT32_C(-1469434386), INT32_C( -207196114), INT32_C(-1865668915)),
      simde_mm512_set_epi32(INT32_C(  261150369), INT32_C(-1842967576), INT32_C(-1148601855), INT32_C( 2136243689),
                            INT32_C(-2013121518), INT32_C(-2046647578), INT32_C(-1816537753), INT32_C( -832110086),
                            INT32_C(  828288790), INT32_C( 1801925150), INT32_C(  292064966), INT32_C(-1755078036),
                            INT32_C(-1190065823), INT32_C(  764421376), INT32_C( -207196114), INT32_C(-1865668915)),
      UINT16_C(  417) },
    { UINT16_C(   61),
      simde_mm512_set_epi32(INT32_C(  219790698), INT32_C(  346516102), INT32_C(-2082495343), INT32_C(  775700745),
                            INT32_C( -630025741), INT32_C( 1914162819), INT32_C( -226095226), INT32_C( -350619769),
                            INT32_C( 1825330894), INT32_C(  -79420124), INT32_C(  939662489), INT32_C(  667606641),
                            INT32_C(-1935137328), INT32_C(  247120548), INT32_C( -894861328), INT32_C(-1690188311)),
      simde_mm512_set_epi32(INT32_C(  400967600), INT32_C(  346516102), INT32_C(-2082495343), INT32_C(  775700745),
                            INT32_C( -630025741), INT32_C( 1914162819), INT32_C(-1771983812), INT32_C( -350619769),
                            INT32_C( 1825330894), INT32_C(-1887033010), INT32_C(  939662489), INT32_C( -440942769),
                            INT32_C(-1935137328), INT32_C(  247120548), INT32_C(-1352163534), INT32_C(-1690188311)),
      UINT16_C(   45) },
    { UINT16_C(40799),
      simde_mm512_set_epi32(INT32_C(-1103261115), INT32_C(-1530092257), INT32_C( -178076517), INT32_C( 1725180044),
                            INT32_C( -619562554), INT32_C(-2028225116), INT32_C( -516465044), INT32_C( -790492311),
                            INT32_C(  770588317), INT32_C(  966229539), INT32_C( 1696981823), INT32_C( 1846986452),
                            INT32_C(  201003704), INT32_C(  -88144749), INT32_C( -459260562), INT32_C(-1462493092)),
      simde_mm512_set_epi32(INT32_C(-1103261115), INT32_C(-1530092257), INT32_C( 1272329003), INT32_C( 1725180044),
                            INT32_C(-1714282865), INT32_C( 1964019033), INT32_C(   -6888948), INT32_C( -794446809),
                            INT32_C(  770588317), INT32_C(  966229539), INT32_C(-1587543669), INT32_C( 1846986452),
                            INT32_C(  201003704), INT32_C(  -88144749), INT32_C(-1549459108), INT32_C(-1462493092)),
      UINT16_C(36957) },
    { UINT16_C(18708),
      simde_mm512_set_epi32(INT32_C( 1654168369), INT32_C(-1358646009), INT32_C(  945188582), INT32_C( 1242452940),
                            INT32_C(-2068238117), INT32_C(  613827224), INT32_C( 1766050173), INT32_C(  788865946),
                            INT32_C( -226150288), INT32_C(   20626714), INT32_C(-1790747056), INT32_C(-1510999017),
                            INT32_C(-2059568770), INT32_C(  525242273), INT32_C(-1970979230), INT32_C( -983788353)),
      simde_mm512_set_epi32(INT32_C(-1802152524), INT32_C(-1358646009), INT32_C( 1400410557), INT32_C( 1242452940),
                            INT32_C(-2068238117), INT32_C(-1745049433), INT32_C(-1272787498), INT32_C(   36641197),
                            INT32_C( -226150288), INT32_C(-2087200149), INT32_C( -530182364), INT32_C(-1510999017),
                            INT32_C(-2082577633), INT32_C(  525242273), INT32_C(-1970979230), INT32_C( -983788353)),
      UINT16_C(18452) },
    { UINT16_C(48938),
      simde_mm512_set_epi32(INT32_C(-1802886705), INT32_C(  505130099), INT32_C( 1294359394), INT32_C(  564426410),
                            INT32_C( -813242663), INT32_C(-1097324530), INT32_C( 1599346411), INT32_C(-1815738445),
                            INT32_C( 2114996332), INT32_C( 2143192037), INT32_C(  342894910), INT32_C( 1933006347),
                            INT32_C(  215936041), INT32_C( 2138148935), INT32_C(-1975112588), INT32_C(-1313889253)),
      simde_mm512_set_epi32(INT32_C( 1272515820), INT32_C(-1571014987), INT32_C( 1294359394), INT32_C(  564426410),
                            INT32_C( -305474417), INT32_C(-2099686495), INT32_C(  217917259), INT32_C( 1770631752),
                            INT32_C( 2114996332), INT32_C( 2143192037), INT32_C(  -26985081), INT32_C(  603877714),
                            INT32_C( 1592556524), INT32_C(  420570241), INT32_C(-1975112588), INT32_C(-1313889253)),
      UINT16_C(12290) },
    { UINT16_C(14127),
      simde_mm512_set_epi32(INT32_C(  452796731), INT32_C( -256668338), INT32_C(-1710549095), INT32_C( 1982965424),
                            INT32_C( 1184306045), INT32_C( -221254467), INT32_C( 1420239721), INT32_C( 2028887361),
                            INT32_C(-1950932361), INT32_C( 1650853943), INT32_C(  239751123), INT32_C( 1018010808),
                            INT32_C( -248946240), INT32_C(  701510715), INT32_C(  824235240), INT32_C( 1829156606)),
      simde_mm512_set_epi32(INT32_C(  452796731), INT32_C( 1031814185), INT32_C(-1710549095), INT32_C(  406415467),
                            INT32_C( 1184306045), INT32_C( -221254467), INT32_C(  419739010), INT32_C( 1708161231),
                            INT32_C(-1950932361), INT32_C( 1650853943), INT32_C(  239751123), INT32_C( 1018010808),
                            INT32_C( -248946240), INT32_C(  701510715), INT32_C(-1571248435), INT32_C( 1829156606)),
      UINT16_C( 9261) },
    { UINT16_C(22801),
      simde_mm512_set_epi32(INT32_C( 1869800572), INT32_C(  184060195), INT32_C(   81710208), INT32_C( -451284065),
                            INT32_C(  397153235), INT32_C(  120564446), INT32_C(-2128920097), INT32_C( 1498011427),
                            INT32_C( -602736654), INT32_C( -931955343), INT32_C(  270436915), INT32_C( -984637478),
                            INT32_C( 2080482721), INT32_C( 1599947836), INT32_C(  374268618), INT32_C(  202341051)),
      simde_mm512_set_epi32(INT32_C( 1869800572), INT32_C(  350721255), INT32_C( 1725621650), INT32_C( 2020045509),
                            INT32_C(  397153235), INT32_C( 2059505832), INT32_C(-2128920097), INT32_C( 1498011427),
                            INT32_C(  884679844), INT32_C( -931955343), INT32_C(-1565261303), INT32_C( -984637478),
                            INT32_C( 1047792745), INT32_C(  969830078), INT32_C(  374268618), INT32_C(  202341051)),
      UINT16_C( 2321) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_mask_cmpeq_epi32_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_mmask16(HEDLEY_STATIC_CAST(uint16_t, r), ==, HEDLEY_STATIC_CAST(uint16_t, test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_cmpeq_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C( 1145569124203592220), INT64_C( 8866992319046943109),
                            INT64_C( 1920152028348566704), INT64_C( 5434169962120345100),
                            INT64_C( 2279810443797316081), INT64_C( 8202334326145056493),
                            INT64_C(-3178237508368099649), INT64_C(  691539695110831332)),
      simde_mm512_set_epi64(INT64_C( 1145569124203592220), INT64_C( 7456258988741005047),
                            INT64_C( 1920152028348566704), INT64_C(-5531344059509930758),
                            INT64_C( 2279810443797316081), INT64_C( 4212838215119313762),
                            INT64_C(-3178237508368099649), INT64_C(  805234941373423218)),
      UINT8_C(170) },
    { simde_mm512_set_epi64(INT64_C(-9153030146845322943), INT64_C(-3269802522838954453),
                            INT64_C( 4057416377680772191), INT64_C(-4770808841142629569),
                            INT64_C(-3341852712217874901), INT64_C( 2807150139607841402),
                            INT64_C(-4019938614639236980), INT64_C(-5612844059017155926)),
      simde_mm512_set_epi64(INT64_C(-9153030146845322943), INT64_C(-3269802522838954453),
                            INT64_C( 4057416377680772191), INT64_C( -940603917401247915),
                            INT64_C(-3341852712217874901), INT64_C( 2807150139607841402),
                            INT64_C(-4019938614639236980), INT64_C(-5612844059017155926)),
      UINT8_C(239) },
    { simde_mm512_set_epi64(INT64_C(-6535160640888369935), INT64_C( 4320507985166557084),
                            INT64_C( 5472888856009482484), INT64_C(-3128657528300165720),
                            INT64_C( 7430914891859325397), INT64_C( -863913734109164798),
                            INT64_C(-7794735185814972844), INT64_C( 6163895309000776850)),
      simde_mm512_set_epi64(INT64_C(-4220461743444256802), INT64_C( 2616373937292152846),
                            INT64_C( 5472888856009482484), INT64_C(-3128657528300165720),
                            INT64_C(-4693544589206901195), INT64_C( -863913734109164798),
                            INT64_C(-7794735185814972844), INT64_C(-7914074467628930001)),
      UINT8_C( 54) },
    { simde_mm512_set_epi64(INT64_C(-2366835550617683621), INT64_C(-7526131353484035546),
                            INT64_C(  792273323175818479), INT64_C(-3293855504021481788),
                            INT64_C( 5766970185621377329), INT64_C( 8555682923177627503),
                            INT64_C( 6363802824474944219), INT64_C(-2294667848278645794)),
      simde_mm512_set_epi64(INT64_C(-2869910567061155737), INT64_C(-7526131353484035546),
                            INT64_C(  792273323175818479), INT64_C( 7002007300200137801),
                            INT64_C( 5766970185621377329), INT64_C( 8555682923177627503),
                            INT64_C( 6363802824474944219), INT64_C( 1235305386817146646)),
      UINT8_C(110) },
    { simde_mm512_set_epi64(INT64_C( 1781453983767744725), INT64_C( 8717105342239974860),
                            INT64_C(-6555437070120516632), INT64_C( -945434448901737124),
                            INT64_C( 2467182069214891728), INT64_C( 6380355612148977321),
                            INT64_C(-8948278762783625779), INT64_C( 4377995125356963906)),
      simde_mm512_set_epi64(INT64_C( 1781453983767744725), INT64_C( 8717105342239974860),
                            INT64_C(-1574265126641933862), INT64_C(-3609136820784425910),
                            INT64_C( 8413977304256335681), INT64_C(-4046135395677773903),
                            INT64_C(-8948278762783625779), INT64_C( 4377995125356963906)),
      UINT8_C(195) },
    { simde_mm512_set_epi64(INT64_C( 3163831140256245302), INT64_C(-7476767975543057611),
                            INT64_C( 4783231484571490676), INT64_C( 4356333140933542181),
                            INT64_C(-5734470250608567849), INT64_C( 5428089484060124354),
                            INT64_C( 6915844972668556704), INT64_C(-4128418267655054219)),
      simde_mm512_set_epi64(INT64_C( 3163831140256245302), INT64_C(-7945608864951271413),
                            INT64_C(-3728561425301803734), INT64_C( 6344562138072151085),
                            INT64_C(-5734470250608567849), INT64_C( 5868624435741359252),
                            INT64_C( 6915844972668556704), INT64_C(-4128418267655054219)),
      UINT8_C(139) },
    { simde_mm512_set_epi64(INT64_C(-8545152605640787948), INT64_C(-5234822620280611494),
                            INT64_C(-2932089901585751375), INT64_C( 4017618173912988951),
                            INT64_C(-8696436452927061736), INT64_C( 3602642025812661939),
                            INT64_C( 5777136991119584953), INT64_C(-5473038481952171581)),
      simde_mm512_set_epi64(INT64_C(-8545152605640787948), INT64_C(-7808252369899371159),
                            INT64_C(-2932089901585751375), INT64_C(  -26139149052321087),
                            INT64_C(-6986660196527912755), INT64_C( 3602642025812661939),
                            INT64_C( 5777136991119584953), INT64_C(-5473038481952171581)),
      UINT8_C(167) },
    { simde_mm512_set_epi64(INT64_C( 7780170108497689334), INT64_C(-8001282944915881932),
                            INT64_C(  382835809361431399), INT64_C(-5014881555296189468),
                            INT64_C(-1844642447215154571), INT64_C(-5452282829002750089),
                            INT64_C(-7793611854809744260), INT64_C(  938166230586687295)),
      simde_mm512_set_epi64(INT64_C( 7780170108497689334), INT64_C( 1739290942316187796),
                            INT64_C( 7815402837606564081), INT64_C(-5014881555296189468),
                            INT64_C(-1844642447215154571), INT64_C( -253128228754997390),
                            INT64_C(-7793611854809744260), INT64_C(  938166230586687295)),
      UINT8_C(155) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_cmpeq_epi64_mask(test_vec[i].a, test_vec[i].b);
    simde_assert_mmask8(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_cmpeq_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {
       { UINT8_C( 90),
      simde_mm512_set_epi64(INT64_C( 7722926897436765530), INT64_C( 7338279138551748064),
                            INT64_C( 8433308126101200079), INT64_C(-4390305748733976547),
                            INT64_C(-1482589068035252753), INT64_C(-5002011091694476743),
                            INT64_C( 5809674310022718254), INT64_C( 7620249298233351482)),
      simde_mm512_set_epi64(INT64_C( 7722926897436765530), INT64_C( 7338279138551748064),
                            INT64_C(-2656726859984743367), INT64_C(-4390305748733976547),
                            INT64_C(-1482589068035252753), INT64_C(-5269390469191050553),
                            INT64_C( 5809674310022718254), INT64_C( 7620249298233351482)),
      UINT8_C( 90) },
    { UINT8_C(178),
      simde_mm512_set_epi64(INT64_C(-8806453660480970182), INT64_C(-2722914847628644365),
                            INT64_C( 2171146127585219679), INT64_C(-7200523266853707115),
                            INT64_C( 8505301695237968355), INT64_C( 6373940775215479358),
                            INT64_C( 8209357864908427195), INT64_C( -995665125730760835)),
      simde_mm512_set_epi64(INT64_C(-8806453660480970182), INT64_C(-2722914847628644365),
                            INT64_C(-1180134256156200317), INT64_C(-7200523266853707115),
                            INT64_C(-1610604796376715795), INT64_C( 5419019224867820225),
                            INT64_C( 8209357864908427195), INT64_C( -995665125730760835)),
      UINT8_C(146) },
    { UINT8_C(171),
      simde_mm512_set_epi64(INT64_C(-6245801519083893310), INT64_C(-7866373458730819532),
                            INT64_C(-5627757407772356197), INT64_C(-2425546480980122794),
                            INT64_C(-8451301604567613199), INT64_C( 1369383717682198649),
                            INT64_C( -532343328754521574), INT64_C(-1062878680437210584)),
      simde_mm512_set_epi64(INT64_C(-9163399881020056955), INT64_C(-2992244142829238392),
                            INT64_C( -213476403626539965), INT64_C(-8591297333400286921),
                            INT64_C(-8451301604567613199), INT64_C(-8139768780594538635),
                            INT64_C(-4714070518405120331), INT64_C(-1062878680437210584)),
      UINT8_C(  9) },
    { UINT8_C( 28),
      simde_mm512_set_epi64(INT64_C( 7845956693704412298), INT64_C(-5781930833336581955),
                            INT64_C( 2851517750261041799), INT64_C(-5814293521236182366),
                            INT64_C( 2292150971239308783), INT64_C( 2594053186857735013),
                            INT64_C( 7307535341641173075), INT64_C(-4427478291595527940)),
      simde_mm512_set_epi64(INT64_C(  536264388241191871), INT64_C(-5781930833336581955),
                            INT64_C( 2851517750261041799), INT64_C( 1349842462394812975),
                            INT64_C( 2292150971239308783), INT64_C( 2594053186857735013),
                            INT64_C( 7307535341641173075), INT64_C(-4427478291595527940)),
      UINT8_C( 12) },
    { UINT8_C(248),
      simde_mm512_set_epi64(INT64_C( 4900816215694077255), INT64_C(-2732029741423656661),
                            INT64_C( 1082977534221618055), INT64_C(-3092044493389993636),
                            INT64_C(-4299277917890019767), INT64_C(-2055775203132417874),
                            INT64_C( -778633101599852237), INT64_C( -563223173848121636)),
      simde_mm512_set_epi64(INT64_C( 7049304296219110648), INT64_C(-2732029741423656661),
                            INT64_C( 7088083428992159722), INT64_C(-3092044493389993636),
                            INT64_C(-4299277917890019767), INT64_C( 4225506809727089751),
                            INT64_C( -778633101599852237), INT64_C( -563223173848121636)),
      UINT8_C( 88) },
    { UINT8_C(171),
      simde_mm512_set_epi64(INT64_C(-1412821155990992029), INT64_C( 4454576651901490962),
                            INT64_C(-7284760734604447652), INT64_C(-7443130466673006479),
                            INT64_C(  320054597637804434), INT64_C(-8860872372305530355),
                            INT64_C(-8428145646879978292), INT64_C(-6547252853189215611)),
      simde_mm512_set_epi64(INT64_C(-1412821155990992029), INT64_C(-2354123670646573707),
                            INT64_C( 4506838144989822528), INT64_C(-7443130466673006479),
                            INT64_C(-5147543239321546686), INT64_C(-8860872372305530355),
                            INT64_C(-8428145646879978292), INT64_C(-6547252853189215611)),
      UINT8_C(131) },
    { UINT8_C( 29),
      simde_mm512_set_epi64(INT64_C( 5675137803130124480), INT64_C( 1211541157654985046),
                            INT64_C( 8724633375562564314), INT64_C(-2760658800846254598),
                            INT64_C(-6714474269646576270), INT64_C( 3484180661422871715),
                            INT64_C( 1469796163712815354), INT64_C(-2336393240308600160)),
      simde_mm512_set_epi64(INT64_C( 5675137803130124480), INT64_C( 1211541157654985046),
                            INT64_C(-8867413355151838495), INT64_C(-8867147959443474315),
                            INT64_C(-6714474269646576270), INT64_C( 3484180661422871715),
                            INT64_C(-7735267815657951749), INT64_C(  413036036281601883)),
      UINT8_C( 12) },
    { UINT8_C(211),
      simde_mm512_set_epi64(INT64_C(-6713502673628263139), INT64_C( 1559753162601267291),
                            INT64_C( 5045660940436454371), INT64_C( 7013290440433503154),
                            INT64_C(-8475145246816690249), INT64_C(-6834826688677600633),
                            INT64_C(-2109099044497919348), INT64_C( 1351143524438105934)),
      simde_mm512_set_epi64(INT64_C( 5625319538109918668), INT64_C( 1559753162601267291),
                            INT64_C( 5045660940436454371), INT64_C(-4654386914804892920),
                            INT64_C( 2407237530895996207), INT64_C(-6834826688677600633),
                            INT64_C( 4684210505965066200), INT64_C( 1351143524438105934)),
      UINT8_C( 65) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_mask_cmpeq_epi64_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_mmask8(r, ==, test_vec[i].r);
  }

  return 0;
}

#if !defined(SIMDE_BUG_GCC_96174)

static int
test_simde_mm512_cmpeq_ps_mask (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde__mmask16 r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -330.05), SIMDE_FLOAT32_C(   847.28), SIMDE_FLOAT32_C(    61.79), SIMDE_FLOAT32_C(   748.75),
        SIMDE_FLOAT32_C(  -125.94), SIMDE_FLOAT32_C(  -287.83), SIMDE_FLOAT32_C(  -156.45), SIMDE_FLOAT32_C(  -904.26),
        SIMDE_FLOAT32_C(   393.62), SIMDE_FLOAT32_C(   694.71), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   245.98),
        SIMDE_FLOAT32_C(  -522.67), SIMDE_FLOAT32_C(   140.34), SIMDE_FLOAT32_C(  -555.38), SIMDE_FLOAT32_C(   596.45) },
      { SIMDE_FLOAT32_C(  -330.05), SIMDE_FLOAT32_C(  -812.74), SIMDE_FLOAT32_C(    61.79), SIMDE_FLOAT32_C(  -304.55),
        SIMDE_FLOAT32_C(    95.53), SIMDE_FLOAT32_C(  -287.83), SIMDE_FLOAT32_C(  -156.45), SIMDE_FLOAT32_C(   699.14),
        SIMDE_FLOAT32_C(   676.85), SIMDE_FLOAT32_C(   694.71), SIMDE_FLOAT32_C(   345.37), SIMDE_FLOAT32_C(   245.98),
        SIMDE_FLOAT32_C(  -161.51), SIMDE_FLOAT32_C(   140.34), SIMDE_FLOAT32_C(  -399.39), SIMDE_FLOAT32_C(   596.45) },
      UINT16_C(44645) },
    { { SIMDE_FLOAT32_C(  -717.84), SIMDE_FLOAT32_C(   512.02), SIMDE_FLOAT32_C(    98.80), SIMDE_FLOAT32_C(  -966.72),
        SIMDE_FLOAT32_C(   -60.71), SIMDE_FLOAT32_C(  -584.27), SIMDE_FLOAT32_C(   204.10), SIMDE_FLOAT32_C(   295.96),
        SIMDE_FLOAT32_C(   -70.24), SIMDE_FLOAT32_C(   661.77), SIMDE_FLOAT32_C(   894.04), SIMDE_FLOAT32_C(   352.28),
        SIMDE_FLOAT32_C(   620.44), SIMDE_FLOAT32_C(   936.22), SIMDE_FLOAT32_C(   428.81), SIMDE_FLOAT32_C(   543.55) },
      { SIMDE_FLOAT32_C(  -717.84), SIMDE_FLOAT32_C(   313.36), SIMDE_FLOAT32_C(  -806.61), SIMDE_FLOAT32_C(   690.40),
        SIMDE_FLOAT32_C(   646.60), SIMDE_FLOAT32_C(  -584.27), SIMDE_FLOAT32_C(   204.10), SIMDE_FLOAT32_C(   460.04),
        SIMDE_FLOAT32_C(   733.57), SIMDE_FLOAT32_C(   661.77), SIMDE_FLOAT32_C(   894.04), SIMDE_FLOAT32_C(  -252.47),
        SIMDE_FLOAT32_C(  -340.15), SIMDE_FLOAT32_C(   936.22), SIMDE_FLOAT32_C(   428.81), SIMDE_FLOAT32_C(   543.55) },
      UINT16_C(58977) },
    { { SIMDE_FLOAT32_C(   375.91), SIMDE_FLOAT32_C(   -19.72), SIMDE_FLOAT32_C(   336.05), SIMDE_FLOAT32_C(  -540.20),
        SIMDE_FLOAT32_C(  -665.47), SIMDE_FLOAT32_C(  -492.58), SIMDE_FLOAT32_C(    15.30), SIMDE_FLOAT32_C(   126.92),
        SIMDE_FLOAT32_C(   767.58), SIMDE_FLOAT32_C(   861.15), SIMDE_FLOAT32_C(   -58.47), SIMDE_FLOAT32_C(  -387.52),
        SIMDE_FLOAT32_C(   800.70), SIMDE_FLOAT32_C(  -537.31), SIMDE_FLOAT32_C(  -644.51), SIMDE_FLOAT32_C(  -955.44) },
      { SIMDE_FLOAT32_C(   375.91), SIMDE_FLOAT32_C(  -356.80), SIMDE_FLOAT32_C(   336.05), SIMDE_FLOAT32_C(   -10.02),
        SIMDE_FLOAT32_C(   -64.34), SIMDE_FLOAT32_C(   408.76), SIMDE_FLOAT32_C(  -734.89), SIMDE_FLOAT32_C(   126.92),
        SIMDE_FLOAT32_C(    10.21), SIMDE_FLOAT32_C(   861.15), SIMDE_FLOAT32_C(   153.18), SIMDE_FLOAT32_C(   569.21),
        SIMDE_FLOAT32_C(   321.66), SIMDE_FLOAT32_C(  -537.31), SIMDE_FLOAT32_C(   613.36), SIMDE_FLOAT32_C(  -776.54) },
      UINT16_C( 8837) },
    { { SIMDE_FLOAT32_C(  -842.85), SIMDE_FLOAT32_C(  -336.15), SIMDE_FLOAT32_C(  -966.61), SIMDE_FLOAT32_C(   670.20),
        SIMDE_FLOAT32_C(   783.55), SIMDE_FLOAT32_C(   477.19), SIMDE_FLOAT32_C(  -864.95), SIMDE_FLOAT32_C(  -372.20),
        SIMDE_FLOAT32_C(   -94.30), SIMDE_FLOAT32_C(  -879.40), SIMDE_FLOAT32_C(  -161.82), SIMDE_FLOAT32_C(   100.12),
        SIMDE_FLOAT32_C(   850.32), SIMDE_FLOAT32_C(   476.49), SIMDE_FLOAT32_C(  -174.44), SIMDE_FLOAT32_C(   934.13) },
      { SIMDE_FLOAT32_C(   404.40), SIMDE_FLOAT32_C(  -570.57), SIMDE_FLOAT32_C(   -86.01), SIMDE_FLOAT32_C(   670.20),
        SIMDE_FLOAT32_C(   312.45), SIMDE_FLOAT32_C(   381.45), SIMDE_FLOAT32_C(  -864.95), SIMDE_FLOAT32_C(  -372.20),
        SIMDE_FLOAT32_C(   -94.30), SIMDE_FLOAT32_C(  -879.40), SIMDE_FLOAT32_C(  -161.82), SIMDE_FLOAT32_C(   100.12),
        SIMDE_FLOAT32_C(   850.32), SIMDE_FLOAT32_C(   386.54), SIMDE_FLOAT32_C(   295.11), SIMDE_FLOAT32_C(  -992.52) },
      UINT16_C( 8136) },
    { { SIMDE_FLOAT32_C(   877.31), SIMDE_FLOAT32_C(   884.47), SIMDE_FLOAT32_C(  -380.38), SIMDE_FLOAT32_C(  -700.84),
        SIMDE_FLOAT32_C(   945.89), SIMDE_FLOAT32_C(   280.68), SIMDE_FLOAT32_C(   832.06), SIMDE_FLOAT32_C(   359.22),
        SIMDE_FLOAT32_C(   586.70), SIMDE_FLOAT32_C(   448.55), SIMDE_FLOAT32_C(   510.98), SIMDE_FLOAT32_C(  -325.00),
        SIMDE_FLOAT32_C(   847.13), SIMDE_FLOAT32_C(  -548.42), SIMDE_FLOAT32_C(  -663.23), SIMDE_FLOAT32_C(   110.33) },
      { SIMDE_FLOAT32_C(   877.31), SIMDE_FLOAT32_C(   884.47), SIMDE_FLOAT32_C(  -380.38), SIMDE_FLOAT32_C(  -700.84),
        SIMDE_FLOAT32_C(   945.89), SIMDE_FLOAT32_C(   280.68), SIMDE_FLOAT32_C(   832.06), SIMDE_FLOAT32_C(   359.22),
        SIMDE_FLOAT32_C(  -806.36), SIMDE_FLOAT32_C(  -673.67), SIMDE_FLOAT32_C(   510.98), SIMDE_FLOAT32_C(  -346.39),
        SIMDE_FLOAT32_C(   789.45), SIMDE_FLOAT32_C(  -548.42), SIMDE_FLOAT32_C(   989.10), SIMDE_FLOAT32_C(  -487.94) },
      UINT16_C( 9471) },
    { { SIMDE_FLOAT32_C(  -787.05), SIMDE_FLOAT32_C(   806.72), SIMDE_FLOAT32_C(   520.29), SIMDE_FLOAT32_C(  -321.05),
        SIMDE_FLOAT32_C(  -366.95), SIMDE_FLOAT32_C(  -748.89), SIMDE_FLOAT32_C(   687.71), SIMDE_FLOAT32_C(  -416.88),
        SIMDE_FLOAT32_C(  -561.92), SIMDE_FLOAT32_C(  -926.01), SIMDE_FLOAT32_C(   843.79), SIMDE_FLOAT32_C(   849.56),
        SIMDE_FLOAT32_C(   -51.86), SIMDE_FLOAT32_C(  -481.78), SIMDE_FLOAT32_C(   491.33), SIMDE_FLOAT32_C(  -936.26) },
      { SIMDE_FLOAT32_C(  -787.05), SIMDE_FLOAT32_C(   806.72), SIMDE_FLOAT32_C(   299.54), SIMDE_FLOAT32_C(   884.74),
        SIMDE_FLOAT32_C(  -278.71), SIMDE_FLOAT32_C(  -748.89), SIMDE_FLOAT32_C(   570.30), SIMDE_FLOAT32_C(  -416.88),
        SIMDE_FLOAT32_C(  -561.92), SIMDE_FLOAT32_C(    59.09), SIMDE_FLOAT32_C(   843.79), SIMDE_FLOAT32_C(   849.56),
        SIMDE_FLOAT32_C(  -136.84), SIMDE_FLOAT32_C(  -481.78), SIMDE_FLOAT32_C(   491.33), SIMDE_FLOAT32_C(  -936.26) },
      UINT16_C(60835) },
    { { SIMDE_FLOAT32_C(  -837.49), SIMDE_FLOAT32_C(   -79.02), SIMDE_FLOAT32_C(  -844.39), SIMDE_FLOAT32_C(  -973.47),
        SIMDE_FLOAT32_C(  -499.80), SIMDE_FLOAT32_C(   961.14), SIMDE_FLOAT32_C(   336.59), SIMDE_FLOAT32_C(  -368.95),
        SIMDE_FLOAT32_C(   727.99), SIMDE_FLOAT32_C(  -900.81), SIMDE_FLOAT32_C(   655.07), SIMDE_FLOAT32_C(  -624.42),
        SIMDE_FLOAT32_C(   244.09), SIMDE_FLOAT32_C(   360.96), SIMDE_FLOAT32_C(  -837.70), SIMDE_FLOAT32_C(  -929.19) },
      { SIMDE_FLOAT32_C(  -837.49), SIMDE_FLOAT32_C(   -79.02), SIMDE_FLOAT32_C(  -169.54), SIMDE_FLOAT32_C(   100.98),
        SIMDE_FLOAT32_C(  -499.80), SIMDE_FLOAT32_C(   961.14), SIMDE_FLOAT32_C(  -254.87), SIMDE_FLOAT32_C(   592.42),
        SIMDE_FLOAT32_C(   312.40), SIMDE_FLOAT32_C(   958.12), SIMDE_FLOAT32_C(  -284.13), SIMDE_FLOAT32_C(  -624.42),
        SIMDE_FLOAT32_C(  -196.30), SIMDE_FLOAT32_C(   360.96), SIMDE_FLOAT32_C(  -837.70), SIMDE_FLOAT32_C(  -975.45) },
      UINT16_C(26675) },
    { { SIMDE_FLOAT32_C(   928.69), SIMDE_FLOAT32_C(    -3.95), SIMDE_FLOAT32_C(  -214.33), SIMDE_FLOAT32_C(  -971.80),
        SIMDE_FLOAT32_C(  -780.70), SIMDE_FLOAT32_C(   950.39), SIMDE_FLOAT32_C(  -857.68), SIMDE_FLOAT32_C(  -246.08),
        SIMDE_FLOAT32_C(   789.62), SIMDE_FLOAT32_C(  -840.89), SIMDE_FLOAT32_C(   194.42), SIMDE_FLOAT32_C(  -873.48),
        SIMDE_FLOAT32_C(  -365.78), SIMDE_FLOAT32_C(  -117.81), SIMDE_FLOAT32_C(   601.86), SIMDE_FLOAT32_C(   913.26) },
      { SIMDE_FLOAT32_C(   928.69), SIMDE_FLOAT32_C(    -3.95), SIMDE_FLOAT32_C(  -214.33), SIMDE_FLOAT32_C(   377.34),
        SIMDE_FLOAT32_C(  -525.21), SIMDE_FLOAT32_C(  -436.16), SIMDE_FLOAT32_C(   186.25), SIMDE_FLOAT32_C(  -246.08),
        SIMDE_FLOAT32_C(   623.36), SIMDE_FLOAT32_C(  -840.89), SIMDE_FLOAT32_C(   194.42), SIMDE_FLOAT32_C(  -873.48),
        SIMDE_FLOAT32_C(  -679.52), SIMDE_FLOAT32_C(   447.41), SIMDE_FLOAT32_C(  -608.79), SIMDE_FLOAT32_C(   721.43) },
      UINT16_C( 3719) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__mmask16 r = simde_mm512_cmpeq_ps_mask(a, b);
    simde_assert_mmask16(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_cmpeq_pd_mask (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde__mmask8 r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   271.69), SIMDE_FLOAT64_C(   217.70), SIMDE_FLOAT64_C(   925.72), SIMDE_FLOAT64_C(   520.03),
        SIMDE_FLOAT64_C(   127.68), SIMDE_FLOAT64_C(   -63.68), SIMDE_FLOAT64_C(  -338.02), SIMDE_FLOAT64_C(   823.86) },
      { SIMDE_FLOAT64_C(   690.45), SIMDE_FLOAT64_C(   347.44), SIMDE_FLOAT64_C(  -649.53), SIMDE_FLOAT64_C(  -641.60),
        SIMDE_FLOAT64_C(   658.05), SIMDE_FLOAT64_C(  -212.84), SIMDE_FLOAT64_C(   796.21), SIMDE_FLOAT64_C(   -36.15) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(   417.99), SIMDE_FLOAT64_C(  -883.29), SIMDE_FLOAT64_C(   571.34), SIMDE_FLOAT64_C(   535.08),
        SIMDE_FLOAT64_C(  -923.74), SIMDE_FLOAT64_C(   773.69), SIMDE_FLOAT64_C(  -589.26), SIMDE_FLOAT64_C(   350.94) },
      { SIMDE_FLOAT64_C(   179.83), SIMDE_FLOAT64_C(   445.85), SIMDE_FLOAT64_C(  -677.60), SIMDE_FLOAT64_C(  -480.10),
        SIMDE_FLOAT64_C(  -974.87), SIMDE_FLOAT64_C(  -558.93), SIMDE_FLOAT64_C(    47.77), SIMDE_FLOAT64_C(   924.57) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -695.12), SIMDE_FLOAT64_C(  -819.01), SIMDE_FLOAT64_C(   861.37), SIMDE_FLOAT64_C(  -968.92),
        SIMDE_FLOAT64_C(  -642.09), SIMDE_FLOAT64_C(   475.36), SIMDE_FLOAT64_C(  -653.40), SIMDE_FLOAT64_C(   274.91) },
      { SIMDE_FLOAT64_C(   408.72), SIMDE_FLOAT64_C(  -646.21), SIMDE_FLOAT64_C(  -843.45), SIMDE_FLOAT64_C(   107.84),
        SIMDE_FLOAT64_C(   465.38), SIMDE_FLOAT64_C(  -336.34), SIMDE_FLOAT64_C(  -820.42), SIMDE_FLOAT64_C(  -749.33) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(    -9.72), SIMDE_FLOAT64_C(   643.44), SIMDE_FLOAT64_C(   336.27), SIMDE_FLOAT64_C(  -313.97),
        SIMDE_FLOAT64_C(  -863.83), SIMDE_FLOAT64_C(  -448.10), SIMDE_FLOAT64_C(   771.84), SIMDE_FLOAT64_C(   249.27) },
      { SIMDE_FLOAT64_C(  -506.33), SIMDE_FLOAT64_C(    28.98), SIMDE_FLOAT64_C(  -919.42), SIMDE_FLOAT64_C(  -710.08),
        SIMDE_FLOAT64_C(  -376.38), SIMDE_FLOAT64_C(   181.22), SIMDE_FLOAT64_C(  -315.61), SIMDE_FLOAT64_C(  -521.71) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -309.90), SIMDE_FLOAT64_C(  -566.85), SIMDE_FLOAT64_C(   953.96), SIMDE_FLOAT64_C(  -760.71),
        SIMDE_FLOAT64_C(   715.80), SIMDE_FLOAT64_C(   511.82), SIMDE_FLOAT64_C(   185.57), SIMDE_FLOAT64_C(   958.96) },
      { SIMDE_FLOAT64_C(  -823.31), SIMDE_FLOAT64_C(   653.67), SIMDE_FLOAT64_C(   300.89), SIMDE_FLOAT64_C(  -999.35),
        SIMDE_FLOAT64_C(  -123.69), SIMDE_FLOAT64_C(  -935.82), SIMDE_FLOAT64_C(  -283.75), SIMDE_FLOAT64_C(  -911.67) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -370.17), SIMDE_FLOAT64_C(   581.24), SIMDE_FLOAT64_C(   903.15), SIMDE_FLOAT64_C(  -702.97),
        SIMDE_FLOAT64_C(  -784.81), SIMDE_FLOAT64_C(  -282.51), SIMDE_FLOAT64_C(  -162.91), SIMDE_FLOAT64_C(   -67.74) },
      { SIMDE_FLOAT64_C(  -458.51), SIMDE_FLOAT64_C(  -138.00), SIMDE_FLOAT64_C(   634.22), SIMDE_FLOAT64_C(  -641.32),
        SIMDE_FLOAT64_C(  -700.95), SIMDE_FLOAT64_C(  -830.62), SIMDE_FLOAT64_C(  -270.15), SIMDE_FLOAT64_C(  -342.52) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(  -741.30), SIMDE_FLOAT64_C(  -961.63), SIMDE_FLOAT64_C(  -159.42), SIMDE_FLOAT64_C(   596.72),
        SIMDE_FLOAT64_C(  -872.26), SIMDE_FLOAT64_C(   -77.79), SIMDE_FLOAT64_C(   608.69), SIMDE_FLOAT64_C(   181.91) },
      { SIMDE_FLOAT64_C(  -693.78), SIMDE_FLOAT64_C(  -430.90), SIMDE_FLOAT64_C(  -141.87), SIMDE_FLOAT64_C(  -384.25),
        SIMDE_FLOAT64_C(   -74.70), SIMDE_FLOAT64_C(   434.70), SIMDE_FLOAT64_C(    -4.99), SIMDE_FLOAT64_C(   104.05) },
      UINT8_C(  0) },
    { { SIMDE_FLOAT64_C(   817.79), SIMDE_FLOAT64_C(   652.33), SIMDE_FLOAT64_C(  -345.32), SIMDE_FLOAT64_C(   150.71),
        SIMDE_FLOAT64_C(   939.32), SIMDE_FLOAT64_C(  -867.25), SIMDE_FLOAT64_C(   158.96), SIMDE_FLOAT64_C(  -396.12) },
      { SIMDE_FLOAT64_C(   363.34), SIMDE_FLOAT64_C(   571.53), SIMDE_FLOAT64_C(  -232.25), SIMDE_FLOAT64_C(   496.58),
        SIMDE_FLOAT64_C(    40.81), SIMDE_FLOAT64_C(   -69.57), SIMDE_FLOAT64_C(   792.81), SIMDE_FLOAT64_C(   833.83) },
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__mmask8 r = simde_mm512_cmpeq_pd_mask(a, b);
    simde_assert_mmask8(r, ==, test_vec[i].r);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_GCC_96174) */

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi8_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_epi64_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_cmpeq_epi64_mask)
  #if !defined(SIMDE_BUG_GCC_96174)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_ps_mask)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_cmpeq_pd_mask)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
