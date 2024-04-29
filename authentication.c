//
// Created by dbaralt on 27/04/24.
//

#include "authentication.h"
#include "HTTPListener.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CLIENT_ID
#define CLIENT_ID ""
#endif

#ifndef CLIENT_SECRET
#define CLIENT_SECRET ""
#endif

bool checkCredentials() {
    authenticate();
    return true;
}

bool authenticate() {
    const char *client_id = CLIENT_ID;
    const char *consentUri = "https://accounts.google.com/o/oauth2/v2/auth?response_type=code&redirect_uri=http://localhost:8092&scope=https://www.googleapis.com/auth/drive&access_type=offline&client_id=";
    char *consentUriFull = malloc(strlen(consentUri) + strlen(client_id) + 1);
    if (consentUriFull == NULL) {
        perror("Failed to allocate memory for consent URI");
        exit(1);
    }
    strncpy(consentUriFull, consentUri, strlen(consentUri));
    strncat(consentUriFull, client_id, strlen(client_id));

    char *cmd = malloc(strlen(consentUriFull) + 12);
    if(cmd == NULL) {
        perror("Failed to allocate memory for command");
        exit(1);
    }
    strncpy(cmd, "xdg-open \"", 10);
    strncat(cmd, consentUriFull, strlen(consentUriFull));
    strncat(cmd, "\"", 1);

    system(cmd);
    char *token = serve(8092, "You can return to the application now.");

    free(cmd);
    free(consentUriFull);

    printf("%s", token);

    /*
     * TODO: Parse token and save it to a file
     */
    free(token);
    return true;
}