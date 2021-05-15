// AuthzBasepSecurityAttributePresent 
 
int __fastcall AuthzBasepSecurityAttributePresent(int a1, int a2)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r6
  bool v6; // cf
  _DWORD *v7; // r0

  v3 = *(_DWORD **)(a1 + 4);
  v4 = (_DWORD *)(a1 + 4);
  if ( v3 == (_DWORD *)(a1 + 4) )
  {
LABEL_6:
    if ( *(_DWORD *)(a1 + 16) != a1 + 16 )
      return sub_517F58();
    return 0;
  }
  while ( 1 )
  {
    v6 = (unsigned int)KeGetCurrentIrql() >= 2;
    v7 = v3 + 4;
    if ( v6 ? AuthzBasepEqualUnicodeStringCaseSensitive(v7, a2) : RtlEqualUnicodeString(v7, a2, 1) )
      break;
    v3 = (_DWORD *)*v3;
    if ( v3 == v4 )
      goto LABEL_6;
  }
  return v3 != 0;
}
