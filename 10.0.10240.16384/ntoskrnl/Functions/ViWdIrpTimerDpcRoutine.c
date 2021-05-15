// ViWdIrpTimerDpcRoutine 
 
// local variable allocation has failed, the output may be wrong!
void __spoils<R2,R3,R12> ViWdIrpTimerDpcRoutine()
{
  int v0; // r3
  BOOL v1; // r5
  unsigned int v2; // r2
  int v3; // r3
  _BYTE *v4; // r5
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  int v7; // r3
  int v8; // r3
  int vars4; // [sp+24h] [bp+4h]

  v0 = ViWdIrpListLength;
  __dmb(0xBu);
  if ( v0 )
  {
    v1 = ViWdTickCount + 1 < (unsigned int)ViWdTickCount;
    ++ViWdTickCount;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfWdIrpListLock);
    }
    else
    {
      do
        v2 = __ldrex((unsigned int *)&VfWdIrpListLock);
      while ( __strex(1u, (unsigned int *)&VfWdIrpListLock) );
      __dmb(0xBu);
      if ( v2 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfWdIrpListLock);
    }
    if ( v1 )
    {
      ViWdFlushIrpList();
    }
    else
    {
      v3 = ViWdIrpListLength;
      __dmb(0xBu);
      if ( v3 )
      {
        v4 = (_BYTE *)VfWdIrpListHead;
        if ( *(_DWORD *)(VfWdIrpListHead + 12) < (unsigned int)ViWdTickCount )
        {
          ViWdIrpTimedOut(VfWdIrpListHead);
          *(_QWORD *)&v5 = *(_QWORD *)v4;
          if ( *(_BYTE **)(*(_DWORD *)v4 + 4) != v4 || (_BYTE *)*v6 != v4 )
            __fastfail(3u);
          *v6 = v5;
          *(_DWORD *)(v5 + 4) = v6;
          __dmb(0xBu);
          v4[16] = 0;
          v7 = ViWdIrpListLength - 1;
          __dmb(0xBu);
          ViWdIrpListLength = v7;
        }
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&VfWdIrpListLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      VfWdIrpListLock = 0;
    }
  }
  v8 = ViWdCancelling;
  __dmb(0xBu);
  if ( !v8 )
    KiSetTimerEx((int)ViWdIrpTimer, (unsigned int)&ViWdIrpTimerDpc, -10000000i64, 0, 0, (int)&ViWdIrpTimerDpc);
}
