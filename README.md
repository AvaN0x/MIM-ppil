# MIM-ppil

Project made in third year of UFR MIM

## Executer le projet

### Client

Se situer dans le dossier client, exécuter make :

```sh
cd client; make
```

Pour l'exécuter, tapez : `./output/main.exe`.
Vous pouvez nettoyer de l'ancien exécutable avec

```sh
make clean
```

### Serveur

Installer maven ( <https://maven.apache.org/download.cgi> ), se situer dans le dossier server. Compiler le projet avec `mvn compile` et l'exécuter avec `mvn exec:java`.

```sh
cd server; mvn compile; mvn exec:java
```

Vous pouvez nettoyer de l'ancien exécutable avec

```sh
mvn clean
```
