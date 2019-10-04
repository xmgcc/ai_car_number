#include <iostream>
#include "ocr.h"

using namespace std;

int main(int argc, char **argv)
{
    int ret;
    std::string in_car_number;

    const std::string appid = "17429561";
    const std::string api_key = "PX3iSpAgRum7usSBAYvfyQkO";
    const std::string secret_key = "BBEo6CpGtAvod3z1txBjRFzWqeNOVpKh";

    // create ocr
    aip::Ocr *ocr = new aip::Ocr(appid, api_key, secret_key);
    
    // load picture
    ret = aip::get_file_content("assets/car.png", &in_car_number);
    if (ret < 0) {
        printf("get_file_content failed\n");
        return -1;
    }

    // ocr by baidu api
    Json::Value out_car_number = ocr->license_plate(in_car_number, aip::null);

#if 0
    {
        "log_id": 3583925545,
        "words_result": {
            "color": "blue",
            "number": "苏HS7766"
            }
    }
#endif
    std::string number = out_car_number["words_result"]["number"].asString();
    std::cout << number << std::endl;

    delete ocr;
    return 0;
}
