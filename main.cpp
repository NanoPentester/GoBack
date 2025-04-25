#include <iostream>
#include <filesystem>



std::filesystem::path calculateTargetSteps(int steps) {

    std::filesystem::path target = std::filesystem::current_path();
    if (steps < 0) {
        int stepsToRoot = 0;
        std::filesystem::path temp = target;
        while (temp != "/") {
            temp = temp.parent_path();
            stepsToRoot++;
        }
        steps = stepsToRoot + steps;
    }

    for (int i = 0; i < steps && target != "/"; i++) {
        target = target.parent_path();
    }

    return target;
}

int main(int argc , char* argv[]) {

    try {
        bool output_only = false;
        int steps = 1;

        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "--get-path-only" || arg == "-p") {
                output_only = true;
            } else {
                steps = std::stoi(arg);
            }
        }

        std::filesystem::path target = calculateTargetSteps(steps);

        if (output_only) {
            std::cout << target.string();
        } else {
            std::cout << "Changing to: " << target << std::endl;
            std::filesystem::current_path(target);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}