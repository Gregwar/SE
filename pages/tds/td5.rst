
Tutorial 4: PlatformIO (ADC et Servo)
==========================

.. image:: /img/platformio.png
    :class: right

Setting up
-------------

.. step::

    After installing at least PlatformIO core, create a directory and run:

    .. code-block:: bash

        pio project init --board uno

    Have a look at ``platformio.ini`` file:

    .. code-block:: ini

        [env:uno]
        platform = atmelavr
        board = uno
        framework = arduino

    To compile:

    .. code-block:: bash

        pio run

    To flash:

    .. code-block:: bash

        pio run -t upload

    Use Arduino's API to get a blinking LED

Sampling ADC and servos
----------------------------------

.. step::

    Use Arduino's API to get some ADC samples from a photoresistor from your kit and
    control the servomotor:

    .. center::
        .. image:: /img/photoresistor.webp

        .. image:: /img/sg90.jpg
            :width: 300

Back to ADXL345
--------------------

.. step::

    On `PlatformIO <https://platformio.org/>`_, find the library allowing you to communicate
    with ADXL345 and install it. Use it to get the samples from the accelerometer.
    