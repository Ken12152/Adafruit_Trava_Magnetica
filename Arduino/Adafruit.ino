///////////////////////// ---------- /////////////////////////

void receiveData(int data)    // Funcao executado quando dados for enviado pelo ESP
{
  ConexaoComESP.varWireWrite(0, 0);    // Garantir '0' armazenado no endreco '0' (reset)
  ConexaoComESP.receiveData();    // Recebe dados

  // Se receber '1' no endereco '0',
  if(ConexaoComESP.varWireRead(0) == 1) {
    unlockFromAdafruit = true;
  }
}
