// AuthzBasepRemoveSecurityAttributeFromLists 
 
_DWORD *__fastcall AuthzBasepRemoveSecurityAttributeFromLists(_DWORD *result, __int64 *a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  __int64 v5; // kr08_8

  if ( a4 && (a2[4] & 2) != 0 )
  {
    v4 = a2[1];
    if ( *(__int64 **)(v4 + 4) != a2 + 1 || *(__int64 **)HIDWORD(v4) != a2 + 1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    *((_DWORD *)a2 + 8) &= 0xFFFFFFFD;
    if ( result )
      --result[3];
  }
  if ( a3 && (a2[4] & 1) != 0 )
  {
    v5 = *a2;
    if ( *(__int64 **)(*(_DWORD *)a2 + 4) != a2 || *(__int64 **)HIDWORD(v5) != a2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v5) = v5;
    *(_DWORD *)(v5 + 4) = HIDWORD(v5);
    *((_DWORD *)a2 + 8) &= 0xFFFFFFFE;
    if ( result )
      --*result;
  }
  return result;
}
