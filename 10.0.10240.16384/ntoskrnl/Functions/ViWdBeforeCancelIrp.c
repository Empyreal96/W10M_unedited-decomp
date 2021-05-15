// ViWdBeforeCancelIrp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ViWdBeforeCancelIrp(int result)
{
  int v1; // r4
  int v2; // r6
  int v3; // r3
  unsigned int v4; // r7
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  int v9; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  v1 = result;
  v2 = VfWdCancelTimeoutTicks;
  __dmb(0xBu);
  if ( v2 )
  {
    v3 = ViWdCancelIrpCount + 1;
    __dmb(0xBu);
    ViWdCancelIrpCount = v3;
    v4 = ViWdTickCount + v2;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = KiAcquireSpinLockInstrumented((int)&VfWdIrpListLock);
    }
    else
    {
      do
        v5 = __ldrex((unsigned int *)&VfWdIrpListLock);
      while ( __strex(1u, (unsigned int *)&VfWdIrpListLock) );
      __dmb(0xBu);
      if ( v5 )
        result = KxWaitForSpinLockAndAcquire((unsigned int *)&VfWdIrpListLock);
    }
    v6 = *(unsigned __int8 *)(v1 + 16);
    __dmb(0xBu);
    if ( v6 )
    {
      if ( *(_DWORD *)(v1 + 12) <= v4 )
        goto LABEL_13;
      *(_QWORD *)&v7 = *(_QWORD *)v1;
      if ( *(_DWORD *)(*(_DWORD *)v1 + 4) != v1 || *v8 != v1 )
        __fastfail(3u);
      *v8 = v7;
      *(_DWORD *)(v7 + 4) = v8;
      v9 = ViWdIrpListLength - 1;
      __dmb(0xBu);
      ViWdIrpListLength = v9;
    }
    *(_DWORD *)(v1 + 12) = v4;
    *(_WORD *)(v1 + 18) = v2;
    result = ViWdInsertSortIrp(v1);
LABEL_13:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = KiReleaseSpinLockInstrumented(&VfWdIrpListLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      VfWdIrpListLock = 0;
    }
  }
  return result;
}
