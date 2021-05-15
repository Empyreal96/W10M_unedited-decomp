// MiIsCfgBitMapPageShared 
 
int __fastcall MiIsCfgBitMapPageShared(unsigned int a1, _DWORD *a2, int a3, unsigned int *a4)
{
  unsigned int *v4; // r4
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r2
  unsigned int v11; // r3
  unsigned int *v12[4]; // [sp+8h] [bp-10h] BYREF

  v12[0] = a4;
  v4 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( v4 != (unsigned int *)MiGetNextPageTable((unsigned int)v4, (unsigned int)v4, 0, a3, 0, v12) )
    return 3;
  v8 = MiGetProtoPteAddress(a2, a1 >> 12, 1, v12);
  v9 = *v4;
  if ( !*v4 )
    return 2;
  if ( (v9 & 2) != 0 )
  {
    v10 = MmPfnDatabase + 24 * (v9 >> 12);
    if ( (*(_DWORD *)(v10 + 20) & 0x8000000) == 0 )
      return 0;
    v11 = *(_DWORD *)(v10 + 4) | 0x80000000;
  }
  else
  {
    if ( (v9 & 0x400) == 0 )
      return 0;
    if ( (v9 & 0xFFFFE000) == -8192 )
      return 1;
    v11 = (*v4 & 0x1FC | (*v4 >> 2) & 0x3FFFFE00) - 0x40000000;
  }
  return v11 == v8;
}
