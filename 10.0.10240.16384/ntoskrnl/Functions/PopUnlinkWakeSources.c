// PopUnlinkWakeSources 
 
unsigned int __fastcall PopUnlinkWakeSources(unsigned int result)
{
  unsigned int v1; // r5
  __int64 **v2; // r4
  __int64 *v3; // r0
  __int64 v4; // r2

  v1 = result;
  v2 = (__int64 **)(result + 12);
  while ( *v2 != (__int64 *)v2 )
  {
    v3 = *v2;
    v4 = **v2;
    if ( (__int64 **)HIDWORD(v4) != v2 || *(__int64 **)(v4 + 4) != v3 )
      __fastfail(3u);
    *v2 = (__int64 *)v4;
    *(_DWORD *)(v4 + 4) = v2;
    result = PopFreeWakeSource(v3);
    --*(_DWORD *)(v1 + 20);
  }
  return result;
}
