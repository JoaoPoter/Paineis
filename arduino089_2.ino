

// --- Bibliotecas Auxiliares ---
#include <SPI.h>
#include <MFRC522.h>

// --- Mapeamento de Hardware ---
#define   SS_PIN     4
#define   RST_PIN    8
#define   led_green  A2
#define   led_red    A1
#define   buzzer     A0
#define   saida1     A4
#define   saida2     A5

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Cria instância com MFRC522


// --- Protótipo das Funções Auxiliares ---
void rfid_func();                            //Função para identificação das tags RFID


// --- Variáveis Globais ---
char st[20];



// --- Configurações Iniciais ---
void setup()
{

  pinMode(led_green, OUTPUT);
  pinMode(led_red,   OUTPUT);
  pinMode(buzzer,    OUTPUT);
  pinMode(saida1, OUTPUT);
  pinMode(saida2, OUTPUT);
  //saídas iniciam desligadas
  digitalWrite(saida1, HIGH);
  digitalWrite(saida2, HIGH);

  Serial.begin(9600);   // Inicia comunicação Serial em 9600 baud rate
  SPI.begin();          // Inicia comunicação SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522

  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();

  //saídas iniciam desligadas
  digitalWrite(led_green, LOW);
  digitalWrite(led_red,   LOW);
  digitalWrite(buzzer,    LOW);


} //end setup


// --- Loop Infinito ---
void loop()
{

  rfid_func();   //chama função para identificação de tags RFID





} //end loop


// === Funções Auxiliares ===
void rfid_func()                            //Função para identificação das tags RFID
{
  // -- Verifica novas tags --
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Seleciona um dos cartões
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  // Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();



  if (conteudo.substring(1) == "33 D6 F2 18") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Alan");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "16 5E 87 F9") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Guilherme");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "95 18 59 1E") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Gilseu");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);




    
  }else if (conteudo.substring(1) == "54 32 68 17") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "C4 73 88 16") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "95 DE 8C 1F") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "18 21 29 2D") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "44 C7 B3 17") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "18 9F 1E 2D") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "D4 A8 CF 16") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Painelista");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "5C 7C FE 37") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Tag");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "B7 5E 85 B3") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Tag");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }else if (conteudo.substring(1) == "B9 E1 77 C1") //tag Chaveiro para liberar acesso
  {
    Serial.println("Acesso liberado!");
    Serial.println("Tag   ");
    Serial.println();

    // Aciona LED verde e buzzer
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_green,  LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

    digitalWrite(saida1, LOW);
    digitalWrite(saida2, LOW);
    delay(1000);
    digitalWrite(saida1, HIGH);
    digitalWrite(saida2, HIGH);
  }
  
    
  else if(conteudo.substring(1) != "33 D6 F2 18") //outras tags
  {
    Serial.println("Acesso Negado");  
    Serial.println();

    // Aciona LED vermelho e buzzer
    digitalWrite(led_red,   HIGH);
    digitalWrite(buzzer,    HIGH);
    delay(800);
    digitalWrite(led_red,    LOW);
    digitalWrite(buzzer,     LOW);
    delay(1200);

  }



} //end rfid_func
