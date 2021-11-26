
Tutorial 2: Let's communicate!
==================


.. image:: /img/adxl345-module.jpg
    :class: right

UART
----

.. step::

    Your **Arduino Uno** board is connected to an USB/Uart emulator, allowing your computer
    to discuss with it through USB.

    Our first goal will be to write some code able to communicate through this port.

    You can use ``cu`` with command line, or `PuTTy <https://www.putty.org/>`_ to open the
    port and communicate.


ADXL345 Module
--------------

You will be provided a chip named `ADXL345 </files/adxl345.pdf>`_. for practical reasons,
it is already soldered on a board (we call this *breakout*) named GY-291:

.. center::

    .. image:: /img/GY-291.jpg
        :width: 700


.. step::

    **Have a look at the chip specification**
    What communication bus is used? 

.. step::

    **Try answering following questions:**

    * What is the address of the chip?
    * What is it measuring?
    * Find some application example
    * How are measures represented numerically?

.. step::

    **Choose proper pins and plug the module to your Arduino Uno.**

.. step::
    **Implement proper bus in your code.**
    With the help of microcontroller's and module's documentation, implement communication
    to retrieve the sampled values.
    
Integration
-----------

.. step::

    Display those values through UART bus

.. step::

    From those information, compute the *pitch* and the *roll* currently experienced
    by the sensor.
