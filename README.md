# 🌤️ Sky Flyer

**Sky Flyer** is a 2D side-scrolling animation-based game developed as part of the **Computer Graphics** course. The game is built using **C++ and OpenGL**, focusing on real-time animation, collision detection, and interactive gameplay mechanics.

---

## 📌 Project Information

* **Project Title:** Sky Flyer
* **Project Type:** 2D Animation–Based Game
* **Course:** Computer Graphics
* **Section:** L
* **Technology Used:** C++ with OpenGL

---

## 🎮 Game Overview

* A side-scrolling 2D game where a bird flies continuously across the sky
* Enemy drones and enemy aircraft appear from the opposite direction at fixed time intervals
* Static buildings act as obstacles
* Player controls the bird using keyboard input
* Collision with any enemy or obstacle results in **Game Over**

---

## 🕹️ Gameplay & Features

### 🐦 Bird Movement

* Continuous horizontal movement
* Vertical movement controlled via **Up** and **Down** arrow keys

### 🚁 Enemy System

* Enemy drones and aircraft spawn periodically
* Enemies move toward the player from the opposite direction
* Enemy speed increases with level progression

### 📈 Level Progression

* Gradual increase in difficulty
* Bird and enemy speed increase with each level

### 🧮 Score System

* Score increases based on player survival time
* Real-time score displayed on the screen

### 🔊 Sound Effects

* Collision sound effects
* Game-over sound for enhanced user feedback

### ⏸️ Pause & Restart

* Press **P** to pause or resume the game
* Press **R** to restart the game after game over

---

## ⚙️ Implementation Details

* 2D objects rendered using OpenGL primitives
* Animation handled using timer-based update functions
* Object movement implemented using translation transformations
* Collision detection using simple bounding-box logic
* Game states include:

  * Running
  * Paused
  * Game Over

## ⚠️ Sound Setup Instructions (Important!)
To run the game with sound, you must link the Windows Multimedia Library in Code::Blocks.

**Steps to fix "undefined reference to PlaySound":**
1. In Code::Blocks, go to the top menu: **Project** -> **Build options...**
2. Click on the **"Linker settings"** tab.
3. Under "Link libraries", click the **Add** button.
4. Type: `winmm`
5. Click **OK**.
   
---

## 👥 Team Member Responsibilities

### **Tajmun Nahar Tisha**

* Bird and enemy aircraft design
* Dynamic sky background animation
* Pause and restart functionality


### **Karima Akter**

* Cloud and building design
* Level Logic & speed control of drone, birds,  and aircraft
* Object movement handling

### **Shafiqul Islam Nayem**

* Drone design
* Full Background  logic Design
* Score system implementation
* Collision detection and game-over logic
 
### **MD. Nazib Mahbub Esam**

* Grass and flower design
* Keyboard control implementation
* Sound system implementation



---
