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
# Requête HTTP

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
# Fonction utile

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
