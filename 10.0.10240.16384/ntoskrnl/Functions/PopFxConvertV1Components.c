// PopFxConvertV1Components 
 
int __fastcall PopFxConvertV1Components(_DWORD *a1, unsigned int a2, int a3, int a4)
{
  _DWORD *v5; // r7
  _DWORD *v6; // r9
  unsigned int v7; // r4
  unsigned int v8; // r2
  _DWORD *v9; // r3
  int v10; // r1
  unsigned int v11; // r1
  unsigned int v12; // r8
  int v13; // r4
  _BYTE *v14; // r0
  _DWORD *v15; // r5
  _DWORD *v16; // r0
  unsigned int v17; // lr
  char *v18; // r8
  unsigned int v19; // r10
  int v20; // r2
  int v21; // r3
  int v22; // r4
  int v23; // r4
  char *v24; // r1
  _DWORD *v25; // r2
  int v26; // r3
  unsigned int v27; // r2
  unsigned int v28; // r3
  unsigned int v30; // [sp+0h] [bp-28h] BYREF
  int v31[9]; // [sp+4h] [bp-24h] BYREF

  v31[0] = a3;
  v31[1] = a4;
  v30 = 0;
  v5 = a1;
  v6 = 0;
  if ( a2 )
  {
    v7 = 0;
    v8 = 0;
    v9 = a1;
    while ( 1 )
    {
      v10 = v9[4];
      if ( !v10 )
        break;
      v11 = v10 + v7;
      if ( v11 < v7 )
        break;
      ++v8;
      v9 += 7;
      v7 = v11;
      if ( v8 >= a2 )
      {
        if ( RtlULongLongToULong(48 * a2, (48 * (unsigned __int64)a2) >> 32, v31) >= 0 )
        {
          v12 = (v31[0] + 7) & 0xFFFFFFF8;
          if ( RtlULongLongToULong(24 * v7, (24 * (unsigned __int64)v7) >> 32, &v30) >= 0 )
          {
            v13 = v12 + v30;
            if ( v12 + v30 >= v30 )
            {
              v14 = (_BYTE *)ExAllocatePoolWithTag(512, v12 + v30, 1297630800);
              v15 = v14;
              if ( v14 )
              {
                v16 = memset(v14, 0, v13);
                v17 = 0;
                v18 = (char *)v15 + v12;
                if ( a2 )
                {
                  v16 = v15;
                  v19 = v13 - 24;
                  while ( 1 )
                  {
                    v20 = v5[1];
                    v21 = v5[2];
                    v22 = v5[3];
                    *v16 = *v5;
                    v16[1] = v20;
                    v16[2] = v21;
                    v16[3] = v22;
                    v16[4] = 0;
                    v16[5] = 0;
                    v16[7] = v5[4];
                    v16[8] = v18;
                    v16[6] = v5[5];
                    v30 = 0;
                    if ( v5[4] )
                      break;
LABEL_17:
                    ++v17;
                    v5 += 7;
                    v16 += 12;
                    if ( v17 >= a2 )
                      goto LABEL_18;
                  }
                  v23 = 0;
                  v24 = (char *)(v18 - (char *)v15);
                  while ( (unsigned int)v24 <= v19 )
                  {
                    v24 += 24;
                    v25 = (_DWORD *)(v5[6] + v23);
                    v23 += 24;
                    *((_DWORD *)v18 + 4) = v25[4];
                    *(_DWORD *)v18 = *v25;
                    *((_DWORD *)v18 + 1) = v25[1];
                    *((_DWORD *)v18 + 2) = v25[2];
                    v26 = v25[3];
                    v27 = v30;
                    *((_DWORD *)v18 + 3) = v26;
                    v28 = v5[4];
                    v18 += 24;
                    v30 = v27 + 1;
                    if ( v27 + 1 >= v28 )
                      goto LABEL_17;
                  }
                }
                else
                {
LABEL_18:
                  v6 = v15;
                  v15 = 0;
                }
                if ( v15 )
                  return sub_81297C(v16);
              }
            }
          }
        }
        return (int)v6;
      }
    }
  }
  return (int)v6;
}
