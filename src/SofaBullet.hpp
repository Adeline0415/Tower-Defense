#ifndef SofaBullet_hpp
#define SofaBullet_hpp

#include "ArmyBullet.hpp"

class Army;
class Defense;
namespace Engine {
struct Point;
}  // namespace Engine

class SofaBullet: public ArmyBullet{
public:
    explicit SofaBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Army* parent);
    void OnExplode(Defense* defense) override;
};


#endif /* ArcherBullet_hpp */
