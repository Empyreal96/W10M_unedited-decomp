// IopStartNextPacket 
 
int __fastcall IopStartNextPacket(_DWORD *a1, int a2)
{
  int v3; // r4
  int result; // r0
  int v6; // r7

  v3 = 0;
  if ( a2 )
    v3 = KeAcquireQueuedSpinLock(7);
  a1[5] = 0;
  result = KeRemoveDeviceQueue(a1 + 24);
  if ( result )
  {
    v6 = result - 64;
    a1[5] = result - 64;
    if ( a2 )
    {
      if ( (*(_DWORD *)(a1[44] + 36) & 0x200) != 0 )
        *(_DWORD *)(result - 8) = 0;
      KeReleaseQueuedSpinLock(7, v3);
    }
    result = (*(int (__fastcall **)(_DWORD *, int))(a1[2] + 48))(a1, v6);
  }
  else if ( a2 )
  {
    result = KeReleaseQueuedSpinLock(7, v3);
  }
  return result;
}
