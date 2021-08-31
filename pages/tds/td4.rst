
Tutorial 4: Further with ADXL345
==========================

.. image:: /img/spark.png
    :class: right

External interrupt
--------------------

.. step::

    **Read ADXL345 documentation from previous tutorial concerning interrupts**

    * What are they used for?
    * How can you interface it with your microcontroller?

.. step::

    **Implementing the DATA_READY interrupt**

    Wire the component properly and use *INT1* to trigger when a *DATA_READY* occurs and
    call a routine to read a new sample from your microcontroller.

Timer
-----

.. step::

    Setup a timer allowing you to measure the time spent between to moments.

.. step::

    With the help of this timer, estimate the number of sample per seconds.

.. step::

    Check out that this number matches the one you can read in ADXL345 documentation. Change
    this sampling frequency and check that the measure is indeed changing.

