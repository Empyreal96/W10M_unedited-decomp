// RtlpNameprepAsciiWorker 
 
int __fastcall RtlpNameprepAsciiWorker(int a1, unsigned __int16 *a2, int a3, int a4, int *a5, char a6)
{
  int v7; // r4
  int v9; // r7
  int v10; // r2
  int v11; // r1
  int v12; // r5
  int result; // r0
  unsigned int v14; // r2
  unsigned __int16 *v15; // r1
  int v16; // r5
  char *v17; // lr
  int v18; // r10
  int v19; // r3
  int v20; // r0
  int v21; // r0
  bool v22; // cc
  int v23; // r2
  unsigned int v25; // r2
  int v26; // [sp+8h] [bp-840h] BYREF
  unsigned int v27; // [sp+Ch] [bp-83Ch] BYREF
  int v28; // [sp+10h] [bp-838h]
  int v29; // [sp+14h] [bp-834h]
  int v30; // [sp+18h] [bp-830h]
  char v31[1024]; // [sp+20h] [bp-828h] BYREF
  _WORD v32[532]; // [sp+420h] [bp-428h] BYREF

  v7 = a3;
  if ( a2 )
  {
    if ( a3 >= -1 )
    {
      if ( a5 )
      {
        v9 = *a5;
        if ( *a5 >= 0 && (*a5 <= 0 || a4) && (a1 & 0xFFFFFFF8) == 0 )
        {
          v27 = (a1 & 1) != 0;
          v10 = (a1 & 4) != 0;
          v11 = (a1 & 2) != 0;
          v12 = 0;
          v29 = v10;
          v30 = v11;
          v28 = 0;
          if ( v7 != -1 )
          {
LABEL_11:
            if ( v7 > 0 && !a2[v7 - 1] )
            {
              v12 = 1;
              v28 = 1;
              --v7;
            }
            if ( RtlpValidateAsciiStd3AndLength(a2, v7, v10, v11) )
            {
              if ( !v7 )
                return -1073740010;
              if ( v12 )
                ++v7;
              if ( !a4 || !v9 )
                goto LABEL_24;
              if ( v7 <= v9 )
              {
                v14 = 2 * v7;
                v15 = a2;
LABEL_23:
                memmove(a4, (int)v15, v14);
LABEL_24:
                *a5 = v7;
                return 0;
              }
              goto LABEL_77;
            }
            v16 = 0;
            v17 = v31;
            v18 = 0;
            v19 = 511;
            if ( !v29 )
              goto LABEL_32;
            v20 = FindEmailAt((int)a2, v7);
            v18 = v20;
            if ( !v20 )
            {
LABEL_28:
              result = -1073740010;
LABEL_78:
              *a5 = 0;
              return result;
            }
            v26 = 511;
            result = RtlNormalizeString(1, a2, v20, v31, &v26);
            v16 = v26;
            if ( result >= 0 )
            {
              if ( v26 )
              {
                v17 = &v31[2 * v26];
                v19 = 511 - v26;
LABEL_32:
                if ( v18 >= v7 )
                {
LABEL_45:
                  if ( v16 > 0 )
                  {
                    if ( *(_WORD *)&v31[2 * v16 - 2] == 46 )
                    {
                      v23 = a2[v7 - 1];
                      if ( v23 != 46 && v23 != 12290 && v23 != 65294 && v23 != 65377 )
                        goto LABEL_28;
                    }
                    if ( !*(_WORD *)&v31[2 * v16 - 2] )
                      goto LABEL_28;
                  }
                  v27 = 515;
                  result = punycode_encode(v31, v16, v32, &v27, v29, v30);
                  v7 = v27;
                  if ( !v27 )
                    goto LABEL_78;
                  if ( !a6 )
                  {
                    if ( v28 )
                    {
                      if ( (unsigned int)v16 > 0x1FF )
                        goto LABEL_28;
                      v25 = 2 * v16++;
                      if ( v25 >= 0x3FE )
                        _report_rangecheckfailure();
                      *(_WORD *)&v31[v25] = 0;
                    }
                    if ( a4 && v9 )
                    {
                      if ( v16 > v9 )
                      {
LABEL_77:
                        result = -1073741789;
                        goto LABEL_78;
                      }
                      memmove(a4, (int)v31, 2 * v16);
                    }
                    *a5 = v16;
                    return 0;
                  }
                  if ( v28 )
                  {
                    if ( v27 >= 0x203 )
                      goto LABEL_28;
                    v7 = v27 + 1;
                    if ( 2 * v27 >= 0x406 )
                      _report_rangecheckfailure();
                    v32[v27] = 0;
                  }
                  if ( !a4 || !v9 )
                    goto LABEL_24;
                  if ( v7 <= v9 )
                  {
                    v14 = 2 * v7;
                    v15 = v32;
                    goto LABEL_23;
                  }
                  goto LABEL_77;
                }
                v26 = v19;
                if ( v27 )
                  v21 = 13;
                else
                  v21 = 269;
                result = RtlNormalizeString(v21, &a2[v18], v7 - v18, v17, &v26);
                if ( result >= 0 )
                {
                  if ( v26 )
                  {
                    v16 += v26;
                    goto LABEL_45;
                  }
                  if ( !result )
                    goto LABEL_28;
                }
                if ( result == -1073741789 || result == -1073740009 )
                  goto LABEL_28;
                v22 = v26 <= 0;
LABEL_39:
                if ( v22 )
                  goto LABEL_78;
                goto LABEL_28;
              }
              if ( !result )
                goto LABEL_28;
            }
            if ( result == -1073741789 || result == -1073740009 )
              goto LABEL_28;
            v22 = v26 <= 0;
            goto LABEL_39;
          }
          if ( RtlStringCchLengthW(a2, 0x7FFFFFFFu, &v26) >= 0 )
          {
            v10 = v29;
            v11 = v30;
            v7 = v26 + 1;
            goto LABEL_11;
          }
        }
      }
    }
  }
  return -1073741811;
}
