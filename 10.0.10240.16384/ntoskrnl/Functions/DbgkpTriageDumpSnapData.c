// DbgkpTriageDumpSnapData 
 
int __fastcall DbgkpTriageDumpSnapData(_DWORD *a1, unsigned int a2, int a3, int a4, signed int a5, _DWORD *a6)
{
  int v7; // r4
  _DWORD *v9; // r5
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r2
  unsigned int v18; // r3
  int v19; // r2
  int v20; // r3
  int v21; // r1
  signed int v22; // r2
  int v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r0
  unsigned int v27; // [sp+0h] [bp-28h] BYREF
  unsigned int v28; // [sp+4h] [bp-24h]
  int v29; // [sp+8h] [bp-20h]

  v27 = a2;
  v28 = a3;
  v29 = a4;
  v7 = *a1;
  v9 = (_DWORD *)(*a1 + 4096);
  v27 = -1;
  v28 = -1;
  if ( a6 )
    *a6 = 0;
  if ( !a2 || !a3 )
    return -1073741811;
  if ( a4 == 1 && !a5 && (*(_DWORD *)(v7 + 3980) & 1) == 0 )
  {
    memmove(v7 + 800, a2, a3);
    *(_DWORD *)(v7 + 3980) |= 1u;
    return 0;
  }
  v29 = a1[6];
  if ( v29 )
  {
    if ( DbgkpTriageDumpCheckPresentHashTable((int)a1, a2, a3, &v27) )
    {
      if ( !a6 )
        return 0;
      v13 = *(_DWORD *)(*(_DWORD *)(v29 + 4 * v27) + 8);
      v14 = *a1;
LABEL_14:
      *a6 = v14 + v13;
      return 0;
    }
    v28 = v27;
  }
  v15 = (a3 + 7) & 0xFFFFFFF8;
  v16 = v15 + 16;
  v29 = v15;
  if ( v15 + 16 >= v15 )
  {
    v17 = a1[5];
    v18 = v9[24];
    if ( v18 >= v17 && v16 <= v18 - v17 )
    {
      memmove(v17 + v7, a2, a3);
      *(_DWORD *)(v7 + 3980) |= 0x800u;
      v19 = v9[24] - 16;
      v20 = v9[25];
      v9[24] = v19;
      v21 = v19 + v7;
      v22 = a5;
      v9[25] = v20 + 1;
      if ( !a5 )
        v22 = a2;
      *(_QWORD *)v21 = v22;
      v23 = v29;
      *(_DWORD *)(v21 + 8) = a1[5];
      *(_DWORD *)(v21 + 12) = a3;
      a1[5] += v23;
      switch ( a4 )
      {
        case 2:
          if ( !v9[7] )
          {
            v9[7] = *(_DWORD *)(v21 + 8);
            v25 = *(_DWORD *)(v7 + 3980) | 4;
            goto LABEL_33;
          }
          break;
        case 3:
          if ( !v9[9] )
          {
            v9[9] = *(_DWORD *)(v21 + 8);
            v25 = *(_DWORD *)(v7 + 3980) | 0x10;
            goto LABEL_33;
          }
          break;
        case 4:
          if ( !v9[8] )
          {
            v9[8] = *(_DWORD *)(v21 + 8);
            *(_DWORD *)(v7 + 3980) |= 8u;
            *(_DWORD *)(v7 + 16) = *(_DWORD *)(a2 + 24);
          }
          break;
        default:
          if ( a4 == 5 && !v9[10] )
          {
            v9[10] = *(_DWORD *)(v21 + 8);
            v24 = *(_DWORD *)(v21 + 12);
            v9[18] = a2;
            v9[11] = v24;
            v25 = *(_DWORD *)(v7 + 3980) | 0x20;
LABEL_33:
            *(_DWORD *)(v7 + 3980) = v25;
            break;
          }
          break;
      }
      v26 = a1[6];
      if ( v26 )
      {
        if ( a1[7] < 0x6F9u )
        {
          *(_DWORD *)(v26 + 4 * v28) = v21;
          ++a1[7];
        }
      }
      if ( !a6 )
        return 0;
      v13 = *a1;
      v14 = *(_DWORD *)(v21 + 8);
      goto LABEL_14;
    }
  }
  return -1073741670;
}
