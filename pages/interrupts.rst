Interrupts and scheduling
=========================

.. slide::

Problem
--------

Consider the following code:

.. code-block:: c

    void uart_send(char *str) {
        while (*str != '\0') {
            // Waits to be ready to send next byte
            while (UCSR0A & _BV(UDRE0));
            // Sends the next byte
            UDRE0 = *(str++);
        }
    }

.. slideOnly::
    .. discoverList::
    * Imagine we are using a 9600 bauds bus, with 1 start bit and 1 stop bit
    * How much time does it take to execute ``uart_send("Hello world");``
    * On a 16Mhz microcontroller, how many cycles are then wasted?

.. textOnly::
    This code works, but is very greedy in computational ressource, because it
    will get the processor busy for a while.

.. slide::

Scheduling
-------------

**How can we do multiple things simultaneously?**

This problem can be solved using a scheduler, which is basic component of an operating system,
but we are currently using none!

It is however possible to manually do simultaneous things code using **cooperative scheduling**:

.. code-block:: c

    int main() {
        setup();

        while (1) {
            usart_tick();
            leds_tick();
        }
    }

Here, ``usart_tick`` and ``leds_tick`` are cooperative methods; they will make some computation
and give back execution by returning quickly

.. slide::

Here is a way to arrange precedent code using scheduling:

.. code-block:: c

    static char buffer[128];
    static size_t position = 0;
    static size_t length = 0;

    void uart_send(char *str) {
        position = 0;
        length = strlen(str);
        memcpy(buffer, str, length);
    }

    void uart_tick() {
        if (position < length) {
            if (UCSR0A & _BV(UDRE0)) {
                UDRE0 = buffer[position];
                position += 1;
            }
        }
    }

.. slide::

Polling and interrupts
------------

In the first example, we waited actively for the buffer to be available with a loop, this
is what we call **polling**.

.. discover::
    Then, we introduced the simple concept of manual **scheduling**, but the microcontroller will
    still spend a lot of time executing tests that are mostly false.

.. discover::
    One feature of microcontrollers can help us here: **interrupts**. Those are simply routines
    executed when some event occurs. The processor then simply automatically "jump" to a given method.

.. textOnly::
    The binary code we upload starts with an **interruption vector table**. Every entry in this
    table matches an interruption type and is giving a target address for the routine to execute.

.. slide::

.. center::
    .. image:: img/interrupts.png

.. slide::

Example
-------

For example, when the sending buffer becomes available for USART, we can trigger
the corresponding interruption:

This polling version:

.. code-block:: c
    // Waits for buffer to be available
    while (UCSR0A & _BV(UDRE0));

Can be re-written to use interruption instead:

.. code-block:: c
    // Enables buffer-available interruption
    UCSR0B |= _BV(UDRIE0); 
    ...
    ISR(USART_UDRE_vect) {
    {
        // ...
    }

.. slide::

Where ``ISR`` is a macro provided by the constructor, declaring a method with the
``signal`` attribute, indicating that it should be connected in the vector table:

.. code-block:: c

    #  define ISR(vector)            \
        void vector (void) __attribute__ ((signal, used)); \
        void vector (void)
    #endif

.. slide::

.. warning::
    **Warning**
    When you enter an interruption, it blocks the other interrupts to happening
    (some more advanced microcontrollers can handled nested interrupts). An interruption
    routine is highly recommended to be small and simple (store a byte in an array, setting
    a flag to true etc.); delegating computations to the non-interrupt code.


.. slide::

Ring buffer
-----------------

To handle sending and receiving data using a bus like UART, we can use a ring buffer, allowing
to store data that are not yet processed.

It can be either TX data that are not yet sent, or RX data that are not been read by code.

.. center::
    .. image:: /img/ring_buffer.gif

.. textOnly::
    The principle is to store an array in memory with two indexes, the first being the next
    item to read, and the second one the next item to write.

    When indexes are incremented, they are overflowing to the length of the buffer (going
    back to the begining when they reach the end)

    We can check if there are data to read by comparing indexes.

.. slide::

.. redirection-title:: tds/td3

TD
---

.. toctree::
    tds/td3