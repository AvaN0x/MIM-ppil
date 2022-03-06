# MIM-ppil

Project made in third year of UFR MIM

## Documentation

You can find the documentation [here](https://avan0x.github.io/MIM-ppil/docs/html).

---

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

Créer un fichier `.env` sous le format présenté dans `.env.example`.
Configuration par défaut :

```env
LOGGER_PROPERTIES_FILE=logger.properties
SERVER_PORT=9111
```

Installer maven (<https://maven.apache.org/download.cgi>, ne pas oublier de l’ajouter aux variable d’environnement dans Path), se situer dans le dossier server. Compiler le projet avec `mvn compile` et l'exécuter avec `mvn exec:java`.

```sh
cd server; mvn compile; mvn exec:java
```

Vous pouvez nettoyer de l'ancien exécutable avec

```sh
mvn clean
```
