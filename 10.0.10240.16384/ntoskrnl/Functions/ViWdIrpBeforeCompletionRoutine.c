// ViWdIrpBeforeCompletionRoutine 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ViWdIrpBeforeCompletionRoutine(int result)
{
  _DWORD *v1; // r7
  unsigned __int8 *v2; // r5
  unsigned int v3; // r2
  int v4; // r3
  int v5; // r1 OVERLAPPED
  unsigned __int8 **v6; // r2 OVERLAPPED
  int v7; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  v1 = (_DWORD *)result;
  v2 = *(unsigned __int8 **)result;
  if ( *(char *)(*(_DWORD *)(*(_DWORD *)result + 8) + 35) >= *(char *)(*(_DWORD *)result + 17) )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&VfWdIrpListLock);
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)&VfWdIrpListLock);
      while ( __strex(1u, (unsigned int *)&VfWdIrpListLock) );
      __dmb(0xBu);
      if ( v3 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&VfWdIrpListLock);
    }
    v4 = v2[16];
    __dmb(0xBu);
    if ( v4 )
    {
      *(_QWORD *)&v5 = *(_QWORD *)v2;
      if ( *(unsigned __int8 **)(*(_DWORD *)v2 + 4) != v2 || *v6 != v2 )
        __fastfail(3u);
      *v6 = (unsigned __int8 *)v5;
      *(_DWORD *)(v5 + 4) = v6;
      __dmb(0xBu);
      v2[16] = 0;
      v7 = ViWdIrpListLength - 1;
      __dmb(0xBu);
      ViWdIrpListLength = v7;
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
    result = ExFreeToNPagedLookasideList((int)&ViWdIrpLookasideList, v2);
    *v1 = 0;
  }
  return result;
}
