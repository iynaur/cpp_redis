#include <cpp_redis/core/client.hpp>
#include <iostream>

int main()
{
    cpp_redis::client client;

    client.connect();

    client.set("hello", "42");
    client.get("hello", [](cpp_redis::reply& reply) {
      std::cout << reply << std::endl;
    });
    //! also support std::future
    //! std::future<cpp_redis::reply> get_reply = client.get("hello");

    client.sync_commit();
    //! or client.commit(); for asynchronous call
}
