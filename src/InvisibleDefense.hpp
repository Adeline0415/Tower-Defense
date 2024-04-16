#ifndef InvisibleDefense_hpp
#define InvisibleDefense_hpp

#include "Defense.hpp"

class InvisibleDefense : public Defense {
public:
    InvisibleDefense(float x, float y);
    void Update(float deltaTime) override;
    void CreateBullet(Engine::Point pt) {};
protected:
    bool triggered = false;
    float timeSpan = 6.0;
    float alpha = 1;
};

#endif /* InvisibleDefense_hpp */