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

**CycloneDDS**
CycloneDDS est une implémentation légère et performante du standard DDS (Data Distribution Service), conçu pour les systèmes embarqués et les applications distribuées. DDS est un standard de communication en temps réel qui permet à des applications d'échanger des données de manière efficace et fiable dans un environnement distribué. CycloneDDS est l'un des RMW (ROS Middleware) disponibles pour ROS 2. Le middleware est une couche d'abstraction qui gère les communications entre les différents nœuds ROS. Il définit comment les messages sont publiés, abonnés, et transmis dans le réseau.

Caractéristiques principales de CycloneDDS :
* Performance élevée : Optimisé pour des systèmes nécessitant une faible latence.
* Faible empreinte mémoire : Convient aux systèmes embarqués.
* Interopérabilité : Respecte le standard DDS, permettant de travailler avec d'autres implémentations DDS.

Le fichier que vous avez montré est une partie de la configuration de CycloneDDS, qui permet de personnaliser son comportement.
Contenu de votre fichier :

<CycloneDDS>
    <Domain>
        <General>
            <DontRoute>true</DontRoute>
        </General>
    </Domain>
</CycloneDDS>

Explications :

* <CycloneDDS> : Racine du fichier de configuration pour CycloneDDS.
* <Domain> : Définit les paramètres spécifiques à un domaine DDS.
* <General> : Contient des paramètres généraux.
* <DontRoute> : Lorsque true, empêche CycloneDDS de router les messages à travers plusieurs domaines. Cela limite la portée des messages à un seul domaine DDS, ce qui peut être utile pour :
    * Réduire la charge réseau.
    * Garantir que les données restent dans un réseau local.

4. Comparaison avec d'autres DDS
Implémentation      DDS	                                 Points forts	                            Points faibles
CycloneDDS	        Performance,                         faible empreinte mémoire	                    Moins de fonctionnalités avancées
FastDDS	            Support communautaire large,         extensible	                                    Peut être plus lourd
RTI Connext	        Support commercial,                  fonctionnalités riches	Licence propriétaire,   coûteux
