void RAW_Loop(){
  uint8_t cmd_switch = 0;
  while(SerialDevice.available()){
    uint8_t c = SerialDevice.read();
    if(c == 0xaf){
      cmd_switch++;
    }else{
      cmd_switch=0;
    }
    if(cmd_switch == 30){
      system_mode = 0;
      switch_flag = 1;
      EEPROM.write(23,0);
      #if defined(ESP8266)
      EEPROM.commit();
      #endif
      return;
    }
    SerialNFC.write(c);
  }
  while(SerialNFC.available()){
      SerialDevice.write(SerialNFC.read());
  }
}

void RAW_Setup(){
  #ifndef CDC
  if ((system_setting[0] & 0b10)){
    SerialDevice.begin(115200);
  }
  else{
    SerialDevice.begin(38400);
  }
  #endif
  if(system_setting[0] & 0b1000)
  {
    for(uint8_t i = 0;i<8;i++)
    {
      mapped_card_IDm[i] = EEPROM.read(i+4);
    }
    for(uint8_t i = 0;i<10;i++)
    {
      card_reflect.block2[i+6] = EEPROM.read(i+12);
    }
  }
  LED_Init();
  //afio_remap(AFIO_REMAP_USART1); 
  nfc.begin();
  while (!nfc.getFirmwareVersion()) {
    delay(500);
    SerialDevice.println("error");
    LED_show(255,0,0);
  }
  #if defined(CONFIG_IDF_TARGET_ESP32C3)
  digitalWrite(nfccommled, 1);
  #endif
  nfc.setPassiveActivationRetries(0x10);
  nfc.SAMConfig();
  memset(req.bytes, 0, sizeof(req.bytes));
  memset(res.bytes, 0, sizeof(res.bytes));
  LED_show(0,128,128);
  delay(1);
}