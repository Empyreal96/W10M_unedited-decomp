// VfCancelAdapterChannel 
 
int __fastcall VfCancelAdapterChannel(int a1, int a2, int a3)
{
  int (__fastcall *v6)(int, int, int); // r4
  int v7; // r7
  int v8; // r0
  int v9; // r4
  _DWORD *v10; // r5

  v6 = (int (__fastcall *)(int, int, int))ViGetRealDmaOperation(a1, 88);
  v7 = ViGetAdapterInformationInternal(a1, 1);
  v8 = v6(a1, a2, a3);
  v9 = v8;
  if ( v7 )
  {
    if ( v8 )
    {
      v10 = (_DWORD *)ViRemoveChannelWcb(v7, 0, a3);
      if ( v10 )
      {
        DECREMENT_ADAPTER_CHANNELS(v7);
        SUBTRACT_MAP_REGISTERS(v7, v10[6]);
        if ( v10[13] )
          ViFreeMapRegisterFile(v7);
        ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v10);
      }
    }
  }
  return v9;
}
