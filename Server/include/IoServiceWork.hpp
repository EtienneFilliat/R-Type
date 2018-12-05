/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** IoServiceWork
*/

#ifndef IOSERVICEWORK_HPP_
	#define IOSERVICEWORK_HPP_

    #include <boost/asio.hpp>
    #include <boost/thread/thread.hpp>

class IoServiceWork {
	public:
		IoServiceWork()
            : m_ioService(new boost::asio::io_service()),
            m_ioServiceWork(new boost::asio::io_service::work(*m_ioService)),
            m_ioWorkThread(new std::thread(std::bind(&IoServiceWork::runIoService, this)))
        {}
		~IoServiceWork()
        {
            delete m_ioServiceWork;
            delete m_ioWorkThread;
            delete m_ioService;
        }

        boost::asio::io_service& ioService()
        {
          return *m_ioService;
        }

        void runIoService()
	{
			m_ioService->run();
	}

	private:
        boost::asio::io_service* m_ioService;
        boost::asio::io_service::work* m_ioServiceWork;
        std::thread* m_ioWorkThread;
};

#endif /* !IOSERVICEWORK_HPP_ */
