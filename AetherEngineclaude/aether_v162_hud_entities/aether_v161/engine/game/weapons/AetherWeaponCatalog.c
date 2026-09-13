#include "AetherWeaponCatalog.h"
#include "AetherCrowbar.h"
#include "AetherGlock.h"
#include "AetherPython.h"
#include "AetherMP5.h"
#include "AetherShotgun.h"
#include "AetherCrossbow.h"
#include "AetherRPG.h"
#include "AetherGauss.h"
#include "AetherEgon.h"
#include "AetherHivehand.h"
#include "AetherGrenade.h"
#include "AetherSatchel.h"
#include "AetherTripMine.h"
#include "AetherSnarks.h"
#include <string.h>

void aether_weapon_catalog_init(aether_weapon_t w[15]){
    if(!w)return;
    memset(w,0,sizeof(aether_weapon_t)*15u);
    aether_crowbar_init(&w[AETHER_WEAPON_CROWBAR]);
    aether_glock_init(&w[AETHER_WEAPON_GLOCK]);
    aetherpython_init(&w[AETHER_WEAPON_PYTHON]);
    aethermp5_init(&w[AETHER_WEAPON_MP5]);
    aethershotgun_init(&w[AETHER_WEAPON_SHOTGUN]);
    aethercrossbow_init(&w[AETHER_WEAPON_CROSSBOW]);
    aetherrpg_init(&w[AETHER_WEAPON_RPG]);
    aethergauss_init(&w[AETHER_WEAPON_GAUSS]);
    aetheregon_init(&w[AETHER_WEAPON_EGON]);
    aetherhivehand_init(&w[AETHER_WEAPON_HIVEHAND]);
    aethergrenade_init(&w[AETHER_WEAPON_GRENADE]);
    aethersatchel_init(&w[AETHER_WEAPON_SATCHEL]);
    aethertripmine_init(&w[AETHER_WEAPON_TRIPMINE]);
    aethersnarks_init(&w[AETHER_WEAPON_SNARK]);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_GLOCK],"9mm",68,250);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_PYTHON],"357",18,36);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_MP5],"9mm",100,250);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_SHOTGUN],"buckshot",24,125);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_CROSSBOW],"bolts",15,50);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_RPG],"rockets",5,20);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_GAUSS],"uranium",100,1000);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_EGON],"uranium",100,1000);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_HIVEHAND],"hornets",8,99);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_GRENADE],"grenades",5,10);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_SATCHEL],"satchels",5,10);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_TRIPMINE],"tripmines",5,10);
    aether_weapon_set_ammo_type(&w[AETHER_WEAPON_SNARK],"snarks",5,15);
}

const aether_weapon_t *aether_weapon_catalog_get(const aether_weapon_t w[15], aether_weapon_id_t id){
    if(!w||id<=AETHER_WEAPON_NONE||id>=15)return NULL;
    return &w[id];
}
