// IoStartPacket 
 
int __fastcall IoStartPacket(_DWORD *a1, int a2, _DWORD *a3, void (__fastcall *a4)(_DWORD *, int))
{
  int v8; // r8
  int v9; // r4
  int v10; // r1
  _DWORD *v11; // r0
  int v12; // r0

  v8 = 0;
  v9 = KfRaiseIrql(2);
  if ( a4 )
  {
    v8 = KeAcquireQueuedSpinLock(7);
    *(_DWORD *)(a2 + 56) = a4;
  }
  v10 = a2 + 64;
  v11 = a1 + 24;
  if ( a3 )
    v12 = KeInsertByKeyDeviceQueue(v11, v10, *a3);
  else
    v12 = KeInsertDeviceQueue(v11, v10);
  if ( v12 )
  {
    if ( a4 )
    {
      if ( *(_BYTE *)(a2 + 36) )
      {
        *(_DWORD *)(a2 + 56) = 0;
        *(_BYTE *)(a2 + 37) = v8;
        a4(a1, a2);
      }
      else
      {
        KeReleaseQueuedSpinLock(7, v8);
      }
    }
  }
  else
  {
    a1[5] = a2;
    if ( a4 )
    {
      if ( (*(_DWORD *)(a1[44] + 36) & 0x200) != 0 )
        *(_DWORD *)(a2 + 56) = 0;
      KeReleaseQueuedSpinLock(7, v8);
    }
    (*(void (__fastcall **)(_DWORD *, int))(a1[2] + 48))(a1, a2);
  }
  return KfLowerIrql(v9);
}
