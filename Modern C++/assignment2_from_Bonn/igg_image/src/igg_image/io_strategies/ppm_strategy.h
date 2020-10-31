#pragma once

#include<string>
#include<sstream>
#include<fstream>
#include "igg_image/io_strategies/strategy.h"

namespace igg{
    class PpmIoStrategy : public IoStrategy
    {
        public:
         bool Write(const std::string& file_name, const ImageData& data) const override;
         ImageData Read(const std::string& file_name) const override;
    };
    
}