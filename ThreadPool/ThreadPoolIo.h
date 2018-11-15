#pragma once

#include <functional>
#include "ThreadPool.h"

namespace ThreadPool {

	class IOItem {


		static void CALLBACK callback(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PVOID Overlapped, ULONG IoResult, ULONG_PTR NumberOfBytesTransferred, PTP_IO Io) {
			IOItem *item = static_cast<IOItem*>(Context);
			item->IoCompletion(Overlapped, IoResult, NumberOfBytesTransferred);
		}

	protected:
		IOItem(HANDLE h, void* context, PTP_CALLBACK_ENVIRON env) {
			m_item = CreateThreadpoolIo(h, callback, context, env);
		}

		PTP_IO m_item;

	public:

		virtual void IoCompletion(PVOID Overlapped, ULONG IoResult, ULONG_PTR NumberOfBytesTransferred) = 0;

		~IOItem() {
			CloseThreadpoolIo(m_item);
		}
	};


	template <typename F_USER_PENDING>
	class ThreadPoolIO : public IOItem {

		using F_USER_PENDING_HANDLER = std::function<void(const PVOID, const ULONG, const ULONG_PTR)>;

		F_USER_PENDING				m_IoPendingFunc;
		F_USER_PENDING_HANDLER		m_IoPendingHandlerFunc;

		void IoCompletion(PVOID Overlapped, ULONG IoResult, ULONG_PTR NumberOfBytesTransferred) {
			m_IoPendingHandlerFunc(Overlapped, IoResult, NumberOfBytesTransferred);
		}

	public:

		ThreadPoolIO(HANDLE h, F_USER_PENDING IoPendingFunc, F_USER_PENDING_HANDLER	IoPendingHandlerFunc, ThreadPool &tp = GetMainThreadPool()) : IOItem(h, this, tp) {
			m_IoPendingFunc = IoPendingFunc;
			m_IoPendingHandlerFunc = IoPendingHandlerFunc;
		}

		void IoPending() {
			StartThreadpoolIo(m_item);

			DWORD err = ERROR_SUCCESS;
			bool ret = m_IoPendingFunc();

			if (ret == true || (ret == false && (err = GetLastError()) != ERROR_IO_PENDING)) {
				CancelThreadpoolIo(m_item);
				m_IoPendingHandlerFunc(nullptr, err, 0);
			}
		};
	};

}
