// CmpUnblockTwoHiveWrites 
 
_DWORD *__fastcall CmpUnblockTwoHiveWrites(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r5

  v2 = result;
  if ( result )
    result = (_DWORD *)ExReleaseResourceLite(result[468]);
  if ( a2 )
    result = (_DWORD *)ExReleaseResourceLite(a2[468]);
  if ( v2 )
    result = CmpDereferenceHive(v2);
  if ( a2 )
    result = CmpDereferenceHive(a2);
  return result;
}
