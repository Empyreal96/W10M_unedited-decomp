// SepSecureBootFindMatchingRegistryRule 
 
_DWORD *__fastcall SepSecureBootFindMatchingRegistryRule(int a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r4
  unsigned int v7; // r5
  int v8; // r6
  _WORD *v9; // r2
  _WORD *v10; // r2
  int v12; // [sp+0h] [bp-20h] BYREF
  _WORD *v13; // [sp+4h] [bp-1Ch]
  int v14; // [sp+8h] [bp-18h]

  v12 = a2;
  v13 = (_WORD *)a3;
  v14 = a4;
  v6 = (_DWORD *)dword_641860;
  v7 = dword_641860 + 16 * *(unsigned __int16 *)(dword_641874 + 38);
  if ( dword_641860 >= v7 )
    return 0;
  v8 = dword_64185C;
  while ( 1 )
  {
    if ( *v6 == -2130706432 )
    {
      v9 = (_WORD *)(v6[1] + v8);
      v13 = v9 + 1;
      LOWORD(v12) = *v9;
      HIWORD(v12) = v12 + 2;
      if ( SepEqualAsciiWideStringCaseInSensitive(a2, &v12) )
      {
        v10 = (_WORD *)(v6[2] + v8);
        v13 = v10 + 1;
        LOWORD(v12) = *v10;
        HIWORD(v12) = v12 + 2;
        if ( SepEqualAsciiWideStringCaseInSensitive(a3, &v12) )
          break;
      }
    }
    v6 += 4;
    if ( (unsigned int)v6 >= v7 )
      return 0;
  }
  return v6;
}
