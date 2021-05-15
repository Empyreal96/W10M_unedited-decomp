// IopFillTriageDumpDataBlocks 
 
unsigned int __fastcall IopFillTriageDumpDataBlocks(_DWORD *a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int v6; // r6
  unsigned int v7; // r8
  unsigned int v8; // r2
  int v9; // lr
  unsigned int result; // r0
  int *v12; // r9
  unsigned int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r1
  __int64 v16; // r2
  unsigned int v17; // r3
  unsigned int v18; // r2
  int v19; // t1
  unsigned int v20; // [sp+0h] [bp-30h]
  unsigned int v21; // [sp+4h] [bp-2Ch]
  unsigned int v22; // [sp+8h] [bp-28h]

  v6 = 0;
  v7 = a1[24] + a4;
  v8 = v7;
  v9 = a4;
  result = v7 + 16 * a1[25];
  v20 = v7;
  v21 = result;
  if ( a2 )
  {
    while ( 1 )
    {
      v12 = (int *)a3[2];
      v22 = 0;
      if ( *a3 )
        break;
LABEL_10:
      ++v6;
      a3 += 3;
      if ( v6 >= a2 )
        return result;
    }
    v13 = -16 - v7;
    while ( 1 )
    {
      v14 = v8 + 16;
      if ( (unsigned int)((int)(v13 + v8 + 16) >> 4) >= a1[25] )
        break;
      v15 = a1[1] + v9;
      if ( v14 > v15 )
        break;
      v16 = *(_QWORD *)v12;
      if ( HIDWORD(v16) < (unsigned int)v16 )
        break;
      v17 = HIDWORD(v16) - v16 + result;
      if ( v17 < result || v17 > v15 )
        break;
      *(_QWORD *)v20 = (int)v16;
      *(_DWORD *)(v20 + 8) = result - v9;
      v18 = v12[1] - *v12;
      *(_DWORD *)(v20 + 12) = v18;
      v19 = *v12;
      v12 += 2;
      memmove(result, v19, v18);
      v9 = a4;
      v8 = v14;
      result = v21 + *(_DWORD *)(v20 + 12);
      v20 = v14;
      v21 = result;
      ++v22;
      v13 = -16 - v7;
      if ( v22 >= *a3 )
        goto LABEL_10;
    }
  }
  return result;
}
