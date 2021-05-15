// PopUmpoSendPowerRequestOverrideCleanup 
 
void __fastcall PopUmpoSendPowerRequestOverrideCleanup(int a1)
{
  int v2[18]; // [sp+0h] [bp-48h] BYREF

  memset(v2, 0, 68);
  v2[0] = 10;
  v2[1] = *(_DWORD *)(a1 + 20);
  if ( (PoDebug & 0x10000000) != 0 )
    sub_7BF168();
  else
    PopUmpoSendPowerMessage((int)v2, 0x44u);
}
