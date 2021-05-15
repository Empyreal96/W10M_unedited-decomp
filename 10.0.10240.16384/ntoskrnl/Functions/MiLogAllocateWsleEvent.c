// MiLogAllocateWsleEvent 
 
int *__fastcall MiLogAllocateWsleEvent(int a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r1
  unsigned int v9[6]; // [sp+8h] [bp-38h] BYREF
  int v10[8]; // [sp+20h] [bp-20h] BYREF

  memset(v9, 0, sizeof(v9));
  MiIdentifyPfnWrapper(a1, v9);
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
  {
    MiFillPageExtraInfo(&v9[4], a2, a3);
    v6 = 642;
    v7 = 24;
  }
  else
  {
    v6 = 630;
    v7 = 16;
  }
  v10[0] = (int)v9;
  v10[1] = 0;
  v10[2] = v7;
  v10[3] = 0;
  return EtwTraceKernelEvent(v10, 1, 0x28000001u, v6, 289413890);
}
