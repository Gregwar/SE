.. slide:: middleSlide

Communication buses
=====

.. slide::

Presentation
------------

Standard communication buses emerged from the need of getting MCU and IC
communicating together. We will here present some of them.

.. slide::


Lines
~~~~~

Before discussing about buses, let's discuss how physical electronic lines work.
Contrary to the "computer scientist" vision, an electronic line is not only "0" or "1",
it is at a given **voltage level**, but also a certain **impedance**.

.. slide::

A line can be driven at low impedance using push/pull transistors:

.. center::
    .. image:: img/push-pull.png

.. slide::

Symbolically, this can be represented with a triangle, and called line driver or buffer.

.. center::
    .. image:: img/tristate.png

Here, the input "B" is equivalent to ``pinMode`` in Arduino, or writing to ``DDRx``
register on the **ATmega328P**, it allows us to either drive the line or let it "floating".

.. slide::

Another possible configuration is "open-drain", that is like push-pull but without the upper
transistor, allowing to pull the line to the ground, but letting it floating else:

.. center::
    .. image:: img/push-pull-od.png

.. slide::

When a line is input high impedance and nothing is plugged (the line is floating), any voltage can be
read due to any kind of interference. If one wants to impose a "default" logic level, it should use
the so-called pull-up/down resistors:

.. center::
    .. image:: img/pull.jpg

.. slide::

In the case of **ATmega328P**, each input/output can actually be set in 4 different
modes:

* **Low impedance (output)**
    * Output high level (ex: 5V)
    * Output low level (0V)
* **High impedance (input)**
    * Input floating
    * Input with pull-up

.. discover::
    .. note::
        Open drain mode can be implemented by writing ``0`` in ``PORTx`` and using ``DDRx`` to
        either set the pin as output or input.

.. discover::
    .. note::
        More complex microcontrollers typically also offer pull-down resistor input possibility

.. slide::

Generalities
~~~~~~~~~~~

.. discoverList::
    * Voltage level?
    * Analog / Digital?
    * Synchronous / Asynchronous ?
    * Full duplex / Half duplex ?
    * Bandwidth ?
    * Robustness ?
    * Protocol ?
    * Efficiency ?

.. slide::

UART
----

UART, also sometime simply called "Serial", is one of the most famous buses.
It is an asynchronous bus (without clock). This implies an agreement on the
communication frequency, called *baud rate*.

.. discover::
    Bytes are transmitted bit per bit (serial).

.. discover::
    Bytes starts with a *start bit* and are followed by a *stop bit* allowing
    to keep synchronisation among lines.

.. slide::

**TTL**

Typically, UART uses two wires TX and RX. Each controller drives its TX pin and listens
on its RX.

.. discover::
    In the most standard form, UART bus is full-duplex.

.. slide::

.. image:: img/rs232.jpg
    :class: right

**RS-232**

RS-232 is another UART standard using more robust voltage levels, typically -12V
and 12V.

It is likely you already saw the historical connector on some old machines.

.. discover::

    **RS-485**

    RS-485 is another standard that is half-duplex and use 2 symetrical wires,
    the difference should be -200mV or +200mV to specify a 0 or a 1.

.. slide::

.. important::
    There are historical typical baud rates, most famouses are 9600, 57600
    or 115200.
    UART can reach only some Mbit/s

.. slide::

I2C/TWI
-------

I2C (Inter-Integrated Circuit), or TWI (Two Wire Interface) is a bus type that uses two wires,
it is synchronous and half-duplex.

.. discover::
    Those lines are pulled to high voltage level with pull-ups and driven by open drains

.. slide::

.. center::
    .. image:: img/i2c.png

.. slide::

.. textOnly::
    I2C is based on a protocol with address, arbitration and acknowledgements.

.. center::
    .. image:: img/i2c_protocol.jpg

.. slide::

If multiple masters start a frame simultaneously, the arbitration is implemented by monitoring
the line level (if LOW is read when the open drain is open, frame is stopped because of a collision).

Thus, addresses with the more ``0``s in the high part have more priority in the arbitration.

.. slide::

.. important::
    This protocol is very widespread, but is limited to 400kbit/s.
    There is however "fast" variants of I2C.

.. slide::

SPI
---

.. textOnly::
    SPI (Serial Peripheral Interface) is a full-duplex and synchronous bus.
    On a SPI bus, there is one master and several slaves.

    It is using 4 lines:

    * **SCK**: The clock indicating when bits are transmitted (synchronous)
    * **MOSI** and **MISO**: respectively *Master Output/Slave Input* and *Master Input/Slave Output*
    * **CS**: For *Chip Slect*, indicating to a slave if it is activated (this allows multiple slave
    to share *MOSI* and *MISO*)


.. center::
    .. image:: img/spi.png

.. slide::

.. textOnly::
    Master is always ticking the clock, meaning that when a slave is responding, it is still
    ticked by the master.

.. center::
    .. image:: img/spi_diagram.jpg

.. slide::

.. important::
    SPI is widespread, and allows for high bandwidth (more than 10 Mbit/s)

.. .. slide::

.. CAN
.. ---

.. Le protocole CAN est un protocole série, basé sur un accord préalable de rapidité (baud rate).
.. Il est très utilisé dans le monde industriel et automobile. Physiquement, il exploite deux lignes
.. CANH et CANL, et se base sur un état dominant et récessif.

.. .. textOnly::
..     Il comporte un arbitrage, comme I2C, et les messages démarrent par un identifiant qui sert
..     justement à ajuster la priorité. Chaque trame comporte également un somme de contrôle CRC.

.. .. slide::

.. .. center::
..     .. image:: img/can.png

.. slide::

.. redirection-title:: tds/td2

TD
---

.. toctree::
    tds/td2
