/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 5/10/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <vector>
#include <concepts>
#include <ranges>
#include <functional>
#include <numeric>
#include <fstream>
#include <iomanip>

using Function = std::function<double(const std::vector<double> &)>;

double convert_f_to_c(const auto &f) {
    return (static_cast<double>(f) - 32) * 5 / 9;
}

std::vector<double> get_forecast(std::vector<std::vector<double>> readings, Function fn) {
    auto v = readings | std::views::transform(fn);
    return std::vector<double>{v.begin(), v.end()};
}

void print_readings(const std::vector<std::vector<double>> &readings, std::ofstream &output) {
    for (const auto &v : readings) {
        for (const auto &t : v) {
            output << std::fixed << std::setprecision(1) << t << " ";
        }
        output << std::endl;
    }
}

void print_v(const std::vector<double> &v, std::ofstream &output) {
    for (const auto &t : v) {
        output << std::fixed << std::setprecision(1) << t << " ";
    }
    output << std::endl;
}

int main() {
    std::vector<std::vector<double>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    std::ofstream output{"output.txt"};
    if (!output.is_open()) {
        std::cerr << "Could not open output.txt" << std::endl;
        return -1;
    }
    // TODO: Convert temperatures to Celsius and output to output.txt
    auto readings_ = readings | std::views::transform([](const auto &v) {
        std::vector<double> v_;
        for (const auto &t : v | std::views::transform(convert_f_to_c<double>)) {
            v_.push_back(t);
        }
        return v_;
    });
    readings = std::vector<std::vector<double>>{readings_.begin(), readings_.end()};
    print_readings(readings, output);
    // TODO: Find the maximum temperature for each day and output to output.txt
    std::vector<double> max = get_forecast(readings, [](const std::vector<double> &v) -> double { return *(std::max_element(v.begin(), v.end())); });
    // TODO: Find the minimum temperature for each day and output to output.txt
    std::vector<double> min = get_forecast(readings, [](const std::vector<double> &v) -> double { return *(std::min_element(v.begin(), v.end())); });
    // TODO: Find the average temperature for each day and output to output.txt
    std::vector<double> avg = get_forecast(readings, [](const std::vector<double> &v) -> double { return std::accumulate(v.begin(), v.end(), 0.0) / v.size(); });

    print_v(max, output);
    print_v(min, output);
    print_v(avg, output);
    return 0;
}