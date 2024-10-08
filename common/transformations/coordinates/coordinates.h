
#pragma once

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

struct ECEF {
  double x, y, z;
  Eigen::Vector3d to_vector(){
    return Eigen::Vector3d(x, y, z);
  }
};

struct NED {
  double n, e, d;
};

struct Geodetic {
  double lat, lon, alt;
  bool radians=false;
};

ECEF geodetic2ecef(Geodetic g);
Geodetic ecef2geodetic(ECEF e);

class LocalCoord {
public:
  Eigen::Matrix3d ned2ecef_matrix;
  Eigen::Matrix3d ecef2ned_matrix;
  Eigen::Vector3d init_ecef;
  LocalCoord(Geodetic g, ECEF e);
  LocalCoord(Geodetic g) : LocalCoord(g, ::geodetic2ecef(g)) {}
  LocalCoord(ECEF e) : LocalCoord(::ecef2geodetic(e), e) {}

  NED ecef2ned(ECEF e);
  ECEF ned2ecef(NED n);
  NED geodetic2ned(Geodetic g);
  Geodetic ned2geodetic(NED n);
};