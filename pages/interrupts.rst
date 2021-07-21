Interruptions et ordonnancement
===============================

.. slide::

Problème
--------

Considérons le code suivant:

.. code-block:: c

    void uart_send(char *str) {
        while (*str != '\0') {
            // Attend d'être prêt pour l'envoi du 
            // prochain octet
            while (UCSR0A & _BV(UDRE0));
            // Envoie le prochain octet
            UDRE0 = *(str++);
        }
    }

.. slideOnly::
    .. discoverList::
    * Imaginons que nous soyons à 9600 bauds, avec 1 bit start
      et 1 bit stop
    * Combien de temps faudrait t-il pour exécuter ``uart_send("Bonjour");``?
    * Sur un micro-contrôleur à 16Mhz, à combien de cycle cela correspond?

.. textOnly::
    Ce code est fonctionnel, mais très gourmand en ressources, car il occupera
    le processeur pendant environ 6.5ms (soit plus de 100000 cycles sur un processeur
    à 16Mhz).

.. slide::

Ordonnancement
-------------

**Comment faire plusieurs choses en même temps ?**

Ce problème est résolu sur votre ordinateur par un ordonnanceur (*scheduler*), mais sur votre
carte il n'y en a aucun!

Il est cependant possible de faire plusieurs choses en même temps de manière **coopérative**, par exemple:

.. code-block:: c

    int main() {
        setup();

        while (1) {
            usart_tick();
            leds_tick();
        }
    }

Ici, ``usart_tick`` et ``leds_tick`` sont des fonctions écrites de manière coopératives; elles font un
peu de calcul et rendent la main systématiquement.

.. slide::

Le code présenté précedemment peut être réécrit de manière ordonancée:

.. code-block:: c

    static char buffer[128];
    static size_t position = 0;
    static size_t length = 0;

    void uart_send(char *str) {
        position = 0;
        length = strlen(str);
        memcpy(buffer, str, length);
    }

    void uart_tick() {
        if (position < length) {
            if (UCSR0A & _BV(UDRE0)) {
                UDRE0 = buffer[position];
                position += 1;
            }
        }
    }

.. slide::

Présentation
------------

Dans l'exemple de code vu précédemment, on attendait de manière active avec une boucle, on appelle
ceci la **scrutation** (ou le *polling*). Ensuite, nous avons vu qu'on pouvait ordonancer manuellement
la scrutation, ce qui permet de rendre la main au CPU, mais il va quand même passer un grand nombre
de cycle à vérifier encore et encore la valeur d'un bit.

.. discover::
    Les interruptions sont des mécanismes "événementiel": le processeur va "sauter" à 
    une adresse sur certaines conditions.

.. textOnly::
    Le code binaire que l'on placera sur un micro contrôleur commencera par une table
    des interruptions. A chaque case de cette table, on trouvera l'adresse à laquelle il faut
    se rendre si une interruption donnée se déclenche.

.. slide::

.. center::
    .. image:: img/interrupts.png

.. slide::

Exemple
-------

Par exemple, lorsque l'envoi d'un octet se termine sur l'USART, on peut déclencher
activer l'interruption correspondante:

Cette version, dite en scrutation:

.. code-block:: c
    // Attend de pouvoir envoyer le prochain octet
    while (UCSR0A & _BV(UDRE0));

Peut être réécrite en utilisant l'interruption correspondange:

.. code-block:: c
    // Active l'interruption à la réception
    UCSR0B |= _BV(UDRIE0); 
    ...
    void __vector_20() __attribute__ ((signal,used));
    void __vector_20()
    {
        // ...
    }

.. slide::

Les en-têtes du constructeur fournissent la macro suivante:

.. code-block:: c

    ISR(USART_UDRE_vect) {
        // Envoi de l'octet suivant
    }

.. slide::

.. warning::
    **Attention** 
    Le fait d'être dans une interruption bloque l'arrivée des autres
    interruptions (selon une politique plus ou moins sophistiquée). Le code d'une
    interruption est en général court et simple (stocker un octet dans un tableau,
    passer un flag à vrai etc.).


.. slide::

Buffer circulaire
-----------------

Pour gérer l'envoi et la réception de données via un bus comme l'USART, on peut mettre
en place un buffer circulaire (*ring buffer*), qui permet de socket les données qui n'ont
pas été transmises (en émission) ou traitée (en réception).

.. center::
    .. image:: /img/ring_buffer.gif

.. textOnly::
    Le principe du buffer circulaire est de stocker un tableau en mémoire ainsi que deux
    indices, le premier étant l'adresse du prochain élément à lire, et le deuxième l'adresse
    du prochain élément à écrire.

    Lorsque les indices sont incrémentés, ils le sont modulo la table du tableau (on revient au
    début lorsqu'on atteint la fin).

    On peut vérifier si il y a des données à lire lorsque les deux indices sont différents.

.. slide::

.. redirection-title:: tds/td3

TD
---

.. toctree::
    tds/td3