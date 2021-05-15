// VfAllocateAdapterChannelEx 
 
int __fastcall VfAllocateAdapterChannelEx(int a1, int a2, int a3, int a4, int a5, int (*a6)(), _BYTE *a7, _DWORD *a8)
{
  unsigned int v8; // r4
  _BYTE *v11; // r5
  int v12; // r6
  _BYTE *v13; // r0
  int v14; // r8
  _BYTE *v16; // r8
  int (*v17)(); // r7
  int (__fastcall *v18)(int, int, int, int, int, int (*)(), _BYTE *, _DWORD *); // r0
  unsigned int *v19; // r4
  int v20; // r9
  unsigned int v21; // r2
  __int64 v22; // r0
  int v25; // [sp+18h] [bp-20h]
  int vars4; // [sp+3Ch] [bp+4h]

  v8 = a4;
  v25 = a3;
  v11 = 0;
  v12 = ViGetAdapterInformationInternal(a1, 1);
  if ( v12 )
  {
    VF_ASSERT_IRQL(2);
    v13 = (_BYTE *)ExAllocateFromNPagedLookasideList((int)&ViHalWaitBlockLookaside);
    v11 = v13;
    if ( !v13 )
      return -1073741670;
    memset(v13, 0, 84);
    v16 = a7;
    v17 = a6;
    *((_DWORD *)v11 + 8) = v12;
    *(_DWORD *)v11 = a7;
    *((_DWORD *)v11 + 1) = a6;
    *((_DWORD *)v11 + 5) = a3;
    *((_DWORD *)v11 + 6) = v8;
    if ( !*(_DWORD *)(v12 + 12) )
      *(_DWORD *)(v12 + 12) = a2;
    if ( a6 )
    {
      v17 = ViAdapterCallback;
      v16 = v11;
    }
    INCREMENT_ADAPTER_CHANNELS(v12);
    ADD_MAP_REGISTERS(v12, v8, 1);
    ExInterlockedInsertTailList((__int64 *)(v12 + 68), (__int64 *)v11 + 5, (unsigned int *)(v12 + 76));
  }
  else
  {
    v16 = a7;
    v17 = a6;
  }
  v18 = (int (__fastcall *)(int, int, int, int, int, int (*)(), _BYTE *, _DWORD *))ViGetRealDmaOperation(a1, 80);
  v14 = v18(a1, a2, v25, a4, a5, v17, v16, a8);
  if ( v12 && ViIsActiveChannelWcb(v12, v11) )
  {
    if ( v14 )
    {
      v19 = (unsigned int *)(v12 + 76);
      v20 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v12 + 76);
      }
      else
      {
        do
          v21 = __ldrex(v19);
        while ( __strex(1u, v19) );
        __dmb(0xBu);
        if ( v21 )
          KxWaitForSpinLockAndAcquire((unsigned int *)(v12 + 76));
      }
      v22 = *((_QWORD *)v11 + 5);
      if ( *(_BYTE **)(v22 + 4) != v11 + 40 || *(_BYTE **)HIDWORD(v22) != v11 + 40 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v22) = v22;
      *(_DWORD *)(v22 + 4) = HIDWORD(v22);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)(v12 + 76), vars4);
      }
      else
      {
        __dmb(0xBu);
        *v19 = 0;
      }
      KfLowerIrql(v20);
      DECREMENT_ADAPTER_CHANNELS(v12);
      SUBTRACT_MAP_REGISTERS(v12, a4);
      ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v11);
    }
    else if ( !v17 )
    {
      *((_DWORD *)v11 + 7) = 1;
      *((_DWORD *)v11 + 12) = *a8;
    }
  }
  return v14;
}
