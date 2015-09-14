Les fonctionnalités
===================

Gestion des bus
---------------

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

.. slide::

DAC
~~~

Le DAC (Ou CNA) est une conversion numérique vers analogique, elle permet à partir d'une
valeur constituée de plusieurs bits en mémoire (par ex de 0 à 1023) de créer une valeur 
représentée par un niveau de voltage (par ex. de 0 à 5V).

.. slide::

**PWM-DAC**

.. textOnly:: 
    La première solution consiste en un signal périodique qui est ensuite passé dans
    un filtre passe bas, donnant alors un signal analogique "moyenné".

.. center::
    .. image:: img/pwm_dac.jpg

.. slide::

**Thermometer DAC**

.. textOnly:: 
    Une autre méthode est la méthode du thermometre, qui se compose d'une chaîne de
    résistances, avec un aiguillage permettant de diriger un des points du réseau
    vers la sortie. Cette solution donnera des résultats précis, mais est extremement
    coûteuse, il faut en effet un réseau d'autant d'éléments que de valeur qu'il
    est possible de prodfuire.

.. center::
    .. image:: img/thermometer.gif

.. slide::

**R2R DAC**

.. textOnly:: 
    Enfin, le R2R ladder (échelle R/R2) est une combinaison de résistances permettant
    de combiner plusieurs bits afin de réaliser la valeur analogique voulue:

.. center::
    .. image:: img/r2r.png

.. slide::

ADC
---

L'ADC (ou CAN) est l'opération inverse du DAC, qui consiste à échantilloner un niveau de 
voltage pour obtenir une valeur numérique.

.. slide::

Interruptions
-------------

Timers
------

Horloge
PLL
Prescaler
PWM
etc

DMA
---

MMU
---

