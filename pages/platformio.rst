.. slide:: middleSlide

PlatformIO
==========

.. slide::

Presentation
------------

In this lecture, we are programming a microcontroller using *bare metal*, which means
without library or tool. However:

.. discoverList::

    * In practice, we of course use libraries for most applications
    * For each microcontroller, toolchain and flashing software are specific!

.. slide::

.. center::
    .. image:: /img/platformio.png

`PlatformIO <https://platformio.org/>`_ is a swiss-knife allowing you to install automatically
cross-compilation toolchains, libraries, and the flashing tools.

.. slide::

Concepts
--------

.. center::
    .. image:: /img/platformio_concepts.png

.. discoverList::
    * **Platforms**: a processor architecture (ARM, AVR, ESP32...) 
    * **Frameworks**: software environment (for example Arduino or mbed)
    * **Boards**: development boards supported
    * **Libraries**: allowing you to support extra hardware or features

.. slide::

Advantages
---------

.. discoverList::
    * Centralizing installation of toolchain and development tools
    * Working on embedded system project mixing multiple target platforms for same codebase
    * Sharing your dependencies using a configuration file ``platformio.ini``

.. slide::

Getting started
-------------

PlatformIO comes with a command line tool (`PlatformIO core <https://docs.platformio.org/en/latest/core/installation.html>`_) and a VSCode integration.


.. slide::

.. redirection-title:: tds/td4

TD
---

.. toctree::

    tds/td5

