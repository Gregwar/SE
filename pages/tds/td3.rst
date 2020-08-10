
TD3: Timer & interruptions
==========================

.. image:: /img/spark.png
    :class: right

Interruption externe
--------------------

.. step::

    **Lisez la documentation de l'ADXL345 du TP précédent concernant les interruptions**

    * A quoi peuvent-elles servir?
    * Comment les interfacer avec votre microcontrôleur?

.. step::

    **Implémentation de l'interruption DATA_READY**

    Câblez correctement le composant et faites en sorte que l'interruption *INT1*
    se déclenche sur un *DATA_READY* et provoque la lecture d'un nouvel échantillon
    par votre microcontrôleur.

Timer
-----

.. step::

    Mettez en place un timer qui vous permettra de mesurer le temps écoulé entre deux
    instants.

.. step::

    A l'aide du timer, mesurez le nombre d'échantillons reçus par seconde.

.. step::

    Vérifiez que ce nombre correspond à celui annoncé par l'ADXL345. Modifiez la fréquence
    de sortie et vérifiez que la mesure change.

