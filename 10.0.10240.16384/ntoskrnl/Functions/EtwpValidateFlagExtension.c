// EtwpValidateFlagExtension 
 
int __fastcall EtwpValidateFlagExtension(int *a1)
{
  int v2; // r4
  unsigned __int16 *v3; // r1
  int v4; // r0
  unsigned int v5; // r4
  unsigned __int16 v6; // r3
  unsigned __int16 *v7; // r0
  unsigned int v8; // r5
  unsigned int v9; // r2
  unsigned int v10; // r1
  int v11; // [sp+0h] [bp-10h]

  v11 = a1[18];
  if ( v11 >= 0 )
    return 0;
  if ( BYTE2(v11) != 255 )
    return -1073741811;
  if ( !(_WORD)v11 )
    return -1073741811;
  v2 = *a1;
  if ( *a1 < (unsigned int)(unsigned __int16)v11 + 4 )
    return -1073741811;
  v3 = (unsigned __int16 *)((char *)a1 + (unsigned __int16)v11);
  if ( ((unsigned __int8)v3 & 1) == 0 )
  {
    v4 = *v3;
    if ( *v3 && 4 * v4 <= v2 - (unsigned int)(unsigned __int16)v11 )
    {
      v5 = v3[1];
      v6 = v4 - 1;
      v7 = v3 + 2;
      LOWORD(v8) = 0;
      v9 = v6;
      if ( v3[1] )
      {
        while ( ((unsigned __int8)v7 & 1) == 0 )
        {
          if ( !v9 )
            return -1073741811;
          v10 = *v7;
          if ( v9 < v10 )
            return -1073741811;
          v9 = (unsigned __int16)(v9 - v10);
          v8 = (unsigned __int16)(v8 + 1);
          v7 += 2 * v10;
          if ( v8 >= v5 )
            goto LABEL_14;
        }
        return -1073741115;
      }
LABEL_14:
      if ( !v9 )
        return 0;
    }
    return -1073741811;
  }
  return -1073741115;
}
