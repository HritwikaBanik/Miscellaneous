/*
1.Callout
2.Notifications
*/

-------------------------------------------
//CALLOUT : Not a function pointer — Usually refers to an external service request, like an HTTP API call.

#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.example.com/data");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        CURLcode res = curl_easy_perform(curl); // Callout to external API
        if(res != CURLE_OK) {
            fprintf(stderr, "Callout failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Callout successful!\n");
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}

-------------------------------------------
//Not a function pointer — A message or signal indicating an event (used in OS or GUIs).
#include <stdio.h>

void notify(const char* message) {
    printf("🔔 Notification: %s\n", message);
}

int main() {
    notify("File download complete!");
    return 0;
}
