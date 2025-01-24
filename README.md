# 🐸 **Juego Interactivo: Frogger**  

**Integrantes:**  
👩‍🎓 *Ma. Soledad Gálvez*  
👩‍🎓 *Valeria Burgos*  

## 🎮 Introducción  

El proyecto "Frogger Interactivo" adapta el clásico juego Frogger a un entorno educativo, combinando electrónica y programación. Usando una ESP32, una matriz LED 32x32 y periféricos como botones y una pantalla LCD, se crea una experiencia inmersiva donde el jugador controla una "rana" que debe esquivar obstáculos y superar niveles con dificultad progresiva.

Este sistema promueve el aprendizaje práctico mediante la integración de hardware y software, destacando el uso de protocolos como SPI y efectos visuales y sonoros interactivos. Más que un juego, es una herramienta educativa que une diversión e innovación tecnológica. 🐸✨

### ✨ **Objetivo general**  

Diseñar un juego interactivo tipo Frogger en una matriz LED de 32x32 controlado por ESP32, que permita a los estudiantes de electrónica y programación practicar el control de hardware de manera lúdica y educativa.

### ✨ **Objetivo especifico**  
• Implementar un sistema de visualización en una matriz LED de 32x32 en color rojo que muestre el juego en tiempo real.  
• Programar la lógica del juego, incluyendo el movimiento de la "rana" y los obstáculos, utilizando el ESP32 como controlador principal.  
• Incorporar controles físicos (botones de movimiento, encendido y pausa) para la interacción del usuario con el juego.  
• Configurar un sistema de audio y visualización en una pantalla LCD que proporcione retroalimentación sobre el estado del juego, incluyendo mensajes de "Game Over", "¡Ganador!" y puntaje máximo.

### 📝 **Descripción**  
El juego se visualiza en una **matriz LED 32x32**, formada por cuatro matrices de 8x32.  

- **🎮 Control del juego:**  
  - Cuatro botones permiten mover la "rana" en las direcciones cardinales.  
  - Un botón adicional controla el encendido y la pausa.  
  - Un potenciómetro regula el volumen de los sonidos emitidos por los zumbadores.  

- **👀 Interacción visual y sonora:**  
  - La pantalla **LCD** muestra mensajes como *"Game Over"*, *"¡Ganador!"* y el puntaje máximo.  
  - Los **zumbadores** emiten sonidos diferentes para eventos importantes del juego.  

#### 🎯 **Flujo del juego**  
1. **Inicio:**  
   - El usuario enciende el juego con el botón de encendido.  
   - Ajusta el volumen mediante el potenciómetro antes de iniciar.  
   
2. **Desarrollo:**  
   - La matriz LED roja muestra la "rana" y los obstáculos en movimiento.  
   - El jugador controla la "rana" con los botones, evitando colisiones con los obstáculos.  
   - Si ocurre una colisión:  
     - 📢 Suena un tono de pérdida.  
     - La pantalla LCD muestra *"Game Over"*.  
     - El nivel se reinicia automáticamente.  

3. **Finalización de nivel:**  
   - Si el jugador llega al otro extremo sin colisiones:  
     - 🎉 Suena un tono de victoria.  
     - La pantalla LCD muestra *"¡Ganador!"* junto con el puntaje máximo.  

📊 Durante el juego, el monitor serial registra el progreso, permitiendo revisar logros y eventos en tiempo real.  

#### **🔧 Componentes**  
- ESP32: Microcontrolador principal encargado de gestionar la matriz LED, procesar los movimientos y controlar los periféricos.  
- Matriz LED 32x32: Pantalla formada por cuatro matrices de 8x32 para representar la "rana" y los obstáculos en el juego.  
- 4 botones de movimiento: Permiten controlar la dirección de la rana (arriba, abajo, izquierda y derecha).  
- Botón de encendido/pausa: Inicia o detiene el juego según sea necesario.  
- Potenciómetro: Ajusta el volumen de los efectos sonoros.  
- Batería recargable: Dos celdas de 3.4 V en serie para alimentar el sistema.  
- DF Mini Player: Controla la reproducción de sonidos almacenados.  
- Altavoz: Emite los sonidos del juego, como tonos de victoria o colisión.  
- Pantalla LCD: Muestra mensajes clave como "Game Over", "¡Ganador!" y el puntaje.  

### 🔍 **Trabajos Relacionados**  
1. **Tetris con ESP32:**  
   - Juego desarrollado en una pantalla OLED utilizando el protocolo **I2C** para la comunicación.  
2. **Snake con Arduino:**  
   - Juego *Snake* en una matriz LED 8x8 controlado por joystick y Arduino Uno, utilizando multiplexación para manejar los LEDs.  

## 🎨 **Alternativas de Diseño**  

### **Microcontrolador**  
- ❌ **Arduino Mega:**  
  - Se descartó por limitaciones en velocidad y memoria.  
- ✅ **ESP32:**  
  - Mejor rendimiento y soporte para librerías como Max72xxPanel.  

### **Librerías para control de matrices LED**  
- ✅ **Max72xxPanel:**  
  - Elegida por su eficiencia y facilidad para manejar múltiples matrices de forma unificada.  
- ❌ **MD_Parola:**  
  - Descartada por no ser ideal para el control directo requerido en el juego.  

### **Protocolo de Comunicación para matrices LED**  
- ✅ **SPI:**  
  - Alta velocidad y eficiencia para conectar múltiples matrices LED.  
- ❌ **UART:**  
  - Inadecuado para el volumen y velocidad de datos requeridos.  

## 🔗 **Referencias**  
- Robot, U. N. O. (2022, mayo 26). *Juego con Arduino: "Snake game con una matriz 8x8"*. [RobotUNO](https://robotuno.com/minijuego-con-arduino-snake-game/)  
- Proyecto final Tetris con ESP32. (s/f). *Studocu*. Recuperado de: [Studocu](https://www.studocu.com/es-mx/document/universidad-politecnica-de-tulancingo/estancia-ii/proyecto-final-tetris-con-esp32/69895701)  

🎉 **¡Gracias por leer!** 🐸✨  
