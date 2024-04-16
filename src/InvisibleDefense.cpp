#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "InvisibleDefense.hpp"
#include "AudioHelper.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"

//Defense(std::string imgDefense, float x, float y, float radius, float coolDown, int hp, int id, float shootRadius);
InvisibleDefense::InvisibleDefense(float x, float y) :
    Defense("play/death-eater.png", x, y, 20, 1, 50, 2, 1.5 * PlayScene::BlockSize) {
    // Move center downward, since we the turret head is slightly biased upward.
    invisible = true;
    Anchor.y += 8.0f / GetBitmapHeight();
}

void InvisibleDefense::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    float block = PlayScene::BlockSize;
    if (!Enabled) {
        return;
    }
    if(scene->allDie) {
        if (invisible)invisible = false;
        else scene->DefenseGroup->RemoveObject(objectIterator);
        return;
    }
    if (!triggered) {
        if (PlayScene::DebugMode)
            for (auto& it : scene->DefenseGroup->GetObjects())it->invisible = false;
        else { invisible = true; }
        for (auto& it : scene->ArmyGroup->GetObjects()) {
            if (dynamic_cast<Army*>(it)->id!=3&&it->Position.x >= Position.x - 0.5 * block && it->Position.x <= Position.x + 0.5 * block && it->Position.y >= Position.y - 0.5 * block && it->Position.y <= Position.y + 0.5 * block) {
                Target = dynamic_cast<Army*>(it);
                Target->Hit(INFINITY);
                invisible = false;
                triggered = true;
                break;
            }
        }
    }
    else {
        alpha -= deltaTime / timeSpan;
        if (alpha <= 0) {
            scene-> DefenseGroup->RemoveObject(objectIterator);
            return;
        }
        for (auto& it : scene->ArmyGroup->GetObjects()) {
            if (InShootingRange(it->Position) && dynamic_cast<Army*>(it)->id != 3) {
                Target = dynamic_cast<Army*>(it);
                Target->Hit(INFINITY);
            }
        }
        unsigned char r, g, b, a = alpha * 255;
        al_unmap_rgb(Tint, &r, &g, &b);
        Tint = al_map_rgba(r, g, b, a);
    }
}