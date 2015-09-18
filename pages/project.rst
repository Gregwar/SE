Projet
======

Le but du projet est d'utiliser votre carte équipée d'un ATmega328p pour produire du son.

Prérequis
~~~~~~~~~

Vous aurez besoin de :doc:`l'architecture du TD1 <tds/td1>`, ainsi que du composant
MCP4822 utilisé lors du :doc:`TD2 <tds/td2>`.

Vous devrez 

Le timing
~~~~~~~~~

La première partie du projet consiste en la configuration des timers de votre carte, afin
d'être capable d'envoyer des échantillons en sortie à une fréquence précise.

Nous choisirons 44100Hz comme fréquence d'échantillonage, car il s'agit d'un standard,
afin de pouvoir représenter des sons jusqu'à environ 22Khz, la limite de l'audible.

Production d'un son sinusoïdal
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Dans un second temps, vous devrez produire un son sinusoïdal sur la sortie de votre carte,
vous pourrez brancher un port Jack pour brancher un casque et écouter.

Vous pourrez alors enchaîner plusieurs sinus de plusieurs durées pour produire une mélodie.

Envoi des échantillons depuis un PC
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enfin, vous enverrez les échantillons depuis votre ordinateur afin de les retranscrire dans
le DAC.

Attention, le timing de cette opération risque d'être délicat.
