// EtwTraceAntiStarvationBoost 
 
int *__fastcall EtwTraceAntiStarvationBoost(int a1, char a2)
{
  int v2; // r3
  int v4; // [sp+8h] [bp-28h] BYREF
  __int16 v5; // [sp+Ch] [bp-24h]
  char v6; // [sp+Eh] [bp-22h]
  char v7; // [sp+Fh] [bp-21h]
  int v8[8]; // [sp+10h] [bp-20h] BYREF

  v4 = *(_DWORD *)(a1 + 880);
  v2 = *(_DWORD *)(a1 + 328);
  __dmb(0xBu);
  v5 = v2;
  v6 = a2;
  v7 = 0;
  v8[0] = (int)&v4;
  v8[1] = 0;
  v8[2] = 8;
  v8[3] = 0;
  return EtwTraceKernelEvent(v8, 1, 0x40000001u, 1340, 4200450);
}
