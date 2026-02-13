# 📡 Hidden SSID CTF Challenge

### Setup Guide (Infrastructure & Deployment)

This document explains how to deploy the **Hidden SSID Wi-Fi CTF challenge** using two ESP8266 boards.

---

# Challenge Architecture

The lab consists of:

* **ESP8266 #1 – Access Point (Hidden SSID)**
* **ESP8266 #2 – Client Device (Auto-Reconnecting)**
* **Attacker Machine – Wi-Fi Adapter in Monitor Mode**

The AP creates a hidden Wi-Fi network.
The client repeatedly connects and reboots every 30 seconds to generate observable Wi-Fi traffic.

---

# Requirements

## Hardware

* 2x ESP8266 boards (NodeMCU or similar)
* 2x USB cables
* 1x Wi-Fi adapter that supports monitor mode (for players)

---

## Software

* Arduino IDE
* ESP8266 Board Package
* aircrack-ng suite (for players)
* Optional: Wireshark

---

# ⚙️ Step 1 – Install ESP8266 Board Support

1. Open **Arduino IDE**
2. Go to:

```
File → Preferences
```

3. Add this to *Additional Board Manager URLs*:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

4. Go to:

```
Tools → Board → Boards Manager
```

5. Install **ESP8266 by ESP8266 Community**

---

# Step 2 – Setup the Hidden Access Point

## Flash the AP Code

Upload the **Access Point code** to ESP8266 #1.

### Important Line:

```cpp
WiFi.softAP(ssid, password, 1, 1);
```

The final `1` enables SSID hiding.

---

##  Power the AP

After flashing:

* Open Serial Monitor (115200 baud)
* You should see:

```
Configuring access point...
AP IP address: 192.168.4.1
HTTP server started
```

The AP is now broadcasting a **hidden SSID** on channel 1.

---

#  Step 3 – Setup the Client Device

##  Flash the Client Code

Upload the **Client code** to ESP8266 #2.

This device:

* Connects to the hidden SSID
* Prints its IP
* Reboots every 30 seconds
* Reconnects automatically

---

## Verify Client Behavior

Open Serial Monitor (115200 baud).

Expected output:

```
Wait for WiFi...
WiFi connected
IP address:
192.168.4.X
Disconnection
```

After ~30 seconds, it reboots and repeats.

This is intentional — it creates repeated association frames for capture.

---

# 🛰Step 4 – Player Setup (Attacker Perspective)

Players must:

1. Use a Wi-Fi adapter
2. Enable monitor mode:

```bash
sudo airmon-ng start wlan0
```

3. Capture wireless traffic:

```bash
sudo airodump-ng wlan0mon
```

They will observe:

* A hidden network (`<hidden>`)
* A client repeatedly associating
* SSID revealed in association frames
