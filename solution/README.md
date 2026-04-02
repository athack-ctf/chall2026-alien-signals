## Quick Solution Walkthrough

### Participants writeups:
- [Writeup by Arianne (team corquETS 2 poulETS)](https://arianne.dev/2026/03/10/athack2026/) 

The network is configured with a **hidden SSID**, meaning it does not broadcast its name in beacon frames. However, hidden does **not** mean secret.

When a client connects to a hidden network, it must include the SSID in its **association request**. This is where the flag is exposed.

---

###  Steps to Solve

1️⃣ Enable monitor mode:

```bash
sudo airmon-ng start wlan0
```

2️⃣ Start capturing traffic:

```bash
sudo airodump-ng wlan0mon
```

3️⃣ Wait for the client device to reconnect (it reboots every 30 seconds).

4️⃣ Observe the association traffic.
The previously “hidden” network name will appear once the client connects.

```
BSSID              STATION            PWR   Rate      Lost  Frames  Notes / Probes
-----------------------------------------------------------------------------------
F8:79:0A:7C:71:75  C0:F8:53:7C:34:C6   -1   1e - 0        0       1
F8:34:5A:D7:E2:08  66:83:E7:CA:64:40  -61   0 - 1e       28      26
4A:3F:DA:63:A1:6D  40:91:51:4E:BD:07  -45   0 - 1         0       5   ATHACKCTF{Alien_Go_LMAO_Not_So_Hidden}

```
---

### Why This Works

Even though the AP hides the SSID in beacon frames, the client must reveal it when associating. By passively monitoring 802.11 management frames, the SSID becomes visible.

---

### Final Answer

The revealed SSID is the flag:

```
FATHACKCTF{Alien_Go_LMAO_Not_So_Hidden}
```

---

Hidden networks aren’t really hidden. 👽📡
