// ExpTranslateHexStringToGUID 
 
int __fastcall ExpTranslateHexStringToGUID(unsigned __int16 *a1, _DWORD *a2)
{
  unsigned __int16 *v3; // r9
  int v4; // r6
  int v5; // r4
  int v6; // r7
  int v7; // r5
  int v8; // r8
  int v9; // t1
  unsigned int v10; // r0
  unsigned __int16 v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v16; // [sp+0h] [bp-30h]
  int v17; // [sp+4h] [bp-2Ch]
  int v18; // [sp+8h] [bp-28h]
  int v19; // [sp+Ch] [bp-24h]

  v3 = a1;
  if ( wcslen(a1) == 32 )
  {
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    while ( 1 )
    {
      v9 = *v3++;
      v10 = towlower(v9);
      if ( v10 < 0x30 || v10 > 0x39 )
      {
        if ( v10 < 0x61 || v10 > 0x66 )
          return -1073741811;
        v4 = v10 + 16 * v4 - 87;
      }
      else
      {
        v4 = v10 + 16 * v4 - 48;
      }
      if ( (v8 & 1) == 0 )
        goto LABEL_25;
      if ( v5 )
      {
        switch ( v5 )
        {
          case 1:
            v7 += v4 << (8 * v6);
            v6 = (unsigned __int16)(v6 + 1);
            if ( v6 == 2 )
            {
              LOWORD(v17) = v7;
              goto LABEL_22;
            }
            break;
          case 2:
            v7 += v4 << (8 * v6);
            v6 = (unsigned __int16)(v6 + 1);
            if ( v6 == 2 )
            {
              HIWORD(v17) = v7;
              goto LABEL_22;
            }
            break;
          case 3:
            *((_BYTE *)&v18 + v6) = v4;
            v6 = (unsigned __int16)(v6 + 1);
            if ( v6 != 8 )
              break;
            v11 = 4;
            goto LABEL_23;
          default:
            return -1073741811;
        }
      }
      else
      {
        v7 += v4 << (8 * v6);
        v6 = (unsigned __int16)(v6 + 1);
        if ( v6 == 4 )
        {
          v16 = v7;
LABEL_22:
          v11 = v5 + 1;
          v6 = 0;
          v7 = 0;
LABEL_23:
          v5 = v11;
          goto LABEL_24;
        }
      }
LABEL_24:
      v4 = 0;
LABEL_25:
      if ( (unsigned int)++v8 >= 0x20 )
      {
        v12 = v17;
        v13 = v18;
        v14 = v19;
        *a2 = v16;
        a2[1] = v12;
        a2[2] = v13;
        a2[3] = v14;
        return 0;
      }
    }
  }
  return -1073741811;
}
