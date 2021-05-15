// PopUmpoSendLegacyEvent 
 
int __fastcall PopUmpoSendLegacyEvent(int *a1)
{
  int v3; // r2
  int v4; // r3
  int v5; // r4
  int v6; // r4
  unsigned int v7; // r0
  int v8[20]; // [sp+8h] [bp-50h] BYREF

  if ( (PoDebug & 0x10000000) != 0 )
    return sub_81C604();
  v8[0] = 7;
  v3 = a1[1];
  v4 = a1[2];
  v5 = a1[3];
  v8[1] = *a1;
  v8[2] = v3;
  v8[3] = v4;
  v8[4] = v5;
  v8[5] = a1[4];
  if ( *((_BYTE *)a1 + 12) )
    PfIoPowerEventNotify(a1[1]);
  v6 = PopUmpoSendPowerMessage((int)v8, 0x44u);
  if ( v6 >= 0 )
  {
    v7 = a1[4];
    if ( v7 )
      KeWaitForSingleObject(v7, 0, 0, 0, 0);
  }
  return v6;
}
