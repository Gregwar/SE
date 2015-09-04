
TD2: Communiquons!
==================

Port série
----------

Votre board **Arduino Uno** est connectée à un émulateur USB/Série, qui permet
à votre ordinateur de communiquer avec elle.

.. step::
    En repartant de votre base de code écrite lors du `TD1 </tds/td1>`_, écrivez
    du code qui permettra d'écrire ou de lire des données depuis le port série.

    Vous pourrez par exemple utiliser l'outil ``cu`` pour tester la communication
    depuis un terminal.

.. image:: /img/mcp.jpg
    :class: right

Puce MCP4822
------------

Nous allons maintenant utiliser une puce nommée `MCP4822 </files/mcp4822.pdf>`_.

Il s'agit d'un convertisseur numérique/analogique, ou DAC. Elle permet, à partir
d'informations numériques de produire un voltage voulu.

.. step::

    **A partir de la spécification de la puce, quel bus semble t-elle utiliser?**
    Votre processeur supporte t-il ce bus? Regardez la spécification pour voir comment
    il fonctionne.

.. step::

    **Choisissez les bonnes broches de votre carte pour effectuer un câblage qui permettra
    de parler à la puce.**

.. step::
    **Implémentez le bus adéquat dans votre code**
    Et envoyez une valeur dans votre DAC. Contrôlez que votre code marche avec, par exemple,
    un multimètre.

Intégration
-----------

.. step::
    Utilisez maintenant votre code série pour définir la valeur de l'échantillon que vous
    allez transmettre à votre DAC.


