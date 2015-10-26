Projet
======

Le but du projet est d'utiliser votre carte équipée d'un ATmega328p pour capturer des
données et les enregistrer dans des formats standard représentant des signaux digitaux (VCD).
Ensuite, vous pourrez visualiser ces signaux à l'aide de logiciels tels que GTKWave, mais aussi
effectuer des analyses logiques.

.. important::

    Le projet est à réaliser par équipe de 3 et devra être versionné sur un dépôt sur Bitbucket
    (ou autre) auquel j'aurai accès.

Partie 1: acquisition
~~~~~~~~~~~~~~~~~~~~~

En programmant votre carte, et éventuellement en utilisant un programme du coté de votre PC,
vous devrez être en mesure de produire des fichiers VCD qui représentera l'acquisition d'une
ou de plusieurs ligne de signaux.

Le challenge de cette partie repose sur la capacité à mesurer des signaux les plus rapides possibles.

Partie 2: analyse
~~~~~~~~~~~~~~~~~

Vous écrirez ensuite un analyseur logique, c'est à dire un programme qui prendra en entrée vos
acquisitions (au format VCD) et permettra d'analyser les lignes logiques.

1) UART
-------

Votre programme devra être en mesure, à partir d'un dump VCD d'une communication série, de retrouver
les données qui ont été échangées.

Vous pourrez vous restreindre à une configuration classique (type 8N1), mais devrez supporter les
différentes baudrates (en lui précisant puis en le détectant automatiquement).

2) PS/2
-------

Une autre analyse que vous pourrez réaliser est celle d'une trame PS/2, sur les anciens claviers afin
de retrouver les touches qui ont été appuyées.




