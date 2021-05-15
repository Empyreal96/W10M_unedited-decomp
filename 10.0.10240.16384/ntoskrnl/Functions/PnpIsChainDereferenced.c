// PnpIsChainDereferenced 
 
int __fastcall PnpIsChainDereferenced(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v8; // r5
  int v9; // r0
  int v10; // r4
  _DWORD *v11; // r7
  int v12; // r6
  int v14; // [sp+8h] [bp-28h]

  if ( a5 )
    *a5 = 0;
  v8 = 0;
  v9 = KeAcquireQueuedSpinLock(10);
  v10 = 0;
  v14 = v9;
  if ( a2 > 0 )
  {
    v11 = a1;
    v12 = v9;
    do
    {
      v8 = PnpIsAnyDeviceInUse(v11);
      v9 = PnpUpdateExtensionFlags(v11);
      if ( a3 )
      {
        if ( v8 )
          break;
      }
      else if ( !v8 )
      {
        KeReleaseQueuedSpinLock(10, v12);
        PnpChainDereferenceComplete(*v11, a4);
        v9 = KeAcquireQueuedSpinLock(10);
        v12 = v9;
      }
      ++v10;
      ++v11;
    }
    while ( v10 < a2 );
    v14 = v12;
  }
  if ( v8 && a3 )
    return sub_5201C4(v9);
  KeReleaseQueuedSpinLock(10, v14);
  if ( !a3 )
    v8 = 1;
  return v8;
}
