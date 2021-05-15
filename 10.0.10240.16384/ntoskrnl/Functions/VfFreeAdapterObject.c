// VfFreeAdapterObject 
 
int __fastcall VfFreeAdapterObject(int a1, int a2)
{
  int (__fastcall *v4)(int, int); // r4
  int v5; // r6
  int result; // r0
  unsigned int *v7; // r5
  int v8; // r9
  unsigned int v9; // r2
  _DWORD *i; // r3
  _DWORD *v11; // r4
  __int64 v12; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = (int (__fastcall *)(int, int))ViGetRealDmaOperation(a1, 108);
  v5 = ViGetAdapterInformationInternal(a1, 1);
  result = v4(a1, a2);
  if ( v5 && (a2 == 2 || a2 == 3) )
  {
    v7 = (unsigned int *)(v5 + 76);
    v8 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v5 + 76);
    }
    else
    {
      do
        v9 = __ldrex(v7);
      while ( __strex(1u, v7) );
      __dmb(0xBu);
      if ( v9 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v5 + 76));
    }
    for ( i = *(_DWORD **)(v5 + 68); ; i = (_DWORD *)*i )
    {
      v11 = i - 10;
      if ( (_DWORD *)(v5 + 68) == i )
        break;
      if ( *(i - 3) == 1 )
      {
        DECREMENT_ADAPTER_CHANNELS(v5);
        if ( a2 == 3 )
        {
          v11[7] = 3;
        }
        else
        {
          v12 = *((_QWORD *)v11 + 5);
          if ( *(_DWORD **)(v12 + 4) != v11 + 10 || *(_DWORD **)HIDWORD(v12) != v11 + 10 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v12) = v12;
          *(_DWORD *)(v12 + 4) = HIDWORD(v12);
          SUBTRACT_MAP_REGISTERS(v5, v11[6]);
          if ( v11[13] )
            ViFreeMapRegisterFile(v5);
          ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v11);
        }
        break;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(v5 + 76), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    result = KfLowerIrql(v8);
  }
  return result;
}
