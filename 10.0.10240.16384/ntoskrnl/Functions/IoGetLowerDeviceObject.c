// IoGetLowerDeviceObject 
 
int __fastcall IoGetLowerDeviceObject(int a1)
{
  int v2; // r0
  int v3; // r2
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v2 = KeAcquireQueuedSpinLock(10);
  v3 = *(_DWORD *)(a1 + 176);
  v4 = v2;
  if ( (*(_DWORD *)(v3 + 16) & 0xF) != 0 )
    return sub_553750();
  v6 = *(_DWORD *)(v3 + 24);
  v7 = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v3 + 24);
    ObfReferenceObjectWithTag(v6);
  }
  KeReleaseQueuedSpinLock(10, v4);
  return v7;
}
