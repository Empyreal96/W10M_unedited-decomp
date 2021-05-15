// IopRetryDeviceRemovalForReset 
 
int __fastcall IopRetryDeviceRemovalForReset(unsigned int a1, int a2)
{
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  BOOL v6; // r6
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1
  int result; // r0

  v3 = *(_DWORD *)(a1 + 104);
  v4 = *(_DWORD *)(v3 + 96);
  PpDevNodeLockTree(0, a2);
  if ( v4 )
    v5 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
  else
    v5 = 0;
  if ( v5 )
    v6 = PipIsDevNodeEffectivelyRemoved(v5);
  else
    v6 = 1;
  PpDevNodeUnlockTree(0);
  __dmb(0xBu);
  v7 = (unsigned int *)(v3 + 32);
  do
  {
    v8 = __ldrex(v7);
    v9 = v8 - 1;
  }
  while ( __strex(v9, v7) );
  __dmb(0xBu);
  if ( !v9 )
    ExFreePoolWithTag(v3);
  *(_DWORD *)(a1 + 104) = 0;
  if ( v6 )
    result = -1073741823;
  else
    result = PnpSetTargetDeviceRemove(
               v4,
               0,
               1,
               0,
               1,
               54,
               0,
               (int)IopDeviceRemovalForResetComplete,
               a1,
               (_DWORD *)(a1 + 100),
               0,
               0,
               (_DWORD *)(a1 + 104));
  if ( result < 0 )
    result = ExFreePoolWithTag(a1);
  return result;
}
