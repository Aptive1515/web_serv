# web_serv

Un serveur HTTP en C++ est un programme qui écoute les connexions entrantes sur un port spécifique
(généralement le port 80 pour les requêtes HTTP), traite les requêtes HTTP reçues,
et renvoie les réponses HTTP appropriées.

Voici les étapes générales pour implémenter un serveur HTTP en C++ :

Créez un socket serveur en utilisant la fonction socket() de la bibliothèque de sockets,
spécifiez l'adresse IP et le port sur lesquels vous souhaitez écouter les connexions entrantes à l'aide de
la fonction bind() et écoutez les connexions entrantes à l'aide de la fonction listen().

Acceptez les connexions entrantes en utilisant la fonction accept() de la bibliothèque de sockets.
Cette fonction retourne un nouveau socket qui sera utilisé pour communiquer avec le client.

Recevez les requêtes HTTP à l'aide de la fonction recv() et analysez-les pour extraire les informations pertinentes,
telles que la méthode HTTP (GET, POST, etc.), l'URL et les en-têtes.

Traitez la requête en fonction des informations extraites et générez une réponse appropriée en utilisant
la fonction send() pour envoyer la réponse au client.

Fermez le socket client et retournez en mode d'écoute pour de nouvelles connexions entrantes.

Répétez les étapes 2 à 5 pour chaque connexion entrante.

----------------------------------------------------------------------------------------------------------------------------------------
## Requête HTTP

Une requête HTTP (Hypertext Transfer Protocol) est une demande envoyée par un client à un serveur Web pour demander un contenu Web.
La requête est généralement envoyée à un serveur Web à l'aide d'une URL (Uniform Resource Locator) qui identifie l'emplacement du
contenu Web que le client souhaite récupérer.

Une requête HTTP est composée d'une ligne de requête suivie d'en-têtes de requête facultatifs et éventuellement d'un corps de requête.
La ligne de requête contient le type de requête, l'URL de la ressource demandée et la version du protocole HTTP utilisée.
Les en-têtes de requête fournissent des informations supplémentaires sur la requête, telles que les informations d'authentification,
les informations de langue préférée et les informations sur le navigateur client.
Le corps de la requête peut contenir des données supplémentaires envoyées avec la requête, telles que des données de formulaire ou
des fichiers.

Une fois qu'une requête est reçue par un serveur Web, le serveur peut répondre en envoyant un code de réponse HTTP,
qui indique si la demande a été traitée avec succès ou non. Si la demande est réussie, le serveur envoie le contenu Web demandé dans
le corps de la réponse,
accompagné d'en-têtes de réponse qui fournissent des informations sur le contenu et sur la façon dont il doit être traité par le client.

- Les méthodes HTTP les plus courantes sont GET, POST, PUT, DELETE, HEAD et OPTIONS. Chaque méthode correspond à une action différente
que le client souhaite effectuer sur une ressource Web.

- Les codes de réponse HTTP sont des nombres à trois chiffres qui indiquent si la requête a été traitée avec succès ou non.
Par exemple, le code 200 indique que la requête a été traitée avec succès, tandis que le code 404 indique que la
ressource demandée n'a pas été trouvée sur le serveur.

- Les en-têtes HTTP peuvent être utilisés pour transmettre des informations supplémentaires entre le client et le serveur.
Par exemple, l'en-tête "User-Agent" peut être utilisé pour indiquer le type de navigateur Web utilisé par le client,

----------------------------------------------------------------------------------------------------------------------------------------
## Fonction utile

- **execve()** : exécute un programme avec un ensemble de paramètres et un environnement définis.
Cette fonction est utile pour exécuter un programme externe à partir d'un programme en cours d'exécution.

- **dup()** et **dup2()** : dupliquent un descripteur de fichier existant.
dup() crée une copie d'un descripteur de fichier existant, en utilisant le plus petit numéro de descripteur disponible.
dup2() fait la même chose, mais permet à l'utilisateur de spécifier le numéro de descripteur de fichier à utiliser.

- **pipe()** : crée une paire de descripteurs de fichiers pour une communication unidirectionnelle entre processus.
Les données écrites dans un descripteur de fichier peuvent être lues depuis l'autre.

- **strerror()** et **gai_strerror()** : renvoient une chaîne de caractères décrivant une erreur système ou réseau.
strerror() prend en argument un code d'erreur et renvoie une chaîne de caractères décrivant l'erreur correspondante.
gai_strerror() prend en argument un code d'erreur d'adressage et renvoie une chaîne de caractères décrivant l'erreur correspondante.

- **errno** : variable globale qui contient le dernier code d'erreur de la dernière opération système.
Cette variable peut être utilisée pour récupérer le code d'erreur renvoyé par une fonction système.

