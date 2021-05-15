// FsRtlIsFatDbcsLegal 
 
int __fastcall FsRtlIsFatDbcsLegal(unsigned int a1, char *a2, int a3, int a4, char a5)
{
  unsigned int v5; // r7
  _BYTE *v6; // r5
  unsigned int v7; // r4
  int v9; // r9
  unsigned int i; // r1
  int v12; // r3
  int v14; // r2
  unsigned int v15; // r1
  int v17; // r2
  __int16 v18; // [sp+8h] [bp-28h]
  _BYTE *v19; // [sp+Ch] [bp-24h]
  int v20; // [sp+10h] [bp-20h]
  int v21; // [sp+14h] [bp-1Ch]
  unsigned int varg_r0; // [sp+38h] [bp+8h] BYREF
  char *varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  varg_r0 = a1;
  v5 = (unsigned __int16)a1;
  v6 = a2;
  v7 = 0;
  varg_r1 = a2;
  v9 = 0;
  if ( !(_WORD)a1 )
    return 0;
  if ( !a3 )
  {
LABEL_3:
    if ( *a2 != 92 )
      goto LABEL_4;
    if ( a5 )
    {
      if ( (unsigned __int16)a1 <= 1u )
        return 1;
      v5 = (unsigned __int16)(a1 - 1);
      v6 = a2 + 1;
      varg_r0 = __PAIR32__(HIWORD(varg_r0), v5) - 0x10000;
      LOWORD(a1) = varg_r0;
      varg_r1 = a2 + 1;
LABEL_4:
      if ( !a4 )
      {
        if ( a3 && FsRtlDoesDbcsContainWildCards((unsigned __int16 *)&varg_r0) )
        {
          v14 = 0;
          if ( v5 )
          {
            while ( 1 )
            {
              v15 = (unsigned __int8)v6[v14];
              if ( v15 >= 0x80 && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[v15] )
              {
                ++v14;
              }
              else if ( (v15 & 0x80u) == 0 && (*((_BYTE *)dword_407310 + v15) & 9) == 0 )
              {
                return 0;
              }
              if ( ++v14 >= v5 )
                return 1;
            }
          }
          return 1;
        }
        if ( v5 <= 0xC )
        {
          for ( i = 0; i < v5; ++v6 )
          {
            v7 = (unsigned __int8)*v6;
            if ( v7 >= 0x80 && NlsMbOemCodePageTag && NlsOemLeadByteInfoTable[v7] )
            {
              if ( !v9 && i >= 7 || i == v5 - 1 )
                return 0;
              ++i;
              ++v6;
            }
            else
            {
              if ( (v7 & 0x80u) == 0 )
              {
                v12 = a3 ? 8 : 0;
                if ( (*((unsigned __int8 *)dword_407310 + v7) & (v12 | 1)) == 0 )
                  return 0;
              }
              if ( v7 == 46 || v7 == 34 )
              {
                if ( !i || v9 || v5 - i - 1 > 3 || *(v6 - 1) == 32 )
                  return 0;
                v9 = 1;
              }
              if ( i >= 8 && !v9 )
                return 0;
            }
            ++i;
          }
          if ( v7 != 32 && v7 != 46 && v7 != 34 )
            return 1;
        }
        return 0;
      }
      v18 = a1;
      v19 = v6;
      if ( v5 )
      {
        while ( *v6 != 92 )
        {
          FsRtlDissectDbcs();
          if ( !FsRtlIsFatDbcsLegal(v20, v21, a3, 0, 0) )
            break;
          if ( !v18 )
            return 1;
          v6 = v19;
        }
        return 0;
      }
      return 1;
    }
    return 0;
  }
  if ( (unsigned __int16)a1 != 1 )
  {
    if ( (unsigned __int16)a1 == 2 )
    {
      v17 = *a2;
      if ( v17 == 46 && a2[1] == 46 )
        return 1;
      if ( v17 == 34 && a2[1] == 34 )
        return 1;
    }
    goto LABEL_3;
  }
  return sub_7D6EE4();
}
