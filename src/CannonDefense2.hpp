#ifndef CannonDefense2_hpp
#define CannonDefense2_hpp

#include "Defense.hpp"

class CannonDefense2 : public Defense {
public:
    CannonDefense2(float x, float y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* CannonDefense2_hpp */
