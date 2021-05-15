// IopCheckUnloadDriver 
 
int __fastcall IopCheckUnloadDriver(int a1, _BYTE *a2)
{
  int v4; // r0
  _DWORD *v5; // r4
  int v6; // r2

  v4 = KeAcquireQueuedSpinLock(10);
  v5 = *(_DWORD **)(a1 + 4);
  if ( !v5 && (*(_DWORD *)(a1 + 8) & 1) != 0
    || (v6 = *(_DWORD *)(a1 + 8), (v6 & 0x80) == 0) && v5 && (*(_DWORD *)(v5[44] + 16) & 1) != 0 )
  {
    JUMPOUT(0x528306);
  }
  if ( (v6 & 0x10) == 0 )
    return sub_528304(v4, 1);
  *a2 = 1;
  while ( v5 )
  {
    *(_DWORD *)(v5[44] + 16) |= 1u;
    if ( v5[1] || v5[4] )
      *a2 = 0;
    v5 = (_DWORD *)v5[3];
  }
  if ( (*(_DWORD *)(a1 + 8) & 0x80) != 0 && *(_DWORD *)(a1 + 4) )
    *a2 = 0;
  if ( *a2 )
    *(_DWORD *)(a1 + 8) |= 1u;
  KeReleaseQueuedSpinLock(10, v4);
  return -1073741823;
}
