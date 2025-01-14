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
