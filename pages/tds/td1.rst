
.. image:: /img/uno.png
    :class: right

TD1: Bye bye, Arduino
=====================

Le but de ce court TD est de programmer une carte **Arduino Uno** sans utiliser l'IDE
proposé par **Arduino**.

Présentation et ressources
-------------------------

.. important::
    `Documentation du ATmega328P (datasheet) </files/atmega328p.pdf>`_  
    `Correspondance des broches Arduino UNO/ATmega328P <https://www.arduino.cc/en/Hacking/PinMapping168>`_  
    `Schéma de l'Arduino Uno <https://www.arduino.cc/en/uploads/Main/Arduino_Uno_Rev3-schematic.pdf>`_

Mise en place de dépôt
----------------------

Afin de conserver le code d'un TD à l'autre (et à votre enseignant de suivre votre travail),
vous allez créer un dépôt privé et versionner votre travail.

Commencez par vous inscrire (si ça n'est pas déjà fait) sur `Bitbucket <https://bitbucket.org>`_, et créez un dépôt privé. Donnez les droits à l'utilisateur
`Gregwar <https://bitbucket.org/Gregwar/>`_.

Chaîne de compilation
---------------------

Votre objectif est d'écrire un ``Makefile`` permettant de compiler et de flasher le code
suivant, qui allume la LED de la carte:

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

N'oubliez pas de commiter.

Port série
----------

Votre board **Arduino Uno** est connectée à un émulateur USB/Série, qui permet
à votre ordinateur de communiquer avec elle.

.. step::
    Écrivez du code qui permettra d'écrire ou de lire des données depuis le port série.

    Vous pourrez par exemple utiliser l'outil ``cu`` pour tester la communication
    depuis un terminal.

Sampling
--------

Lisez la documentation relative au fonctionnement de l'ADC de l'ATmega. Votre objectif est
maintenant de réaliser des échantillons (samples) sur l'ADC pour les transmettre à votre
ordinateur via le port série.

