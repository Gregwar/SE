.. slide:: middleSlide

Architecture
============

.. slide::

Introduction
------------

.. center::
    .. image:: img/woz.jpg

.. textOnly::
    First personal computers followed microcontrollers in the begining of 70s.
    Their capacities were far behind modern computers, but it was possible
    to know EVERYTHING that was included in your maching and how it worked.

.. slide::

Moore's law
~~~~~~~~~~~~

.. center::
    .. image:: img/moore.png

.. textOnly::
    Empirical Moore's law establishes that transistors density in computers doubles
    about every two years for the same budget.

.. slide::

.. center::
    .. image:: img/cloud.jpg

.. textOnly::
    Technological progress leaded to current situation where abstraction
    blocks were stacked, allowing us to enjoy a rich and easy to use
    environment.

    However, modern computer scientists are less aware of hardware and low-level
    considerations.

.. slide::

Wirth's law
~~~~~~~~~~~~

.. important::
    Software is getting slower more rapidly than hardware becomes faster.

Loi de May
~~~~~~~~~~

.. important::
    Software efficiency halves every 18 months, compensating Moore's law.

.. slide::

Software disenchantment
-------------------------

`Full blog post <https://tonsky.me/blog/disenchantment/>`_

.. discoverList::

    * Software is **slow**
        * Windows 10 can take **30 minutes** for an update...
        * ... in the same time budget, we can rewrite **5 times the full SSD**
        * Why a smartphone takes **30 to 60 seconds to even boot** ?
    * Software is **huge**
        * Windows 95 size was **30 Mo** ...
        * ... the android Google keyboard now used **150 Mo** of RAM
    * Software is **quickly obsolete**

.. slide::

.. center::
    .. image:: /img/python_vs_rust.png
        :width: 750

.. slide::

.. center::
    .. image:: /img/xkcd_soft.gif

.. slide::

.. center::
    .. image:: /img/xkcd_abstraction.png
        :width: 750

.. slide::

What is an embedded system?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. image:: img/finger.jpg
    :class: right

In this lecture, embedded system will be:

.. discoverList::
* A system containing at least something we can program
* Having some constraints:
  * Size
  * Power
  * Performance
  * Real-time

.. slide::

Silicium to program
------------------------

.. textOnly::
    Integrated circuits is the base technology of all embedded system.
    They are engraved on silicium disks called **wafers**:

.. center::
    .. image:: img/insolation.png

.. textOnly::
    Those disks are engraved using photolitography process using optical
    masks to duplicate a pattern forming components (transistors, diodes, resistors...)

.. slide::

.. center::
    .. image:: img/wafer.jpg

.. textOnly::
    Those silicium dices are then encased in packages that can be assembled in
    electronics boards

.. slide::

.. center::
    .. image:: img/ic.jpg

.. slide::

.. center::
    .. image:: img/pcb.jpg

.. slide::

.. image:: img/ics.jpg
    :class: right

ICs
~~~~~~~

There are several types of integrated circuits:

* Computer processing unit (CPU)
* Microcontrollers (MCU)
* DSP
* FPGA
* ASIC/ASSP

.. textOnly::
    For our work, we will focus on ICs we can program, but we will communicate with
    other ICs.

.. slide::

Programming a microcontroller
---------------------------------

Memory
~~~~~~~

There are different types of memory:

* RAM
* Flash (ROM)
* EEEPROM

.. slide::

Registers
~~~~~~~~~

In the memory, some address are used as **registers**, that can be used
to change the processor and hardware behaviour.

.. center::

    .. image:: img/atmega-regs.png

.. slide::

Those registers are available just like any other memory **address**.

.. slide::

.. center::
    .. image:: img/atmega-archi.png

.. slide::

Binary instruction, assembly
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Processor core read sequentially instructions and executes actions.

.. discover::
    Those instructions are the machine language.

.. discover::
    To represent those operations visually, we use the so-called mnemonics:
    this is the assembly language.

.. slide::

Loading a program
~~~~~~~~~~~~~~~~~

Microcontrollers are generally featuring several ways to program them
(JTAG, SPI, usart, USB...); thus are **bootloaders**.

.. discover::
    Developing boards are usually provided with programs allowing to reprogram them
    using more convenient ways (like ethernet, over-the-air...),
    we call them **software bootloaders**.

.. slide::

C compiling
~~~~~~~~~~~~~~~~~~~~

**Cross-compilation**

We can build binaries for another architecture than the computer we are
currently working on, this process is known as **cross-compilation**.

For this, we need the proper **compilation toolchain**. (For example,
the compiler itself is running on an ``x86_64`` computer and producing
``avr`` bytecodes).

.. slide::

**Binaries**

