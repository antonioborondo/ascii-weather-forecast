#include <curl/curl.h>

int main(int argc, char** argv) {
  char url[256];
  sprintf(url, "https://wttr.in/%s", argv[1]);

  const auto curl_handle{curl_easy_init()};
  if (curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);
  }

  return 0;
}
