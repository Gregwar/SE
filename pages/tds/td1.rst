
.. image:: /img/uno.png
    :class: right

TD1: Bye bye, Arduino
=====================

Le but de ce court TD est de programmer une carte **Arduino Uno** sans utiliser l'IDE
proposé par **Arduino**.

Ressources
-------------------------

.. important::
    `Elegoo Super Starter Kit <https://www.elegoo.com/product/elegoo-uno-project-super-starter-kit/>`_ 
    `Documentation du ATmega328P (datasheet) </files/atmega328p.pdf>`_  
    `Correspondance des broches Arduino UNO/ATmega328P <https://www.arduino.cc/en/Hacking/PinMapping168>`_  
    `Schéma de l'Arduino Uno <https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf>`_

Chaîne de compilation
---------------------

.. step::

    Votre objectif est d'écrire un ``Makefile`` permettant de compiler et de flasher le code
    suivant, qui allume la LED de la carte (``PB5``, marquée "L"):

    .. code-block:: cpp

        #include <avr/io.h>

        int main() {
            // Active et allume la broche PB5 (led)
            DDRB |= _BV(PB5);
            PORTB |= _BV(PB5);
        }

    Les principales étapes que vous devrez suivre:

    * Utilisez ``avr-gcc``, compilateur pour avr afin de produire le binaire
    * Utilisez ``avr-objcopy`` afin de produire un binaire "brut" (non elf)
    * Utilisez ``avrdude``, outil permettant de programmer la carte

    Vous pourrez par exemple taper ``make`` pour produire le binaire puis ``make install`` pour
    l'installer à bord de votre carte.

Contrôle d'un stepper
---------------------

.. step::

    Le kit vous fournit un moteur à pas (28BYJ-48) et son driver (ULN2003APG):

    .. center::
        .. image:: /img/stepper.png
        .. image:: /img/stepper_schematics.png

    Branchez ``-`` sur ``GND``, ``+`` sur ``VIN`` et ``IN1``, ``IN2``,
    ``IN3`` et ``IN4`` sur les broches de votre choix.

    Le contrôle se fait alors très simplement en basculant de step en step:
    
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

    Utilisez un délai pour attendre entre deux changements de phase.
