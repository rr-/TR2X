#define FRAMES_PER_SECOND 30
#define TICKS_PER_FRAME 2

#define PHD_ONE 0x10000
#define PHD_HALF 0x100
#define PHD_DEGREE (PHD_ONE / 360) // = 182
#define PHD_360 (PHD_ONE) // = 65536 = 0x10000
#define PHD_180 (PHD_ONE / 2) // = 32768 = 0x8000
#define PHD_90 (PHD_ONE / 4) // = 16384 = 0x4000
#define PHD_45 (PHD_ONE / 8) // = 8192 = 0x2000
#define PHD_135 (PHD_45 * 3) // = 24576 = 0x6000

#define CLASS_NAME "Dude:TombRaiderII:DDWndClass"
#define WINDOW_NAME "Tomb Raider II"

#define W2V_SHIFT 14
#define WALL_L 1024
#define WALL_SHIFT 10
#define STEP_L (WALL_L / 4)
#define NO_HEIGHT (-32512)
#define NO_BAD_POS (-NO_HEIGHT) // = 32512
#define NO_BAD_NEG (NO_HEIGHT) // = -32512
#define BAD_JUMP_CEILING ((STEP_L * 3) / 4) // = 192
#define STEPUP_HEIGHT ((STEP_L * 3) / 2) // = 384
#define SLOPE_DIF 60
#define WIBBLE_SIZE 32

#define GAME_FOV 80
#define MIN_SQUARE SQUARE(WALL_L / 3)
#define NO_BOX (-1)
#define NO_ITEM (-1)
#define NO_OBJECT (-1)
#define NO_ROOM (-1)
#define NO_CAMERA (-1)

#define GRAVITY 6

#define MAX_AUDIO_SAMPLE_BUFFERS 256
#define MAX_AUDIO_SAMPLE_TRACKS 32
#define MAX_TEXTURE_PAGES 32
#define MAX_VERTICES 0x2000

#define MAX_EFFECTS 100
#define MAX_PICKUPS 12

#define DAMAGE_START 140
#define DAMAGE_LENGTH 14

#define HEAD_TURN (2 * PHD_DEGREE) // = 364
#define MAX_HEAD_TILT (22 * PHD_DEGREE) // = 4004
#define MIN_HEAD_TILT (-42 * PHD_DEGREE) // = -7644
#define MAX_HEAD_ROTATION (44 * PHD_DEGREE) // = 8008
#define MIN_HEAD_ROTATION (-MAX_HEAD_ROTATION) // = -8008
#define HEAD_TURN_CAM (4 * PHD_DEGREE) // = 728
#define MAX_HEAD_TILT_CAM (85 * PHD_DEGREE) // = 15470
#define MIN_HEAD_TILT_CAM (-MAX_HEAD_TILT_CAM) // = -15470
#define MAX_HEAD_ROTATION_CAM (50 * PHD_DEGREE) // = 9100
#define MIN_HEAD_ROTATION_CAM (-MAX_HEAD_ROTATION_CAM) // = -9100
#define FAST_FALL_SPEED 128
#define LARA_TURN_UNDO (2 * PHD_DEGREE) // = 364
#define LARA_TURN_RATE ((PHD_DEGREE / 4) + LARA_TURN_UNDO) // = 409
#define LARA_TURN_RATE_UW (2 * PHD_DEGREE) // = 364
#define LARA_MED_TURN ((PHD_DEGREE * 4) + LARA_TURN_UNDO) // = 1092
#define LARA_SLOW_TURN ((PHD_DEGREE * 2) + LARA_TURN_UNDO) // = 728
#define LARA_SURF_TURN (LARA_SLOW_TURN / 2) // = 364
#define LARA_FAST_TURN ((PHD_DEGREE * 6) + LARA_TURN_UNDO) // = 1456
#define LARA_LEAN_UNDO PHD_DEGREE // = 182
#define LARA_LEAN_UNDO_SURF (LARA_LEAN_UNDO * 2) // = 364
#define LARA_LEAN_UNDO_UW LARA_LEAN_UNDO_SURF // = 364
#define LARA_LEAN_RATE 273
#define LARA_LEAN_RATE_SWIM (LARA_LEAN_RATE * 2) // = 546
#define LARA_LEAN_MAX ((10 * PHD_DEGREE) + LARA_LEAN_UNDO) // = 2002
#define LARA_LEAN_MAX_UW (LARA_LEAN_MAX * 2) // = 4004
#define LARA_JUMP_TURN ((PHD_DEGREE * 1) + LARA_TURN_UNDO) // = 546
#define LARA_FAST_FALL_SPEED (FAST_FALL_SPEED + 3) // = 131
#define LARA_MAX_SURF_SPEED 60
#define LARA_MAX_SWIM_SPEED 200
#define LARA_UW_FRICTION 6
#define LARA_CLIMB_WIDTH_LEFT 80
#define LARA_CLIMB_WIDTH_RIGHT 120
#define LARA_RADIUS 100
#define LARA_RADIUS_UW 300
#define LARA_HEIGHT 762
#define LARA_HEIGHT_SURF 700
#define LARA_HEIGHT_UW 400
#define LARA_CLIMB_HEIGHT (WALL_L / 2) // = 512
#define LARA_DEFLECT_ANGLE (5 * PHD_DEGREE) // = 910
#define LARA_HANG_ANGLE (35 * PHD_DEGREE) // = 6370
#define LARA_VAULT_ANGLE (30 * PHD_DEGREE) // = 5460
#define LARA_MAX_AIR 1800
#define LARA_MAX_HITPOINTS 1000

