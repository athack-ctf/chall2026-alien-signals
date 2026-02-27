# 📡 Hidden SSID CTF Challenge

NOTE: this is an updated version following the revamp of the chall.


### Setup Guide (Infrastructure & Deployment)

This document explains how to deploy the **Alien Signal Wi-Fi CTF challenge** using one ESP8266 boards.

---

# Challenge Architecture

The lab consists of:

* **ESP8266 #1 – Access Point (Hidden SSID)**

The AP creates a Wi-Fi network.
The flag is hidden in the Vendor Information field exposed by the AP (element 221).

---

# Requirements

## Hardware

* 1x ESP8266 boards (NodeMCU or similar)
* 1x USB cables

---

## Software

* Arduino IDE
* ESP8266 Board Package
* aircrack-ng suite (Linux) or WifiInfoView or anything SSID exploration system.

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
WiFi.softAP(ssid, password, 1, 0);
```


The final `0` disables SSID hiding.
Use `1` to hide if needed.

---

##  Power the AP

After flashing:

* Open Serial Monitor (115200 baud)
* You should see:

```
Configuring access point...
Beacon IE Injection Successful
AP IP address: 192.168.4.1
HTTP server started
```
NOTE: the server is technicall not needed but why not.
The AP is now broadcasting an SSID on channel 1.

---

# 🛰Step 3 – Player Setup (Attacker Perspective)

Players must:
They will observe:

* In the field #221 of the AP
```
Element ID: 221  (Vendor Specific)
18 FE 34 DD 01 DE AD BE 41 54 48 41 43 4B 43 54    ..4.....ATHACKCT
46 7B 41 6C 69 65 6E 5F 47 6F 5F 4C 4D 41 4F 5F    F{Alien_Go_LMAO_
4E 6F 74 5F 53 6F 5F 48 69 64 64 65 6E 7D          Not_So_Hidden}  
```
