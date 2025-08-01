/**
 * @file main.cpp
 * @brief Main entry point for SIREN C++ server
 * @author KostasAndroulidakis
 * @date 2025
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <boost/version.hpp>
#include <boost/asio/version.hpp>
#include <boost/asio.hpp>

// Military-grade configuration headers
#include "data/sonar_types.hpp"
#include "constants/message.hpp"
#include "constants/communication.hpp"
#include "constants/hardware.hpp"
#include "constants/performance.hpp"
#include "constants/math.hpp"
#include "core/master_controller.hpp"

int main() {
    namespace cnst = siren::constants;
    namespace msg = cnst::message;
    namespace perf = cnst::performance;
    namespace comm = cnst::communication;
    namespace hw = cnst::hardware;

    std::cout << "SIREN Server v" << msg::version::VERSION_STRING << std::endl;
    std::cout << "Boost version: " << BOOST_VERSION / perf::optimization::BOOST_VERSION_MAJOR_DIVISOR << "."
              << BOOST_VERSION / perf::optimization::BOOST_VERSION_MINOR_DIVISOR % perf::optimization::BOOST_VERSION_MINOR_MODULO << "."
              << BOOST_VERSION % perf::optimization::BOOST_VERSION_PATCH_MODULO << std::endl;
    std::cout << "Boost.Asio version: " << BOOST_ASIO_VERSION << std::endl;
    std::cout << "Build type: " << msg::version::BUILD_TYPE << std::endl;
    std::cout << "WebSocket port: " << comm::websocket::DEFAULT_PORT << std::endl;
    std::cout << "Serial baud rate: " << comm::serial::BAUD_RATE << std::endl;

    // Test configuration system - all values from constants, no magic numbers
    std::cout << "\n=== Military-Grade Configuration Test ===" << std::endl;
    std::cout << "Servo range: " << hw::servo::MIN_ANGLE_DEGREES << "° to "
              << hw::servo::MAX_ANGLE_DEGREES << "°" << std::endl;
    std::cout << "Sensor range: " << hw::sensor::MIN_DISTANCE_CM << "cm to "
              << hw::sensor::MAX_DISTANCE_CM << "cm" << std::endl;
    std::cout << "Target latency: " << perf::timing::TARGET_LOOP_TIME_US << "μs" << std::endl;

    // Test data types
    siren::data::SonarDataPoint test_point(cnst::math::test::TEST_ANGLE_DEGREES, cnst::math::test::TEST_DISTANCE_CM);
    std::cout << "Test data point: angle=" << test_point.angle
              << "°, distance=" << test_point.distance << "cm" << std::endl;

    // Test military-grade master controller
    std::cout << "\n=== Phase 2: Military-Grade Master Controller Test ===" << std::endl;

    siren::core::MasterController controller;

    std::cout << "Initializing master controller..." << std::endl;
    if (!controller.initialize()) {
        std::cout << "❌ Controller initialization failed" << std::endl;
        return 1;
    }

    std::cout << "Starting controller..." << std::endl;
    if (!controller.start()) {
        std::cout << "❌ Controller start failed" << std::endl;
        return 1;
    }

    std::cout << "Controller state: " << static_cast<int>(controller.getSystemState()) << std::endl;
    std::cout << "System healthy: " << (controller.isHealthy() ? "Yes" : "No") << std::endl;

    // Run controller continuously (military-grade production mode)
    std::cout << "Running controller in production mode - Ctrl+C to stop..." << std::endl;

    // Run the controller (this blocks until stop() is called)
    controller.run();

    auto metrics = controller.getPerformanceMetrics();
    std::cout << "Final metrics - Active connections: " << metrics.active_connections << std::endl;

    std::cout << "\n✅ Master controller test complete" << std::endl;
    std::cout << "✅ Phase 2 Step 1 Complete - Event loop operational" << std::endl;

    return 0;
}