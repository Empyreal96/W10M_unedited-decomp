// PspApplyWorkingSetLimits 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PspApplyWorkingSetLimits(int a1)
{
  int *v2; // r5
  __int64 v3; // r2
  int **v4; // r1
  unsigned int *v5; // r2
  unsigned int v6; // r0
  unsigned int v7; // r0
  unsigned int result; // r0
  unsigned int v9; // r4
  int *v10; // r1 OVERLAPPED
  int *v11; // [sp+0h] [bp-30h] BYREF
  int **v12; // [sp+4h] [bp-2Ch]
  char v13[40]; // [sp+8h] [bp-28h] BYREF

  v12 = &v11;
  v11 = (int *)&v11;
  while ( 1 )
  {
    v2 = (int *)PspWorkingSetChangeHead;
    if ( PspWorkingSetChangeHead == &PspWorkingSetChangeHead )
      break;
    v3 = *(_QWORD *)PspWorkingSetChangeHead;
    if ( *((void ***)PspWorkingSetChangeHead + 1) != &PspWorkingSetChangeHead
      || *(void **)(v3 + 4) != PspWorkingSetChangeHead )
    {
      __fastfail(3u);
    }
    PspWorkingSetChangeHead = *(void **)PspWorkingSetChangeHead;
    *(_DWORD *)(v3 + 4) = &PspWorkingSetChangeHead;
    v4 = v12;
    *v2 = (int)&v11;
    v2[1] = (int)v4;
    if ( *v4 != (int *)&v11 )
      __fastfail(3u);
    *v4 = v2;
    v12 = (int **)v2;
    KiStackAttachProcess(v2[2], 0, (int)v13);
    MmAdjustWorkingSetSize(v2[3], v2[4], 0, 1);
    MmEnforceWorkingSetLimit(v2[2], 1);
    KiUnstackDetachProcess((unsigned int)v13, 0);
  }
  __dmb(0xBu);
  v5 = (unsigned int *)(a1 + 744);
  do
    v6 = __ldrex(v5);
  while ( __strex(v6 & 0xFFFFFEFF, v5) );
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&dword_618E28);
  while ( __strex(v7 - 1, (unsigned int *)&dword_618E28) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_618E28);
  for ( result = KeAbPostRelease((unsigned int)&dword_618E28); ; result = ExFreePoolWithTag(v9) )
  {
    v9 = (unsigned int)v11;
    if ( v11 == (int *)&v11 )
      break;
    *(_QWORD *)&v10 = *(_QWORD *)v11;
    if ( (int **)v11[1] != &v11 || (int *)v10[1] != v11 )
      __fastfail(3u);
    v11 = v10;
    v10[1] = (int)&v11;
    ObfDereferenceObjectWithTag(*(_DWORD *)(v9 + 8));
  }
  return result;
}
