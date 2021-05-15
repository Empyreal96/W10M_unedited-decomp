// VfAllocateAdapterChannel 
 
int __fastcall VfAllocateAdapterChannel(int a1, int a2, unsigned int a3, int (*a4)(), int a5)
{
  _BYTE *v9; // r5
  int v10; // r4
  _BYTE *v11; // r0
  int v12; // r7
  int v14; // r0
  unsigned int *v15; // r6
  int v16; // r10
  unsigned int v17; // r2
  __int64 v18; // r0
  int (__fastcall *v19)(int, int, unsigned int, int (*)()); // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  v9 = 0;
  v19 = (int (__fastcall *)(int, int, unsigned int, int (*)()))ViGetRealDmaOperation(a1, 16);
  v10 = ViGetAdapterInformationInternal(a1, 1);
  if ( v10 )
  {
    VF_ASSERT_IRQL(2);
    v11 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&ViHalWaitBlockLookaside);
    v9 = v11;
    if ( !v11 )
      return -1073741670;
    memset(v11, 0, 84);
    *(_DWORD *)v9 = a5;
    *((_DWORD *)v9 + 1) = a4;
    *((_DWORD *)v9 + 8) = v10;
    *((_DWORD *)v9 + 6) = a3;
    if ( ViDoubleBufferDma && !*(_BYTE *)(v10 + 17) && *(_DWORD *)(v10 + 120) < 3u )
      *((_DWORD *)v9 + 13) = ViAllocateMapRegisterFile(v10, a3);
    if ( !*(_DWORD *)(v10 + 12) )
      *(_DWORD *)(v10 + 12) = a2;
    a4 = ViAdapterCallback;
    INCREMENT_ADAPTER_CHANNELS(v10);
    ADD_MAP_REGISTERS(v10, a3, 0);
    ExInterlockedInsertTailList((__int64 *)(v10 + 68), (__int64 *)v9 + 5, (unsigned int *)(v10 + 76));
  }
  v14 = v19(a1, a2, a3, a4);
  v12 = v14;
  if ( v10 && v14 && ViIsActiveChannelWcb(v10, v9) )
  {
    v15 = (unsigned int *)(v10 + 76);
    v16 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v10 + 76);
    }
    else
    {
      do
        v17 = __ldrex(v15);
      while ( __strex(1u, v15) );
      __dmb(0xBu);
      if ( v17 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v10 + 76));
    }
    v18 = *((_QWORD *)v9 + 5);
    if ( *(_BYTE **)(v18 + 4) != v9 + 40 || *(_BYTE **)HIDWORD(v18) != v9 + 40 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v18) = v18;
    *(_DWORD *)(v18 + 4) = HIDWORD(v18);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(v10 + 76), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v15 = 0;
    }
    KfLowerIrql(v16);
    DECREMENT_ADAPTER_CHANNELS(v10);
    SUBTRACT_MAP_REGISTERS(v10, a3);
    if ( *((_DWORD *)v9 + 13) )
      ViFreeMapRegisterFile(v10);
    ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v9);
  }
  return v12;
}
