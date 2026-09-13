#include "AetherFuncDoor.h"
#include <string.h>
#include <math.h>

static f32 clampf_(f32 v, f32 a, f32 b) { return v < a ? a : (v > b ? b : v); }

static aether_vec3_t vadd_(aether_vec3_t a, aether_vec3_t b) {
    aether_vec3_t r = { a.x + b.x, a.y + b.y, a.z + b.z };
    return r;
}
static aether_vec3_t vscale_(aether_vec3_t a, f32 s) {
    aether_vec3_t r = { a.x * s, a.y * s, a.z * s };
    return r;
}
static aether_vec3_t vlerp_(aether_vec3_t a, aether_vec3_t b, f32 t) {
    aether_vec3_t r = { a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t };
    return r;
}
static f32 vdist_(aether_vec3_t a, aether_vec3_t b) {
    f32 dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return (f32)sqrtf(dx*dx + dy*dy + dz*dz);
}

void aetherfuncdoor_init(aetherfuncdoor_state_t *s, aether_vec3_t origin,
                          aether_vec3_t move_dir, f32 distance,
                          f32 speed, f32 wait, bool toggle) {
    if (!s) return;
    memset(s, 0, sizeof *s);
    s->enabled = true;
    s->pos_closed = origin;
    s->pos_open = vadd_(origin, vscale_(move_dir, distance));
    s->position = origin;
    s->speed = speed > 0 ? speed : 100.0f;
    s->wait = wait; /* -1 means stay open permanently once opened */
    s->toggle = toggle;
    s->state = AETHER_DOOR_CLOSED;
}

void aetherfuncdoor_reset(aetherfuncdoor_state_t *s) {
    if (!s) return;
    s->state = AETHER_DOOR_CLOSED;
    s->position = s->pos_closed;
    s->wait_timer = 0;
}

bool aetherfuncdoor_is_open(const aetherfuncdoor_state_t *s) {
    return s && s->state == AETHER_DOOR_OPEN;
}

bool aetherfuncdoor_is_moving(const aetherfuncdoor_state_t *s) {
    return s && (s->state == AETHER_DOOR_OPENING || s->state == AETHER_DOOR_CLOSING);
}

void aetherfuncdoor_use(aetherfuncdoor_state_t *s) {
    if (!s || !s->enabled || s->locked) return;
    switch (s->state) {
        case AETHER_DOOR_CLOSED:
            s->state = AETHER_DOOR_OPENING;
            break;
        case AETHER_DOOR_OPEN:
            if (s->toggle) s->state = AETHER_DOOR_CLOSING;
            else s->wait_timer = 0; /* re-trigger just resets the auto-close timer */
            break;
        case AETHER_DOOR_OPENING:
            if (s->toggle) s->state = AETHER_DOOR_CLOSING;
            break;
        case AETHER_DOOR_CLOSING:
            s->state = AETHER_DOOR_OPENING; /* re-open if someone triggers while closing */
            break;
    }
}

void aetherfuncdoor_block(aetherfuncdoor_state_t *s) {
    if (!s) return;
    if (s->state == AETHER_DOOR_CLOSING) s->state = AETHER_DOOR_OPENING;
}

void aetherfuncdoor_update(aetherfuncdoor_state_t *s, f32 dt) {
    if (!s || !s->enabled || dt <= 0) return;

    switch (s->state) {
        case AETHER_DOOR_OPENING: {
            f32 total = vdist_(s->pos_closed, s->pos_open);
            f32 remain = vdist_(s->position, s->pos_open);
            f32 step = s->speed * dt;
            if (step >= remain || total <= 0.0001f) {
                s->position = s->pos_open;
                s->state = AETHER_DOOR_OPEN;
                s->wait_timer = 0;
                s->events++;
            } else {
                f32 t = 1.0f - (remain - step) / total;
                s->position = vlerp_(s->pos_closed, s->pos_open, clampf_(t, 0, 1));
            }
            break;
        }
        case AETHER_DOOR_OPEN: {
            if (s->toggle || s->wait < 0) return; /* stays open until re-triggered */
            s->wait_timer += dt;
            if (s->wait_timer >= s->wait) s->state = AETHER_DOOR_CLOSING;
            break;
        }
        case AETHER_DOOR_CLOSING: {
            f32 total = vdist_(s->pos_closed, s->pos_open);
            f32 remain = vdist_(s->position, s->pos_closed);
            f32 step = s->speed * dt;
            if (step >= remain || total <= 0.0001f) {
                s->position = s->pos_closed;
                s->state = AETHER_DOOR_CLOSED;
                s->events++;
            } else {
                f32 t = remain - step > 0 ? 1.0f - (remain - step) / total : 1.0f;
                s->position = vlerp_(s->pos_closed, s->pos_open, clampf_(t, 0, 1));
            }
            break;
        }
        case AETHER_DOOR_CLOSED:
        default:
            break;
    }
}
