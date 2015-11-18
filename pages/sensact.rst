
Capteurs et Actuateurs
======================

.. slide::

Potentiomètres
--------------

Principe du pont diviseur de tension, avec un "balai" qui le rend variable.

.. center::
    .. image:: /img/potentiometer.png

.. textOnly::
    Il permet de mesurer la position de ce balai. Un potentiomètre peut être
    rotatif ou rectiligne, et son échelle n'est pas nécessairement linéaire.

.. slide::

Centrales inertielles
---------------------

Les centrales inertielles font partie de ce que l'on appelle les MEMS (microsystème
électromécanique). Elles permettent de mesurer:

.. discoverList::
    * Les accelerations (Accéletomètre)
    * Les vitesses de rotations (Gyroscope)
    * Le champ magnétique de la terre (Magnétomètre)

.. discover::
    Ces composants (parfois regroupés tous sur la même puce) communiquent assez fréquement
    en I2C.

.. slide::

Acceleromètre
~~~~~~~~~~~~~

Un acceleromètre est capable de mesurer les **accélérations** selon un ou plusieurs
axes.

.. center::
    .. image:: /img/adxl.png

.. textOnly::
    En général, la composante la plus intéréssante est la gravité. L'accéléromètre nous
    indique sa direction. Il permet d'estimer le **tangage** et le **roulis**.

.. slide::

Magnétomètre
~~~~~~~~~~~~

Un magnétomètre mesure le **champ magnétique** selon un ou plusieurs axes.

Par exemple, un magnétomètre 3 axes vous fournira un vecteur qui indiquera la direction
du champ magnétique de la terre, et vous permettra d'estimer votre **lacet**.

.. slide::

Gyroscope
~~~~~~~~~

Un gyroscope mesure les **vitesses de rotation** autour d'un ou plusieurs axes.

.. center::
    .. image:: /img/itg.png

.. textOnly::
    Le gyroscope ne fournit pas de valeur absolu, seulement des variation. Il permet en
    général de rafiner les valeurs obtenues à l'aide de l'accéléromètre et du magnétomètre
    mais intégrer ses valeurs seules dérivera avec le temps.

.. slide::

Mécanique
---------

FSR
~~~

.. textOnly::
    Les FSR (Force-Sensing resistor) permettent d'estimer l'intensité d'une force
    appliquée sur une surface.

.. center::
    .. image:: /img/fsr.jpg

.. slide::

.. textOnly::
    Par exemple, le robot NAO intègre ces capteurs sous ses pieds.

.. center::
    .. image:: /img/nao.jpg


.. slide::

Jauges de contrainte
~~~~~~~~~~~~~~~~~~~

.. center::
    .. image:: /img/strain.png

.. slide::

.. center::
    .. image:: /img/deformation.png

.. slide::

Flex
~~~~

.. center::
    .. image:: /img/flex.jpg

.. slide::

.. center::
    .. image:: /img/glove.jpg



Effet Hall
----------

Optique
    Photoresistor / Photo transistor
    Cas des optocoupleurs pour le découplage
        + pour la distance (GP2)
    Caméras (pas trop de détails, cours complet sur le sujet...)

Sonore
    Microphone electret pour le son
    Capteurs de distance basés son

Techniques pour mesurer rotation
    Capteurs à impulsion (optique / hall)
    Encodeur rotary
    
Autre
    Thermistor
    Pression
    Capacitif (touché)
    Thermistor

Actuateurs
----------

Solenoides
- Cas des valve (hydraulique/pneumatique)
- Cas des relais
- Son & piezo

Moteurs
- DC
- Brushless
- Stepper

