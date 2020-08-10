
TD4: PlatformIO (ADC et Servo)
==========================

.. image:: /img/platformio.png
    :class: right

Mise en place
-------------

.. step::

    Après avoir installé au moins PlatformIO core, créez un dossier, et dans ce dernier lancez:

    .. code-block:: bash

        pio project init --board uno

    Observez le contenu de ``platformio.ini``:

    .. code-block:: ini

        [env:uno]
        platform = atmelavr
        board = uno
        framework = arduino

    Pour compiler:

    .. code-block:: bash

        pio run

    Pour flasher:

    .. code-block:: bash

        pio run -t upload

    Utilisez l'API de Arduino pour faire clignoter une LED

Échantillonnage ADC et servomoteur
----------------------------------

.. step::

    Utilisez l'API d'Arduino pour prendre des échantillons (ADC) d'une photorésistance de votre kit
    et contrôleur le servomoteur de modélisme:

    .. center::
        .. image:: /img/photoresistor.webp

        .. image:: /img/sg90.jpg
            :width: 300

Retour sur l'ADXL345
--------------------

.. step::

    Sur le site de `PlatformIO <https://platformio.org/>`_, trouvez la bibliothèque qui permet de
    contrôler l'ADXL345 utilisé précédemment et utilisez là pour échantillonner.