#include "DevelopmentCard.hpp"

// Define static members
const std::string DevelopmentCard::Type::Monopoly = "Monopoly";
const std::string DevelopmentCard::Type::RoadBuilding = "Road Building";
const std::string DevelopmentCard::Type::YearOfPlenty = "Year of Plenty";
const std::string DevelopmentCard::Type::Knight = "Knight";
const std::string DevelopmentCard::Type::VictoryPoint = "Victory Point";

DevelopmentCard::DevelopmentCard(const std::string& type) : type(type) {}

std::string DevelopmentCard::getType() const {
    return type;
}

std::string DevelopmentCard::getCardTypeString(const std::string& type) {
    return type;
}
