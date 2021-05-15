// IoGetDiskDeviceObject 
 
int __fastcall IoGetDiskDeviceObject(int a1, int *a2)
{
  int v4; // r4
  int v5; // r6
  int v6; // r2
  int v7; // r0

  if ( *(_DWORD *)(a1 + 36) )
    return -1073741811;
  v5 = KeAcquireQueuedSpinLock(9);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 40);
  if ( v6 )
  {
    if ( *(_DWORD *)(v6 + 20) && (*(_WORD *)(v6 + 4) & 1) != 0 )
    {
      v7 = *(_DWORD *)(v6 + 12);
      *a2 = v7;
      ObfReferenceObjectWithTag(v7);
      v4 = 0;
    }
    else
    {
      v4 = -1073741202;
    }
  }
  else
  {
    v4 = -1073741811;
  }
  KeReleaseQueuedSpinLock(9, v5);
  return v4;
}
