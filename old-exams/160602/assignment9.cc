#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Sauna {
    public:
        static constexpr float room_temperature = 22.0;

        Sauna(double thermostat = room_temperature)
            : thermostat_(thermostat) {};
        virtual ~Sauna() = 0;

        double get_temprature() const { return temperature_; }
        void set_temperature(double temp) { temperature_ = temp; } 

        void turnOn();
        void turnOff();

        Sauna* clone() { return get_clone(); } 

        virtual std::string str() const = 0;

        friend std::ostream& operator<<(std::ostream&, Sauna const&);

    protected:
        virtual Sauna* get_clone() = 0;

        const double thermostat_;
        double temperature_ = { room_temperature };
    private:
        bool is_on_ { false };
};

class Steam_Heater : public Sauna {
    public:
        Steam_Heater() : Sauna(38) { };
        Steam_Heater(Steam_Heater&) = delete;
        ~Steam_Heater() = default;

        std::string str() const override;
    private:
        Sauna* get_clone() override;        
};

class Wood_Heater : public Sauna {
    public:
        Wood_Heater() = default;
        Wood_Heater(Wood_Heater&) = delete;
        ~Wood_Heater() = default;

        void add_log();

        std::string str() const override;
    private:
        Sauna* get_clone() override;        
};

class Electrical_Heater : public Sauna {
    public:
        Electrical_Heater() : Sauna(85) { };
        Electrical_Heater(Electrical_Heater&) = delete;
        ~Electrical_Heater() = default;

        std::string str() const override;
    private:
        Sauna* get_clone() override;        
};

Sauna::~Sauna() = default;

void Sauna::turnOn() {
    is_on_ = true;
    temperature_ = thermostat_;
}

void Sauna::turnOff() {
    is_on_ = false;
    temperature_ = room_temperature;
}

std::string Steam_Heater::str() const {
    return "Steam sauna";
}

Sauna* Steam_Heater::get_clone() {
    Sauna* clone = new Steam_Heater();
    clone->set_temperature(temperature_);
    return clone;
}

void Wood_Heater::add_log() {
    temperature_ += 5;
}

std::string Wood_Heater::str() const {
    return "Wood-burning sauna";
}

Sauna* Wood_Heater::get_clone() {
    Sauna* clone = new Wood_Heater();
    clone->set_temperature(temperature_);
    return clone;
}

std::string Electrical_Heater::str() const {
    return "Electrical Heater";
}

Sauna* Electrical_Heater::get_clone() {
    Sauna* clone = new Electrical_Heater();
    clone->set_temperature(temperature_);
    return clone;
}

std::ostream& operator<<(std::ostream& os, Sauna const& sauna) {
    os << sauna.str() << (sauna.is_on_ ? "[ON]" : "[OFF]") << " " 
        << sauna.temperature_ << " degrees";
    return os;
}

void function(Sauna* sauna) {
    std::cout << *sauna << std::endl;

    sauna->turnOn();

    Wood_Heater* wood = dynamic_cast<Wood_Heater*>(sauna);

    if(wood)
        for(int i = 0; i < 10; i++)
            wood->add_log();

    std::cout << *sauna << std::endl;
}

int main() {
    std::vector<std::reference_wrapper<Sauna> > saunas;

    Steam_Heater steam;
    saunas.push_back(steam);

    Wood_Heater wood;
    saunas.push_back(wood);

    Electrical_Heater electrical;
    saunas.push_back(electrical);

    for(Sauna& sauna : saunas) {
        Sauna* copy = sauna.clone();
        function(copy);
        delete copy;
    }
}
