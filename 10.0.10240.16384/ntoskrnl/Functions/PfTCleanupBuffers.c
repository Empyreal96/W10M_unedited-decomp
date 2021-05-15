// PfTCleanupBuffers 
 
unsigned int __fastcall PfTCleanupBuffers(unsigned int result)
{
  unsigned int v1; // r5
  __int64 **v2; // r4
  __int64 *v3; // r0
  __int64 v4; // r2
  _DWORD *v5; // r4
  unsigned int v6; // r0

  v1 = result;
  v2 = (__int64 **)(result + 16);
  while ( *v2 != (__int64 *)v2 )
  {
    v3 = *v2;
    v4 = **v2;
    if ( (__int64 **)HIDWORD(v4) != v2 || *(__int64 **)(v4 + 4) != v3 )
      __fastfail(3u);
    *v2 = (__int64 *)v4;
    *(_DWORD *)(v4 + 4) = v2;
    result = ExFreePoolWithTag((unsigned int)v3);
  }
  v5 = *(_DWORD **)(v1 + 12);
  if ( v5 )
  {
    *(_DWORD *)(v1 + 12) = *v5;
    while ( v5 )
    {
      v6 = (unsigned int)v5;
      v5 = *(_DWORD **)(v1 + 12);
      if ( v5 )
        *(_DWORD *)(v1 + 12) = *v5;
      result = ExFreePoolWithTag(v6);
    }
  }
  *(_WORD *)(v1 + 10) = 0;
  return result;
}
