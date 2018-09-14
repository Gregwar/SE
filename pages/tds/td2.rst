
TD2: Communiquons!
==================

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

    **Essayez de répondre aux questions suivantes:**

    * A quoi sert la broche LDAC?
    * Quelle est la résolution du DAC?
    * Quelle est la conversion effectuée entre numérique et analogique? (selon quelle équation)
    * Combien d'échantillons par seconde maximum pourrait-on envoyer à la carte?

.. step::

    **Choisissez les bonnes broches de votre carte pour effectuer un câblage qui permettra
    de parler à la puce.**

.. step::

    **Vous pouvez alors tester la communication avec la puce**
    Pour ce faire, utilisez simplement les broches pour envoyer "à la main" un signal
    permettant de sortir un échantillon.

.. step::
    **Implémentez le bus adéquat dans votre code**
    Et envoyez une valeur dans votre DAC. Contrôlez que votre code marche avec, par exemple,
    un multimètre.

Intégration
-----------

.. step::
    Utilisez maintenant votre code série pour définir la valeur de l'échantillon que vous
    allez transmettre à votre DAC.
