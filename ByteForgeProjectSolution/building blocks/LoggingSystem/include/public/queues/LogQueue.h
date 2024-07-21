#ifndef LOG_QUEUE_H
#define LOG_QUEUE_H

#include <thread>
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <models/LogEntryProperties.h>

using std::thread;
using std::queue;
using std::string;
using std::mutex;
using std::condition_variable;
using std::function;
using std::lock_guard;
using std::unique_lock;

namespace ByteForgeEngine::LoggingSystem {
	class LogQueue {
	public:
		LogQueue() : isRunning(false) {};
		LogQueue(function<void(const LogEntryProperties&)> callback);
		virtual ~LogQueue();

		void Stop();
		void AddLogEntry(const LogEntryProperties& logEntryProperties);
	private:
		thread logThread;
		queue<LogEntryProperties> logQueue;
		mutex threadMutex;
		condition_variable threadCondition;
		function<void(const LogEntryProperties&)> logCallback;
		bool isRunning;

		void Process();
	};
}

#endif // !LOG_QUEUE_H

