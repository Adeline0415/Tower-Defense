#ifndef DracoBullet_hpp
#define DracoBullet_hpp

#include "Bullet.hpp"

class Army;
class Defense;
namespace Engine {
    struct Point;
}  // namespace Engine

class DracoBullet : public Bullet {
public:
    explicit DracoBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent);
};

#endif /* DracoBullet_hpp */
