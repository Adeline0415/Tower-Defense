#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "HeroArmy.hpp"
#include "AudioHelper.hpp"
//#include "ArmyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
#include "Defense.hpp"
#include "DirtyEffect.hpp"

//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius);
HeroArmy::HeroArmy(int x, int y) : Army("play/hero.png", x, y, 20, 1, 55, 25, 4, 1.5 * PlayScene::BlockSize) {
    // Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
    // and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void HeroArmy::Update(float deltaTime) {
    if (Enabled)alpha -= deltaTime / timeSpan;
    // PlayScene
    PlayScene* scene = getPlayScene();
    Engine::Sprite* sprite = 0;
    if (isPreview) return;
    // position
    int x = static_cast<int>(floor(Position.x / PlayScene::BlockSize));
    int y = static_cast<int>(floor(Position.y / PlayScene::BlockSize));
    if (alpha <= 0) {
        scene->ArmyGroup->RemoveObject(objectIterator);
        return;
    }
    scene->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/hero.png", 2, Position.x, Position.y));
    if (sprite)sprite->Rotation = 0;
    if (!Target) {
        for (auto& it : scene->DefenseGroup->GetObjects()) {
            if (InShootingRange(it->Position) && dynamic_cast<Defense*>(it)->id != 2) {
                Target = dynamic_cast<Defense*>(it);
                Target->Hit(INFINITY);
            }
        }
    }
    unsigned char r, g, b, a = alpha * 255;
    al_unmap_rgb(Tint, &r, &g, &b);
    Tint = al_map_rgba(r, g, b, a);

    Velocity = Velocity * speed;
    Position.x += Velocity.x * deltaTime;
    Position.y += Velocity.y * deltaTime;
}