# ft_undertale

A small 2D game inspired by **Undertale**, built as part of the 42 school's `so_long` project.  
Navigate a pixel-art maze, collect tokens and make it to the exit all wrapped in retro-style Undertale aesthetics.

---
<img width="373" height="369" alt="Screenshot from 2025-07-21 15-34-31" src="https://github.com/user-attachments/assets/33b19bbd-780b-426a-94f4-3359938b7c47" />


## 🎮 Gameplay

You play as a little character trapped in a maze.  
Your goal is simple:

- Collect all the items  
- Find the exit  
---

## ✨ Features

- Pixel-art maps themed after *Undertale*  
- Utilizes MLX42 for rendering and input handling.
- Map validation and error handling  

---

## 🧠 Technologies

- **Language:** C  
- **Graphics:** MLX42 (a lightweight graphics library used in 42 projects)  
- **Platform:** Unix-based (macOS or Linux)  

---

## 🔧 How to Run

> ⚠️ This project requires MLX42 and a Unix-like OS.

Clone the repo:

#!/bin/bash
# Скрипт для клонирования, сборки и запуска ft_undertale

# 1. Клонируем репозиторий
git clone https://github.com/Trojanforyou/ft_undertale.git

# 2. Переходим в папку проекта
cd ft_undertale || exit

# 3. Сборка проекта
make

# 4. Запуск игры
./so_long maps/classic.ber
