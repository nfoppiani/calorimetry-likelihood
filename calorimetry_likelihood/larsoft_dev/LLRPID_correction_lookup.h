#ifndef CORRECTION_LOOKUP_H
#define CORRECTION_LOOKUP_H
#include <stdlib.h>
#include <vector>

namespace searchingfornues
{
  struct CorrectionLookUpParameters
  {
    std::vector<std::vector<float>> parameter_correction_edges_pl_0 = {
    {0.300, 0.400, 0.700, 1.000, 1.500, 30.000, },
    {0.000, 0.262, 0.524, 0.785, 1.047, 1.309, 1.571, },
    };

    std::vector<float> correction_table_pl_0 = {
    1.038, 1.036, 1.034, 1.030, 1.032, 1.026, 1.042, 1.046, 1.052, 1.049, 1.039, 1.025, 1.045, 1.067, 1.083, 1.082, 1.064, 1.042, 1.033, 1.088, 
    1.119, 1.104, 1.080, 1.045, 0.907, 1.045, 1.095, 1.132, 1.112, 1.075, 
    };


    std::vector<std::vector<float>> parameter_correction_edges_pl_1 = {
    {0.300, 0.400, 0.700, 1.000, 1.500, 30.000, },
    {0.000, 0.262, 0.524, 0.785, 1.047, 1.309, 1.571, },
    };

    std::vector<float> correction_table_pl_1 = {
    1.029, 1.027, 1.027, 1.024, 1.027, 1.059, 1.026, 1.034, 1.041, 1.042, 1.031, 1.038, 1.031, 1.062, 1.077, 1.069, 1.053, 1.034, 1.049, 1.110, 
    1.115, 1.097, 1.070, 1.045, 1.049, 1.111, 1.110, 1.143, 1.107, 1.061, 
    };


    std::vector<std::vector<float>> parameter_correction_edges_pl_2 = {
    {0.300, 0.400, 0.700, 1.000, 1.500, 30.000, },
    {0.000, 0.262, 0.524, 0.785, 1.047, 1.309, 1.571, },
    };

    std::vector<float> correction_table_pl_2 = {
    0.976, 0.981, 0.989, 0.993, 0.997, 1.012, 0.960, 0.964, 0.977, 0.987, 0.994, 1.000, 0.915, 0.950, 0.973, 0.988, 0.990, 0.991, 0.882, 0.944, 
    0.977, 0.992, 0.990, 0.993, 0.934, 0.969, 0.996, 1.009, 1.001, 1.002, 
    };


  };
}

#endif