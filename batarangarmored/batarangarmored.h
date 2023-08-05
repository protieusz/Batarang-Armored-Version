#ifndef batarangarmored_h
#define batarangarmored_h
#endif

#pragma once

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004,                 K008, K009, K010, K011, K012, \
	K100, K101, K102, K103, K104,                 K108, K109, K110, K111, K112, \
	K200, K201, K202, K203, K204, K205,      K207,K208, K209, K210, K211, K212, \
	            K302, K303, K304,      K306,      K308, K309, K310              \
) { \
	{ K000,  K001,  K002,  K003,  K004,  KC_NO, KC_NO, KC_NO, K008,  K009,  K010, K011, K012 }, \
	{ K100,  K101,  K102,  K103,  K104,  KC_NO, KC_NO, KC_NO, K108,  K109,  K110, K111, K112 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  KC_NO, K207,  K208,  K209,  K210, K211, K212 }, \
	{ KC_NO, KC_NO, K302,  K303,  K304,  KC_NO, K306,  KC_NO, K308,  K309,  K310 }  \
}
