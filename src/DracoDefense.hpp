#ifndef DracoDefense_hpp
#define DracoDefense_hpp

#include "Defense.hpp"

class DracoDefense : public Defense {
public:
    DracoDefense(float x, float y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* DracoDefense_hpp */
