// SepSecureBootValidateBcdDataAgainstBcdRule 
 
int __fastcall SepSecureBootValidateBcdDataAgainstBcdRule(int a1, _DWORD *a2, unsigned int a3, int a4)
{
  int v6; // r5
  _WORD *v7; // r0
  int v8; // r1
  int v9; // r3
  bool v10; // zf
  int v11; // r7
  int v12; // r4
  unsigned int v14; // [sp+0h] [bp-18h] BYREF
  int v15; // [sp+4h] [bp-14h]

  v14 = a3;
  v15 = a4;
  v6 = 0;
  v7 = (_WORD *)(*(_DWORD *)(a1 + 8) + dword_64185C);
  v8 = *v7 & 0x1F;
  if ( v8 != 8 )
  {
    v9 = *(_BYTE *)(a1 + 7) & 0xF;
    switch ( v9 )
    {
      case 2:
        if ( v8 || (a3 & 1) != 0 )
          return -1069350910;
        for ( ; a3; a3 -= 2 )
        {
          if ( *((_WORD *)a2 + (a3 >> 1) - 1) )
            break;
        }
        if ( a3 != (unsigned __int16)v7[1] )
          return -1069350910;
        v10 = memcmp((unsigned int)a2, (unsigned int)(v7 + 2), a3) == 0;
        break;
      case 5:
        if ( a3 != 8 )
          return -1069350910;
        v11 = *a2;
        v12 = a2[1];
        v14 = *a2;
        v15 = v12;
        v6 = SepSecureBootGetQWordPolicyValue((int)v7, (int)&v14);
        if ( v6 < 0 )
          return v6;
        if ( v11 != v14 )
          return -1069350910;
        v10 = v12 == v15;
        break;
      case 6:
        if ( v8 != 1 || a3 - 1 > 1 )
          return -1069350910;
        v10 = (v7[1] != 0) == (*(_BYTE *)a2 != 0);
        break;
      default:
        return v6;
    }
    if ( v10 )
      return v6;
    return -1069350910;
  }
  if ( !v7[1] )
    return -1069350910;
  return v6;
}
