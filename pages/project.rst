Projet: afficheur à persistance rétinienne
==========================================

Le but de ce projet est de programmer un afficheur à **persistance rétinienne**.
Un bandeau de 16 LEDs montés sur une carte électronique elle-même montée sur un moteur
est mis en rotation, en changeant la configuration des LEDs, il est ainsi possible d'en faire
un afficheur:

.. center::
    .. youtube:: syYFvFRE7No

.. important::
    `Télécharger le schéma de la carte </files/pov.pdf>`_

#=) Contraintes
~~~~~~~~~~~~~~~

* Le projet se fera par groupes (à définir en classe),
* Vous n'utiliserez pas de bibliothèque externe, on programmera ce projet en *bare-metal*,
  comme dans les TDs,
* Vous devrez créer une dépôt git **privé** et le partager avec vos enseignants.

.. image:: /img/pov.png
    :class: right

#=) Prise en main du matériel
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#~) Liste des composants
-------------------------------------

Voici les composants qui vous seront fournis:

1. `Une carte électronique POV </files/pov.pdf>`_
2. `Deux aimants, diamètre 12mm, épaisseur 5mm <https://fr.aliexpress.com/item/1005001404825174.html>`_
3. `Un moteur (ventilateur) 60x60x25mm, avec un axe vissable monté dans la boîte en plastique
  <https://www.aliexpress.com/item/32882742546.html>`_
4. `Une alimentation 12V, connecteur DC 5.5mm <https://www.aliexpress.com/item/32980020011.html>`_
5. `Un boîtier de programmation USBASP 10 broches avec adaptateur vers 6 broches
  <https://fr.aliexpress.com/item/32670511994.html>`_
6. `Une clé Allen 2.5mm <https://www.bricovis.fr/std/cles-males-allen-35.php>`_

#~) Programmation
-------------------------------------

La carte comporte un processeur "sorti d'usine", il n'y a pas de *bootloader*
logiciel dessus. Vous devrez pour le
programmer utiliser un boîtier permettant d'utiliser le programmateur ISP.
(En l'occurrence, nous utiliserons le boîtier *low-cost* USBASP).

.. note::
    Indications pour avrdude, utilisez: ``-c usbasp``

.. warning::
    Le boîtier USBASP est accompagné d'un adaptateur pour se connecter à l'ISP 6 broches,
    ce dernier n'est pas doté d'un détrompeur, c'est pour cela que ce dernier a été marqué d'un
    trait blanc.

Adaptez tout d'abord votre ``Makefile`` de manière à pouvoir programmer la carte.
Vous pouvez essayer de faire clignoter la LED connectée à ``PD6``.

La fréquence du CPU est de 13Mhz (``13000000``), et le processeur est déjà réglé
pour utiliser l'horloge externe.

#~) Batteries
-------------

La batterie du POV charge automatiquement lorsqu'il est branché à un PC (via les
5V fournis en USB), que l'interrupteur du POV soit allumé ou non.
La LED rouge "Charge" reste allumée tant que la batterie n'a pas fini de charger.

Pensez à vérifier que le POV est éteint quand vous le rangez, vous pouvez vérifier
cela à l'aide de la LED *power* (verte).

#~) Communication série
-----------------------

La carte est équipée d'une puce *bluetooth HC-05*. Pour communiquer avec, vous
aurez besoin de faire fonctionner la communication série, et de la configurer
de la bonne manière.

La mise en place de cette communication série avec la carte est vitale pour
pouvoir dialoguer avec la carte pendant qu'elle tourne, et ainsi *débugger* ou pouvoir
la contrôler.

Un numéro est étiqueté sur l'arrière de votre carte, il correspond à votre numéro de
groupe. La puce Bluetooth a déjà été configurée avec les paramètres:

    Nom: POV**N** 
    Pin: 00**N** 
    Baud rate: 38400

Où N est votre numéro de groupe (par exemple ``POV17`` aura pour PIN ``0017``).

.. note::
  Afin de communiquer en Bluetooth, vous pouvez utiliser votre PC, mais aussi votre téléphone
  portable.

#=) Prise en main
~~~~~~~~~~~~~~~~~~~

.. step::

    #~) Pilotage des LEDs
    ---------------------

    Comme vous pouvez le voir sur le schéma, la carte est équipée de 16 LEDs et
    d'une puce qui permet de les piloter en courant.

    Vous devez implémenter le code permettant d'allumer et d'éteindre ces LEDs.

.. step::

    #~) Capteur magnétique
    ----------------------

    Le capteur magnétique de la carte permet de détecter la présence d'un aimant.
    Testez-le en vérifiant que vous arrivez bien à différencier le cas où il est
    devant l'aimant et où il n'est pas devant l'aimant.

    Désormais, programmez une interruption pour qu'une fonction soit automatiquement
    appelée lorsque vous passerez devant l'aimant.

.. step::

    #~) Calcul de l'heure
    ----------------------

    À l'aide de timers, vous devez être capable de calculer l'heure courante.

    Vous devrez être en mesure de définir l'heure courante en Bluetooth depuis votre
    ordinateur ou téléphone portable.

#=) Modes de fonctionnement
~~~~~~~~~~~~~~~~~~~

.. warning::

    Note: gardez la possibilité de présenter tous les modes ci-dessous à la soutenance

.. step::

    #~) Affichage horloge à aiguilles
    ---------------------------------

    Vous avez maintenant tous les éléments pour pouvoir programmer votre horloge.
    Le but ici est d'afficher l'heure avec des "aiguille" en LEDs.

    .. center::
        .. image:: img/clock_1.jpg

.. step::

    #~) Horloge numérique numérique arrondie
    ----------------------------------------

    Affichez l'heure avec des nombres, sans compenser la distorsion de
    la rotation, comme ceci:

    .. center::
        .. image:: img/other_clock.jpg

.. step::

    #~) Affichage horloge numérique générique
    -----------------------------------------

    Essayez ensuite de compenser la distorsion pour avoir une heure
    "droite", ayant ainsi un afficheur générique:

    .. center::
        .. image:: img/clock_2.jpg

.. step::

    #~) Attentes techniques du projet
    ---------

    - Granularité et précision spatiale. Avec quelle précision êtes vous capables de créer un point de lumière à une coordonnée donnée ? Quelle est la taille minimale de ce point ?
    - Granularité et précision temporelle. Fréquence de rafraîchissement des LEDs ? Avec quelle granularité êtes vous capables de mesurer le temps de rotation du POV ?
    - Quelle est la vitesse de rotation du POV ? Quantifiez sa stabilité.
    - Précision de l'heure. Si l'heure que vous insérez aujourd'hui est parfaite, quantifiez l'erreur attendue sur l'heure au bout de 6 mois d'utilisation.
    - Ordres de grandeurs des actions. Combien coûte (en temps et en coups d'horloge) une interruption ? Une multiplication et une division flottante ? Une multiplication et une division entière ?
    - Combien de mémoire utilisez vous ? Combien il en reste ? Quels sont les différents types de mémoire disponibles et à quoi servent-ils ?
