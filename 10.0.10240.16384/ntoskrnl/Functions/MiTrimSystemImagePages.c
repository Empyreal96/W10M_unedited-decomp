// MiTrimSystemImagePages 
 
int __fastcall MiTrimSystemImagePages(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r5
  int i; // r9
  int v4; // r3
  unsigned int v5; // r6
  int v6; // r4
  unsigned int v7; // r2
  unsigned int v9; // r8
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  int v12; // r6
  int v13; // r2
  unsigned int *v14; // r2
  unsigned int v15; // r4
  int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  int v21; // r2
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  unsigned __int8 *v25; // r1
  int v26; // r3
  unsigned int v27; // r2

  v2 = a1;
  for ( i = 0; v2 <= a2; v2 += 4 )
  {
    v4 = *(_DWORD *)v2;
    if ( (*(_DWORD *)v2 & 2) == 0 && (v4 & 0x400) != 0 )
    {
      v5 = v4 & 0xFFFFFBFF | 2;
      v6 = MmPfnDatabase + 24 * (v5 >> 12);
      if ( (*(_DWORD *)(v6 + 20) & 0x8000000) != 0 )
        v7 = (*(_DWORD *)(v6 + 4) | 0x80000000) & 0x1FC | (4 * ((*(_DWORD *)(v6 + 4) | 0x80000000) & 0xFFFFFE00 | 0x100));
      else
        v7 = v5 & 0xFFFFF81C | *(_DWORD *)(v6 + 8) & 0x3E0 | 0x800;
      if ( v2 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v2 = v7;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v2 = v7;
        if ( v2 >= 0xC0300000 )
          return sub_54E0D8(0x80000000, 0);
      }
      v9 = 0;
      v10 = (unsigned __int8 *)(v6 + 15);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 0x80, v10) );
      __dmb(0xBu);
      if ( v11 >> 7 )
      {
        v22 = (unsigned __int8 *)(v6 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v6 + 12);
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v22);
          while ( __strex(v24 | 0x80, v22) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
      *(_BYTE *)(v6 + 19) &= 0xF7u;
      if ( (v5 & 0x200) == 0 )
        v9 = MiCaptureDirtyBitToPfn(v6);
      if ( (*(_DWORD *)(v6 + 20) & 0x8000000) != 0 )
      {
        v16 = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
        if ( (*(_DWORD *)v16 & 2) == 0 )
          KeBugCheckEx(26, 399680, v16 << 10);
        v12 = *(_DWORD *)v16 >> 12;
      }
      else
      {
        v12 = -1;
      }
      *(_BYTE *)(v6 + 19) = *(_BYTE *)(v6 + 19) & 0xF8 | 2;
      if ( (*(_BYTE *)(v6 + 18) & 7) != 6 )
        KeBugCheckEx(78, 153, (v6 - MmPfnDatabase) / 24);
      v13 = *(_DWORD *)(v6 + 12);
      *(_DWORD *)(v6 + 12) = v13 & 0xC0000000 | ((v13 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
      if ( (v13 & 0x3FFFFFFF) == 1 )
        MiPfnShareCountIsZero(v6, 0);
      if ( v12 != -1 )
      {
        __dmb(0xBu);
        v17 = (unsigned int *)(v6 + 12);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 & 0x7FFFFFFF, v17) );
        v6 = MmPfnDatabase + 24 * v12;
        v19 = (unsigned __int8 *)(v6 + 15);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 | 0x80, v19) );
        __dmb(0xBu);
        if ( v20 >> 7 )
        {
          v25 = (unsigned __int8 *)(v6 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v26 = *(_DWORD *)(v6 + 12);
              __dmb(0xBu);
            }
            while ( (v26 & 0x80000000) != 0 );
            do
              v27 = __ldrex(v25);
            while ( __strex(v27 | 0x80, v25) );
            __dmb(0xBu);
          }
          while ( v27 >> 7 );
        }
        if ( (*(_BYTE *)(v6 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v6 - MmPfnDatabase) / 24);
        v21 = *(_DWORD *)(v6 + 12);
        *(_DWORD *)(v6 + 12) = v21 & 0xC0000000 | ((v21 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
        if ( (v21 & 0x3FFFFFFF) == 1 )
          MiPfnShareCountIsZero(v6, 0);
      }
      __dmb(0xBu);
      v14 = (unsigned int *)(v6 + 12);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 & 0x7FFFFFFF, v14) );
      if ( v9 )
        MiReleasePageFileInfo((int)MiSystemPartition, v9, 1, 0);
      ++i;
    }
  }
  return i;
}
