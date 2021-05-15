// sub_7C3AC8 
 
void sub_7C3AC8()
{
  _BYTE *v0; // r7

  if ( ZwAlpcAcceptConnectPort() < 0 )
  {
    ZwAlpcAcceptConnectPort();
    JUMPOUT(0x6B4486);
  }
  *v0 = 1;
  if ( (PoDebug & 0x10000000) != 0 )
    DbgPrint("%s: UMPO Connected, port=%p\n", "PopUmpoProcessMessage", (const void *)PopAlpcServerPort);
  JUMPOUT(0x6B4484);
}
