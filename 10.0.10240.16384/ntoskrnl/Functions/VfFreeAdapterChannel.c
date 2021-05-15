// VfFreeAdapterChannel 
 
int __fastcall VfFreeAdapterChannel(int a1)
{
  int (__fastcall *v2)(int); // r4
  int v3; // r6
  int result; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r1
  _DWORD *v7; // r4

  VF_ASSERT_IRQL(2);
  v2 = (int (__fastcall *)(int))ViGetRealDmaOperation(a1, 24);
  v3 = ViGetAdapterInformationInternal(a1, 1);
  result = v2(a1);
  if ( v3 )
  {
    __dmb(0xBu);
    v5 = (unsigned int *)(v3 + 116);
    do
      v6 = __ldrex(v5);
    while ( __strex(0, v5) );
    __dmb(0xBu);
    result = ViRemoveChannelWcb(v3, 0, 0);
    v7 = (_DWORD *)result;
    if ( result )
    {
      DECREMENT_ADAPTER_CHANNELS(v3);
      SUBTRACT_MAP_REGISTERS(v3, v7[6]);
      if ( v7[13] )
        ViFreeMapRegisterFile(v3);
      result = ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v7);
    }
  }
  return result;
}
