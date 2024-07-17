#include "gtest/gtest.h"
#include "WindowsVisualStudioLogOutput.h"

using namespace ByteForgeEngine::LoggingSystem;

TEST(LogOutputTests, WindowsVisualStudioLogOutputCheck) {
	ByteForgeEngine::LoggingSystem::WindowsVisualStudioLogOutput output;

	output.Log("Number: %d\n", 15);

	// If the test reaches this point, it has passed
	EXPECT_TRUE(true);
}