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
Contrairement à la vision "informaticien", une ligne n'est pas simplement à "0" ou à "1",
elle est d'une part à un certain **niveau de voltage**, mais aussi à une certaine **impédance**.

.. slide::

Lorsqu'une ligne est pilotée par un contrôleur, elle est amenée en basse impédance à
un niveau logique ou à un autre. En général, peu de courant peuvent circuler à travers.

.. center::
    .. image:: img/drive.jpg

.. slide::

Un troisième état est la haute impédance, c'est à dire une connexion flottante. C'est
elle qui correspond par exemple au mode "entrée" de votre ATmega328p.

.. center::
    .. image:: img/tristate.png

.. textOnly::
    Certaines lignes sont cependant pilotées seulement par moment, et "relachée" à d'autre,
    elles sont alors flottantes. On utilise en général une **résistance de tirage**, qui
    leur impose un niveau logique, on dit qu'elles sont en haute impédance.

.. slide::

.. center::
    .. image:: img/pull.jpg

.. slide::

.. textOnly::
    Une autre configuration que l'on trouve est le collecteur ouvert (ou drain ouvert), qui
    signifie qu'un transistor prêt à être fermé est acollé à cette broche.

.. center::
    .. image:: img/opencollector.png

.. slide::

Généralités
~~~~~~~~~~~

.. discoverList::
    * Niveau de voltage?
    * Analogique/Digital?
    * Synchrone (avec horloge) ou asynchrone?
    * Full duplex ou half duplex?
    * Bande(s) passante(s)?
    * Robustesse?


Les standards
-------------

UART
~~~~

**TTL**

**RS-232**

**RS-485**

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

.. redirection-title:: tds/td2

TD
---

.. toctree::
    tds/td2
