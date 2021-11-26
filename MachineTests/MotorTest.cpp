/**
 * @file MotorTest.cpp
 * @author Anurag Kompalli
 */

#include "pch.h"
#include "gtest/gtest.h"

#include <ActualMachine.h>

TEST(MotorTest, Construct)
{
    auto motor = std::make_shared<Motor>();
}

TEST(MotorTest, Speed)
{
    auto motor = std::make_shared<Motor>();
    motor->SetSpeed(0.5);
    ASSERT_NEAR(motor->GetSpeed(), 0.5, 0.000001);

    motor->SetSpeed(0);
    ASSERT_NEAR(motor->GetSpeed(), 0, 0.000001);

    motor->SetSpeed(2);
    ASSERT_NEAR(motor->GetSpeed(), 2, 0.000001);
}


TEST(MotorTest, Updates)
{
    auto motor = std::make_shared<Motor>();
    auto genericComponent = std::make_shared<Component>();

    auto mockSink = std::make_shared<RotationSink>(genericComponent.get());

    motor->GetSource()->AddSink(mockSink.get());
    motor->SetSpeed(0.5);
    motor->UpdateMachine(1);

    double rotations = mockSink->GetRotation();
    ASSERT_NEAR(rotations, 0.5, 0.000001);

    motor->SetSpeed(1);
    motor->UpdateMachine(2);
    rotations = mockSink->GetRotation();

    ASSERT_NEAR(rotations, 2, 0.000001);
}