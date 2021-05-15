// ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented 
 
int __fastcall ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(unsigned int *a1)
{
  _DWORD *v2; // r5
  int v3; // r8
  int v4; // r0
  int v5; // r10
  int v6; // r9
  int v7; // r4
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  int result; // r0
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r1
  int v14; // [sp+10h] [bp-28h]

  v2 = (_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v3 = 1;
    v4 = ReadTimeStampCounter();
    v5 = v2[576];
    v6 = v4;
  }
  else
  {
    v6 = v14;
    v5 = v14;
    v3 = 0;
  }
  v7 = 0;
  ++v2[928];
  v8 = (unsigned __int8 *)a1 + 3;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    v7 = ExpWaitForSpinLockExclusiveAndAcquire(a1);
  while ( 1 )
  {
    result = *a1;
    if ( (*a1 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (result & 0x40000000) == 0 )
    {
      do
        v11 = __ldrex(a1);
      while ( v11 == result && __strex(result | 0x40000000, a1) );
      __dmb(0xBu);
    }
    ++v7;
    __dmb(0xAu);
    __yield();
  }
  if ( v7 )
  {
    ++v2[929];
    v2[930] += v7;
  }
  if ( v3 )
  {
    v12 = ReadTimeStampCounter();
    result = PerfLogSpinLockAcquire(a1, v13, v12, v13, v12 - v6, v7, v5, 3);
  }
  return result;
}
