// IopCheckStackForTransactionSupport 
 
int __fastcall IopCheckStackForTransactionSupport(int a1)
{
  int v1; // r4
  int v2; // r0
  int v3; // r3

  v1 = a1;
  if ( (*(_DWORD *)(a1 + 28) & 0x40000) == 0 )
  {
    v2 = KeAcquireQueuedSpinLock(10);
    do
    {
      if ( (*(_DWORD *)(v1 + 28) & 0x40000) != 0 )
        break;
      v3 = *(_DWORD *)(v1 + 176);
      v1 = v3 ? *(_DWORD *)(v3 + 24) : 0;
    }
    while ( v1 );
    KeReleaseQueuedSpinLock(10, v2);
  }
  return v1;
}
