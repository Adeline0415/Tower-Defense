#ifndef CannonBullet2_hpp
#define CannonBullet2_hpp

#include "Bullet.hpp"

class Army;
class Defense;
namespace Engine {
    struct Point;
}  // namespace Engine

class CannonBullet2 : public Bullet {
public:
    explicit CannonBullet2(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent);
};

#endif /* CannonBullet2_hpp */
