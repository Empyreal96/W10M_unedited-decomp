// EtwpPmcInterrupt 
 
int *__fastcall EtwpPmcInterrupt(int a1, __int16 a2)
{
  unsigned int v2; // r0
  int v3; // r2
  int v4; // r3
  _DWORD v6[2]; // [sp+8h] [bp-30h] BYREF
  __int16 v7; // [sp+10h] [bp-28h]
  __int16 v8; // [sp+12h] [bp-26h]
  int v9[8]; // [sp+18h] [bp-20h] BYREF

  v2 = *(_DWORD *)(a1 + 128);
  v3 = 33593858;
  if ( v2 <= MmHighestUserAddress )
    v3 = 33591810;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x370);
  v6[0] = v2;
  v6[1] = v4;
  v8 = 0;
  v9[0] = (int)v6;
  v9[1] = 0;
  v9[2] = 12;
  v9[3] = 0;
  v7 = a2;
  return EtwTraceKernelEvent(v9, 1, 0x20000400u, 3887, v3);
}
