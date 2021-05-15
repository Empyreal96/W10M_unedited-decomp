// PiPnpRtlEndOperation 
 
int __fastcall PiPnpRtlEndOperation(int result)
{
  int v1; // r4
  int v2; // r3
  unsigned int v3; // r2
  int v4; // r2
  int v5; // r3
  int v6; // r0

  v1 = result;
  v2 = *(_DWORD *)(result + 76) - 1;
  *(_DWORD *)(result + 76) = v2;
  if ( !v2 )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v3 + 308);
    ExAcquireResourceSharedLite((int)&PiPnpRtlRemoveOperationDispatchLock, 1);
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v5 = *(__int16 *)(v4 + 0x134) - 1;
    *(_WORD *)(v4 + 308) = v5;
    v6 = ExAcquireResourceExclusiveLite((int)&PiPnpRtlActiveOperationsLock, 1, v4, v5);
    if ( *(_DWORD *)(*(_DWORD *)v1 + 4) != v1 )
      __fastfail(3u);
    result = sub_7C5F70(v6);
  }
  return result;
}
