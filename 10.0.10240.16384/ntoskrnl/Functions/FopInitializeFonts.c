// FopInitializeFonts 
 
void __fastcall FopInitializeFonts(_DWORD *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r7
  unsigned int v8; // r6
  int v9; // r8
  _BYTE *v10; // r0
  _DWORD *v11; // r4
  _BYTE *v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r1
  int v18[7]; // [sp+Ch] [bp-1Ch] BYREF

  v18[0] = a4;
  v7 = 0;
  v8 = 0;
  if ( a1[3] )
  {
    v9 = 12;
    do
    {
      v10 = (_BYTE *)BgpFwAllocateMemory(0x5Cu);
      v11 = v10;
      if ( v10 )
      {
        v12 = memset(v10, 0, 92);
        v11[20] = v11 + 20;
        v11[21] = v11 + 20;
        v11[2] = a1;
        v11[5] = v8;
        v15 = a1[5];
        if ( (v15 & 1) != 0 )
        {
          sub_975EF4((int)v12, v13, v14, v15, a5, a6);
          return;
        }
        v11[6] = 0;
        if ( ((int (__fastcall *)(_DWORD, _DWORD, int, _DWORD *, int *, int, _DWORD))FopGetTableOffsetAndSize)(
               a1[2],
               0,
               1668112752,
               v11 + 7,
               v18,
               a2,
               0) >= 0
          && FopValidateFontNameTable(a1[2], v11[6], v11 + 4) >= 0
          && FopReadMappingTable(a1[2], v11[7], v11 + 3) >= 0
          && BgpRasInitializeRasterizer(v11) >= 0 )
        {
          v16 = (_DWORD *)a1[7];
          *v11 = a1 + 6;
          v11[1] = v16;
          if ( (_DWORD *)*v16 != a1 + 6 )
            __fastfail(3u);
          *v16 = v11;
          a1[7] = v11;
          ++v7;
        }
        else
        {
          FopFreeFontData(v11);
        }
      }
      ++v8;
      v9 += 4;
    }
    while ( v8 < a1[3] );
  }
}
