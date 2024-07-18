#include "game/objects/general/door.h"

#include "game/lara/lara_misc.h"
#include "global/funcs.h"
#include "global/vars.h"

void __cdecl Door_Collision(
    const int16_t item_num, ITEM_INFO *const lara_item, COLL_INFO *const coll)
{
    ITEM_INFO *const item = &g_Items[item_num];

    if (!Item_TestBoundsCollide(item, lara_item, coll->radius)) {
        return;
    }

    if (!Collide_TestCollision(item, lara_item)) {
        return;
    }

    if (coll->enable_baddie_push) {
        Lara_Push(
            item, lara_item, coll,
            item->current_anim_state != item->goal_anim_state
                ? coll->enable_spaz
                : false,
            true);
    }
}
