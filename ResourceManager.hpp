#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource_;
public:
    ResourceManager() 
        : resource_(new Resource()){}

    ~ResourceManager(){
        delete resource_;
}

    ResourceManager(const ResourceManager& other)
        : resource_(new Resource(*other.resource_)){}

    ResourceManager& operator=(const ResourceManager& other){
        if (this != &other)
        {
            Resource* newResource = new Resource(*other.resource_);
            delete resource_;
            resource_ = newResource;
        }
        return *this;
    }
    double get() const
    {
        return resource_->get();
    }

};
