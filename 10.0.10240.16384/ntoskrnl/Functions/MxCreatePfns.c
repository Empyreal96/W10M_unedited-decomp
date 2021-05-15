// MxCreatePfns 
 
unsigned int __fastcall MxCreatePfns(unsigned int result, unsigned int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int v6; // r4
  int i; // lr
  unsigned int v8; // r7
  int v9; // r10
  int v10; // r6
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // r5
  unsigned int v15; // r6
  unsigned int v16; // r3
  int v17; // r5
  int v18; // r0
  int v19; // r1
  int v20; // [sp+0h] [bp-28h]

  v4 = a3;
  v6 = result;
  v20 = a4;
  for ( i = a4; v6 <= a2; v4 = a3 )
  {
    result = *(_DWORD *)v6;
    if ( (*(_DWORD *)v6 & 2) != 0 )
    {
      v8 = result >> 12;
      v9 = *(_DWORD *)(((v6 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
      v10 = MmPfnDatabase + 24 * (result >> 12);
      *(_DWORD *)(MmPfnDatabase + 24 * v9 + 12) = *(_DWORD *)(MmPfnDatabase + 24 * v9 + 12) & 0xC0000000 | (*(_DWORD *)(MmPfnDatabase + 24 * v9 + 12) + 1) & 0x3FFFFFFF;
      if ( v4 == 1 )
      {
        if ( (result & 0x400) == 0 )
        {
LABEL_25:
          result = MxCreatePfn(result >> 12, v6, v9, 0);
          if ( v6 != -1070593024 )
            result = MxCreatePfns(v6 << 10, (v6 << 10) + 4092, v4 - 1, v20);
          goto LABEL_3;
        }
        v13 = result & 0xFFFFFFDF;
        if ( (result & 0x200) == 0 )
          v13 |= 0x80u;
        if ( v6 >= 0xC0000000 )
          return sub_96AF70();
        *(_DWORD *)v6 = v13 & 0xFFFFF7FF;
        v14 = v6 << 10;
        v15 = (v6 << 10) + 4096;
        if ( v6 << 10 < v15 )
        {
          do
          {
            result = MiIsRegularMemory(v20, v8);
            if ( result )
              result = MxCreatePfn(v8, v14, v9, 1);
            v14 += 4;
            ++v8;
          }
          while ( v14 < v15 );
        }
      }
      else
      {
        if ( v4 )
          goto LABEL_25;
        v11 = result & 0xFFFFFFDF;
        if ( (result & 0x200) == 0 )
          v11 |= 0x80u;
        v12 = v11 & 0xFFFFF7FF;
        if ( v6 < 0xC0000000 || v6 > 0xC03FFFFF )
        {
          *(_DWORD *)v6 = v12;
        }
        else
        {
          v16 = *(_DWORD *)v6;
          v17 = 0;
          __dmb(0xBu);
          *(_DWORD *)v6 = v12;
          if ( (v16 & 2) == 0 && (v12 & 2) != 0 )
            v17 = 1;
          if ( v6 + 1070596096 <= 0xFFF )
          {
            v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v18, (_DWORD *)(v18 + 4 * (v6 & 0xFFF)), v12);
            i = v20;
          }
          if ( v17 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        result = MiIsRegularMemory(i, v8);
        if ( result )
        {
          if ( (*(_BYTE *)(v10 + 18) & 7) != 6
            || (v19 = *(_DWORD *)(v10 + 12), (v19 & 0x3FFFFFFF) == 1) && (*(_DWORD *)(v10 + 20) & 0xFFFFF) == 1048573 )
          {
            result = MxCreatePfn(v8, v6, v9, 1);
          }
          else
          {
            *(_DWORD *)(v10 + 12) = v19 & 0xC0000000 | (v19 + 1) & 0x3FFFFFFF;
          }
        }
      }
    }
LABEL_3:
    v6 += 4;
    i = v20;
  }
  return result;
}
