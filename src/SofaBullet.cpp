#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "SofaBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Defense.hpp"
#include "ShootEffect.hpp"

class Defense;

//ArmyBullet::ArmyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Army* parent)
SofaBullet::SofaBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Army* parent) :
    ArmyBullet("play/bullet-7.png", 40, 5, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}

void SofaBullet::OnExplode(Defense* defense) {
    // TODO 3 (1/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(defense->Position.x, defense->Position.y));
}
