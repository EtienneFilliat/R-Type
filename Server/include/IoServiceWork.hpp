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
            m_ioWorkThread(new boost::thread(boost::bind(&boost::asio::io_service::run, m_ioService)))
        {}
		~IoServiceWork()
        {
            delete m_ioServiceWork;
            m_ioWorkThread->interrupt();
            delete m_ioWorkThread;
            delete m_ioService;
        }

        boost::asio::io_service& ioService()
        {
          return *m_ioService;
        }

	private:
        boost::asio::io_service* m_ioService;
        boost::asio::io_service::work* m_ioServiceWork;
        boost::thread* m_ioWorkThread;
};

#endif /* !IOSERVICEWORK_HPP_ */
