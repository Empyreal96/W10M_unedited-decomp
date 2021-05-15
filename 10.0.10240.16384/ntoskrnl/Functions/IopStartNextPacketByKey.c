// IopStartNextPacketByKey 
 
int __fastcall IopStartNextPacketByKey(_DWORD *a1, int a2, int a3)
{
  int v4; // r6
  int result; // r0
  int v8; // r5

  v4 = 0;
  if ( a2 )
    v4 = KeAcquireQueuedSpinLock(7);
  a1[5] = 0;
  result = KeRemoveByKeyDeviceQueue(a1 + 24, a3);
  if ( result )
  {
    v8 = result - 64;
    a1[5] = result - 64;
    if ( a2 )
    {
      if ( (*(_DWORD *)(a1[44] + 36) & 0x200) != 0 )
        *(_DWORD *)(result - 8) = 0;
      KeReleaseQueuedSpinLock(7, v4);
    }
    result = (*(int (__fastcall **)(_DWORD *, int))(a1[2] + 48))(a1, v8);
  }
  else if ( a2 )
  {
    result = KeReleaseQueuedSpinLock(7, v4);
  }
  return result;
}
