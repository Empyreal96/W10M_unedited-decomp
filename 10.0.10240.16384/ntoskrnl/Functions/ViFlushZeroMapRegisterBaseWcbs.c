// ViFlushZeroMapRegisterBaseWcbs 
 
__int64 __fastcall ViFlushZeroMapRegisterBaseWcbs(int a1)
{
  unsigned int *v2; // r4
  int v3; // r8
  unsigned int v4; // r2
  _DWORD *v5; // r2
  _DWORD *v6; // r5
  int v7; // r3
  __int64 v8; // r0
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = (unsigned int *)(a1 + 76);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v2);
  }
  else
  {
    do
      v4 = __ldrex(v2);
    while ( __strex(1u, v2) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire(v2);
  }
  v5 = *(_DWORD **)(a1 + 68);
  while ( v5 != (_DWORD *)(a1 + 68) )
  {
    v6 = v5 - 10;
    v7 = v5[2];
    v5 = (_DWORD *)*v5;
    if ( !v7 && !v6[13] && v6[7] == 3 )
    {
      v8 = *((_QWORD *)v6 + 5);
      if ( *(_DWORD **)(v8 + 4) != v6 + 10 || *(_DWORD **)HIDWORD(v8) != v6 + 10 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v8) = v8;
      *(_DWORD *)(v8 + 4) = HIDWORD(v8);
      SUBTRACT_MAP_REGISTERS(a1, v6[6]);
      ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, v6);
      break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v2, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v2 = 0;
  }
  return KfLowerIrql(v3);
}
