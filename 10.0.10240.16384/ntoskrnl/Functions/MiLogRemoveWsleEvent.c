// MiLogRemoveWsleEvent 
 
int *__fastcall MiLogRemoveWsleEvent(int a1, int a2)
{
  unsigned int v3[2]; // [sp+8h] [bp-28h] BYREF
  int v4[8]; // [sp+10h] [bp-20h] BYREF

  v3[0] = 0;
  MiFillPageExtraInfo(v3, a2, a1);
  v4[0] = (int)v3;
  v4[1] = 0;
  v4[2] = 4;
  v4[3] = 0;
  return EtwTraceKernelEvent(v4, 1, 0x28000000u, 643, 289413890);
}
