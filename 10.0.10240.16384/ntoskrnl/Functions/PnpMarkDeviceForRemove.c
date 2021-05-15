// PnpMarkDeviceForRemove 
 
int __fastcall PnpMarkDeviceForRemove(int a1, int a2, int *a3)
{
  int v5; // r5
  int v6; // r0
  int v7; // r6
  int v8; // r8
  __int16 v9; // r3
  int v10; // r0
  int v11; // r0

  v5 = a1;
  if ( a2 )
  {
    *a3 = 0;
    a3[1] = 0;
    *a3 = a1;
  }
  while ( v5 )
  {
    if ( *(_DWORD *)(v5 + 36) )
    {
      v6 = KeAcquireQueuedSpinLock(9);
      v7 = *(_DWORD *)(v5 + 36);
      v8 = v6;
      if ( a2 )
      {
        v9 = *(_WORD *)(v7 + 4) | 8;
        *(_WORD *)(v7 + 4) = v9;
        if ( (v9 & 1) != 0 )
        {
          v10 = *(_DWORD *)(v7 + 8);
          *a3 = v5;
          a3[1] = v10;
          ObfReferenceObjectWithTag(v10);
          IopIncrementDeviceObjectRefCount(a3[1], 1);
        }
      }
      else
      {
        *(_WORD *)(v7 + 4) &= 0xFFF7u;
      }
      KeReleaseQueuedSpinLock(9, v8);
    }
    if ( a2 && a3[1] )
      return a3[1];
    v11 = KeAcquireQueuedSpinLock(10);
    v5 = *(_DWORD *)(v5 + 16);
    KeReleaseQueuedSpinLock(10, v11);
  }
  if ( a3[1] )
    return a3[1];
  return *a3;
}
