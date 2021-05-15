// RtlpMuiRegCreateLanguageConfigList 
 
_BYTE *__fastcall RtlpMuiRegCreateLanguageConfigList(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  _BYTE *result; // r0
  int v6; // r3
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v4 = a1;
  if ( a1 < 1 )
    v4 = 4;
  result = sub_4F4478(0xCu, v4, 0xCu, 0, 0, v7);
  if ( result )
  {
    v6 = v7[0];
    *((_WORD *)result + 2) = 0;
    *((_WORD *)result + 3) = v4;
    *(_DWORD *)result = v6;
    *((_DWORD *)result + 2) = result + 12;
  }
  return result;
}
