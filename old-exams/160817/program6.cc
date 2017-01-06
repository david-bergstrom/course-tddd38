/*
 * program6.cc
 */
#include <iostream>
#include <string>

using namespace std;

class Celestial_Body
{
   public:
      Celestial_Body(string name, double size) : name(name), size(size) { }
      virtual ~Celestial_Body() = 0;

      string get_name() const noexcept { return name; }
      double get_size() const noexcept { return size; }

   private:
      const string name;
      const double size;
};

Celestial_Body::~Celestial_Body() = default;

class Star : public Celestial_Body
{
   public:
      Star(string name, double size, string galaxy_name)
         : Celestial_Body(name, size), galaxy_name(galaxy_name) { }

      const string get_galaxy() const noexcept { return galaxy_name; }

   private:
      const string galaxy_name;
};

class Planet : public Celestial_Body
{
   public:
      Planet(string name, double size, Celestial_Body const* belongs_to,
            double orbit_time, bool populated = false)
         : Celestial_Body(name, size), _belongs_to(belongs_to), _orbit_time(orbit_time),
           _populated(populated) { }

      Celestial_Body const* get_celestial_body() const noexcept { return _belongs_to; }
      double get_orbit_time() const noexcept { return _orbit_time; }
      bool is_populated() const noexcept { return _populated; };
      void populated(bool populated) noexcept { _populated = populated; }

   private:
      Celestial_Body const * _belongs_to;
      const double _orbit_time;
      bool _populated;
};

class Moon : public Planet
{
   public:
      using Planet::Planet;
};

void print(const Celestial_Body& cb)
{
   Star const* star = dynamic_cast<Star const*>(&cb);
   Planet const* planet = dynamic_cast<Planet const*>(&cb);
   Moon const* moon = dynamic_cast<Moon const*>(&cb);

   if (moon) {
      cout << moon->get_name() << ": moon, radius " << moon->get_size()
         << " km, belongs to planet " << moon->get_celestial_body()->get_name()
         << ", orbit time " << moon->get_orbit_time() << " days, "
         << (moon->is_populated() ? "" : "not ") << "populated" << endl;;
   } else if (planet) {
      cout << planet->get_name() << ": planet, radius " << planet->get_size()
         << " km, belongs to star " << planet->get_celestial_body()->get_name()
         << ", orbit time " << planet->get_orbit_time() << " days, "
         << (planet->is_populated() ? "" : "not ") << "populated" << endl;;
   } else if (star) {
      cout << star->get_name() << ": star, radius " << star->get_size()
         << "km , belongs to galaxy " << star->get_galaxy() << endl;
   }
}

int main()
{
   Star star("Helios", 696342.0, "Milky Way");
   Planet planet("Earth", 6371.0, &star, 365.2, true);
   Moon moon("Moon", 1737.1, &planet, 27.3);

   print(star);
   print(planet);
   print(moon);

   return 0;
}
