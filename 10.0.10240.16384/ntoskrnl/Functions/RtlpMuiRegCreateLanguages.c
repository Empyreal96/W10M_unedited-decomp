// RtlpMuiRegCreateLanguages 
 
_BYTE *__fastcall RtlpMuiRegCreateLanguages(int a1, int a2, int a3, int a4)
{
  _BYTE *result; // r0
  int v5; // r3
  int v6; // [sp+8h] [bp-8h] BYREF

  v6 = a4;
  result = sub_4F4478(0x10u, 4u, 0x1Cu, 0, 0, &v6);
  if ( result )
  {
    v5 = v6;
    *((_WORD *)result + 3) = 0;
    *(_DWORD *)result = v5;
    *((_WORD *)result + 2) = 4;
    *((_DWORD *)result + 3) = result + 16;
  }
  return result;
}
