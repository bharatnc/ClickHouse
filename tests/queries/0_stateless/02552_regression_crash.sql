CREATE TABLE store_sales
(
    `ss_sold_date_sk` Float64,
    `ss_sold_time_sk` Float64,
    `ss_customer_sk` Float64,
    `ss_cdemo_sk` Float64,
    `ss_hdemo_sk` Float64
)
ENGINE = Memory;

insert into store_sales values (-3.273, -1.452, 4.267, 20.0, 40.0),(0.121, -0.615, 4.290, 20.0, 40.0), (-1.099, 2.755, -3.060, 20.0, 40.0),(1.090, 2.945, -2.346, 20.0, 40.0), (0.305, 2.179, -1.205, 20.0, 40.0),(-0.925, 0.702, 1.134, 20.0, 40.0), (3.178, -1.316, 7.221, 20.0, 40.0),(-2.756, -0.473, 2.569, 20.0, 40.0), (3.665, 2.303, 0.226, 20.0, 40.0),(1.662, 1.951, -0.070, 20.0, 40.0), (2.869, 0.593, 3.249, 20.0, 40.0),(0.818, -0.593, 4.594, 20.0, 40.0), (-1.917, 0.916, 0.209, 20.0, 40.0),(2.706, 1.523, 1.307, 20.0, 40.0), (0.219, 2.162, -1.214, 20.0, 40.0),(-4.510, 1.376, -2.007, 20.0, 40.0), (4.284, -0.515, 6.173, 20.0, 40.0),(-1.101, 2.810, -3.170, 20.0, 40.0), (-1.810, -1.117, 4.329, 20.0, 40.0),(0.055, 1.115, 0.797, 20.0, 40.0), (-2.178, 2.904, -3.898, 20.0, 40.0),(-3.494, -1.814, 4.882, 20.0, 40.0), (3.027, 0.476, 3.562, 20.0, 40.0),(-1.434, 1.151, -0.018, 20.0, 40.0), (1.180, 0.992, 1.606, 20.0, 40.0),(0.015, 0.971, 1.067, 20.0, 40.0), (-0.511, -0.875, 4.495, 20.0, 40.0),(0.961, 2.348, -1.216, 20.0, 40.0), (-2.279, 0.038, 1.785, 20.0, 40.0),(-1.568, -0.248, 2.712, 20.0, 40.0), (-0.496, 0.366, 2.020, 20.0, 40.0),(1.177, -1.401, 6.390, 20.0, 40.0), (2.882, -1.442, 7.325, 20.0, 40.0),(-1.066, 1.817, -1.167, 20.0, 40.0), (-2.144, 2.791, -3.655, 20.0, 40.0),(-4.370, 2.228, -3.642, 20.0, 40.0), (3.996, 2.775, -0.553, 20.0, 40.0),(0.289, 2.055, -0.965, 20.0, 40.0), (-0.588, -1.601, 5.908, 20.0, 40.0),(-1.801, 0.417, 1.265, 20.0, 40.0), (4.375, -1.499, 8.186, 20.0, 40.0),(-2.618, 0.038, 1.615, 20.0, 40.0), (3.616, -0.833, 6.475, 20.0, 40.0),(-4.045, -1.558, 4.094, 20.0, 40.0), (-3.962, 0.636, -0.253, 20.0, 40.0),(3.505, 2.625, -0.497, 20.0, 40.0), (3.029, -0.523, 5.560, 20.0, 40.0),(-3.520, -0.474, 2.188, 20.0, 40.0), (2.430, -1.469, 7.154, 20.0, 40.0),(1.547, -1.654, 7.082, 20.0, 40.0), (-1.370, 0.575, 1.165, 20.0, 40.0),(-1.869, -1.555, 5.176, 20.0, 40.0), (3.536, 2.841, -0.913, 20.0, 40.0),(-3.810, 1.220, -1.344, 20.0, 40.0), (-1.971, 1.462, -0.910, 20.0, 40.0),(-0.243, 0.167, 2.545, 20.0, 40.0), (-1.403, 2.645, -2.991, 20.0, 40.0),(0.532, -0.114, 3.494, 20.0, 40.0), (-1.678, 0.975, 0.212, 20.0, 40.0),(-0.656, 2.140, -1.609, 20.0, 40.0), (1.743, 2.631, -1.390, 20.0, 40.0),(2.586, 2.943, -1.593, 20.0, 40.0), (-0.512, 2.969, -3.195, 20.0, 40.0),(2.283, -0.100, 4.342, 20.0, 40.0), (-4.293, 0.872, -0.890, 20.0, 40.0),(3.411, 1.300, 2.106, 20.0, 40.0), (-0.281, 2.951, -3.042, 20.0, 40.0),(-4.442, 0.384, 0.012, 20.0, 40.0), (1.194, 1.746, 0.104, 20.0, 40.0),(-1.152, 1.862, -1.300, 20.0, 40.0), (1.362, -1.341, 6.363, 20.0, 40.0),(-4.488, 2.618, -4.481, 20.0, 40.0), (3.419, -0.564, 5.837, 20.0, 40.0),(-3.392, 0.396, 0.512, 20.0, 40.0), (-1.629, -0.909, 4.003, 20.0, 40.0),(4.447, -1.088, 7.399, 20.0, 40.0), (-1.232, 1.699, -1.014, 20.0, 40.0),(-1.286, -0.609, 3.575, 20.0, 40.0), (2.437, 2.796, -1.374, 20.0, 40.0),(-4.864, 1.989, -3.410, 20.0, 40.0), (-1.716, -1.399, 4.940, 20.0, 40.0),(-3.084, 1.858, -2.259, 20.0, 40.0), (2.828, -0.319, 5.053, 20.0, 40.0),(-1.226, 2.586, -2.786, 20.0, 40.0), (2.456, 0.092, 4.044, 20.0, 40.0),(-0.989, 2.375, -2.245, 20.0, 40.0), (3.268, 0.935, 2.765, 20.0, 40.0),(-4.128, -1.995, 4.927, 20.0, 40.0), (-1.083, 2.197, -1.935, 20.0, 40.0),(-3.471, -1.198, 3.660, 20.0, 40.0), (4.617, -1.136, 7.579, 20.0, 40.0),(2.054, -1.675, 7.378, 20.0, 40.0), (4.106, 2.326, 0.402, 20.0, 40.0),(1.558, 0.310, 3.158, 20.0, 40.0), (0.792, 0.900, 1.596, 20.0, 40.0),(-3.229, 0.300, 0.785, 20.0, 40.0), (3.787, -0.793, 6.479, 20.0, 40.0),(1.786, 2.288, -0.684, 20.0, 40.0), (2.643, 0.223, 3.875, 20.0, 40.0),(-3.592, 2.122, -3.040, 20.0, 40.0), (4.519, -1.760, 8.779, 20.0, 40.0),(3.221, 2.255, 0.101, 20.0, 40.0), (4.151, 1.788, 1.500, 20.0, 40.0),(-1.033, -1.195, 4.874, 20.0, 40.0), (-1.636, -1.037, 4.257, 20.0, 40.0),(-3.548, 1.911, -2.596, 20.0, 40.0), (4.829, -0.293, 6.001, 20.0, 40.0),(-4.684, -1.664, 3.986, 20.0, 40.0), (4.531, -0.503, 6.271, 20.0, 40.0),(-3.503, -1.606, 4.460, 20.0, 40.0), (-2.036, -1.522, 5.027, 20.0, 40.0),(-0.473, -0.617, 3.997, 20.0, 40.0), (-1.554, -1.630, 5.483, 20.0, 40.0),(-3.567, -1.043, 3.302, 20.0, 40.0), (-2.038, 0.579, 0.823, 20.0, 40.0),(-3.040, 0.857, -0.233, 20.0, 40.0), (4.610, 0.562, 4.181, 20.0, 40.0),(-3.323, -1.938, 5.215, 20.0, 40.0), (4.314, 1.720, 1.717, 20.0, 40.0),(-1.220, 0.615, 1.161, 20.0, 40.0), (-2.556, 1.120, -0.519, 20.0, 40.0),(-3.717, -0.108, 1.358, 20.0, 40.0), (4.689, -1.826, 8.996, 20.0, 40.0),(3.452, 0.506, 3.713, 20.0, 40.0), (2.472, 0.612, 3.012, 20.0, 40.0),(3.452, 0.450, 3.826, 20.0, 40.0), (1.207, 2.585, -1.567, 20.0, 40.0),(-4.826, 1.090, -1.593, 20.0, 40.0), (3.116, -1.118, 6.794, 20.0, 40.0),(0.448, 2.732, -2.240, 20.0, 40.0), (-1.096, -0.525, 3.503, 20.0, 40.0),(-4.680, -0.238, 1.137, 20.0, 40.0), (2.552, -1.403, 7.082, 20.0, 40.0),(0.719, 2.997, -2.635, 20.0, 40.0), (0.347, -1.966, 7.105, 20.0, 40.0),(2.958, -0.404, 5.288, 20.0, 40.0), (0.722, -1.950, 7.261, 20.0, 40.0),(-2.851, -0.986, 3.546, 20.0, 40.0), (-4.316, -0.439, 1.721, 20.0, 40.0),(-1.685, -0.201, 2.560, 20.0, 40.0), (1.856, 0.190, 3.549, 20.0, 40.0),(-2.052, 0.206, 1.562, 20.0, 40.0), (-2.504, -0.646, 3.041, 20.0, 40.0),(3.235, 0.882, 2.854, 20.0, 40.0), (-1.366, -1.573, 5.463, 20.0, 40.0),(-3.447, 2.419, -3.562, 20.0, 40.0), (4.155, 2.092, 0.893, 20.0, 40.0),(-0.935, 0.209, 2.116, 20.0, 40.0), (3.117, -1.821, 8.201, 20.0, 40.0),(3.759, 0.577, 3.725, 20.0, 40.0), (-0.938, 2.992, -3.453, 20.0, 40.0),(-0.525, 2.341, -1.945, 20.0, 40.0), (4.540, 2.625, 0.019, 20.0, 40.0),(-2.097, 1.190, -0.429, 20.0, 40.0), (-2.672, 1.983, -2.302, 20.0, 40.0),(-3.038, -1.490, 4.460, 20.0, 40.0), (-0.943, 2.149, -1.770, 20.0, 40.0),(0.739, 1.598, 0.174, 20.0, 40.0), (1.828, 1.853, 0.208, 20.0, 40.0),(4.856, 0.137, 5.153, 20.0, 40.0), (-1.617, 0.468, 1.255, 20.0, 40.0),(-1.972, 2.053, -2.092, 20.0, 40.0), (-4.633, 1.389, -2.094, 20.0, 40.0),(-3.628, -1.156, 3.498, 20.0, 40.0), (3.597, 1.034, 2.731, 20.0, 40.0),(-1.488, -0.002, 2.261, 20.0, 40.0), (0.749, 1.921, -0.468, 20.0, 40.0),(1.304, -1.371, 6.394, 20.0, 40.0), (4.587, 2.936, -0.579, 20.0, 40.0),(-2.241, 1.791, -1.703, 20.0, 40.0), (-2.945, 1.372, -1.216, 20.0, 40.0),(1.375, 0.395, 2.898, 20.0, 40.0), (-1.281, -0.641, 3.642, 20.0, 40.0),(2.178, 0.895, 2.299, 20.0, 40.0), (3.031, -0.786, 6.087, 20.0, 40.0),(-1.385, -0.375, 3.058, 20.0, 40.0), (4.041, -0.431, 5.882, 20.0, 40.0),(0.480, -0.507, 4.254, 20.0, 40.0), (-3.797, 0.140, 0.822, 20.0, 40.0),(2.355, 2.502, -0.827, 20.0, 40.0), (1.376, -1.583, 6.854, 20.0, 40.0),(0.164, 1.405, 0.273, 20.0, 40.0), (-1.273, 1.471, -0.579, 20.0, 40.0),(0.770, 2.246, -1.107, 20.0, 40.0), (4.552, 2.904, -0.533, 20.0, 40.0),(4.259, -1.772, 8.674, 20.0, 40.0), (-0.309, 1.159, 0.528, 20.0, 40.0),(3.581, 2.700, -0.610, 20.0, 40.0), (-3.202, 0.346, 0.707, 20.0, 40.0),(-1.575, 1.242, -0.271, 20.0, 40.0), (-1.584, -0.493, 3.194, 20.0, 40.0),(-3.778, 0.150, 0.810, 20.0, 40.0), (-4.675, 1.749, -2.835, 20.0, 40.0),(3.567, -0.792, 6.367, 20.0, 40.0), (-0.417, 1.399, -0.006, 20.0, 40.0),(-4.672, 2.007, -3.349, 20.0, 40.0), (-1.034, 0.196, 2.090, 20.0, 40.0),(-3.796, 2.496, -3.890, 20.0, 40.0), (3.532, -0.497, 5.759, 20.0, 40.0),(4.868, -1.359, 8.151, 20.0, 40.0), (-0.769, 0.302, 2.011, 20.0, 40.0),(4.475, 2.612, 0.014, 20.0, 40.0), (-3.532, -0.395, 2.024, 20.0, 40.0),(0.322, 0.675, 1.812, 20.0, 40.0), (-2.028, -1.942, 5.870, 20.0, 40.0),(1.810, -1.244, 6.392, 20.0, 40.0), (-0.783, 1.242, 0.124, 20.0, 40.0),(-4.745, -1.300, 3.227, 20.0, 40.0), (1.902, 1.973, 0.005, 20.0, 40.0),(-3.453, -1.429, 4.132, 20.0, 40.0), (1.559, 0.986, 1.808, 20.0, 40.0),(0.128, 2.754, -2.443, 20.0, 40.0), (2.759, 1.727, 0.926, 20.0, 40.0),(-4.468, 1.690, -2.614, 20.0, 40.0), (-2.368, -1.922, 5.659, 20.0, 40.0),(-2.766, 2.128, -2.640, 20.0, 40.0), (0.967, -1.825, 7.133, 20.0, 40.0),(-2.854, 2.855, -4.136, 20.0, 40.0), (-2.944, 1.875, -2.222, 20.0, 40.0),(-2.632, -0.983, 3.649, 20.0, 40.0), (2.427, 2.239, -0.266, 20.0, 40.0),(-1.726, -0.838, 3.812, 20.0, 40.0), (0.007, -0.903, 4.809, 20.0, 40.0),(-2.013, 1.092, -0.191, 20.0, 40.0), (-0.449, 0.970, 0.836, 20.0, 40.0),(1.396, 0.411, 2.876, 20.0, 40.0), (-1.115, -1.790, 6.023, 20.0, 40.0),(3.748, 1.917, 1.039, 20.0, 40.0), (2.978, 1.043, 2.404, 20.0, 40.0),(-3.969, 2.514, -4.013, 20.0, 40.0), (4.455, -0.050, 5.328, 20.0, 40.0),(-3.065, -0.846, 3.160, 20.0, 40.0), (-1.069, 2.167, -1.869, 20.0, 40.0),(3.016, -1.393, 7.294, 20.0, 40.0), (0.045, -1.928, 6.879, 20.0, 40.0),(-2.555, -0.984, 3.690, 20.0, 40.0), (-1.995, -0.054, 2.111, 20.0, 40.0),(4.600, -0.509, 6.318, 20.0, 40.0), (-1.942, 1.215, -0.402, 20.0, 40.0),(1.262, 2.765, -1.899, 20.0, 40.0), (2.617, -1.106, 6.521, 20.0, 40.0),(1.737, 0.554, 2.761, 20.0, 40.0), (-2.197, 0.632, 0.638, 20.0, 40.0),(4.768, 2.618, 0.147, 20.0, 40.0), (-3.737, -0.939, 3.010, 20.0, 40.0),(-2.623, 0.595, 0.499, 20.0, 40.0), (4.752, -0.340, 6.057, 20.0, 40.0),(2.333, -1.037, 6.240, 20.0, 40.0), (4.234, -1.882, 8.881, 20.0, 40.0),(-3.393, -0.812, 2.927, 20.0, 40.0), (0.885, 1.383, 0.678, 20.0, 40.0),(0.123, 2.937, -2.812, 20.0, 40.0), (2.969, 0.760, 2.964, 20.0, 40.0),(-4.929, 1.251, -1.967, 20.0, 40.0), (1.916, 2.223, -0.488, 20.0, 40.0),(-0.020, -1.740, 6.469, 20.0, 40.0), (0.702, -1.272, 5.895, 20.0, 40.0),(2.496, 2.648, -1.048, 20.0, 40.0), (4.067, -1.475, 7.984, 20.0, 40.0),(-3.717, 1.851, -2.561, 20.0, 40.0), (1.678, -0.624, 5.088, 20.0, 40.0),(1.073, 0.695, 2.146, 20.0, 40.0), (1.842, -0.749, 5.419, 20.0, 40.0),(-3.518, 1.909, -2.578, 20.0, 40.0), (2.229, 1.189, 1.737, 20.0, 40.0),(4.987, 2.893, -0.292, 20.0, 40.0), (-4.809, 1.043, -1.490, 20.0, 40.0),(-0.241, -0.728, 4.334, 20.0, 40.0), (-3.331, 0.590, 0.156, 20.0, 40.0),(-0.455, 2.621, -2.470, 20.0, 40.0), (1.492, 1.223, 1.301, 20.0, 40.0),(3.948, 2.841, -0.709, 20.0, 40.0), (0.732, 0.446, 2.475, 20.0, 40.0),(2.400, 2.390, -0.579, 20.0, 40.0), (-2.718, 1.427, -1.213, 20.0, 40.0),(-1.826, 1.451, -0.815, 20.0, 40.0), (1.125, 0.438, 2.686, 20.0, 40.0),(-4.918, 1.880, -3.219, 20.0, 40.0), (3.068, -0.442, 5.418, 20.0, 40.0),(1.982, 1.201, 1.589, 20.0, 40.0), (0.701, -1.709, 6.768, 20.0, 40.0),(-1.496, 2.564, -2.877, 20.0, 40.0), (-3.812, 0.974, -0.853, 20.0, 40.0),(-3.405, 2.018, -2.739, 20.0, 40.0), (2.211, 2.889, -1.674, 20.0, 40.0),(-2.481, 2.931, -4.103, 20.0, 40.0), (-3.721, 2.765, -4.391, 20.0, 40.0),(-1.768, -1.292, 4.699, 20.0, 40.0), (-4.462, 1.058, -1.347, 20.0, 40.0),(-3.516, -1.942, 5.126, 20.0, 40.0), (0.485, 2.420, -1.597, 20.0, 40.0),(-0.492, 0.242, 2.270, 20.0, 40.0), (4.245, 1.689, 1.744, 20.0, 40.0),(2.234, 0.364, 3.389, 20.0, 40.0), (2.629, 2.224, -0.134, 20.0, 40.0),(-4.375, 1.221, -1.630, 20.0, 40.0), (-0.618, 1.374, -0.057, 20.0, 40.0),(-2.580, -1.604, 4.918, 20.0, 40.0), (0.159, 1.104, 0.871, 20.0, 40.0),(-3.597, 0.975, -0.749, 20.0, 40.0);
INSERT INTO store_sales (ss_sold_time_sk) VALUES (1);
INSERT INTO store_sales (ss_cdemo_sk) VALUES (0.1);
select stochasticLinearRegressionState(0.03, 0.00001, 2, 'Momentum')(ss_sold_time_sk, ss_sold_time_sk, ss_sold_time_sk) as ss_wholesale_cost from store_sales format Null;
