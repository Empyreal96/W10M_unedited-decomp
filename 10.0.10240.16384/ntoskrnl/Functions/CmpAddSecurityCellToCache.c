// CmpAddSecurityCellToCache 
 
int __fastcall CmpAddSecurityCellToCache(int a1, int a2, int a3, int a4)
{
  int v7; // r2
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r3
  int v11; // r0
  int *v12; // r6
  unsigned int v13; // r5
  int v14; // r3
  int v15; // r0
  int v16; // r3
  unsigned int v18; // r5
  unsigned int v19; // r2
  int v20; // r0
  int v21; // r1
  _DWORD *v22; // r0
  _DWORD *v23; // r2
  int v24; // [sp+0h] [bp-18h] BYREF
  int v25[5]; // [sp+4h] [bp-14h] BYREF

  v25[0] = a4;
  v24 = -1;
  if ( CmpFindSecurityCellCacheIndex((_DWORD *)a1, a2, v25) != 1 )
  {
    v7 = *(_DWORD *)(a1 + 1996);
    if ( *(_DWORD *)(a1 + 1992) == v7 )
    {
      v13 = *(_DWORD *)(a1 + 2004);
      if ( a3 == 1 )
        v14 = v7 + 512;
      else
        v14 = v7 + 16;
      *(_DWORD *)(a1 + 1996) = v14;
      v15 = ExAllocatePoolWithTag(1, 8 * v14, 1666403651);
      v16 = *(_DWORD *)(a1 + 1992);
      *(_DWORD *)(a1 + 2004) = v15;
      if ( !v15 )
        return sub_80590C();
      memmove(v15, v13, 8 * v16);
      if ( v13 )
        ExFreePoolWithTag(v13);
    }
    v8 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v24);
    v9 = v8;
    if ( v8 )
    {
      v10 = *(_DWORD *)(v8 + 16);
      if ( v10 != 0 && v10 < 0xFFFFFFE8 )
      {
        v11 = ExAllocatePoolWithTag(1, v10 + 24, 1666403651);
        v12 = (int *)v11;
        if ( v11 )
        {
          memmove(v11 + 24, v9 + 20, *(_DWORD *)(v9 + 16));
          *v12 = a2;
          v12[4] = *(_DWORD *)(v9 + 16);
          v12[5] = 0;
          v20 = CmpSecConvKey(*(_DWORD *)(v9 + 16), v9 + 20);
          v21 = a1 + 8 * ((v20 & 0x3F) + 251);
          v12[1] = v20;
          v22 = *(_DWORD **)(v21 + 4);
          v23 = v12 + 2;
          v12[2] = v21;
          v12[3] = (int)v22;
          if ( *v22 != v21 )
            __fastfail(3u);
          *v22 = v23;
          v18 = v25[0];
          *(_DWORD *)(v21 + 4) = v23;
          v19 = *(_DWORD *)(a1 + 1992);
          if ( v18 < v19 )
            memmove(*(_DWORD *)(a1 + 2004) + 8 * v18 + 8, *(_DWORD *)(a1 + 2004) + 8 * v18, 8 * (v19 - v18));
          *(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v18) = a2;
          *(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v18 + 4) = v12;
          ++*(_DWORD *)(a1 + 1992);
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v24);
          return 0;
        }
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v24);
    }
    return -1073741670;
  }
  return 0;
}
