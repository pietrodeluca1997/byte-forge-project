#include <gtest/gtest.h>
#include <LogManager.h>

using namespace ByteForgeEngine::LoggingSystem;

TEST(LogManagerTests, ShouldLogOnMultipleOutputs) {
	ByteForgeEngine::LoggingSystem::LogManager logManager;

	logManager.AddConsoleOutput();
	logManager.AddWindowsVisualStudioDebugOutput();

	testing::internal::CaptureStdout();

	logManager.Entry("Number: %d\n", 15);

	std::string output = testing::internal::GetCapturedStdout();

	// If the test reaches this point, it means that the test passed (Windows visual studio debug purposes)
	EXPECT_TRUE(true);
	// If the output is equal to "Number: 15\n", the test passed
	EXPECT_EQ(output, "Number: 15\n");
}