#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ssid";
const char* password = "password here";

WebServer server(80);

const int speakerPin = 14;  

// Define frequencies for notes
float DO = 261.63;
float RE = 293.66;
float MI = 329.63;
float FA = 349.23;
float SOL = 392.00;
float LA = 440.00;
float SI = 493.88;

volatile bool isPlaying = false;
volatile float currentFrequency = 0;

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  pinMode(speakerPin, OUTPUT);

  // Route to serve HTML page
  server.on("/", HTTP_GET, []() {
    String html = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Piano</title>";
    html += "<style>";
    html += "body { font-family: Arial, sans-serif; background-color: #f4f4f4; text-align: center; padding: 50px; }";
    html += ".keyboard { display: flex; justify-content: center; margin-bottom: 30px; }";
    html += ".key { width: 60px; height: 200px; background-color: #fff; border: 1px solid #ccc; margin: 0 2px; position: relative; cursor: pointer; }";
    html += ".key:active { background-color: #ddd; }";
    html += "</style>";
    html += "<script>";
    html += "function play(note) { fetch('/play?note=' + note); }";
    html += "function stop() { fetch('/stop'); }";
    html += "</script>";
    html += "</head><body>";
    html += "<div class='keyboard'>";
    html += createKey("DO");
    html += createKey("RE");
    html += createKey("MI");
    html += createKey("FA");
    html += createKey("SOL");
    html += createKey("LA");
    html += createKey("SI");
    html += "</div>";
    html += "</body></html>";

    server.send(200, "text/html", html);
  });

  // Endpoint to start playing a note
  server.on("/play", HTTP_GET, []() {
    String note = server.arg("note");
    currentFrequency = getFrequency(note);
    isPlaying = true;
    server.send(200, "text/plain", "Playing " + note);
  });

  // Endpoint to stop playing
  server.on("/stop", HTTP_GET, []() {
    isPlaying = false;
    server.send(200, "text/plain", "Stopped");
  });

  server.begin();
}

void loop() {
  server.handleClient();
  if (isPlaying) {
    playTone(currentFrequency, 1000);  // Play tone for 1 second
  }
}

// Function to play a tone with a specific frequency for a fixed duration
void playTone(float frequency, int duration) {
  if (frequency > 0) {
    int period = (1.0 / frequency) * 1000000;  // Period in microseconds
    int pulseWidth = period / 2;              // 50% duty cycle
    
    unsigned long startMillis = millis();
    while (millis() - startMillis < duration) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(pulseWidth);  // High time
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(pulseWidth);  // Low time
    }
  }
}

// Function to get frequency based on note name
float getFrequency(String note) {
  if (note == "DO") return DO;
  if (note == "RE") return RE;
  if (note == "MI") return MI;
  if (note == "FA") return FA;
  if (note == "SOL") return SOL;
  if (note == "LA") return LA;
  if (note == "SI") return SI;
  return 0;
}

// Helper function to generate the key HTML structure
String createKey(String note) {
  return "<div class='key' onmousedown='play(\"" + note + "\")' onmouseup='stop()'>" + note + "</div>";
}
