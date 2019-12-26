#include "YamlConfig.hpp"

#include "spdlog/spdlog.h"

YAML::Node loadYamlFile(std::string path, std::string file_name)
{
    std::string file_path = path+"config/"+file_name+".yaml";
    try{
        return YAML::LoadFile(file_path);
    }
    catch(YAML::ParserException){
        spdlog::error("YAML : Parser Error \nHint : make sure mentioned file exists \nFile : {}",file_path);
    }
    catch(YAML::BadFile){
        spdlog::error("YAML : Bad File Error \nHint : check if mentioned file is damaged or empty \nFile : {}",file_path);
    }
}