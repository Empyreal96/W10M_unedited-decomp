// ViAdapterCallback 
 
int __fastcall ViAdapterCallback(int a1, int a2, int a3, __int64 *a4)
{
  int v5; // r5
  int v6; // r7
  _DWORD *v9; // r3
  __int64 v10; // r3
  int v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  _DWORD *v15; // r1
  unsigned int *v16; // r5
  int v17; // r8
  unsigned int v18; // r2
  __int64 v19; // r0
  int vars4; // [sp+24h] [bp+4h]

  v5 = *((_DWORD *)a4 + 8);
  v6 = a3;
  if ( v5 )
  {
    if ( *(_DWORD *)(v5 + 120) < 3u )
    {
      v9 = (_DWORD *)*((_DWORD *)a4 + 13);
      if ( v9 && *v9 == -1393569779 )
      {
        v9[7] = a3;
        v6 = *((_DWORD *)a4 + 13);
      }
      else if ( !a3 )
      {
        v6 = -559026163;
      }
    }
    if ( *(_BYTE *)(v5 + 124) )
      DECREMENT_ADAPTER_CHANNELS(v5);
  }
  v10 = *a4;
  *((_DWORD *)a4 + 12) = v6;
  v11 = ((int (__fastcall *)(int, int, int, _DWORD))HIDWORD(v10))(a1, a2, v6, v10);
  if ( v5 && ViIsActiveChannelWcb(v5, a4) )
  {
    *((_DWORD *)a4 + 7) = v11;
    if ( v11 == 1 )
    {
      if ( *(_BYTE *)(v5 + 124) )
      {
        __dmb(0xBu);
        v12 = (unsigned int *)(v5 + 112);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 - 1, v12) );
        __dmb(0xBu);
        VfUtilDbgPrint((int)"Driver at address %p has a problem\n");
        VfUtilDbgPrint((int)"Master devices should return DeallocateObjectKeepRegisters\n");
      }
      v11 = 1;
      *(_DWORD *)(v5 + 184) = *((_DWORD *)a4 + 6);
    }
    else
    {
      if ( !*(_BYTE *)(v5 + 124) )
        DECREMENT_ADAPTER_CHANNELS(v5);
      if ( v11 == 3 )
      {
        v11 = 3;
      }
      else
      {
        SUBTRACT_MAP_REGISTERS(v5, *((_DWORD *)a4 + 6));
        v15 = (_DWORD *)*((_DWORD *)a4 + 13);
        if ( v15 && *v15 == -1393569779 )
        {
          ViFreeMapRegisterFile(v5);
          *((_DWORD *)a4 + 13) = 0;
        }
        v16 = (unsigned int *)(v5 + 76);
        v17 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)v16);
        }
        else
        {
          do
            v18 = __ldrex(v16);
          while ( __strex(1u, v16) );
          __dmb(0xBu);
          if ( v18 )
            KxWaitForSpinLockAndAcquire(v16);
        }
        v19 = a4[5];
        if ( *(__int64 **)(v19 + 4) != a4 + 5 || *(__int64 **)HIDWORD(v19) != a4 + 5 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v19) = v19;
        *(_DWORD *)(v19 + 4) = HIDWORD(v19);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v16, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v16 = 0;
        }
        KfLowerIrql(v17);
        ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, a4);
      }
    }
  }
  return v11;
}
