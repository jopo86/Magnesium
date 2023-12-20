#pragma once

#if defined(__LP64__) || defined(_LP64) || defined(__amd64__) || defined(__x86_64__) || defined(_M_X64) || defined(__ia64__) || defined(_M_IA64) || defined(__aarch64__) || defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(__mips64__) || defined(__mips64) || defined(__mips64) || defined(__sparc64__) || defined(__arch64__)
	#define MG_ARCH_64
#elif defined(__i386__) || defined(_M_IX86) || defined(__arm__) || defined(__mips__) || defined(__mips) || defined(__sparc__) || defined(__PPC__) || defined(__ppc__) || defined(__powerpc__) || defined(__powerpc) || defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64) || defined(__PPC64) || defined(__mip) || defined(__mips) || defined(__mips__)
	#define MG_ARCH_32
#else
	#define MG_ARCH_UNKNOWN
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
	#define MG_OS_WINDOWS
#elif defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
	#define MG_OS_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
	#define MG_OS_MAC
#else
	#define MG_OS_UNKNOWN
#endif

#ifdef MG_ARCH_64
	#define MG_BUFFER_SIZE 1024
#elif defined(MG_ARCH_32)
	#define MG_BUFFER_SIZE 512
#else
	#define MG_BUFFER_SIZE 256
#endif

#define MG_VERTEX_FORMAT_V 400
#define MG_VERTEX_FORMAT_VC 401
#define MG_VERTEX_FORMAT_CV 402
#define MG_VERTEX_FORMAT_VT 403
#define MG_VERTEX_FORMAT_TV 404
#define MG_VERTEX_FORMAT_VCT 405
#define MG_VERTEX_FORMAT_VTC 406
#define MG_VERTEX_FORMAT_CVT 407
#define MG_VERTEX_FORMAT_TVC 408
#define MG_VERTEX_FORMAT_CTV 409
#define MG_VERTEX_FORMAT_TCV 410

#define MG_UNIT_LINES 411;
#define MG_UNIT_TRIANGLES 412;

#define MG_KEY_UNKNOWN -1
#define MG_KEY_SPACE 32
#define MG_KEY_APOSTROPHE 39
#define MG_KEY_COMMA 44
#define MG_KEY_MINUS 45
#define MG_KEY_PERIOD 46
#define MG_KEY_SLASH 47
#define MG_KEY_0 48
#define MG_KEY_1 49
#define MG_KEY_2 50
#define MG_KEY_3 51
#define MG_KEY_4 52
#define MG_KEY_5 53
#define MG_KEY_6 54
#define MG_KEY_7 55
#define MG_KEY_8 56
#define MG_KEY_9 57
#define MG_KEY_SEMICOLON 59
#define MG_KEY_EQUAL 61
#define MG_KEY_A 65
#define MG_KEY_B 66
#define MG_KEY_C 67
#define MG_KEY_D 68
#define MG_KEY_E 69
#define MG_KEY_F 70
#define MG_KEY_G 71
#define MG_KEY_H 72
#define MG_KEY_I 73
#define MG_KEY_J 74
#define MG_KEY_K 75
#define MG_KEY_L 76
#define MG_KEY_M 77
#define MG_KEY_N 78
#define MG_KEY_O 79
#define MG_KEY_P 80
#define MG_KEY_Q 81
#define MG_KEY_R 82
#define MG_KEY_S 83
#define MG_KEY_T 84
#define MG_KEY_U 85
#define MG_KEY_V 86
#define MG_KEY_W 87
#define MG_KEY_X 88
#define MG_KEY_Y 89
#define MG_KEY_Z 90
#define MG_KEY_LEFT_BRACKET 91
#define MG_KEY_BACKSLASH 92
#define MG_KEY_RIGHT_BRACKET 93
#define MG_KEY_GRAVE_ACCENT 96
#define MG_KEY_WORLD_1 161
#define MG_KEY_WORLD_2 162
#define MG_KEY_ESCAPE 256
#define MG_KEY_ENTER 257
#define MG_KEY_TAB 258
#define MG_KEY_BACKSPACE 259
#define MG_KEY_INSERT 260
#define MG_KEY_DELETE 261
#define MG_KEY_RIGHT 262
#define MG_KEY_LEFT 263
#define MG_KEY_DOWN 264
#define MG_KEY_UP 265
#define MG_KEY_PAGE_UP 266
#define MG_KEY_PAGE_DOWN 267
#define MG_KEY_HOME 268
#define MG_KEY_END 269
#define MG_KEY_CAPS_LOCK 280
#define MG_KEY_SCROLL_LOCK 281
#define MG_KEY_NUM_LOCK 282
#define MG_KEY_PRINT_SCREEN 283
#define MG_KEY_PAUSE 284
#define MG_KEY_F1 290
#define MG_KEY_F2 291
#define MG_KEY_F3 292
#define MG_KEY_F4 293
#define MG_KEY_F5 294
#define MG_KEY_F6 295
#define MG_KEY_F7 296
#define MG_KEY_F8 297
#define MG_KEY_F9 298
#define MG_KEY_F10 299
#define MG_KEY_F11 300
#define MG_KEY_F12 301
#define MG_KEY_F13 302
#define MG_KEY_F14 303
#define MG_KEY_F15 304
#define MG_KEY_F16 305
#define MG_KEY_F17 306
#define MG_KEY_F18 307
#define MG_KEY_F19 308
#define MG_KEY_F20 309
#define MG_KEY_F21 310
#define MG_KEY_F22 311
#define MG_KEY_F23 312
#define MG_KEY_F24 313
#define MG_KEY_F25 314
#define MG_KEY_NUMPAD_0 320
#define MG_KEY_NUMPAD_1 321
#define MG_KEY_NUMPAD_2 322
#define MG_KEY_NUMPAD_3 323
#define MG_KEY_NUMPAD_4 324
#define MG_KEY_NUMPAD_5 325
#define MG_KEY_NUMPAD_6 326
#define MG_KEY_NUMPAD_7 327
#define MG_KEY_NUMPAD_8 328
#define MG_KEY_NUMPAD_9 329
#define MG_KEY_NUMPAD_DECIMAL 330
#define MG_KEY_NUMPAD_DIVIDE 331
#define MG_KEY_NUMPAD_MULTIPLY 332
#define MG_KEY_NUMPAD_SUBTRACT 333
#define MG_KEY_NUMPAD_ADD 334
#define MG_KEY_NUMPAD_ENTER 335
#define MG_KEY_NUMPAD_EQUAL 336
#define MG_KEY_LEFT_SHIFT 340
#define MG_KEY_LEFT_CONTROL 341
#define MG_KEY_LEFT_ALT 342
#define MG_KEY_LEFT_SUPER 343
#define MG_KEY_RIGHT_SHIFT 344
#define MG_KEY_RIGHT_CONTROL 345
#define MG_KEY_RIGHT_ALT 346
#define MG_KEY_RIGHT_SUPER 347
#define MG_KEY_MENU 348
#define MG_MAX_KEY MG_KEY_MENU

typedef char byte;
typedef unsigned char ubyte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;