To program a microcontroller, we need to output a raw binary, and not
an ELF-like file, the one we run using Linux for example.

On the target, there are no operating system (unless we bring one), which means
no scheduling, no kernel/user space, no system call etc.

.. slide::

**Optimisations**

It is really necessary to enable compilers **optimisations** to work on
microcontrollers. Typically ``-Os``:

.. code-block:: bash

    gcc -Os code.c

.. textOnly::
    This option asks the compiler to produce the smallest possible output

.. slide::

**Registers**

.. textOnly::
    You can meet this notation:

.. code-block:: cpp
    #define REG (*(volatile uint8_t *)(0xf00))

    int main(void) {
        REG = 123;
    }

.. textOnly::
    To access a register. The ``volatile`` keyword tell the compiler that
    this memory address should be written (especially, it should not be optimized out).

.. slide::

**Binary operations**

.. textOnly::
    You should become familiar to bitwise operators:

=============   ======================
**Operator**    **Meaning**
=============   ======================
``&``           Logical "and"
=============   ======================
``|``           Logical "or"
=============   ======================
``~``           Negation (invert)
=============   ======================
``<<``          Left shift
=============   ======================
``>>``          Right shift
=============   ======================

.. slide::

.. warning::
    **Attention**, il ne faut pas confondre l'opérateur ``&&`` et l'opérateur ``&``,
    tout comme il ne faut pas confondre ``||`` avec `|`.

    Ces derniers sont respectivement des opérateurs logiques (agissant sur des booléens)
    et binaires (agissant sur des entiers).

.. slide::

**Exemples**

Que fait cette macro?

.. code-block:: cpp

    #define _BV(n) (1<<(n))

.. slide::

Que fait ce bout de code?

.. code-block:: cpp

    PORTD |= _BV(3);

.. slide::

Et celui-ci?

.. code-block:: cpp

    PORTD &= ~_BV(3);

.. slide::

Et celui-ci?

.. code-block:: cpp

    PORTD &= ~(_BV(3) | _BV(4));

.. slide::

Et celui-ci?

.. code-block:: cpp

    if (PORTD & _BV(3)) {
        // ...
    }

.. textOnly::
    Il est important de maîtriser ces opérations binaires pour pouvoir facilement
    travailler sur des registres par la suite.

.. slide::

Un exemple: les broches d'ATmega
--------------------------------

.. textOnly::
    Dans la documentation officielle, on trouve l'utilisation des registres permettant
    de piloter les broches:

.. center::
    .. image:: img/ddr.png

.. slide::

.. textOnly::
    Sachant que, par exemple, un des boîtiers a cette forme:

.. center::
    .. image:: img/dip.png

.. slide::

Il sera possible de changer la valeur de la broche PB2 comme cela:

.. code-block:: cpp

    // En-têtes fournies par AVR pour les
    // registres
    #include <avr/io.h>

    int main() {
        // Paramètre en sortie
        DDRB |= _BV(PB5);
        // Définit la broche à "High"
        PORTB |= _BV(PB5);
    }

.. slide::

Voici le code assembleur qui correspondra à ces instructions::

      25 9a           sbi     0x04, 5 ; 4
      2d 9a           sbi     0x05, 5 ; 5
      08 95           ret

.. slide::

En amont, le compilateur ajoutera le préambule::

      11 24           eor     r1, r1
      1f be           out     0x3f, r1        ; 63
      cf ef           ldi     r28, 0xFF       ; 255
      d8 e0           ldi     r29, 0x08       ; 8
      de bf           out     0x3e, r29       ; 62
      cd bf           out     0x3d, r28       ; 61
      0e 94 40 00     call    0x80    ; 0x80 <main>
      0c 94 43 00     jmp     0x86    ; 0x86 <_exit>

.. slide::

Et l'épilogue::

        00000086 <_exit>:
          86:   f8 94           cli
        00000088 <__stop_program>:
          88:   ff cf           rjmp    .-2             ; 0x88 <__stop_program>


.. slide::

Les GPIOs
---------

.. textOnly::
    Les GPIOs (*General Purpose Input/Outputs*) sont des broches que l'on peut piloter
    en lecture/écriture à notre guise.

    Cet exemple montre le schéma logique d'une broche d'ATmega, il est ici possible
    d'activer la broche en sortie et de la piloter au niveau haut ou bas (milieu du schéma),
    de l'échantilloner (bas du schéma) et d'y activer une pull-up (haut du schéma).

.. center::
    .. image:: img/atmega-pin.png


.. slide::

Les broches sont en général utilisables en GPIO et peuvent passer en mode alternatif,
étant alors gérée par une fonctionnalité du contrôleur (pensez par exemple à l'UART).

.. redirection-title:: tds/td1

TD
---

.. toctree::
    tds/td1
