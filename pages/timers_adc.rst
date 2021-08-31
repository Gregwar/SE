Timers and ADCs
=============

.. slide::

DAC
---

DAC stands for Digital to Analog converter, it allows to convert a number represented
in memory with bits (for eg. from 0 to 1023) to a voltage level (for eg. from 0 to 5V).

.. slide::

**PWM-DAC**

.. textOnly:: 
    A simple solution to achieve this is to use a periodic signal that goes through
    a low-pass filter, producing an "averaged" signal:

.. center::
    .. image:: img/pwm_dac.jpg

.. slide::

**Thermometer DAC**

.. textOnly:: 
    Another method is the thermometer one, using a string of resistors allowing to
    represent all possible values. The output can then be selected using a multiplexer.
    This solution has a huge footprint, because all values corresponds to a physical point
    in the circuit.

.. center::
    .. image:: img/thermometer.gif

.. slide::

**R2R DAC**

.. textOnly:: 
    Finally, R2R ladder is a way to combine resistors to produce a voltage level using
    directly the bits representation:

.. center::
    .. image:: img/r2r.png

.. slide::

ADC
---

ADC is inverse of DAC, standing for Analog to Digital Convertion. It consists in sampling
a voltage level to represent it numerically in the program.

ADC design is dual to DAC ones, comparing produced voltages with the input to sample:

.. slide::

.. center::
    .. image:: img/adc_flash.png

.. textOnly::
    For example, the "flash" ADC (above) is the dual to thermometer DAC, containing all
    possible voltage levels.

.. slide::

In ATmega328P, the ADC is based on successive comparisons using values from an internal DAC:

.. center::
    .. image:: img/atmega_dac.png

.. slide::

.. image:: img/quartz.jpg
    :class: right

Timers
------

Time is ticked using a low-level oscillator named **quartz** generating a periodic signal
at a given frequency.

.. discover::
    This clock can be sped up using *PLL*, or sped down using *dividers*

.. slide::

Operation
~~~~~~~~~~~~~~

A timer is a configurable feature, where an initial clocks increments a register at
a given frequency.

.. discover::
    When this register reaches its maximum value, it will go back to 0, this is
    **overflow**

.. discover::
    Dependeing on the timer, this maximum value can be the representation of the
    value (like ``0xFF`` or ``0xFFFF``) or set by user to arbitrary value.

.. discover::
    An interrupt can be used at this particular time to trigger some periodical event.

.. slide::

PWM
~~~

Often, timers comes with the possibility to generate output hardware PWM.

In this case, the state of a pin can be changed each time the timer reaches 0 or
a particular value:

.. slide::

.. center::
    .. image:: img/fast_pwm_example.png

.. slide::

.. redirection-title:: tds/td4

TD
---

.. toctree::
    tds/td4
