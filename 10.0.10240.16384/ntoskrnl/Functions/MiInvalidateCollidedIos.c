// MiInvalidateCollidedIos 
 
int __fastcall MiInvalidateCollidedIos(int a1)
{
  int v2; // r2
  __int64 v3; // r0
  _DWORD *v4; // r5
  int v5; // lr
  _DWORD *v6; // r6
  unsigned int v7; // r4
  unsigned int v8; // r3
  unsigned int v10; // r3
  int v11; // r8
  int v12; // r1
  int v13; // r6
  _DWORD *v14; // r5
  _DWORD *v15; // r6
  _DWORD *v16; // t1
  _DWORD *v17; // r8
  int v18; // r3
  int v19; // r0
  _DWORD *v20; // r2
  __int64 v21; // r0
  int v22; // r9
  int v23; // r0

  if ( (*(_BYTE *)(a1 + 113) & 8) != 0 )
  {
    v2 = a1 + 8;
    v3 = *(_QWORD *)(a1 + 8);
    if ( *(_DWORD *)(v3 + 4) != v2 || *(_DWORD *)HIDWORD(v3) != v2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    v4 = *(_DWORD **)(a1 + 184);
    v5 = *(_DWORD *)(a1 + 180);
    v6 = v4 + 38;
    v7 = *(_DWORD *)(MmPfnDatabase + 24 * v5 + 4) | 0x80000000;
    if ( v4[36] )
      v6 = (_DWORD *)v4[36];
    v8 = *(_DWORD *)(MmPfnDatabase + 24 * v6[7] + 4) | 0x80000000;
    if ( v7 < v8 )
      return sub_528BAC();
    v10 = (int)(v7 - v8) >> 2;
    if ( v10 >= (v6[5] + (((unsigned __int16)v6[6] + (unsigned __int16)v6[4]) & 0xFFFu) + 4095) >> 12
      || (v11 = MmPfnDatabase + 24 * v6[v10 + 7], v7 != (*(_DWORD *)(v11 + 4) | 0x80000000)) )
    {
      JUMPOUT(0x528BCA);
    }
    v12 = *(_DWORD *)v7;
    v13 = *(_DWORD *)v7 & 0xFFF | (v5 << 12);
    if ( v7 + 0x40000000 <= 0x3FFFFF )
    {
      v22 = 0;
      __dmb(0xBu);
      *(_DWORD *)v7 = v13;
      if ( (v12 & 2) == 0 && (v13 & 2) != 0 )
        v22 = 1;
      if ( v7 + 1070596096 <= 0xFFF )
      {
        v23 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v23, (_DWORD *)(v23 + 4 * (v7 & 0xFFF)), v13);
      }
      if ( v22 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    else
    {
      *(_DWORD *)v7 = v13;
    }
    *(_DWORD *)(a1 + 96) = v13;
    *(_DWORD *)(MmPfnDatabase + 24 * v5 + 8) ^= ((unsigned __int16)*(_DWORD *)(MmPfnDatabase + 24 * v5 + 8) ^ (unsigned __int16)*(_DWORD *)(v11 + 8)) & 0x3E0;
    MiReleaseInPageRefs(v11);
  }
  else
  {
    v7 = 0;
    v4 = (_DWORD *)a1;
  }
  v16 = (_DWORD *)v4[2];
  v14 = v4 + 2;
  v15 = v16;
  while ( v15 != v14 )
  {
    v17 = v15 - 2;
    v18 = v15[43];
    v15 = (_DWORD *)*v15;
    v19 = MmPfnDatabase + 24 * v18;
    if ( (*(_BYTE *)(a1 + 113) & 8) == 0 || (*(_DWORD *)(v19 + 4) | 0x80000000) == v7 )
    {
      MiReleaseInPageRefs(v19);
      v20 = v17 + 2;
      v21 = *((_QWORD *)v17 + 1);
      if ( *(_DWORD **)(v21 + 4) != v17 + 2 || *(_DWORD **)HIDWORD(v21) != v20 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v21) = v21;
      *(_DWORD *)(v21 + 4) = HIDWORD(v21);
      *v20 = v20;
      v17[3] = v17 + 2;
    }
  }
  return 1;
}
