
#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

namespace rendersystem {

/**
  * @ingroup RenderSystem
  * A simple timer.
  *
  * @bug Only for Linux/UNIX/MacosX
  */
class Timer {
public:

    typedef double Time;

    Timer() : last_ ( 0. ) {
        reset();
    }

    ~Timer() {
    }

    inline void start ( void ) {
        last_ = getTime();
    }
    inline void stop ( void ) {
        sum_ += getTime() - last_;
    }
    inline void reset ( void ) {
        sum_ = 0.;
    }

    inline Time value ( void ) const {
        return sum_;
    }

    static Time getTime ( void ) {
        struct timeval tv;
        struct timezone tz;
        gettimeofday ( &tv, &tz );
        return ( Time ) ( ( double ) tv.tv_sec + 1.e-6 * ( double ) tv.tv_usec );
    }

protected:

    Time sum_, last_;

};

}
#endif
