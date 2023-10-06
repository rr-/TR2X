#define PHD_ONE 0x10000
#define PHD_DEGREE (PHD_ONE / 360) // = 182
#define PHD_360 (PHD_ONE) // = 65536 = 0x10000
#define PHD_180 (PHD_ONE / 2) // = 32768 = 0x8000
#define PHD_90 (PHD_ONE / 4) // = 16384 = 0x4000
#define PHD_45 (PHD_ONE / 8) // = 8192 = 0x2000
#define PHD_135 (PHD_45 * 3) // = 24576 = 0x6000

#define W2V_SHIFT 14
#define WALL_L 1024
#define WALL_SHIFT 10
#define STEP_L (WALL_L / 4)
#define GAME_FOV 80
#define MIN_SQUARE SQUARE(WALL_L / 3)
#define NO_BOX (-1)
#define NO_ITEM (-1)
#define NO_CAMERA (-1)
#define HEAD_TURN (4 * PHD_DEGREE) // = 728
#define MAX_HEAD_ROTATION (50 * PHD_DEGREE) // = 9100
#define MIN_HEAD_ROTATION (-MAX_HEAD_ROTATION) // = -9100
#define MAX_HEAD_TILT_CAM (85 * PHD_DEGREE) // = 15470
#define MIN_HEAD_TILT_CAM (-MAX_HEAD_TILT_CAM) // = -15470

#define MAX_AUDIO_SAMPLE_BUFFERS 256
#define MAX_AUDIO_SAMPLE_TRACKS 32

#define FAST_FALL_SPEED 128
#define LARA_TURN_UNDO (2 * PHD_DEGREE) // = 364
#define LARA_TURN_RATE ((PHD_DEGREE / 4) + LARA_TURN_UNDO) // = 409
#define LARA_MED_TURN ((PHD_DEGREE * 4) + LARA_TURN_UNDO) // = 1092
#define LARA_SLOW_TURN ((PHD_DEGREE * 2) + LARA_TURN_UNDO) // = 728
#define LARA_FAST_TURN ((PHD_DEGREE * 6) + LARA_TURN_UNDO) // = 1456
#define LARA_LEAN_UNDO PHD_DEGREE
#define LARA_LEAN_RATE 273
#define LARA_LEAN_MAX ((10 * PHD_DEGREE) + LARA_LEAN_UNDO) // = 2002
#define LARA_JUMP_TURN ((PHD_DEGREE * 1) + LARA_TURN_UNDO) // = 546
#define LARA_FAST_FALL_SPEED (FAST_FALL_SPEED + 3) // = 131

#define DAMAGE_START 140
#define DAMAGE_LENGTH 14
