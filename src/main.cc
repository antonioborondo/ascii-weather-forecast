#include <curl/curl.h>

int main() {
  const auto curl_handle{curl_easy_init()};
  if (curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://wttr.in?0AFQ");
    curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);
  }

  return 0;
}
