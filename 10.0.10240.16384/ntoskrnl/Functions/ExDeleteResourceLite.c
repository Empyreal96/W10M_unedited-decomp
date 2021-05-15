// ExDeleteResourceLite 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExDeleteResourceLite(_DWORD *a1)
{
  unsigned int v2; // r3
  int v3; // r8
  unsigned int v5; // r1
  int v6; // r6
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  unsigned int v9; // r5
  int v10; // r0
  int v11; // r0
  unsigned int v12; // r1

  v2 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v2 & 0xFFFFF000) + 0x1420);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54A3AC();
  do
    v5 = __ldrex((unsigned __int8 *)&ExpResourceSpinLock + 3);
  while ( __strex(v5 | 0x80, (unsigned __int8 *)&ExpResourceSpinLock + 3) );
  __dmb(0xBu);
  if ( v5 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&ExpResourceSpinLock);
  while ( 1 )
  {
    v6 = ExpResourceSpinLock;
    if ( (ExpResourceSpinLock & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (ExpResourceSpinLock & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex((unsigned int *)&ExpResourceSpinLock);
      while ( v12 == v6 && __strex(v6 | 0x40000000, (unsigned int *)&ExpResourceSpinLock) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  *(_QWORD *)&v7 = *(_QWORD *)a1;
  if ( *(_DWORD **)(*a1 + 4) != a1 || (_DWORD *)*v8 != a1 )
    __fastfail(3u);
  *v8 = v7;
  *(_DWORD *)(v7 + 4) = v8;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ExpResourceSpinLock);
  }
  else
  {
    __dmb(0xBu);
    ExpResourceSpinLock = 0;
  }
  KfLowerIrql(v3);
  *a1 = 0;
  a1[1] = 0;
  if ( (a1[7] & 2) != 0 )
  {
    v9 = a1[6] & 0xFFFFFFFC;
LABEL_13:
    if ( v9 )
    {
      if ( (a1[7] & 1) != 0 )
        PsBoostThreadIoEx(v9, 1, 0);
      if ( (a1[7] & 2) != 0 )
        ObDereferenceObjectDeferDeleteWithTag(v9);
    }
    goto LABEL_14;
  }
  v9 = a1[6];
  if ( (v9 & 3) == 0 )
    goto LABEL_13;
LABEL_14:
  v10 = a1[2];
  if ( v10 )
    ExFreePoolWithTag(v10, 0);
  v11 = a1[5];
  if ( v11 )
    ExFreePoolWithTag(v11, 0);
  return 0;
}
