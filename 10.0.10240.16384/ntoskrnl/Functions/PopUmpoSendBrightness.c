// PopUmpoSendBrightness 
 
int __fastcall PopUmpoSendBrightness(int a1, int a2)
{
  int v4[20]; // [sp+0h] [bp-50h] BYREF

  memset(v4, 0, 68);
  v4[0] = 8;
  v4[5] = a2;
  v4[1] = -1376952702;
  v4[2] = 1176090889;
  v4[3] = -671790695;
  v4[4] = -888427491;
  if ( (PoDebug & 0x10000000) != 0 )
    DbgPrint("%s: Sending new brightness value to UMPO.", "PopUmpoSendBrightness");
  return PopUmpoSendPowerMessage((int)v4, 0x44u);
}
