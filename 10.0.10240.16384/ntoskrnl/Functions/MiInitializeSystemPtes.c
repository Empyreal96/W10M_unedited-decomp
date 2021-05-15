// MiInitializeSystemPtes 
 
int MiInitializeSystemPtes()
{
  unsigned int v0; // r1
  unsigned int v1; // r9
  unsigned int v2; // r7
  int v4; // r0
  int v5; // r6
  unsigned int v6; // r7
  unsigned int v7; // r6
  unsigned int v8; // r7
  unsigned int v9; // r0
  unsigned int v10; // r0
  unsigned int v11; // [sp+0h] [bp-20h]

  v0 = MiLowHalVa - dword_63389C;
  v11 = (((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000;
  v1 = (unsigned int)(MiLowHalVa - dword_63389C) >> 12;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1578) = -1;
  v2 = ((v0 >> 15) + 4095) & 0xFFFFF000;
  if ( (dword_681258 & 2) != 0 )
    return sub_96A8CC();
  v4 = MiObtainSystemVa((v2 + 0x3FFFFF) >> 22, 9);
  v5 = v4;
  if ( !v4 )
    return 0;
  dword_634D84 = dword_634808;
  if ( !MiInitializeDynamicBitmap((unsigned int *)&dword_634D58, v4, v1, 1) )
    return 0;
  if ( (dword_681258 & 2) != 0 && !MiInitializeDynamicBitmap(&dword_634800, v5 + v2, 2 * v1, 1) )
    dword_681258 &= 0xFFFFFFFD;
  dword_634D64 = 11;
  unk_634D68 = 9;
  dword_634D6C = (int)&unk_634D70;
  dword_634D60 = v11;
  unk_634D78 = dword_634F00;
  dword_634D58 = 0;
  v6 = v5 + v2;
  __dmb(0xBu);
  dword_634D88 = 0;
  __dmb(0xBu);
  dword_634D7C = 0;
  dword_634D74 = 0;
  byte_634F70 = byte_634F70 & 0xF8 | 4;
  if ( !MiInitializeSystemWorkingSetList(dword_634F00, v1) )
    return 0;
  if ( (v6 & 0x3FFFFF) != 0 )
  {
    v7 = (0x400000 - (v6 & 0x3FFFFF)) >> 12;
    v8 = (int)(((v6 >> 10) & 0x3FFFFC) - dword_634D60 - 0x40000000) >> 2;
    if ( MiSplitBitmapPages(9, dword_634D5C + (v8 >> 3), (v8 & 7) + v7) == 1 )
    {
      dword_634D58 = v8 + v7;
      RtlClearBits(&dword_634D58, v8, v7);
      do
        v9 = __ldrex((unsigned int *)&dword_634D88);
      while ( __strex(v9 + v7, (unsigned int *)&dword_634D88) );
      do
        v10 = __ldrex((unsigned int *)&dword_634D7C);
      while ( __strex(v10 + v7, (unsigned int *)&dword_634D7C) );
    }
    if ( (dword_681258 & 2) != 0 && !MiSplitBitmapPages(9, dword_634804 + ((2 * v8) >> 3), ((2 * v8) & 7) + 2 * v7) )
      dword_681258 &= 0xFFFFFFFD;
  }
  return 1;
}
