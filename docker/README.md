**Dokerfile.sbc** 

Un fichier nommé Dockerfile.sbc est une variante d'un fichier Dockerfile standard, utilisé pour construire une image Docker. L'extension ou le suffixe .sbc n'a pas de signification particulière dans Docker lui-même, 
mais il est souvent utilisé comme une convention ou pour distinguer un Dockerfile spécifique.
Signification possible de .sbc :

* Small Board Computer (SBC) :
  * SBC pourrait faire référence à des ordinateurs monocartes comme Raspberry Pi, NVIDIA Jetson Nano, ou autres. Le fichier Dockerfile.sbc serait donc une version adaptée pour un environnement ARM ou un système embarqué.

 * Pourquoi ce fichier semble adapté aux SBC ?
   * Les SBC comme les Raspberry Pi ou NVIDIA Jetson ont souvent des contraintes matérielles spécifiques (architecture ARM, accès direct aux périphériques).
    Ce Dockerfile :
        * Configure un utilisateur pour accéder directement à des périphériques matériels (vidéo, port série).
        * Inclut des outils nécessaires à des capteurs et actuateurs typiques des robots embarqués.


**MakeFile**
Un Makefile est un fichier utilisé par l'outil make pour automatiser des tâches répétitives, principalement dans le domaine de la compilation de logiciels, mais aussi pour d'autres tâches telles que la gestion de conteneurs, le déploiement ou l'exécution de scripts.

Que fait le makefile ? 

* Build : Construire des images Docker pour PC ou SBC (build-pc, build-sbc).
* Run : Lancer un conteneur interactif avec accès complet aux périphériques matériels (run).
* Deploy : Construire une image de déploiement et exécuter une application spécifique (deploy).
* GPU : Support intégré pour les cartes NVIDIA si détectées (NVIDIA_GPU).
