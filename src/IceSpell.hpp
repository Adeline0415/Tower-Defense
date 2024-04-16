#ifndef IceSpellArmy_hpp
#define IceSpellArmy_hpp

#include "Army.hpp"

class IceSpell : public Army {
public:
    IceSpell(int x, int y);
    void CreateBullet(Engine::Point pt) {};
    void CreateSnow()override;
    void Update(float deltaTime)override;
protected:
    float timeSpan = 2.0;
    float alpha = 1;
};

#endif /* IceSpellArmy_hpp */