- **fork()** : crée un nouveau processus en dupliquant le processus existant.
Le nouveau processus est identique au processus parent, à l'exception de son identifiant de processus (PID) et de son identifiant de groupe de processus (PGID).
Le processus parent et le nouveau processus continuent l'exécution à partir du point d'appel de la fonction fork().

- **htonl()**, **htons()**, **ntohl()** et **ntohs()** : convertissent des entiers entre l'ordre des octets d'hôte et l'ordre des octets du réseau.
Ces fonctions sont nécessaires pour convertir les entiers lors de la communication via le réseau.

- **select()**, **poll()** et **epoll()** : sont des mécanismes de gestion d'événements pour les sockets.
Ces fonctions sont utilisées pour surveiller plusieurs sockets en même temps, en attendant qu'un ou plusieurs événements se produisent.

- **socket()** : crée un nouveau socket.
Les sockets sont des canaux de communication bidirectionnels utilisés pour la communication entre processus sur un réseau.

- **accept()** : accepte une nouvelle connexion sur un socket.
Lorsqu'un client se connecte à un serveur, le serveur appelle la fonction accept() pour accepter la connexion.

- **listen()** : met un socket en mode écoute des connexions entrantes.
Cette fonction est appelée sur un socket côté serveur pour spécifier le nombre maximal de connexions en attente de traitement.

- **send()** et **recv()** : envoient et reçoivent des données sur un socket.
Ces fonctions sont utilisées pour envoyer et recevoir des données sur un socket.

- **bind()** : attache un socket à une adresse IP et à un port.
Cette fonction est utilisée pour spécifier l'adresse IP et le port sur lequel le socket doit écouter les conn

----------------------------------------------------------------------------------------------------------------------------------------
## Cree un socket

Pour créer un socket pour le protocole HTTP, vous devez d'abord déterminer le type de socket à utiliser. Dans ce cas, le protocole HTTP utilise le protocole de transport TCP (Transmission Control Protocol), donc nous allons créer un **socket TCP**.

nous créons un nouveau socket en utilisant la fonction **socket()** avec les arguments **AF_INET** pour spécifier le domaine d'adressage IPv4, **SOCK_STREAM** pour spécifier le type de socket TCP, et 0 pour le protocole par défaut.

Ensuite, nous configurons l'adresse IP et le port du serveur en remplissant une structure **sockaddr_in** avec les informations nécessaires. Nous utilisons **inet_addr()** pour convertir l'adresse IP sous forme de chaîne de caractères en un format binaire utilisé par la structure sockaddr_in, et **htons()** pour convertir le numéro de port en ordre de bits réseau.

Enfin, nous utilisons la fonction **connect()** pour établir une connexion TCP avec le serveur en passant le socket, l'adresse IP et le port du serveur à la fonction.

Notez que ce code ne fait que créer et connecter le socket, il n'envoie ni ne reçoit aucune donnée HTTP. Pour cela, vous devez utiliser des fonctions telles que **send()** et **recv()** pour envoyer et recevoir des données via le socket.

## Lien utile

- https://c.developpez.com/cours/sockets-c-cpp-demystifies/
- http://sdz.tdct.org/sdz/les-sockets.html

----------------------------------------------------------------------------------------------------------------------------------------

## NORME RFC

Le protocole HTTP (Hypertext Transfer Protocol) est un protocole de communication client-serveur utilisé pour la transmission de données sur le Web. Le protocole HTTP est décrit dans les documents RFC 7230 à 7237.

Voici un aperçu des principales RFC pour le protocole HTTP :

RFC 7230: Cette RFC spécifie la syntaxe et la sémantique de base du protocole HTTP/1.1, y compris la façon dont les messages HTTP sont formatés et transmis entre le client et le serveur.

RFC 7231: Cette RFC décrit les méthodes HTTP (par exemple GET, POST, PUT, DELETE) et les codes de statut HTTP (par exemple 200 OK, 404 Not Found) utilisés dans les échanges entre le client et le serveur.

RFC 7232: Cette RFC définit les règles de gestion de la mise en cache des ressources HTTP, y compris les entêtes de requête et de réponse utilisés pour contrôler la mise en cache.

RFC 7233: Cette RFC décrit les entêtes de requête et de réponse utilisés pour la récupération partielle des ressources HTTP (par exemple, la récupération de parties d'un fichier vidéo en streaming).

RFC 7234: Cette RFC définit les règles de validation de la mise en cache des ressources HTTP, y compris la façon dont les serveurs et les clients communiquent pour vérifier si une ressource en cache est toujours valide.

RFC 7235: Cette RFC spécifie les mécanismes d'authentification HTTP, y compris les entêtes d'authentification et les codes de réponse utilisés pour demander et fournir des informations d'identification.

Ces RFC constituent la base du protocole HTTP tel que nous le connaissons aujourd'hui. Cependant, il existe également d'autres RFC qui étendent ou modifient le protocole HTTP, comme RFC 7540 pour HTTP/2 et RFC 8441 pour HTTP/3.
