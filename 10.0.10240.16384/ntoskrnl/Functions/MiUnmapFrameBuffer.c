// MiUnmapFrameBuffer 
 
int __fastcall MiUnmapFrameBuffer(unsigned int *a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v5; // r7
  unsigned int v7; // r8
  int v10; // r0
  unsigned int v11; // r4
  int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r6
  int v17; // r0

  v5 = *a1;
  v7 = *a1 >> 12;
  *a4 = -1;
  v10 = MI_IS_PFN(v7);
  v11 = 128;
  v12 = v10;
  if ( a2 == 2 )
  {
    v11 = 896;
  }
  else if ( a2 )
  {
    if ( a2 == 3 )
    {
      if ( v10 )
        v11 = 0;
      else
        v11 = v5 & 0xFFFFFFFC | 0x400;
    }
  }
  else
  {
    v11 = 384;
  }
  v13 = MmPfnDatabase + 24 * v7;
  if ( v12 )
  {
    v14 = 1;
    if ( (*(_DWORD *)(v13 + 20) & 0xFFFFF) == 1048573 )
      v14 = 2;
    if ( *(unsigned __int16 *)(v13 + 16) > v14 )
      a3 = 1;
  }
  else
  {
    *a4 = v7;
  }
  if ( a2 != 3 )
  {
    if ( (v5 & 0x80) != 0 )
      v15 = 4;
    else
      v15 = 1;
    v11 = ((v11 & 0xFF1F | (unsigned __int16)(32 * v15)) ^ v11 & 0xFF1F) & 0x3E0 ^ v11 & 0xFFFFFF1F;
  }
  if ( (unsigned int)(a1 + 0x10000000) > 0x3FFFFF )
  {
    *a1 = v11;
  }
  else
  {
    v16 = 0;
    __dmb(0xBu);
    *a1 = v11;
    if ( (v5 & 2) == 0 && (v11 & 2) != 0 )
      v16 = 1;
    if ( (unsigned int)(a1 + 267649024) <= 0xFFF )
    {
      v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v17, (_DWORD *)(v17 + 4 * ((unsigned __int16)a1 & 0xFFF)), v11);
    }
    if ( v16 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  return a3;
}
