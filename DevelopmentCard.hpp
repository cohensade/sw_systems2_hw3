#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>

class DevelopmentCard {
private:
    std::string type;

public:
    // Class to define the type of the card
    class Type {
    public:
        static const std::string Monopoly;
        static const std::string RoadBuilding;
        static const std::string YearOfPlenty;
        static const std::string Knight;
        static const std::string VictoryPoint;
    };

    DevelopmentCard(const std::string& type);

    std::string getType() const;
    static std::string getCardTypeString(const std::string& type);
};

#endif // DEVELOPMENTCARD_HPP
