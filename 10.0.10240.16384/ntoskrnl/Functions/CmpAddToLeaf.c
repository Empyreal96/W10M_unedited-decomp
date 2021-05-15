// CmpAddToLeaf 
 
int __fastcall CmpAddToLeaf(int a1, unsigned int a2, int a3, unsigned __int16 *a4)
{
  int v5; // r5
  unsigned __int16 *v8; // r0
  unsigned __int16 *v9; // r4
  unsigned int v10; // r1
  int v11; // r3
  unsigned __int16 *v13; // r7
  unsigned int v14; // r9
  int v15; // r6
  int v16; // r0
  int v17; // r3
  unsigned __int16 *v18; // r0
  int v19; // r1
  unsigned int v20; // r2
  int v21; // r0
  unsigned __int16 *v22; // r5
  unsigned __int16 *v23; // r0
  unsigned int v24; // r2
  char *v25; // r1
  unsigned int v26; // r3
  unsigned int v27; // r4
  int v28; // [sp+8h] [bp-30h] BYREF
  unsigned __int16 *v29; // [sp+Ch] [bp-2Ch] BYREF
  unsigned __int16 *v30; // [sp+10h] [bp-28h]
  int v31; // [sp+14h] [bp-24h]
  unsigned int v32[8]; // [sp+18h] [bp-20h] BYREF

  v30 = a4;
  v31 = a3;
  v5 = -1;
  v28 = -1;
  if ( HvpMarkCellDirty(a1, a2, 0, 0) )
  {
    v8 = (unsigned __int16 *)(*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, a2, &v28);
    v9 = v8;
    if ( v8 )
    {
      v10 = -4 - *((_DWORD *)v8 - 1);
      v11 = v8[1];
      if ( *v8 == 26988 )
        return sub_805B78(v8, v10, 26988, v11);
      v13 = v8;
      v14 = a2;
      if ( v10 - 8 * v11 - 4 < 8 )
      {
        v27 = v10 + (v10 >> 1);
        if ( v27 < 4 - *((_DWORD *)v8 - 1) )
          v27 = 4 - *((_DWORD *)v8 - 1);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
        v29 = 0;
        v14 = HvReallocateCell(a1, a2, v27, 0, &v29, &v28);
        if ( v14 == -1 )
          return v5;
        v9 = v29;
        v13 = v29;
      }
      CmpFindSubKeyInLeafWithStatus(a1, (int)v9, (int)a4, &v29, v32);
      v15 = v32[0];
      if ( (v32[0] & 0x80000000) == 0 && v29 == (unsigned __int16 *)-1 )
      {
        if ( v32[0] == v9[1] )
        {
LABEL_16:
          if ( v13 )
          {
            v22 = &v13[4 * v15];
            *((_DWORD *)v22 + 1) = v31;
            if ( *v13 == 26732 )
            {
              *((_DWORD *)v22 + 2) = CmpComputeHashKey(0, v30);
            }
            else
            {
              v23 = v30;
              *((_BYTE *)v22 + 8) = 0;
              *((_BYTE *)v22 + 9) = 0;
              *((_BYTE *)v22 + 10) = 0;
              *((_BYTE *)v22 + 11) = 0;
              v24 = *v23 >> 1;
              if ( v24 >= 4 )
                v24 = 4;
              v25 = (char *)&v13[4 * v15] + v24;
              do
              {
                v26 = *(unsigned __int16 *)(*((_DWORD *)v23 + 1) + 2 * v24 - 2);
                if ( v26 > 0xFF )
                  break;
                v25[7] = v26;
                --v24;
                --v25;
              }
              while ( v24 );
            }
          }
          else
          {
            *(_DWORD *)&v9[2 * v15 + 2] = v31;
          }
          ++v9[1];
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
          if ( v14 != a2 )
            HvFreeCell(a1, a2);
          return v14;
        }
        v16 = CmpCompareInIndex(a1, v30, v32[0], v9, &v29);
        if ( v16 != 2 )
        {
          if ( v16 > 0 )
            ++v15;
          v17 = v9[1];
          if ( v15 != v17 )
          {
            if ( v13 )
            {
              v18 = &v13[4 * v15];
              v19 = (int)(v18 + 2);
              v20 = 8 * (v13[1] - v15);
              v21 = (int)(v18 + 6);
            }
            else
            {
              v20 = 4 * (v17 - v15);
              v19 = (int)&v9[2 * v15 + 2];
              v21 = (int)&v9[2 * v15 + 4];
            }
            memmove(v21, v19, v20);
          }
          goto LABEL_16;
        }
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v28);
      if ( v14 != a2 )
        HvFreeCell(a1, v14);
      return v5;
    }
  }
  return v5;
}
