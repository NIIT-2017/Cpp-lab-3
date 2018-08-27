#include "gtest/gtest.h"
#include "common.h"

#include "ocean.h"


TEST(lab3,task1_1)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Test1.txt";
		
    bool result=atlantic->read(ch);

    EXPECT_EQ(1,result);
}


TEST(lab3,task1_2)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Test2.txt";
		
	
    bool result=atlantic->read(ch);

    EXPECT_EQ(1,result);
}


TEST(lab3,task1_3)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Coral";
	
	
    int result=atlantic->fill(ch, 1, 4);

    EXPECT_EQ(4,result);
}


TEST(lab3,task1_4)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Predator";
	
	
    int result=atlantic->fill(ch, 1, 11);


     
    EXPECT_EQ(11,result);
}


TEST(lab3,task1_5)
{
    Ocean *atlantic =new Ocean;
	
    char ch[200] = "Время цикла питания";
	
	
    int result=atlantic->fill(ch, 1, 9);

    EXPECT_EQ(9,result);
}

