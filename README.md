# Spes Autonomy

Spes Robotics autonomy packages, software infrastructure, and hardware platform.

## Installation

You can install as a typical ROS workspace, but we highly recommend using Docker: 

```bash
# Install Docker (and other dependencies)
sudo apt install git make curl
curl https://get.docker.com | sh && sudo systemctl --now enable docker

# Clone the repo
git clone https://github.com/SpesRobotics/spes_autonomy.git $HOME/spes_autonomy

# Build and run the Docker image (only once)
make -f $HOME/spes_autonomy/docker/Makefile build-pc run

# Attach to a terminal
make -f $HOME/spes_autonomy/docker/Makefile exec
```

## Examples

Visual servoing with latency compensation:
```bash
ros2 launch spes_tests test_move_latency_compensation_launch.py
```

SLAM & Navigation:
```bash
# Create a map
ros2 launch nav2_bringup slam_launch.py
rviz2

# Save the map
ros2 run nav2_map_server map_saver_cli -f /spesbot/assets/map

# Navigate
ros2 launch nav2_bringup bringup_launch.py map:=/spesbot/assets/map.yaml
ros2 launch nav2_bringup rviz_launch.py
```
* **ros2 launch nav2_bringup slam_launch.py** :
   * Démarre un nœud SLAM pour permettre au robot de générer une carte en temps réel tout en se déplaçant dans l'environnement.
   * SLAM (Simultaneous Localization and Mapping) utilise des capteurs comme le LIDAR, des caméras, ou des IMU pour créer une carte tout en localisant le robot dans cette carte.

* **rviz2** :
   * Lance RViz2, un outil de visualisation pour surveiller la carte en cours de création.
   * Permet de visualiser (la carte générée, la position actuelle du robot et les données des capteurs)
 
* **ros2 run nav2_map_server map_saver_cli** :

    * Utilise le composant Map Server de Nav2 pour sauvegarder la carte générée.
      * -f /spesbot/assets/map :
        * Sauvegarde la carte dans un fichier nommé map.pgm (fichier d'image) et génère également un fichier map.yaml contenant les métadonnées (résolution, position d'origine, etc.).
       
* **ros2 launch nav2_bringup bringup_launch.py** :
        * Lance le framework Nav2 en mode navigation autonome.
        * Charge la carte sauvegardée (/spesbot/assets/map.yaml) pour permettre au robot de se localiser et de planifier des trajectoires dans cet environnement.
* **ros2 launch nav2_bringup rviz_launch.py**:
  * Relance RViz2 pour visualiser le robot pendant qu'il navigue.
  * Pour voir (la carte utilisée par le robot, les trajectoires planifiées pour atteindre les points d'intérêt, les obstacles détectés)

