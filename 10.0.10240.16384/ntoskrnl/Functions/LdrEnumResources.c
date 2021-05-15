// LdrEnumResources 
 
int __fastcall LdrEnumResources(int a1, unsigned __int16 **a2, unsigned int a3, _DWORD *a4, int a5)
{
  int v5; // r7
  unsigned int v6; // r10
  unsigned __int16 **v7; // r8
  int v8; // r0
  int v9; // r5
  int v10; // r4
  int *v11; // r9
  bool v12; // zf
  BOOL v13; // r3
  int v14; // r2
  int v15; // r3
  int *v16; // r8
  BOOL v17; // r3
  int v18; // r2
  int v19; // r3
  int *v20; // r7
  unsigned int v21; // r10
  unsigned int v22; // lr
  int *v23; // r0
  BOOL v24; // r3
  int v25; // r2
  int v26; // r3
  _DWORD *v27; // r1
  int v29; // [sp+0h] [bp-58h]
  unsigned __int16 **v30; // [sp+4h] [bp-54h]
  int *v31; // [sp+8h] [bp-50h]
  unsigned int v33; // [sp+10h] [bp-48h]
  int v34; // [sp+14h] [bp-44h]
  int v35; // [sp+18h] [bp-40h]
  unsigned int i; // [sp+1Ch] [bp-3Ch]
  int v37; // [sp+20h] [bp-38h]
  unsigned int v38; // [sp+24h] [bp-34h]
  unsigned int v40; // [sp+2Ch] [bp-2Ch]
  unsigned int v41; // [sp+30h] [bp-28h] BYREF
  _DWORD *v42; // [sp+34h] [bp-24h]

  v5 = 0;
  v29 = 0;
  v30 = a2;
  v6 = a3;
  v42 = a4;
  v7 = a2;
  if ( a5 )
    v33 = *a4;
  else
    v33 = 0;
  *a4 = 0;
  v8 = RtlImageDirectoryEntryToData(a1, 1, 2, (int)&v41);
  v9 = v8;
  if ( !v8 )
    return -1073741687;
  v10 = 0;
  v11 = (int *)(v8 + 16);
  v12 = *(unsigned __int16 *)(v8 + 12) + *(unsigned __int16 *)(v8 + 14) == 0;
  v41 = *(unsigned __int16 *)(v8 + 12) + *(unsigned __int16 *)(v8 + 14);
  v37 = 0;
  if ( !v12 )
  {
    while ( 1 )
    {
      if ( v6 )
        v13 = LdrpCompareResourceNames_U(*v7, v9, v11) == 0;
      else
        v13 = 1;
      if ( v13 )
      {
        v14 = v11[1];
        if ( (v14 & 0x80000000) == 0 )
          return -1073741701;
        if ( (*v11 & 0x80000000) != 0 )
          v34 = (*v11 & 0x7FFFFFFF) + v9;
        else
          v34 = *(unsigned __int16 *)v11;
        v15 = (v14 & 0x7FFFFFFF) + v9;
        v16 = (int *)(v15 + 16);
        v40 = *(unsigned __int16 *)(v15 + 12) + *(unsigned __int16 *)(v15 + 14);
        for ( i = 0; i < v40; ++i )
        {
          if ( v6 <= 1 )
            v17 = 1;
          else
            v17 = LdrpCompareResourceNames_U(v30[1], v9, v16) == 0;
          if ( v17 )
          {
            v18 = v16[1];
            if ( (v18 & 0x80000000) == 0 )
              return -1073741701;
            if ( (*v16 & 0x80000000) != 0 )
              v35 = (*v16 & 0x7FFFFFFF) + v9;
            else
              v35 = *(unsigned __int16 *)v16;
            v19 = (v18 & 0x7FFFFFFF) + v9;
            v20 = (int *)(v19 + 16);
            v21 = 0;
            v22 = *(unsigned __int16 *)(v19 + 14) + *(unsigned __int16 *)(v19 + 12);
            v38 = v22;
            if ( v22 )
            {
              v23 = (int *)(a5 + 24 * v29);
              v31 = v23;
              do
              {
                if ( a3 <= 2 )
                {
                  v24 = 1;
                }
                else
                {
                  v24 = LdrpCompareResourceNames_U(v30[2], v9, v20) == 0;
                  v23 = v31;
                  v22 = v38;
                }
                if ( v24 )
                {
                  v25 = v20[1];
                  if ( (v25 & 0x80000000) != 0 )
                    return -1073741701;
                  if ( (*v20 & 0x80000000) != 0 )
                    v26 = (*v20 & 0x7FFFFFFF) + v9;
                  else
                    v26 = *(unsigned __int16 *)v20;
                  v27 = (_DWORD *)(v25 + v9);
                  v31 = v23 + 6;
                  if ( ++v29 > v33 )
                  {
                    v10 = -1073741820;
                  }
                  else
                  {
                    v23[2] = v26;
                    *v23 = v34;
                    v23[1] = v35;
                    v23[3] = *v27 + a1;
                    v23[4] = v27[1];
                    v23[5] = 0;
                  }
                }
                ++v21;
                v23 = v31;
                v20 += 2;
              }
              while ( v21 < v22 );
            }
            v6 = a3;
          }
          v16 += 2;
        }
        v7 = v30;
      }
      v11 += 2;
      if ( ++v37 >= v41 )
      {
        v5 = v29;
        break;
      }
    }
  }
  *v42 = v5;
  return v10;
}
