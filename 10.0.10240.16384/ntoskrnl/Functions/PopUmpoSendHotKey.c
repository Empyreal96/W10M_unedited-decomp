// PopUmpoSendHotKey 
 
int __fastcall PopUmpoSendHotKey(int a1)
{
  _DWORD v3[18]; // [sp+0h] [bp-48h] BYREF

  memset(v3, 0, 68);
  v3[0] = 12;
  v3[1] = a1;
  if ( (PoDebug & 0x10000000) != 0 )
    DbgPrint("%s: Sending hot-key action to UMPO.", "PopUmpoSendHotKey");
  return PopUmpoSendPowerMessage((int)v3, 0x44u);
}
