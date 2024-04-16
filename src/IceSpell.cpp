#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "IceSpell.hpp"
#include "AudioHelper.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
#include "DirtyEffect.hpp"
#include "Defense.hpp"

//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius);
IceSpell::IceSpell(int x, int y) : Army("play/dumbledore.png", x, y, 20, 1, 0, 100, 3, 1.5 * PlayScene::BlockSize),alpha(1){
    // and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void IceSpell::CreateSnow() {
    float block = PlayScene::BlockSize;
    PlayScene* scene = getPlayScene();
    Engine::Sprite* sprite=0;
    for (float i = -1; i < 2; i++) {
        for (float j = -1; j < 2; j++) {
            if (Position.x + i * block >= 0 && Position.y + j * block >= 0)
                scene->GroundEffectGroup->AddNewObject(sprite=new DirtyEffect("play/Snowflake.png", 2, Position.x + i * block, Position.y + j * block));
                if(sprite)sprite->Rotation = 0;
        }
    }
    scene->GroundEffectGroup->AddNewObject(sprite=new DirtyEffect("play/dumbledore.png",2, Position.x, Position.y ));
    if(sprite)sprite->Rotation = 0;
}

void IceSpell::Update(float deltaTime) {
    if (Enabled)alpha -= deltaTime / timeSpan;
    PlayScene* scene = getPlayScene();
    float block = PlayScene::BlockSize;
    if (isPreview) return;
    CreateSnow();
    if (alpha <= 0) {
        for (auto& it : scene->DefenseGroup->GetObjects()) {
            if (it->Position.x >= Position.x - 1.5 * block && it->Position.x <= Position.x + 1.5 * block && it->Position.y >= Position.y - 1.5 * block && it->Position.y <= Position.y + 1.5 * block) {
                Target = dynamic_cast<Defense*>(it);
                Target->Enabled = true;
            }
        }
        scene->ArmyGroup->RemoveObject(objectIterator);
        return;
    }
    for (auto& it : scene->DefenseGroup->GetObjects()) {
        if (it->Position.x >= Position.x - 1.5 * block && it->Position.x <= Position.x + 1.5 * block && it->Position.y >= Position.y - 1.5 * block && it->Position.y <= Position.y + 1.5 * block) {
            Target = dynamic_cast<Defense*>(it);
            Target->Enabled = false;
        }
    }
    unsigned char r, g, b, a = alpha * 255;
    al_unmap_rgb(Tint, &r, &g, &b);
    Tint = al_map_rgba(r, g, b, a);

    Sprite::Update(deltaTime);
    Velocity = Velocity * speed;
    Position.x += Velocity.x * deltaTime;
    Position.y += Velocity.y * deltaTime;
}
