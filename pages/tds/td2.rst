
TD2: Communiquons!
==================


.. image:: /img/adxl345-module.jpg
    :class: right

Port série
----------

.. step::

    Votre board **Arduino Uno** est connectée à un émulateur USB/Série, qui permet
    à votre ordinateur de communiquer avec elle.

    Écrivez du code qui permettra d'écrire ou de lire des données depuis le port série.

    Vous pourrez par exemple utiliser l'outil ``cu``, ou `PuTTy <https://www.putty.org/>`_
    pour tester la communication depuis un terminal.


Module ADXL345
--------------

Nous allons utiliser une puce nommée `ADXL345 </files/ADXL345.pdf>`_. Pour
des raisons pratique, cette puce a été achetée déjà soudée sur une carte
(*breakout*) dont le nom est GY-291:

.. center::

    .. image:: /img/GY-291.jpg
        :width: 700


.. step::

    **Regardez la spécification de la puce**
    Quel bus est utilisé par cette dernière? L'ATmega328P le supporte t-il?

.. step::

    **Essayez de répondre aux questions suivantes:**

    * Quelle est l'adresse de la puce?
    * Que mesure t-elle?
    * Trouvez des exemples d'application
    * Comment les mesures sont t-elles représentées?

.. step::

    **Choisissez les bonnes broches pour brancher le module à votre carte.**

.. step::
    **Implémentez le bus adéquat dans votre code**
    A l'aide de la documentation du microcontrôleur ET du module, implémentez
    la communication de manière à récupérer les valeurs du module.
    
Intégration
-----------

.. step::

    Remontez les valeurs mesurées à travers la communication série UART

.. step::

    A partir des informations fournies par le capteur, calculez le *tangage* et le
    *roulis*.
