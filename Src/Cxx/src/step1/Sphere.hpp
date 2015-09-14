#ifndef Sphere_hpp
#define Sphere_hpp
class Sphere
{
public:
  Sphere(const double& radius) : _radius(radius) {};

  double volume () const;

private:
  double _radius;
};
#endif
