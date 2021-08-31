
Tutorial 3: Interrupts and ring buffer
==========================

.. image:: /img/spark.png
    :class: right

UART and interrupt
-------------------

.. step::

    Setup an interruption triggered when some byte is received or when buffer is available
    to transmit to avoid the need of polling.


.. note::
    The interrupt indicating that the buffer is ready to transmit will be always
    triggered if you don't send anything; you might want to enable it only when you
    have something to send, and disable it after.

Ring buffer
------------------

.. step::

    Setup a ring buffer allowing you to store data to send and received data.

    Here is an example of the methods you can have to use your UART port:

.. code-block:: c

    // Sends data (store them in the ring buffer)
    void usart_send_byte(uint8_t byte);
    void usart_send_string(uint8_t *str);
    // Returns the number of available bytes in receive ring buffer
    size_t usart_available();
    // Reads one byte from the ring buffer
    uint8_t usart_read();
