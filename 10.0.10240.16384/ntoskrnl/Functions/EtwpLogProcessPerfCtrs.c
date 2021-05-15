// EtwpLogProcessPerfCtrs 
 
int *__fastcall EtwpLogProcessPerfCtrs(_DWORD *a1)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v6[4]; // [sp+8h] [bp-58h] BYREF
  int v7[18]; // [sp+18h] [bp-48h] BYREF

  memset(v7, 0, 60);
  v7[0] = a1[44];
  v7[4] = a1[56];
  v7[5] = a1[144] << 12;
  v2 = a1[122];
  __dmb(0xBu);
  v7[6] = v2 << 12;
  v3 = a1[55];
  __dmb(0xBu);
  v7[7] = v3;
  v4 = a1[54];
  __dmb(0xBu);
  v7[8] = v4;
  v6[0] = (int)v7;
  v6[1] = 0;
  v6[2] = 60;
  v6[3] = 0;
  return EtwTraceKernelEvent(v6, 1, 1u, 800, 5249026);
}
