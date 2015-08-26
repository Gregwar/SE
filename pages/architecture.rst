.. slide:: middleSlide

Architecture
============

.. slide::

Introduction
------------

Qu'est-ce qu'un système embarqué?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Problèmes d'encombrement, d'énergie, de performance et
de temps réel...

.. slide::

Loi de Moore
~~~~~~~~~~~~

.. slide::

Loi de Wirth
~~~~~~~~~~~~

.. slide::

Du silicium au programme
------------------------


.. slide::

Les CIs
~~~~~~~

ASIC vs MCU/CPU vs FPGA

.. slide::

Programmation de microcontrôleurs
---------------------------------

Exemple bottom-up ou top down 

.. slide::

Mémoire et adressage
~~~~~~~~~~~~~~~~~~~~

ROM, RAM, registres
Pile et tas

.. slide::

Instructions binaire, assembleur
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Exemples depuis une datasheet type atmega

.. slide::

Chargement du programme
~~~~~~~~~~~~~~~~~~~~~~~

Modes natifs, bootloaders...

.. slide::

Compilation depuis C
~~~~~~~~~~~~~~~~~~~~

Le code doit etre petit (Activation de Os)
-> Utilisation des volatile & co pour les registres
cross compilation
création du binaire "pur" 
pas de threads, scheduling, appels systeme -> pas d'os!

