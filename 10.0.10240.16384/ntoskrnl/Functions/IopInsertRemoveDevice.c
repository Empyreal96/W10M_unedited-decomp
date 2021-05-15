// IopInsertRemoveDevice 
 
int __fastcall IopInsertRemoveDevice(int a1, int a2, int a3)
{
  int v6; // r0
  _DWORD *i; // r2

  v6 = KeAcquireQueuedSpinLock(10);
  if ( a3 )
  {
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(a1 + 4) = a2;
  }
  else
  {
    for ( i = (_DWORD *)(*(_DWORD *)(a2 + 8) + 4); *i != a2; i = (_DWORD *)(*i + 12) )
      ;
    *i = *(_DWORD *)(a2 + 12);
  }
  return KeReleaseQueuedSpinLock(10, v6);
}
