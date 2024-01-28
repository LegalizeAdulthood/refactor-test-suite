#pragma once

#include <coroutine>
#include <exception>
#include <utility>

namespace RenameCpp20
{

// #TEST#: R854 Rename struct Point
struct Point
{
    // #TEST#: R855 Rename member x
    int x;
    // #TEST#: R856 Rename member y
    int y;
    // #TEST#: R857 Rename member z
    int z;
};

// Cribbed from https://en.cppreference.com/w/cpp/language/coroutines
template <typename T>
struct Generator
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type
    {
        T m_value;
        std::exception_ptr m_exception;

        Generator get_return_object()
        {
            return Generator(handle_type::from_promise(*this));
        }
        std::suspend_always initial_suspend()
        {
            return {};
        }
        std::suspend_always final_suspend() noexcept
        {
            return {};
        }
        void unhandled_exception()
        {
            m_exception = std::current_exception();
        }

        template <std::convertible_to<T> From>
        std::suspend_always yield_value(From &&from)
        {
            m_value = std::forward<From>(from);
            return {};
        }
        void return_void()
        {
        }
    };

    Generator(handle_type h) : m_handle(h)
    {
    }
    ~Generator()
    {
        m_handle.destroy();
    }
    explicit operator bool()
    {
        fill();
        return !m_handle.done();
    }
    T operator()()
    {
        fill();
        m_full = false;
        return std::move(m_handle.promise().m_value);
    }

private:
    handle_type m_handle;
    bool m_full{};

    void fill()
    {
        if (!m_full)
        {
            m_handle();
            if (m_handle.promise().m_exception)
            {
                std::rethrow_exception(m_handle.promise().m_exception);
            }
            m_full = true;
        }
    }
};

}    // namespace RenameCpp20
