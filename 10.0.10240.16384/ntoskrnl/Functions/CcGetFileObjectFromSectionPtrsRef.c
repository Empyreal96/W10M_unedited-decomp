// CcGetFileObjectFromSectionPtrsRef 
 
int __fastcall CcGetFileObjectFromSectionPtrsRef(int a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r3
  int v5; // r6

  v2 = 0;
  v3 = KeAcquireQueuedSpinLock(5);
  v4 = *(_DWORD *)(a1 + 4);
  v5 = v3;
  if ( v4 )
  {
    v2 = *(_DWORD *)(v4 + 68) & 0xFFFFFFF8;
    ObfReferenceObjectWithTag(v2);
  }
  KeReleaseQueuedSpinLock(5, v5);
  return v2;
}
