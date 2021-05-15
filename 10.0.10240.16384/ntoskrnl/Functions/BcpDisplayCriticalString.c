// BcpDisplayCriticalString 
 
int __fastcall BcpDisplayCriticalString(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int *v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r9
  int v11; // r7
  unsigned int v12; // r5
  int v13; // r8
  int v14; // r4
  int v15; // r6
  int v16; // r1
  int v17; // r4
  unsigned int v18; // r2
  unsigned int v19; // r7
  int v20; // r3
  int v21; // r2
  int v22; // r1
  int v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r3
  unsigned int v26; // r0
  int v28; // [sp+10h] [bp-48h]
  int v29; // [sp+18h] [bp-40h] BYREF
  unsigned int v30; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v31; // [sp+20h] [bp-38h]
  int v32; // [sp+24h] [bp-34h]
  int v33; // [sp+28h] [bp-30h] BYREF
  int v34; // [sp+2Ch] [bp-2Ch]
  int v35; // [sp+30h] [bp-28h]
  int *v36; // [sp+34h] [bp-24h]
  int v37[8]; // [sp+38h] [bp-20h] BYREF

  v5 = &dword_616150[14 * a4];
  v6 = v5[7];
  v7 = v5[3];
  v36 = v5;
  v8 = v6 + v7;
  v9 = v5[5];
  v35 = v8;
  v10 = v9 + v8;
  v11 = *(_DWORD *)(dword_641660 + 20);
  *(_DWORD *)(v11 + 40) = a2;
  *(_DWORD *)(dword_641660 + 4) = a2;
  v34 = v11;
  v13 = dword_653570;
  v12 = BcpCursor;
  v14 = dword_653574;
  v37[0] = 0;
  v15 = BgpFoGetStringAdvanceWidth(v11 + 28, a1, &v33, 0);
  if ( v15 < 0 || v33 + v12 <= v10 )
  {
    v16 = 0;
  }
  else
  {
    v16 = 1;
    v37[0] = 1;
  }
  v17 = v14 - v13;
  v32 = *(_DWORD *)(v11 + 28);
  if ( v17 <= 0 )
    v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = *a1 & 0xFFFE;
  v31 = 0;
  if ( v20 )
  {
    do
    {
      if ( v16 )
      {
        if ( v18 <= v19 )
        {
          v21 = *((_DWORD *)a1 + 1);
          v22 = 2 * v19;
          v33 = 0;
          v23 = *(unsigned __int16 *)(2 * v19 + v21);
          v31 = v19;
          if ( v23 != 32 )
          {
            do
            {
              v24 = *(unsigned __int16 *)(v21 + v22);
              if ( !v24 || v24 == 13 || v24 == 10 )
                break;
              v15 = BgpRasGetGlyphAdvanceWidth(v34 + 28, v24, &v29, v34, BcpWorkspace);
              if ( v15 < 0 )
                goto LABEL_33;
              v25 = v33 + v29 + v12;
              v26 = v31 + 1;
              v33 += v29;
              ++v31;
              if ( v10 < v25 && v17 )
              {
                if ( v12 < v10 )
                {
                  v15 = BcpPrintSpaces(dword_641660, v12, v10, v13, v32, &v30);
                  if ( v15 < 0 )
                    goto LABEL_33;
                  v17 = v30;
                }
                v12 = v35;
                v13 += v36[9] + v17;
                v17 = 0;
                break;
              }
              v21 = *((_DWORD *)a1 + 1);
              v22 = 2 * v26;
            }
            while ( *(_WORD *)(v21 + 2 * v26) != 32 );
          }
        }
      }
      v15 = BgpRasGetGlyphAdvanceWidth(
              v34 + 28,
              *(unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * v19),
              &v29,
              v34,
              BcpWorkspace);
      if ( v15 < 0 )
        break;
      if ( v10 < v29 + v12 )
      {
        if ( v12 < v10 )
        {
          v15 = BcpPrintSpaces(dword_641660, v12, v10, v13, v32, &v30);
          if ( v15 < 0 )
            break;
          v17 = v30;
        }
        v12 = v35;
        v13 += v36[9] + v17;
        v17 = 0;
        if ( *(_WORD *)(*((_DWORD *)a1 + 1) + 2 * v19) == 32 )
          continue;
      }
      v15 = BgpDisplayCharacterEx(
              *(unsigned __int16 *)(*((_DWORD *)a1 + 1) + 2 * v19),
              (int *)dword_641660,
              v12,
              v13,
              v32,
              -1,
              (int)&v29,
              (int)&v30,
              v28,
              (int)BcpWorkspace);
      if ( v15 < 0 )
        break;
      v12 += v29;
      if ( v30 > v17 )
        v17 = v30;
      ++v19;
      v18 = v31;
      v16 = v37[0];
    }
    while ( v19 < *a1 >> 1 );
  }
LABEL_33:
  v37[0] = v17 + v13;
  BcpSetCursorPosition(v12, v13, v37);
  return v15;
}
