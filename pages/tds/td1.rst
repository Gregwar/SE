
.. image:: /img/uno.png
    :class: right

Tutorial 1: Bye bye, Arduino
=====================

The goal of this tutorial is programming **Arduino Uno** board without using **Arduino**'s IDE.

Ressources
-------------------------

.. important::
    `Elegoo Super Starter Kit <https://www.elegoo.com/product/elegoo-uno-project-super-starter-kit/>`_ 
    `ATmega328P documentation (datasheet) </files/atmega328p.pdf>`_  
    `Pin mapping for UNO/ATmega328P <https://www.arduino.cc/en/Hacking/PinMapping168>`_  
    `Arduino Uno schematics <https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf>`_

Compilation toolchain
---------------------

.. step::

    Your goal is to write a ``Makefile`` allowing compiling and flashing of the following code,
    that enables on-board LED (``PB5``, marked "L" on the PCB):

    .. code-block:: cpp

        #include <avr/io.h>

        int main() {
            // Enables and turn the PB5 pin ON (led)
            DDRB |= _BV(PB5);
            PORTB |= _BV(PB5);
        }

    Here are the main steps will have to follow:

    * Use ``avr-gcc``, compiler to produce the binary
    * Use ``avr-objcopy`` to extract a "raw" binary (not elf)
    * Use ``avrdude``, a tool to flash the board

    Make it so that you will run:

    * ``make`` to build the firmware
    * ``make install`` to send the firmware on the board

    .. note::
        To install the toolchain:

        * Ubuntu: ``apt-get install avrdude gcc-avr avr-libc``
        * Windows: You can install Arduino, and then find the installation directory, the toolchain will be available there

Controlling a stepper
---------------------

.. step::

    The Arduino kit you have provides a stepper motor (28BYJ-48) and its driver (ULN2003APG):

    .. center::
        .. image:: /img/stepper.png
        .. image:: /img/stepper_schematics.png

    Plug ``-`` on ``GND``, ``+`` on ``VIN`` on ``IN1``, ``IN2``,
    ``IN3`` on ``IN4`` on any GPIO you want.

    To control it, you can simply switch it step by step:
    
    ===========  ============= ============= ============= =============
                 IN1           IN2           IN3           IN4
                 Blue          Pink          Yellow        Orange
    ===========  ============= ============= ============= =============
    Step1        1             1             0             0
    ===========  ============= ============= ============= =============
    Step2        0             1             1             0
    ===========  ============= ============= ============= =============
    Step3        0             0             1             1
    ===========  ============= ============= ============= =============
    Step4        1             0             0             1
    ===========  ============= ============= ============= =============

    Use some delay to wait in between each phase.
