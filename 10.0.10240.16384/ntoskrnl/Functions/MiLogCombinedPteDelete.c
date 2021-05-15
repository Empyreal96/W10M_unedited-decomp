// MiLogCombinedPteDelete 
 
int *__fastcall MiLogCombinedPteDelete(int a1)
{
  int v2[4]; // [sp+8h] [bp-30h] BYREF
  int v3[8]; // [sp+18h] [bp-20h] BYREF

  v2[1] = a1;
  v2[2] = -1;
  v3[0] = (int)v2;
  v3[1] = 0;
  v3[2] = 12;
  v3[3] = 0;
  v2[0] = a1;
  return EtwTraceKernelEvent(v3, 1, 0x28000001u, 591, 289413890);
}
