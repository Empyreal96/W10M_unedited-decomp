// CcGetFileObjectFromSectionPtrs 
 
unsigned int __fastcall CcGetFileObjectFromSectionPtrs(int a1)
{
  unsigned int v2; // r5
  int v3; // r0
  int v4; // r2

  v2 = 0;
  v3 = KeAcquireQueuedSpinLock(5);
  v4 = *(_DWORD *)(a1 + 4);
  if ( v4 )
  {
    v2 = *(_DWORD *)(v4 + 68) & 0xFFFFFFF8;
    *(_DWORD *)(v4 + 96) |= 0x100000u;
  }
  KeReleaseQueuedSpinLock(5, v3);
  return v2;
}
