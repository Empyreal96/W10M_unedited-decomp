// CcAllocateInitializeVacbArray 
 
int CcAllocateInitializeVacbArray()
{
  int v0; // r0
  _BYTE *v2; // r0
  _BYTE *v3; // r4
  _BYTE *v4; // r3
  int v5; // r2
  int v6; // r0

  v0 = KeAcquireQueuedSpinLock(4);
  if ( CcVacbArraysAllocated )
    return sub_50B3F0(v0, v0);
  ++CcVacbArraysAllocated;
  KeReleaseQueuedSpinLock(4, v0);
  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 0x20000, 1633051459);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, 0x20000);
    v4 = v3 + 16;
    v5 = 5460;
    do
    {
      *((_DWORD *)v4 + 4) = v3;
      v4 += 24;
      --v5;
    }
    while ( v5 );
  }
  else
  {
    v6 = KeAcquireQueuedSpinLock(4);
    --CcVacbArraysAllocated;
    KeReleaseQueuedSpinLock(4, v6);
  }
  return (int)v3;
}
