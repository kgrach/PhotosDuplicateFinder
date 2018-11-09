#pragma once

#include <Windows.h>

namespace ThreadPool {

	class ThreadPool {
		PTP_POOL m_tp;
		TP_CALLBACK_ENVIRON m_env;

		bool m_is_starting;
	public:
		ThreadPool() : m_is_starting(false) {
		}

		void StartingWork() {
			m_tp = CreateThreadpool(nullptr);
			InitializeThreadpoolEnvironment(&m_env);

			SetThreadpoolCallbackPriority(&m_env, TP_CALLBACK_PRIORITY_NORMAL);
			SetThreadpoolCallbackPool(&m_env, m_tp);

			SYSTEM_INFO sysinfo;
			GetSystemInfo(&sysinfo);

			SetThreadpoolThreadMaximum(m_tp, 2 * sysinfo.dwNumberOfProcessors);
			SetThreadpoolThreadMinimum(m_tp, sysinfo.dwNumberOfProcessors);

			m_is_starting = true;
		}

		bool IsStarted() {
			return m_is_starting;
		}

		~ThreadPool() {

			if (m_is_starting) {
				DestroyThreadpoolEnvironment(&m_env);
				CloseThreadpool(m_tp);
			}
		}

		operator PTP_CALLBACK_ENVIRON() {
			return &m_env;
		}
	};

	ThreadPool& GetMainThreadPool();
}





