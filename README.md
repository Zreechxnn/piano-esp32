
# piano-esp32

A web-based piano application powered by an ESP32 microcontroller. It allows users to play musical notes by pressing virtual keys on a web interface. The ESP32 acts as a Wi-Fi access point, serving the webpage and generating tones through a connected speaker. Supports basic musical notes and offers a simple interactive experience.

## Features
- **Web Interface**: A simple piano keyboard accessible through a web browser.
- **ESP32 Powered**: Uses an ESP32 as the central controller to serve the webpage and generate tones.
- **Wi-Fi Access Point**: ESP32 creates its own Wi-Fi network to which users can connect.
- **Basic Musical Notes**: Supports playing notes (DO, RE, MI, FA, SOL, LA, SI).
- **Speaker Output**: Sound is generated on a speaker connected to the ESP32.

## Requirements
- **ESP32 board** (e.g., ESP32 DevKit v1)
- **Speaker or Buzzer** connected to GPIO pin (default: pin 15)
- **Arduino IDE** (with ESP32 support installed)

## Installation

### 1. Set up the Arduino IDE for ESP32
If you haven't already, follow these steps to set up your Arduino IDE for ESP32:

1. Open Arduino IDE.
2. Go to `File > Preferences`.
3. In the "Additional Boards Manager URLs" field, add the following URL:
https://dl.espressif.com/dl/package_esp32_index.json

markdown
Copy code
4. Go to `Tools > Board > Board Manager` and search for **ESP32**.
5. Install the ESP32 board package.

### 2. Upload the Code to the ESP32

1. Connect your ESP32 to your computer via USB.
2. Open the provided `piano-esp32` code in Arduino IDE.
3. Select the correct ESP32 board and port under `Tools > Board` and `Tools > Port`.
4. Upload the code to the ESP32.

### 3. Connect to the Wi-Fi Access Point

1. After uploading the code, open the Serial Monitor in Arduino IDE (baud rate 115200).
2. You will see the ESP32 create an access point. The IP address of the ESP32 will be shown in the Serial Monitor.
3. Connect your computer or mobile device to the Wi-Fi network created by the ESP32 (`SSID: ecan`, `Password: 101001010100`).

### 4. Access the Web Interface

1. Open a web browser and type in the IP address of the ESP32 (shown in the Serial Monitor).
2. You should see a virtual piano keyboard on the webpage.
3. Click on the keys to play the musical notes.

### 5. Playing Notes
- The virtual keyboard on the webpage allows you to play seven musical notes (DO, RE, MI, FA, SOL, LA, SI).
- When you click on a key, it will play the corresponding note through the connected speaker.

## Code Explanation

- **Wi-Fi Access Point**: The ESP32 creates its own Wi-Fi network, which users connect to.
- **Web Server**: The ESP32 hosts a simple webpage with a piano keyboard interface.
- **Tone Generation**: The ESP32 generates musical tones for each key using the `tone()` function.
- **Speaker Output**: The sound is played through a speaker or buzzer connected to pin 15 (you can change the pin if needed).

## Circuit Diagram

Here is the circuit diagram for connecting the ESP32 with the speaker or buzzer:

![ESP32 Circuit Diagram](https://a.top4top.io/p_3282v9r9x1.png)

## Web Interface

Here is a screenshot of the web interface you will interact with:

![Web Interface](https://j.top4top.io/p_328246b3g1.jpg)

## Troubleshooting
- **No Sound**: Ensure that the speaker or buzzer is correctly connected to the specified GPIO pin (default: pin 15).
- **Page Not Loading**: Make sure you are connected to the correct Wi-Fi network (the one created by the ESP32).
- **Wi-Fi Connection Issue**: If your ESP32 doesn't show up in the Serial Monitor, try resetting the device and check the connection again.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to modify the code or improve the project as needed!
