# Chall - Alien Signal


> NOTE: this challenge was originally involving a hidden SSID. However, it was discovered late that only Linux bare metal host could solve the challenge.
> HA did not want to push the challenge as-is, as it would give too much advantage to people with Flipper Zero/ESP32 Marauder and equivalent; while making it time-consuming and risky to do for others, particularly beginner teams.
> We have agreed on an alternative that is to hide the flag in the Vendor Information field emitted by the access point instead/
> I apologize to Enrique, the designer, for this oversight on my side, and thank him for accepting to modify the challenge under such short notice.

<details>
<summary>Original HACKME Here</summary>
Strange activity has been observed on the 802.11 spectrum.
A small device appears briefly… connects to something unseen… then vanishes.
Moments later, it returns. The pattern repeats.

The network it reaches for does not announce itself.
It does not broadcast its name.
It prefers to remain hidden.
</details>

- Captain! We have reached asteroid #80211! But it's only a matter of minutes before the Aliens put their hands on it. Where should we plant our flag??!
- Where, you ask? Plant it in landing site #221 before it's too late!
- IT'S DONE CAPTAIN, THE ASTEROID IS OURS!!!

NOTE: Asteroid #80211 orbitates somewhere in the 2.130 quadrant of the MB region of the Concordia system.

## Challenge Type

- [X] **OFF**line
- [ ] **ON**line

## Design Type

- [X] **Black**-Box
- [ ] **White**-Box

## Designer(s)

- Enrique Calderon 

## Description


<details>
<summary>Original Description Here</summary>
This challenge is designed to test participants’ understanding of how Wi-Fi networks operate at the 802.11 protocol level  specifically the misconception around hidden SSIDs.

At a glance, the scenario appears simple: a device connects periodically to a Wi-Fi network that does not broadcast its name. The network seems invisible. However, the intuition behind the challenge is that “hidden” does not mean secret.

In Wi-Fi communications, even when an access point disables SSID broadcasting in beacon frames, the SSID must still be revealed during the association process. When a client connects to that network, it includes the SSID in its management frames. Anyone monitoring the wireless traffic can observe this exchange.
</details>


## Category(ies)

- `misc`
- `physical`
