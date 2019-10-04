all:
	gcc test.cpp -std=c++11 -lcurl -lcrypto, -ljsoncpp -Iaip-cpp-sdk-0.8.3 -I/usr/include/jsoncpp
