// CmpCancelSubordinatePost 
 
_DWORD *__fastcall CmpCancelSubordinatePost(_DWORD *result, int a2)
{
  __int64 v2; // kr00_8

  if ( (_DWORD *)result[4] != result + 4 )
  {
    result = (_DWORD *)(result[4] - 16);
    v2 = *(_QWORD *)result;
    if ( *(_DWORD **)(*result + 4) != result || *(_DWORD **)HIDWORD(v2) != result )
      sub_7EBB08();
    *(_DWORD *)HIDWORD(v2) = v2;
    *(_DWORD *)(v2 + 4) = HIDWORD(v2);
    if ( a2 )
      result = (_DWORD *)CmpAddToDelayedDeref((int)result, a2);
  }
  return result;
}
