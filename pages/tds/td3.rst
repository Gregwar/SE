
TD3: Timer & Interruptions
==========================

.. image:: /img/sinus.jpg
    :class: right

Le but de ce TD est de reprendre la base du TD2 (communication avec la
puce MCP4822) et d'y ajouter l'utilisation de timer et d'interruption
afin de produire en sortie un signal sonore.

Obtenir les samples
-------------------

Modifiez votre code pour produire des échantillons qui suivent une courbe
sinusoïdale à une fréquence fixe choisie (par exemple 440hz).

Vérifiez à l'aide par exemple d'un oscilloscope que vous produisez un
tel signal.

Mise en place d'un timer avec interruptions
-------------------------------------------

Utilisez un timer pour provoquer l'envoi d'échantillons dans le DAC.

Vous provoquerez une interruption à une fréquence fixe (comme 44100hz, standard
pour l'échantillonage musical) qui déclenchera l'envoi du prochain échantillon.
