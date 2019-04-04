#include <iostream>
#include "TXT_Manager.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    TXT_Manager holiwis;
    holiwis.verif_palabra("YUXTAPOSICION");
    return 0;

}