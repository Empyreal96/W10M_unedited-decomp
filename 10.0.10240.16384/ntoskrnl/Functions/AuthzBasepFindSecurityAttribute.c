// AuthzBasepFindSecurityAttribute 
 
_DWORD *__fastcall AuthzBasepFindSecurityAttribute(int a1, int a2)
{
  _DWORD *v3; // r4
  _DWORD *v4; // r7
  bool v6; // cf
  _DWORD *v7; // r0
  _DWORD *v9; // r4
  _DWORD *v10; // r5
  _DWORD *v11; // t1
  _DWORD *result; // r0

  v3 = *(_DWORD **)(a1 + 4);
  v4 = (_DWORD *)(a1 + 4);
  if ( v3 == (_DWORD *)(a1 + 4) )
  {
LABEL_6:
    v11 = *(_DWORD **)(a1 + 16);
    v10 = (_DWORD *)(a1 + 16);
    v9 = v11;
    if ( v11 == v10 )
    {
LABEL_7:
      result = 0;
    }
    else
    {
      while ( (v9[6] & 1) != 0 || !AuthzBasepEqualUnicodeString((int)(v9 + 2), a2) )
      {
        v9 = (_DWORD *)*v9;
        if ( v9 == v10 )
          goto LABEL_7;
      }
      result = v9 - 2;
    }
  }
  else
  {
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
    result = v3;
  }
  return result;
}
