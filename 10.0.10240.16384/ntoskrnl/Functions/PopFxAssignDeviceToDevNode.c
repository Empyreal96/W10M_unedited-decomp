// PopFxAssignDeviceToDevNode 
 
int __fastcall PopFxAssignDeviceToDevNode(int a1, int a2)
{
  unsigned int *v3; // r4
  int v5; // r8
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r3
  __int64 v11; // kr00_8
  unsigned int v12; // r1

  v3 = (unsigned int *)(a1 + 44);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5513BC();
  v7 = (unsigned __int8 *)v3 + 3;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v3);
  while ( 1 )
  {
    v9 = *v3;
    if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex(v3);
      while ( v12 == v9 && __strex(v9 | 0x40000000, v3) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v10 = *(_DWORD *)(a1 + 168);
  if ( a2 )
  {
    *(_DWORD *)(a1 + 168) = v10 & 0xFFFFFFF7;
    *(_BYTE *)(a1 + 48) = 0;
    *(_BYTE *)(a1 + 49) = 0;
    *(_BYTE *)(a1 + 50) = 4;
    *(_DWORD *)(a1 + 52) = 0;
    *(_DWORD *)(a1 + 56) = a1 + 56;
    *(_DWORD *)(a1 + 60) = a1 + 56;
  }
  else
  {
    *(_DWORD *)(a1 + 168) = v10 & 0xFFFFFFFB;
  }
  v11 = *(_QWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 64) = v11 - HIDWORD(v11);
  *(_DWORD *)(a1 + 40) = a2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v5);
}
