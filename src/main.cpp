#include "../libs/isNumber.h"
#include "../libs/str2int.h"
#include "app.h"

int main(int argc, const char** argv) {
    uint16_t width(1024), height(768);
    std::string map("default.txt"), forecast("forecast.txt");
    if (argc > 0) {
        for (uint8_t i = 1; i < static_cast<int8_t>(argc); i++) {
            switch (str2int(argv[i])) {
            case str2int("-d"): {
                if ((i + 2) < argc) {
                    std::string square_width = argv[i + 1];
                    std::string square_height = argv[i + 2];
                    if (isNumber(square_width) && isNumber(square_height)) {
                        uint16_t temp_width = std::stoi(square_width);
                        uint16_t temp_height = std::stoi(square_height);

                        float report = static_cast<float>(temp_width) / static_cast<float>(temp_height);
                        bool rep_condition = (temp_width >= 200) && (temp_height >= 200) && (0.5f < report) && (report < 2.f);

                        if (rep_condition) {
                            width = temp_width;
                            height = temp_height;
                        } else {
                            std::cout << "Inacceptable window size. Using 1024x768" << std::endl;
                        }

                    } else {
                        std::cout << "Invalid expression. Using 1024x768" << std::endl;
                    }
                } else {
                    std::cout << "Invalid expression. Using 1024x768" << std::endl;
                }
                break;
            }
            case str2int("-m"):
                if ((i + 1) < argc) {
                    map = argv[i + 1];
                } else {
                    std::cout << "Invalid expression. Using default map" << std::endl;
                }
                break;
            case str2int("-f"):
                if ((i + 1) < argc) {
                    forecast = argv[i + 1];
                } else {
                    std::cout << "Invalid expression. Using default map" << std::endl;
                }
                break;
            case str2int("-h"): {
                /// @todo: display help
                
            } return 0;
            }
        }
    }
    
    Application app(width, height, map, forecast);
    return app.start();
}
