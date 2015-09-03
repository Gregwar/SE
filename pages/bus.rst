.. slide:: middleSlide

Les bus
=======

.. slide::

Présentation
------------

Le besoin d'avoir des protocoles commun pour faire dialoguer les CIs/composants
a donné naissance à certains bus standards.

.. slide::


Les lignes
~~~~~~~~~~

Avant de parler des bus, parlons du fonctionnement des différentes lignes électroniques.
Logique, voltage, 3 états, impédance etc.
PU, PD, OD...

.. slide::

Les GPIOs
~~~~~~~~~

.. textOnly::
    Les GPIOs (General Purpose Input/Outputs) sont des broches que l'on peut piloter
    en lecture/écriture à notre guise.

    Cet exemple montre le schéma logique d'une broche d'ATmega, il est ici possible
    d'activer la broche en sortie et de la piloter au niveau haut ou bas (milieu du schéma),
    de l'échantilloner (bas du schéma) et d'y activer une pull-up (haut du schéma).

.. center::
    .. image:: img/atmega-pin.png

Généralités
~~~~~~~~~~~

Niveau de voltage?
Analogique/Digital?
Synchrone (avec horloge) ou asynchrone?
Full duplex ou half duplex?
Bande passante typique?
Robustesse?


Les standards
-------------

UART
~~~~

SPI
~~~

I2C/TWI
~~~~~~~

CAN
~~~

USB
~~~

Ethernet
~~~~~~~~

Exemples
--------

Lecture de datasheets pour comprendre les problèmes liés au timing etc.
