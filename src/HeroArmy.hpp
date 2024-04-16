#ifndef HeroArmy_hpp
#define HeroArmy_hpp

#include "Army.hpp"

class HeroArmy : public Army {
public:
    HeroArmy(int x, int y);
    void Update(float deltaTime) override;
    void CreateBullet(Engine::Point pt) {};
    void CreateSnow() {};
protected:
    float timeSpan = 2.0;
    float alpha = 1;
};

#endif /* HeroArmy_hpp */