#define CAM_HANG_ANGLE 0
#define CAM_HANG_ELEVATION (-60 * PHD_DEGREE) // = -10920
#define CAM_REACH_ANGLE (85 * PHD_DEGREE) // = 15470
#define CAM_SLIDE_ELEVATION (-45 * PHD_DEGREE) // = -8190
#define CAM_BACK_JUMP_ANGLE (135 * PHD_DEGREE) // = 24570
#define CAM_PUSH_BLOCK_ANGLE (35 * PHD_DEGREE) // = 6370
#define CAM_PUSH_BLOCK_ELEVATION (-25 * PHD_DEGREE) // = -4550
#define CAM_PP_READY_ANGLE (75 * PHD_DEGREE) // = 13650
#define CAM_PICKUP_ANGLE (-130 * PHD_DEGREE) // = -23660
#define CAM_PICKUP_ELEVATION (-15 * PHD_DEGREE) // = -2730
#define CAM_PICKUP_DISTANCE WALL_L // = 1024
#define CAM_SWITCH_ON_ANGLE (80 * PHD_DEGREE) // = 14560
#define CAM_SWITCH_ON_ELEVATION (-25 * PHD_DEGREE) // = -4550
#define CAM_SWITCH_ON_DISTANCE WALL_L // = 1024
#define CAM_SWITCH_ON_SPEED 6
#define CAM_USE_KEY_ANGLE (-CAM_SWITCH_ON_ANGLE) // = -14560
#define CAM_USE_KEY_ELEVATION CAM_SWITCH_ON_ELEVATION // = -4550
#define CAM_USE_KEY_DISTANCE WALL_L // = 1024
#define CAM_SPECIAL_ANGLE (170 * PHD_DEGREE) // = 30940
#define CAM_SPECIAL_ELEVATION (-25 * PHD_DEGREE) // = -4550
#define CAM_WADE_ELEVATION (-22 * PHD_DEGREE) // = -4004
#define CAM_DEATH_SLIDE_ANGLE (70 * PHD_DEGREE) // = 12740
#define CAM_YETI_KILL_ANGLE (160 * PHD_DEGREE) // = 29120
#define CAM_YETI_KILL_DISTANCE (3 * WALL_L) // = 3072
#define CAM_SHARK_KILL_ANGLE (160 * PHD_DEGREE) // = 29120
#define CAM_SHARK_KILL_DISTANCE (3 * WALL_L) // = 3072
#define CAM_AIRLOCK_ANGLE (80 * PHD_DEGREE) // = 14560
#define CAM_AIRLOCK_ELEVATION (-25 * PHD_DEGREE) // = -4550
#define CAM_GONG_BONG_ANGLE (-25 * PHD_DEGREE) // = -4550
#define CAM_GONG_BONG_ELEVATION (-20 * PHD_DEGREE) // = -3640
#define CAM_GONG_BONG_DISTANCE (3 * WALL_L) // = 3072
#define CAM_DINO_KILL_ANGLE (170 * PHD_DEGREE) // = 30940
#define CAM_DINO_KILL_ELEVATION (-25 * PHD_DEGREE) // = -4550
#define CAM_CLIMB_LEFT_ANGLE (-30 * PHD_DEGREE) // = -5460
#define CAM_CLIMB_LEFT_ELEVATION (-15 * PHD_DEGREE) // = -2730
#define CAM_CLIMB_RIGHT_ANGLE (-CAM_CLIMB_LEFT_ANGLE) // = 5460
#define CAM_CLIMB_RIGHT_ELEVATION CAM_CLIMB_LEFT_ELEVATION // = -2730
#define CAM_CLIMB_STANCE_ELEVATION (-20 * PHD_DEGREE) // = -3640
#define CAM_CLIMBING_ELEVATION (30 * PHD_DEGREE) // = 5460
#define CAM_CLIMB_END_ELEVATION (-45 * PHD_DEGREE) // = -8190
#define CAM_CLIMB_DOWN_ELEVATION CAM_CLIMB_END_ELEVATION // = -8190

#define SW_DETAIL_LOW (0 * WALL_L << W2V_SHIFT) // = 0
#define SW_DETAIL_MEDIUM (3 * WALL_L << W2V_SHIFT) // = 50331648
#define SW_DETAIL_HIGH (6 * WALL_L << W2V_SHIFT) // = 100663296
#define SW_DETAIL_ULTRA (20 * WALL_L << W2V_SHIFT) // = 335544320

#define VIEW_NEAR (20 * 1) // = 20
#define VIEW_FAR (20 * WALL_L) // = 20480

#define FOG_START (12 * WALL_L) // = 12288
#define FOG_END (20 * WALL_L) // = 20480

#define NUM_SLOTS 5
#define DONT_TARGET (-16384)
#define PITCH_SHIFT 4
#define DATA_TYPE 0x00FF
#define TARGET_DIST (WALL_L * 4) // = 4096

#define IDS_DX5_REQUIRED 1
