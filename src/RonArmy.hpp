#ifndef RonArmy_hpp
#define RonArmy_hpp

#include "Army.hpp"

class RonArmy : public Army {
public:
    RonArmy(int x, int y);
    void CreateBullet(Engine::Point pt) {};
    void CreateSnow() {};
};

#endif /* RonArmy_hpp */
