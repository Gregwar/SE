
TD3: Interruptions et buffers circulaires
==========================

.. image:: /img/spark.png
    :class: right

Interruptions USART
-------------------

.. step::

    Mettez en place une interruption se déclenchant lorsqu'un octet est reçu ou lorsque
    le buffer d'envoi est disponible


.. note::
    L'interruption indiquant que le microcontrôleur est prêt à transmettre risque de se
    déclencher en boucle, il faudra donc l'activer uniquement au moment où vous souhaiterez
    transmettre quelque chose, et la stopper lorsque le transfert sera terminé.


Buffer circulaire
------------------

.. step::

    Mettez en place un buffer circulaire permettant de stocker les données à envoyer
    ainsi que les données reçues.

    Vous pourrez alors disposer par exemple des fonctions ci-dessous:

.. code-block:: c

    // Sends data (store them in the ring buffer)
    void usart_send_byte(uint8_t byte);
    void usart_send_string(uint8_t *str);
    // Returns the number of available bytes in receive ring buffer
    size_t usart_available();
    // Reads one byte from the ring buffer
    uint8_t usart_read();
