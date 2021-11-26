Project: Persistent of View
==========================================

The goal of this project is to program a **persistent of view** display.
A 16 leds strip is assembled on a board itself assembled on a rotating motor. By changing
the leds configuration while it's moving, it is then possible to display things:

.. center::
    .. youtube:: syYFvFRE7No

.. important::
    `Board's schematics </files/pov.pdf>`_

#=) Constraints
~~~~~~~~~~~~~~~

* This is a group projects (to be defined during the class),
* You can't use any external library, it will be programmed using *bare-metal*, just like
  we did during tutorials
* You should create a **private** git repository and share it with your teachers.

.. image:: /img/pov.png
    :class: right

#=) Getting started with hardware
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#~) Components list
-------------------------------------

Here are provided components:

1. `One "POV" board </files/pov.pdf>`_
2. `Two magnets, diameter 12mm, thickness 5mm <https://fr.aliexpress.com/item/1005001404825174.html>`_
3. `One (fan) motor 60x60x25mm, with a threaded shaft assembled in the plastic box
  <https://www.aliexpress.com/item/32882742546.html>`_
4. `A 12V power supply, with DC 5.5mm connector <https://www.aliexpress.com/item/32980020011.html>`_
5. `A programming module, USBASP 10 pins, with 10 to 6 pins adapter
  <https://fr.aliexpress.com/item/32670511994.html>`_
6. `An Allen hexkey 2.5mm <https://www.bricovis.fr/std/cles-males-allen-35.php>`_

#~) Programming
-------------------------------------

The board is assembled with a brand new microcontroller, there is no *bootloader*
on it. You have to program it using your USBASP programming module (which is a
*low-cost* version of ISP).

.. note::
    In ``avrdude``, use: ``-c usbasp``

.. warning::
    The USBASP comes with an adapter to connect it to 6 pins ISP. This one is not equiped with a
    keyed connector, that is why it is marked with a white dash. If any doubt about the orientation
    of the connector please ask your teacher.

First, adapt your ``Makefile`` to be able to program this board. You can first try getting the
``PD6`` blue led blinking.

CPU's frequency is 13Mhz (``13000000``), and the microcontroller's fuses are already setup to use
an external clock.

If you use Windows, it possible that the programming module is not detected. You can use
Zadig software to install drivers, with the following settings:

.. center::
    .. image:: /img/zadig.png

#~) Batteries
-------------

POV's batteries are automatically charging when you plug it to the computer (using
the USB 5V), even if the POV's switch is off. The red LED "charge" is kept on
until the charge is over.

Please check that your POV is turned off when you are stopping working, you can
check it by watching if green *power* LED is off.

#~) UART communcation
-----------------------

The board features a *bluetooth HC-05* chip. To communicate with it, you will
need to get the UART bus working, and to configure it the proper way.

Setting up the communication with the board is essential to be able to *debug* or
control it (like setting the time of the clock).

A number is labeled on your PCB (for example ``POV 34``). The Bluetooth chip is already
configured with following parameters:

    Name: POV**N** 
    Pin: 00**N** 
    Baud rate: 38400

Where ``N`` is your group number (for example ``POV 34`` will have ``0034`` for PIN).

.. note::
    To communicate with the Bluetooth board, you can use your PC, but also your mobile phone.
  

#~) Charset
~~~~~~~~~~~

At some point you will have to draw some messages on the POV. For this, we recommend you
write some code to generate some C code to embed the characters images in the board memory.

An example is using Python and OpenCV to open PNG files and access them at pixel level to
generate C code.

#=) Software roadmap
~~~~~~~~~~~~~~~~~~~

.. step::

    #~) Handling LEDs
    ---------------------

    As you can notice on schematics, the board features 16 LEDs and a driver allowing
    to control their current.

    You have to implement code to turn them on and off.

.. step::

    #~) Magnetic sensor
    ----------------------

    The hall effect magnetic sensor allows to detect magnet presence.
    You can test it by simply turning a LED on or off when a magnet is detected.
    
    You can then setup an external interrupt that will be automatically triggered when
    the magnet is present.

.. step::

    #~) Computing current time
    ----------------------

    With the help of timers, you should be available to compute current time.

    Write some code to setup the initial time through Bluetooth communication from your
    computer or your phone.

#=) Modes of operation
~~~~~~~~~~~~~~~~~~~

.. warning::

    Note: keep an easy way to do a demo of all the asked modes during the project's defense

.. step::

    #~) Displaying a needles clock
    ---------------------------------

    You now can assemble all those elements to program your clock. The first goal will
    be to display time using LEDs "needles".

    .. center::
        .. image:: img/clock_1.jpg

.. step::

    #~) Rounded digital clock
    ----------------------------------------

    The next goal is to show the current time using digits, without
    compensating rotation's distortion, like this:

    .. center::
        .. image:: img/other_clock.jpg

.. step::

    #~) Straight digital clock
    -----------------------------------------

    Now, compensate for distortion by displaying straight digital clock:

    .. center::
        .. image:: img/clock_2.jpg

.. step::

    #~) Technical expectations
    ---------

    - Spatial accuracy and granularity. What is the precision you can create a dot at a given coordinate?
    What is the minimum size of this dot?
    - Temporal accuracy and granularity. What is the LEDs refreshing frequency ? What is the granularity you
    can reach to measure the boards's rotation duration?
    - What is the board's rotating speed? Quantify its stability
    - Time estimation accuracy. If you start with a perfect time, how much will it drift after 6 month of use?
    - Code efficiency. What is the cost (in time and in number of cycles) of your interrupts? Of a floating
    multiplication and division? Of an integer multiplication and division?
    - How much memory do you use? How much is left? What are different types of memory available and what are they
    used for?

#=) Test firmware
~~~~~~~~~~~~~~~~~~~~~~~~~~~

If any doubt about your board, you can flash the following test firmware:

* Télécharger `pov-demo.bin <files/pov-demo.bin>`_

With this firmware:

* Blue (``PD6``) LED blinks at startup
* White LEDs are turning on one by one
* If you present a magnet to the hall effect sensor, the white LEDs colors are inverted

.. If you connect using Bluetooth and send a message, the firmware should answer ``POV echo: message``,
.. where ``message`` is the message you sent

  
