# IoT-Based Light Intensity Monitoring System

## 📌 Overview

This project demonstrates a simple **IoT-based system** that measures ambient light intensity using an **LDR (Light Dependent Resistor)** and an **ESP32 microcontroller**, and visualizes the data in real-time on the ThingSpeak cloud platform.

The system captures analog light data, processes it into meaningful formats, and uploads it to the cloud for monitoring and analysis.

---

## 🎯 Objectives

* To measure light intensity using an LDR sensor
* To process analog data using ESP32
* To convert raw data into percentage and logical conditions
* To send real-time data to a cloud platform (ThingSpeak)
* To visualize sensor data using graphs

---

## 🧰 Components Used

* ESP32 Microcontroller
* LDR (Light Dependent Resistor)
* 10kΩ Resistor
* Breadboard
* Jumper Wires
* WiFi Connection

---

## 🔌 Circuit Diagram Description

The LDR is connected in a **voltage divider configuration**:

* One end of LDR → 3.3V
* Other end → GPIO 34 (analog pin)
* 10kΩ resistor from GPIO 34 → GND

---

## ⚙️ Working Principle

1. The LDR senses ambient light intensity.
2. The ESP32 reads analog values (0–4095).
3. The data is processed into:

   * Raw value
   * Percentage (%)
   * Light condition (Bright/Dark)
4. Data is sent to ThingSpeak every 15 seconds.
5. Graphs are generated for real-time visualization.

---

## 📊 ThingSpeak Fields

* **Field 1:** Light Intensity (Raw ADC Value)
* **Field 2:** Light Percentage (%)
* **Field 3:** Light Condition (0 = Dark, 1 = Bright)

---

## 💻 Code Features

* WiFi connectivity using ESP32
* Analog data acquisition
* Data normalization (percentage conversion)
* Logical decision-making (light condition)
* Cloud data transmission

---

## 🚀 How to Run

1. Connect the circuit as described
2. Open Arduino IDE
3. Install required libraries:

   * WiFi.h
   * ThingSpeak
4. Update the code with:

   * WiFi credentials
   * ThingSpeak Channel ID
   * Write API Key
5. Upload code to ESP32
6. Open Serial Monitor (115200 baud)
7. Observe live data on ThingSpeak

---

## 🔥 Demonstration

* Cover the LDR → light intensity decreases
* Shine light → intensity increases
* Observe real-time graph changes on ThingSpeak

---

## 🧠 Applications

* Smart lighting systems
* Environmental monitoring
* Automatic street lights
* Energy-efficient buildings

---

## 📌 Conclusion

This project successfully demonstrates how sensor data can be collected, processed, and visualized using IoT technologies. It highlights the integration of hardware (ESP32 + LDR) with cloud platforms for real-time monitoring.

---

## 👨‍💻 Author

*Harsh Vardhan Saini*

---
