// PromoteNode 
 
__int64 **__fastcall PromoteNode(__int64 **result)
{
  __int64 *v1; // r2
  __int64 v2; // kr00_8
  __int64 *v3; // r3
  __int64 *v4; // r3

  v1 = *result;
  v2 = **result;
  if ( (__int64 **)HIDWORD(v2) == result )
  {
    v4 = result[2];
    *((_DWORD *)v1 + 1) = v4;
    if ( v4 )
      *(_DWORD *)v4 = v1;
    result[2] = v1;
  }
  else
  {
    v3 = result[1];
    *((_DWORD *)v1 + 2) = v3;
    if ( v3 )
      *(_DWORD *)v3 = v1;
    result[1] = v1;
  }
  *(_DWORD *)v1 = result;
  if ( *(__int64 **)(v2 + 4) == v1 )
    *(_DWORD *)(v2 + 4) = result;
  else
    *(_DWORD *)(v2 + 8) = result;
  *result = (__int64 *)v2;
  return result;
}
