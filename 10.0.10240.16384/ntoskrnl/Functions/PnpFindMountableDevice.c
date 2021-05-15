// PnpFindMountableDevice 
 
_DWORD *__fastcall PnpFindMountableDevice(_DWORD *a1)
{
  int v2; // r0

  v2 = KeAcquireQueuedSpinLock(10);
  while ( a1 && ((a1[7] & 0x40) == 0 || !a1[9]) )
    a1 = (_DWORD *)a1[4];
  KeReleaseQueuedSpinLock(10, v2);
  return a1;
}
