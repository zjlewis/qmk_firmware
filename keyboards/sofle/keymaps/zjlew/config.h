// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define ENCODER_DIRECTION_FLIP


#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_SLEEP // turn off effects when suspended
#define RGB_MATRIX_LED_FLUSH_LIMIT 33 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 125 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 5
#define RGB_MATRIX_SPD_STEP 10


#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_RIVERFLOW

#endif //RGB_MATRIX_ENABLE
