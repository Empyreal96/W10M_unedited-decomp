// _PnpValidatePropertyData 
 
int __fastcall PnpValidatePropertyData(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v7; // r5
  __int16 v8; // r2
  int v9; // r3
  int v10; // r8
  int v11; // r3
  bool v12; // zf
  unsigned int v14; // r2
  int v15; // r3
  unsigned int v16; // r3
  bool v17; // zf
  unsigned int v18; // r5
  unsigned int v19; // r3
  int v20[6]; // [sp+0h] [bp-18h] BYREF

  v20[0] = a4;
  v4 = 0;
  if ( (a3 & 0xFFFF0000) != 0 )
    return -1073741811;
  v7 = a3 & 0xFFF;
  if ( v7 > 0x19 )
    return -1073741811;
  v9 = GetBaseTypeSize(a3 & 0xFFF);
  v10 = v8 & 0xF000;
  if ( !v9 )
    goto LABEL_8;
  if ( v10 == 4096 )
  {
    if ( v7 <= 1 || !IsFixedSizeType(v8) || a2 < v16 )
      return -1073741811;
    if ( !v16 )
      __brkdiv0();
    v17 = a2 % v16 == 0;
  }
  else
  {
    if ( v10 != 0x2000 )
    {
      if ( (v8 & 0xF000) != 0 || IsFixedSizeType(v8) && a2 != v11 )
        return -1073741811;
      goto LABEL_8;
    }
    if ( v7 == 18 )
      goto LABEL_10;
    v17 = v7 == 20;
  }
  if ( !v17 )
    return -1073741811;
LABEL_8:
  if ( v7 <= 0x12 )
  {
    if ( v7 == 18 )
    {
LABEL_10:
      if ( !a1 || a2 < 2 )
        return -1073741811;
      if ( (v10 & 0x2000) != 0 )
      {
        v18 = 0;
        if ( *(_WORD *)a1 )
        {
          while ( RtlStringCbLengthW(a1, a2 - v18, v20) >= 0 )
          {
            if ( (v20[0] & 1) != 0 )
              break;
            v19 = v20[0] + 2;
            v20[0] = v19;
            if ( v19 > 0xFFFE )
              break;
            v18 += v19;
            if ( v18 > a2 )
              break;
            a1 += 2 * (v19 >> 1);
            if ( !*(_WORD *)a1 )
              goto LABEL_49;
          }
          return -1073741811;
        }
LABEL_49:
        v12 = v18 + 2 == a2;
      }
      else
      {
        v20[0] = 0;
        if ( RtlStringCbLengthW(a1, a2, v20) < 0 || (unsigned int)(v20[0] + 2) > 0xFFFE )
          return -1073741811;
        v12 = v20[0] + 2 == a2;
      }
LABEL_16:
      if ( !v12 )
        return -1073741811;
      return v4;
    }
    if ( v7 <= 1 )
    {
      v12 = a2 == 0;
      goto LABEL_16;
    }
    if ( v7 == 16 )
    {
      if ( a1 )
      {
        v14 = 0;
        if ( !(a2 >> 3) )
          return v4;
        while ( *(int *)(a1 + 4) >= 0 )
        {
          ++v14;
          a1 += 8;
          if ( v14 >= a2 >> 3 )
            return v4;
        }
      }
      return -1073741811;
    }
    if ( v7 == 17 )
    {
      if ( a1 )
      {
        v15 = 0;
        if ( !a2 )
          return v4;
        while ( !*(_BYTE *)(v15 + a1) || *(char *)(v15 + a1) == -1 )
        {
          if ( ++v15 >= a2 )
            return v4;
        }
      }
      return -1073741811;
    }
    return 0;
  }
  if ( v7 == 25 )
    goto LABEL_10;
  if ( v7 != 19 )
  {
    if ( v7 == 20 )
      goto LABEL_10;
    return 0;
  }
  return sub_7C6FCC();
}
