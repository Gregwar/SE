.. slide:: middleSlide

PlatformIO
==========

.. slide::

Présentation
------------

Jusque là, nous avons programmé un microcontrôleur en *bare metal*, c'est à dire
sans bibliothèques ou outil particulier. Cependant:

.. discoverList::

    * Dans la pratique, on utilise en général des bibliothèques pour faire tout cela
    * Pour chaque contrôleur, vous devrez utiliser des outils spécifiques!

.. slide::

.. center::
    .. image:: /img/platformio.png

L'outil `PlatformIO <https://platformio.org/>`_ est un couteau-suisse permettant d'installer
automatiquement les chaînes de cross-compilation, les bibliothèques, et les outils permettant
de programmer les cartes électroniques.

.. slide::

Concepts
--------

.. center::
    .. image:: /img/platformio_concepts.png

.. discoverList::
    * **Plateforme**: une architecture (ARM, AVR, ESP32...) de processeur
    * **Frameworks**: environnement logiciel (par exemple Arduino ou mbed)
    * **Boards**: cartes de développements connues et supportées
    * **Libraries**: bibliothèques permettant d'ajouter du support

.. slide::

Avantages
---------

.. discoverList::
    * Centralisation de l'installation de la chaîne de compilation, des outils de
    développement
    * Travailler sur des projets embarqués variant plusieurs plateformes dans le même
    environnement logiciel
    * Partage des dépendances par le simple fichier ``platformio.ini``

.. slide::

Prise en main
-------------

PlatformIO vient avec un outil en ligne de commande (`PlatformIO core <https://docs.platformio.org/en/latest/core/installation.html>`_) et une intégration à VSCode.


.. slide::

.. redirection-title:: tds/td4

TD
---

.. toctree::

    tds/td4

