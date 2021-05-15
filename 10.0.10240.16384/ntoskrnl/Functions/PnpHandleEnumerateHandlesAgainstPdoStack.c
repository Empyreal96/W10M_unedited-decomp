// PnpHandleEnumerateHandlesAgainstPdoStack 
 
int __fastcall PnpHandleEnumerateHandlesAgainstPdoStack(int a1)
{
  int v1; // r5
  int v2; // r7
  int v3; // r0
  int v4; // r3
  int v5; // r6
  int v6; // r4
  int v7; // r4
  int v8; // r0
  int v9; // r4
  int v10; // r6

  v1 = a1;
  ObfReferenceObjectWithTag(a1);
  while ( 1 )
  {
    v2 = PnpHandleEnumerateHandlesAgainstDeviceObject(v1);
    if ( v2 )
      break;
    v3 = KeAcquireQueuedSpinLock(9);
    v4 = *(_DWORD *)(v1 + 36);
    v5 = 0;
    v6 = v3;
    if ( v4 )
    {
      v5 = *(_DWORD *)(v4 + 8);
      if ( v5 )
        ObfReferenceObjectWithTag(*(_DWORD *)(v4 + 8));
    }
    KeReleaseQueuedSpinLock(9, v6);
    if ( v5 )
    {
      v7 = IoGetDeviceAttachmentBaseRef(v5);
      v2 = PnpHandleEnumerateHandlesAgainstDeviceObject(v7);
      ObfDereferenceObjectWithTag(v7);
      ObfDereferenceObjectWithTag(v5);
      if ( v2 )
        break;
    }
    v8 = KeAcquireQueuedSpinLock(10);
    v9 = *(_DWORD *)(v1 + 16);
    v10 = v8;
    if ( v9 )
      ObfReferenceObjectWithTag(*(_DWORD *)(v1 + 16));
    KeReleaseQueuedSpinLock(10, v10);
    ObfDereferenceObjectWithTag(v1);
    v1 = v9;
    if ( !v9 )
      return v2;
  }
  ObfDereferenceObjectWithTag(v1);
  return v2;
}
