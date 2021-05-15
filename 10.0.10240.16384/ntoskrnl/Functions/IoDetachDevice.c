// IoDetachDevice 
 
int __fastcall IoDetachDevice(_DWORD *a1)
{
  int v2; // r0
  int result; // r0
  int v4; // r3

  v2 = KeAcquireQueuedSpinLock(10);
  if ( (MmVerifierData & 0x10) != 0 )
    return sub_527BF0(v2);
  *(_DWORD *)(*(_DWORD *)(a1[4] + 176) + 24) = 0;
  v4 = a1[44];
  a1[4] = 0;
  if ( (*(_DWORD *)(v4 + 16) & 7) == 0 || a1[1] )
    result = KeReleaseQueuedSpinLock(10, v2);
  else
    result = IopCompleteUnloadOrDelete(a1, 0, v2);
  return result;
}
