#pragma once

#include <string>

#include "yaml-cpp/yaml.h"

YAML::Node loadYamlFile(std::string path,std::string fileName);
