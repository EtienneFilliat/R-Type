/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** SafeQueue
*/

#ifndef PROJECT_SAFEQUEUE_HPP
    #define PROJECT_SAFEQUEUE_HPP

    #include <queue>
    #include <mutex>
    #include <condition_variable>

template <typename T>
class SafeQueue {
public:
    SafeQueue() = default;
    ~SafeQueue() = default;
    bool empty() noexcept
    {
        std::unique_lock<std::mutex> lock(_mutex);
        bool err;

        err = this->_queue.empty();
        lock.unlock();
        return (err);
    }
    size_t size() noexcept
    {
        std::unique_lock<std::mutex> lock(_mutex);
        size_t size;

        size = this->_queue.size();
        lock.unlock();
        return (size);
    }
    void push(T &&value)
    {
        std::unique_lock<std::mutex> lock(_mutex);

        this->_queue.push(std::move(value));
        lock.unlock();
        cond.notify_one();
    }
    void push(const T &value)
    {
        std::unique_lock<std::mutex> lock(_mutex);

        this->_queue.push(value);
        lock.unlock();
        cond.notify_one();
    }
    T pop()
    {
        std::unique_lock<std::mutex> lock(_mutex);

        while (_queue.empty())
            cond.wait(lock);
        auto item =_queue.front();
        _queue.pop();
        return item;
    }
private:
    std::mutex _mutex;
    std::queue<T> _queue;
    std::condition_variable cond;
};

#endif //PROJECT_SAFEQUEUE_HPP
