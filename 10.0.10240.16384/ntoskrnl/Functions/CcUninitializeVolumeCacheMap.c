// CcUninitializeVolumeCacheMap 
 
int __fastcall CcUninitializeVolumeCacheMap(int a1)
{
  int v2; // r6
  int v3; // r0
  int v4; // r3
  int v5; // r3
  int result; // r0
  __int64 v7; // kr00_8

  v2 = 0;
  v3 = KeAcquireQueuedSpinLock(5);
  v4 = *(_DWORD *)(a1 + 4);
  if ( !v4 )
    KeBugCheckEx(52, 1369, -1073740768);
  v5 = v4 - 1;
  *(_DWORD *)(a1 + 4) = v5;
  if ( !v5 )
  {
    v7 = *(_QWORD *)(a1 + 12);
    v2 = 1;
    if ( *(_DWORD *)(v7 + 4) != a1 + 12 || *(_DWORD *)HIDWORD(v7) != a1 + 12 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v7) = v7;
    *(_DWORD *)(v7 + 4) = HIDWORD(v7);
    if ( *(_DWORD *)(a1 + 104) )
      return sub_53E6C4();
  }
  result = KeReleaseQueuedSpinLock(5, v3);
  if ( v2 )
    result = ExFreePoolWithTag(a1, 1834378051);
  return result;
}
