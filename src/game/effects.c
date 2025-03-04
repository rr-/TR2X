#include "game/effects.h"

#include "game/matrix.h"
#include "game/output.h"
#include "global/const.h"
#include "global/funcs.h"
#include "global/vars.h"

static void Effect_RemoveActive(const int16_t fx_num);
static void Effect_RemoveDrawn(const int16_t fx_num);

static void Effect_RemoveActive(const int16_t fx_num)
{
    FX_INFO *const fx = &g_Effects[fx_num];
    int16_t link_num = g_NextEffectActive;
    if (link_num == fx_num) {
        g_NextEffectActive = fx->next_active;
        return;
    }

    while (link_num != NO_ITEM) {
        if (g_Effects[link_num].next_active == fx_num) {
            g_Effects[link_num].next_active = fx->next_active;
            return;
        }
        link_num = g_Effects[link_num].next_active;
    }
}

static void Effect_RemoveDrawn(const int16_t fx_num)
{
    FX_INFO *const fx = &g_Effects[fx_num];
    int16_t link_num = g_Rooms[fx->room_num].fx_num;
    if (link_num == fx_num) {
        g_Rooms[fx->room_num].fx_num = fx->next_fx;
        return;
    }

    while (link_num != NO_ITEM) {
        if (g_Effects[link_num].next_fx == fx_num) {
            g_Effects[link_num].next_fx = fx->next_fx;
            return;
        }
        link_num = g_Effects[link_num].next_fx;
    }
}

void __cdecl Effect_InitialiseArray(void)
{
    g_NextEffectFree = 0;
    g_NextEffectActive = NO_ITEM;

    for (int32_t i = 0; i < MAX_EFFECTS - 1; i++) {
        FX_INFO *const fx = &g_Effects[i];
        fx->next_fx = i + 1;
    }
    g_Effects[MAX_EFFECTS - 1].next_fx = NO_ITEM;
}

int16_t __cdecl Effect_Create(const int16_t room_num)
{
    int16_t fx_num = g_NextEffectFree;
    if (fx_num == NO_ITEM) {
        return NO_ITEM;
    }

    FX_INFO *const fx = &g_Effects[fx_num];
    g_NextEffectFree = fx->next_fx;

    ROOM_INFO *const room = &g_Rooms[room_num];
    fx->room_num = room_num;
    fx->next_fx = room->fx_num;
    room->fx_num = fx_num;

    fx->next_active = g_NextEffectActive;
    g_NextEffectActive = fx_num;

    fx->shade = 0x1000;

    return fx_num;
}

void __cdecl Effect_Kill(const int16_t fx_num)
{
    FX_INFO *const fx = &g_Effects[fx_num];
    Effect_RemoveActive(fx_num);
    Effect_RemoveDrawn(fx_num);

    fx->next_fx = g_NextEffectFree;
    g_NextEffectFree = fx_num;
}

void __cdecl Effect_NewRoom(const int16_t fx_num, const int16_t room_num)
{
    FX_INFO *const fx = &g_Effects[fx_num];
    ROOM_INFO *room = &g_Rooms[fx->room_num];

    int16_t link_num = room->fx_num;
    if (link_num == fx_num) {
        room->fx_num = fx->next_fx;
    } else {
        while (link_num != NO_ITEM) {
            if (g_Effects[link_num].next_fx == fx_num) {
                g_Effects[link_num].next_fx = fx->next_fx;
                break;
            }
            link_num = g_Effects[link_num].next_fx;
        }
    }

    fx->room_num = room_num;
    room = &g_Rooms[room_num];
    fx->next_fx = room->fx_num;
    room->fx_num = fx_num;
}

void __cdecl Effect_Draw(const int16_t fx_num)
{
    const FX_INFO *const fx = &g_Effects[fx_num];
    const OBJECT_INFO *const object = &g_Objects[fx->object_num];
    if (!object->loaded) {
        return;
    }

    if (fx->object_num == O_GLOW) {
        Output_DrawSprite(
            (fx->rot.y << 16) | (unsigned __int16)fx->rot.x, fx->pos.x,
            fx->pos.y, fx->pos.z, g_Objects[O_GLOW].mesh_idx, fx->shade,
            fx->frame_num);
        return;
    }

    if (object->mesh_count < 0) {
        Output_DrawSprite(
            SPRITE_ABS | (object->semi_transparent ? SPRITE_SEMITRANS : 0)
                | SPRITE_SHADE,
            fx->pos.x, fx->pos.y, fx->pos.z, object->mesh_idx - fx->frame_num,
            fx->shade, 0);
        return;
    }

    Matrix_Push();
    Matrix_TranslateAbs(fx->pos.x, fx->pos.y, fx->pos.z);
    if (g_MatrixPtr->_23 > g_PhdNearZ && g_MatrixPtr->_23 < g_PhdFarZ) {
        Matrix_RotYXZ(fx->rot.y, fx->rot.x, fx->rot.z);
        if (object->mesh_count) {
            S_CalculateStaticLight(fx->shade);
            Output_InsertPolygons(g_Meshes[object->mesh_idx], -1);
        } else {
            S_CalculateStaticLight(fx->shade);
            Output_InsertPolygons(g_Meshes[fx->frame_num], -1);
        }
    }
    Matrix_Pop();
}
