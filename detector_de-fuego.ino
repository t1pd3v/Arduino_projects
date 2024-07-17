// Definir los pines
#define FLAME_SENSOR_PIN A0
#define LED_PIN 8

void setup() {
  // Inicializar el pin del LED como salida
  pinMode(LED_PIN, OUTPUT);

  // Inicializar la comunicación serial para la depuración
  Serial.begin(9600);

  // Mensaje de inicio
  Serial.println("Sistema Iniciado");
}

void loop() {
  // Leer el valor del sensor de llamas
  int flameValue = analogRead(FLAME_SENSOR_PIN);

  // Mostrar el valor leído en el monitor serial
  Serial.print("Valor del sensor de llamas: ");
  Serial.println(flameValue);

  // Verificar si se detecta fuego
  if (flameValue <= 45) { // Ajusta el umbral según la sensibilidad del sensor
    // Encender el LED
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Fuego detectado!");
  } else {
    // Apagar el LED
    digitalWrite(LED_PIN, LOW);
    Serial.println("No hay fuego");
  }

  // Pequeño retardo para la estabilidad de lectura
  delay(1000);
}
