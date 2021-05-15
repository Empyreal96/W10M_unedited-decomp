// IopEliminateBogusConflict 
 
int __fastcall IopEliminateBogusConflict(int a1, int a2)
{
  int v4; // r0
  int v5; // r3
  int v6; // r0
  int v7; // r3
  int v8; // r1

  if ( !a1 || !a2 )
    return 0;
  v4 = KeAcquireQueuedSpinLock(10);
  v5 = a1;
  do
  {
    if ( v5 == a2 )
    {
      KeReleaseQueuedSpinLock(10, v4);
      return 1;
    }
    v5 = *(_DWORD *)(v5 + 16);
  }
  while ( v5 );
  KeReleaseQueuedSpinLock(10, v4);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( (*(_DWORD *)(v6 + 268) & 0x1000) != 0 && (*(_DWORD *)(a2 + 28) & 0x1000) == 0 )
  {
    v7 = *(_DWORD *)(a2 + 8);
    if ( v7 )
    {
      if ( *(_WORD *)(v6 + 28) )
      {
        v8 = *(_DWORD *)(v7 + 24);
        if ( *(unsigned __int16 *)(v6 + 28) == *(unsigned __int16 *)(v8 + 12)
          && !RtlCompareUnicodeString(v6 + 28, v8 + 12, 1) )
        {
          return 1;
        }
      }
    }
  }
  return 0;
}
