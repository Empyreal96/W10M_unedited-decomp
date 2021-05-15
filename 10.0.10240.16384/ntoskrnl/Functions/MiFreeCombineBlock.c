// MiFreeCombineBlock 
 
int __fastcall MiFreeCombineBlock(int a1, int a2, int a3, int a4)
{
  __int64 v5; // r2
  int v6; // r1
  int result; // r0
  int v8; // r9
  unsigned int *v9; // r5
  int v10; // r8
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r1
  _DWORD _0[11]; // [sp+0h] [bp-28h] BYREF

  _0[0] = a2;
  _0[1] = a3;
  _0[2] = a4;
  v5 = *(_QWORD *)(a1 + 16);
  if ( v5 )
  {
    v8 = v5 & 0xF;
    v9 = (unsigned int *)((char *)&unk_640404 + 8 * v8);
    v10 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_523A7C();
    v11 = (unsigned __int8 *)v9 + 3;
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v9);
    while ( 1 )
    {
      v13 = *v9;
      if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v13 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v9);
        while ( v14 == v13 && __strex(v13 | 0x40000000, v9) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    RtlAvlRemoveNode((char *)&unk_640400 + 8 * v8, a1);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v9);
    }
    else
    {
      __dmb(0xBu);
      *v9 = 0;
    }
    KfLowerIrql(v10);
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = 0;
  }
  *(_DWORD *)(a1 + 28) = 0;
  KeAcquireInStackQueuedSpinLock(&unk_6403FC, _0);
  v6 = dword_6403F4;
  *(_DWORD *)a1 = dword_6403F4;
  *(_DWORD *)(a1 + 4) = &dword_6403F4;
  if ( *(int **)(v6 + 4) != &dword_6403F4 )
    __fastfail(3u);
  *(_DWORD *)(v6 + 4) = a1;
  dword_6403F4 = a1;
  KeReleaseInStackQueuedSpinLock(_0);
  do
    result = __ldrex((unsigned int *)&dword_6404AC);
  while ( __strex(result - 1, (unsigned int *)&dword_6404AC) );
  return result;
}
