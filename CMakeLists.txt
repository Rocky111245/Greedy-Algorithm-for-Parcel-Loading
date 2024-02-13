cmake_minimum_required(VERSION 3.26)
project(CLion)

set(CMAKE_CXX_STANDARD 23)

# Define an executable for "Unoptimized Simple Delivery Truck Algorithm"
add_executable(UnoptimizedSimpleDeliveryTruck
        "Unoptimized Simple Delivery Truck Algorithm.cpp"
        "Utility Functions .cpp")

# Define an executable for "Optimized (First Fit Increasing) Delivery Truck Algorithm"
add_executable(OptimizedFirstFitIncreasing
        "Optimized (First Fit Increasing) Delivery Truck Algorithm.cpp"
        "Utility Functions .cpp")

# Define an executable for "Optimized (First Fit Decreasing) Delivery Truck Algorithm"
add_executable(OptimizedFirstFitDecreasing
        "Optimized (First Fit Decreasing) Delivery Truck Algorithm.cpp"
        "Utility Functions .cpp")
