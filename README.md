# Chall - Alien Signal

Strange activity has been observed on the 802.11 spectrum.
A small device appears briefly… connects to something unseen… then vanishes.
Moments later, it returns. The pattern repeats.

The network it reaches for does not announce itself.
It does not broadcast its name.
It prefers to remain hidden.

## Challenge Type

- [X] **OFF**line
- [] **ON**line

## Design Type

- [X] **Black**-Box
- [ ] **White**-Box

## Designer(s)

- Enrique Calderon 

## Description

This challenge is designed to test participants’ understanding of how Wi-Fi networks operate at the 802.11 protocol level — specifically the misconception around hidden SSIDs.

At a glance, the scenario appears simple: a device connects periodically to a Wi-Fi network that does not broadcast its name. The network seems invisible. However, the intuition behind the challenge is that “hidden” does not mean secret.

In Wi-Fi communications, even when an access point disables SSID broadcasting in beacon frames, the SSID must still be revealed during the association process. When a client connects to that network, it includes the SSID in its management frames. Anyone monitoring the wireless traffic can observe this exchange.

## Category(ies)

- `misc`
- `wireless`

---

# Project Structure

## 1. HACKME.md

- **[HACKME.md](HACKME.md)**: A teaser or description of the challenge to be shared with participants (in CTFd).

## 2. Source Code

- **[source/README.md](source/README.md)**: Comprehensive instructions on how to have a running instance of your
  challenge from the source.
  If your project includes multiple subprojects, please consult us (Alin and William).
- **[source/*](source/)**: Your source code.

## 3. Offline Artifacts [OPTIONAL]

> **NOTE:** This directory is optional for online challenges. However, if offline artifacts need to be provided as well, 
> they should be placed here.

- **[offline-artifacts/*](offline-artifacts/)**: All files intended to be downloaded by participants
  (e.g., a flagless version of the running binary executable of a pwn challenge).
  For large files (exceeding 100 MB), please consult us (Alin and William).

## 4. Solution

- **[solution/README.md](solution/README.md)**: A detailed writeup of the working solution.
- **[solution/FLAGS.md](solution/FLAGS.md)**: A single markdown file listing all (up-to-date) flags.
- **[solution/*](solution/)**: Any additional files or code necessary for constructing a reproducible solution for the
  challenge (e.g., `PoC.py`, `requirement.txt`, etc.).

## 5. Dockerization

> **NOTE:** For deployment on @Hack's infrastructure, online challenges must be containerized.
> However, this requirement does not apply during the early stages of challenge development, so do not hesitate to start
> building your online challenge if you are unfamiliar with containerization.
> We (Anis and Hugo) will take care of it.

- **[source/Dockerfile](source/Dockerfile)**: Needed for building a containerized image of the online challenge.
- **[source/docker-compose.yml](source/docker-compose.yml)**: Needed for a configuration-free run of the online
  challenge