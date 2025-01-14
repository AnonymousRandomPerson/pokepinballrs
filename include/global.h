#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "gba/gba.h"

#define NUM_SPRITE_GROUPS 100
#define MAX_SPRITES_IN_GROUP 22

#include "types.h"
#include "functions.h"
#include "variables.h"

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")
#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided")
#define NAKED __attribute__((naked))

// IDE support
#if defined (__APPLE__) || defined (__CYGWIN__) || defined (_MSC_VER)
#define _(x) x
#define __(x) x
#define INCBIN_U8 {0}
#define INCBIN_U16 {0}
#define INCBIN_U32 {0}
#define INCBIN_S8 {0}
#define INCBIN_S16 {0}
#define INCBIN_S32 {0}
#endif // IDE support

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

// useful math macros

// Converts a number to Q8.8 fixed-point format
#define Q_8_8(n) ((s16)((n) * 256))

// Converts a number to Q4.12 fixed-point format
#define Q_4_12(n)  ((s16)((n) * 4096))

// Converts a number to Q24.8 fixed-point format
#define Q_24_8(n)  ((s32)((n) * 256))

// Converts a Q8.8 fixed-point format number to a regular integer
#define Q_8_8_TO_INT(n) ((int)((n) / 256))

// Converts a Q4.12 fixed-point format number to a regular integer
#define Q_4_12_TO_INT(n)  ((int)((n) / 4096))

// Converts a Q24.8 fixed-point format number to a regular integer
#define Q_24_8_TO_INT(n) ((int)((n) >> 8))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))

enum
{
    STATE_INTRO,
    STATE_TITLE,
    STATE_GAME_MAIN,
    STATE_GAME_IDLE,
    STATE_OPTIONS,
    STATE_POKEDEX,
    STATE_UNKNOWN6,
    STATE_EREADER,
    STATE_SCORES_MAIN,
    STATE_SCORES_IDLE,
    STATE_FIELD_SELECT,
    STATE_BONUS_FIELD_SELECT,
};

struct PinballGame
{
	/*0x000*/ u8 filler0[0x13];
	/*0x013*/ s8 unk13;
	/*0x014*/ u8 filler14[0x11];
	/*0x025*/ s8 unk25;
	/*0x026*/ u16 unk26;
	/*0x028*/ u16 unk28;
	/*0x02A*/ u8 filler2A[0xB];
	/*0x035*/ s8 area;
	/*0x036*/ u8 filler36[0x6];
	/*0x03C*/ u32 unk3C;
	/*0x040*/ u8 filler40[0x28];
	/*0x068*/ s16 unk68;
	/*0x06A*/ u8 filler6A[0xC1];
	/*0x12B*/ s8 unk12B;
	/*0x12C*/ s8 unk12C;
	/*0x12D*/ u8 filler12D;
	/*0x12E*/ s16 unk12E;
	/*0x130*/ s16 unk130[8];
	/*0x140*/ u8 filler140[0x54];
	/*0x194*/ s8 unk194;
	/*0x195*/ u8 filler195[0x25];
	/*0x1BA*/ u16 unk1BA;
	/*0x1BC*/ u8 filler1BC[0x1C];
	/*0x1D8*/ u16 unk1D8;
	/*0x1DA*/ u16 unk1DA;
	/*0x1DC*/ u8 filler1DC[0x9];
	/*0x1E5*/ u8 unk1E5;
	/*0x1E6*/ u8 unk1E6;
	/*0x1E7*/ u8 filler1E7[0xB5];
	/*0x29C*/ u16 unk29C;
	/*0x29E*/ u8 filler29E[0xA6];
	/*0x344*/ u32 unk344;
	/*0x348*/ u8 filler348[0x250];
	/*0x598*/ u16 unk598; // Current catch/hatch mode species? Is it evo mode as well?
	/*0x59A*/ u8 filler59A[0x2];
	/*0x59C*/ u16 unk59C; // Previous catch mode species?
	/*0x59E*/ u16 unk59E; // Previous hatch mode species?
	/*0x5A0*/ u8 filler5A0[0x50];
	/*0x5F0*/ u16 unk5F0;
	/*0x5F2*/ u8 filler5F2[0x5];
	/*0x5F7*/ u8 unk5F7;
	/*0x5F8*/ u8 filler5F8[0x8];
	/*0x600*/ u16 unk600;
	/*0x602*/ u8 filler602[0x126];
	/*0x728*/ u8 unk728; // TODO: unknown type
	/*0x729*/ u8 filler729[0x14];
	/*0x73D*/ s8 unk73D;
};

struct Unk02031520
{
	/*0x0*/ u8 filler0[0x8];
	/*0x8*/ s16 unk8;
};

extern struct PinballGame *gUnknown_020314E0;
extern struct Unk02031520 gUnknown_02031520;

#endif // GUARD_GLOBAL_H
