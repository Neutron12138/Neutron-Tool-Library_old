#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

class Emitter : public ntl::Reflectible
{
public:
    ntl::Signal signal = ntl::Signal(1);

    void emit()
    {
        signal.emit(666);
    }
};

class Receiver : public ntl::Reflectible
{
public:
    void received(int num)
    {
        std::cout << "received:" << num << std::endl;
    }
};

class Emitter2 : public ntl::Signalable
{
public:
    Emitter2()
    {
        m_signals.insert(
            ntl::Signalable::SignalMap::value_type(
                "signal",
                ntl::Signal(1)));
    }

public:
    void emit_signal()
    {
        emit("signal", 123);
    }
};

int main()
{
    try
    {
        Receiver receiver;

        Emitter emitter;
        emitter.signal.connect("receiver", &receiver, &Receiver::received);
        emitter.emit();

        Emitter2 emitter2;
        emitter2.connect("signal", "receiver", &receiver, &Receiver::received);
        emitter2.emit_signal();
    }
    catch (const ntl::CaughtException &exception)
    {
        std::cout << exception << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}