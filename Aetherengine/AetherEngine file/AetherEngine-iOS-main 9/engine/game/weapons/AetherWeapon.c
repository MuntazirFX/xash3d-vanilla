#include "AetherWeapon.h"
#include <string.h>

static f32 maxf_(f32 a,f32 b){return a>b?a:b;}

void aether_weapon_init(aether_weapon_t*w,aether_weapon_id_t id,const char*n,
                        i32 cm,f32 dmg,f32 delay,f32 range,bool aut){
    if(!w)return;
    memset(w,0,sizeof*w);
    w->id=id;
    w->clip_max=cm;
    w->clip=cm;
    w->damage=dmg;
    w->fire_delay=delay;
    w->range=range;
    w->automatic=aut;
    w->spread=0.0f;
    w->pellets=1;
    if(n){strncpy(w->classname,n,31);w->classname[31]=0;}
    const char *ammo=aether_weapon_ammo_type(id);
    if(ammo){strncpy(w->ammo_name,ammo,31);w->ammo_name[31]=0;}
}

void aether_weapon_set_ammo_type(aether_weapon_t*w,const char*n,i32 reserve,i32 reserve_max){
    if(!w)return;
    if(n){strncpy(w->ammo_name,n,31);w->ammo_name[31]=0;}
    w->ammo=reserve<0?0:reserve;
    w->ammo_max=reserve_max>0?reserve_max:999;
    if(w->ammo>w->ammo_max)w->ammo=w->ammo_max;
}

void aether_weapon_tick(aether_weapon_t*w,f32 dt){
    if(!w)return;
    w->cooldown=maxf_(0,w->cooldown-dt);
    w->attacking=false;
}

bool aether_weapon_can_fire(const aether_weapon_t*w){
    return w&&w->cooldown<=0&&((w->id==AETHER_WEAPON_CROWBAR)||w->clip>0);
}

bool aether_weapon_fire(aether_weapon_t*w){
    if(!aether_weapon_can_fire(w))return false;
    if(w->id!=AETHER_WEAPON_CROWBAR)w->clip--;
    w->cooldown=w->fire_delay;
    w->attacking=true;
    return true;
}

bool aether_weapon_reload(aether_weapon_t*w){
    if(!w||w->clip>=w->clip_max||w->ammo<=0)return false;
    i32 n=w->clip_max-w->clip;
    if(n>w->ammo)n=w->ammo;
    w->clip+=n;
    w->ammo-=n;
    return true;
}

const char *aether_weapon_name(aether_weapon_id_t id){
    switch(id){
        case AETHER_WEAPON_CROWBAR:return "Crowbar";
        case AETHER_WEAPON_GLOCK:return "Glock";
        case AETHER_WEAPON_PYTHON:return "Python";
        case AETHER_WEAPON_MP5:return "MP5";
        case AETHER_WEAPON_SHOTGUN:return "Shotgun";
        case AETHER_WEAPON_CROSSBOW:return "Crossbow";
        case AETHER_WEAPON_RPG:return "RPG";
        case AETHER_WEAPON_GAUSS:return "Gauss";
        case AETHER_WEAPON_EGON:return "Egon";
        case AETHER_WEAPON_HIVEHAND:return "Hivehand";
        case AETHER_WEAPON_GRENADE:return "Grenade";
        case AETHER_WEAPON_SATCHEL:return "Satchel";
        case AETHER_WEAPON_TRIPMINE:return "Tripmine";
        case AETHER_WEAPON_SNARK:return "Snark";
        default:return "None";
    }
}

const char *aether_weapon_ammo_type(aether_weapon_id_t id){
    switch(id){
        case AETHER_WEAPON_GLOCK:return "9mm";
        case AETHER_WEAPON_PYTHON:return "357";
        case AETHER_WEAPON_MP5:return "9mm";
        case AETHER_WEAPON_SHOTGUN:return "buckshot";
        case AETHER_WEAPON_CROSSBOW:return "bolts";
        case AETHER_WEAPON_RPG:return "rockets";
        case AETHER_WEAPON_GAUSS:return "uranium";
        case AETHER_WEAPON_EGON:return "uranium";
        case AETHER_WEAPON_HIVEHAND:return "hornets";
        case AETHER_WEAPON_GRENADE:return "grenades";
        case AETHER_WEAPON_SATCHEL:return "satchels";
        case AETHER_WEAPON_TRIPMINE:return "tripmines";
        case AETHER_WEAPON_SNARK:return "snarks";
        default:return NULL;
    }
}
