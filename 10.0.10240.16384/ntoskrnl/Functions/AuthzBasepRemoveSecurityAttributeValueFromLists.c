// AuthzBasepRemoveSecurityAttributeValueFromLists 
 
_DWORD *__fastcall AuthzBasepRemoveSecurityAttributeValueFromLists(_DWORD *result, __int64 *a2, int a3)
{
  __int64 v3; // kr00_8
  __int64 v4; // kr08_8

  if ( (a2[2] & 2) != 0 )
  {
    v3 = a2[1];
    if ( *(__int64 **)(v3 + 4) != a2 + 1 || *(__int64 **)HIDWORD(v3) != a2 + 1 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
    *((_DWORD *)a2 + 4) &= 0xFFFFFFFD;
    if ( result )
      --result[13];
  }
  if ( a3 && (a2[2] & 1) != 0 )
  {
    v4 = *a2;
    if ( *(__int64 **)(*(_DWORD *)a2 + 4) != a2 || *(__int64 **)HIDWORD(v4) != a2 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v4) = v4;
    *(_DWORD *)(v4 + 4) = HIDWORD(v4);
    *((_DWORD *)a2 + 4) &= 0xFFFFFFFE;
    if ( result )
    {
      --result[9];
      if ( (a2[2] & 4) != 0 )
        --result[10];
    }
  }
  return result;
}
