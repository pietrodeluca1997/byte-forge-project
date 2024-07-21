#include <queues/LogQueue.h>

namespace ByteForgeEngine::LoggingSystem
{
	LogQueue::LogQueue(function<void(const LogEntryProperties&)> callback) : logCallback(callback)
	{
		isRunning = true;
		logThread = thread(&LogQueue::Process, this);
	}

	LogQueue::~LogQueue() {
		Stop();
	}

	void LogQueue::Stop()
	{
		isRunning = false;
		threadCondition.notify_one();
		logThread.join();
	}

	void LogQueue::AddLogEntry(const LogEntryProperties& logEntryProperties)
	{
		lock_guard<mutex> lock(threadMutex);
		logQueue.push(logEntryProperties);
		threadCondition.notify_one();
	}

	void LogQueue::Process() {
		while (isRunning) {
			unique_lock<mutex> lock(threadMutex);
			threadCondition.wait(lock, [this] { return !logQueue.empty() || !isRunning; });

			if (!logQueue.empty()) {
				LogEntryProperties logMessage = logQueue.front();
				logQueue.pop();
				logCallback(logMessage);
			}
		}
	}
}