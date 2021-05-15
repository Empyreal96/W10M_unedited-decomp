// ExpTryConvertSharedSpinLockExclusiveInstrumented 
 
int __fastcall ExpTryConvertSharedSpinLockExclusiveInstrumented(unsigned int *a1, int a2)
{
  _DWORD *v3; // r4
  int v4; // r8
  int v5; // r0
  int v6; // r10
  int v7; // r9
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  int i; // r5
  unsigned int v11; // r0
  unsigned int v12; // r1
  int v13; // r0
  int v14; // r1
  int v15; // r0
  int v16; // r1
  int v19; // [sp+18h] [bp-28h]

  v3 = (_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v4 = 1;
    v5 = ReadTimeStampCounter();
    v6 = v3[576];
    v7 = v5;
  }
  else
  {
    v7 = v19;
    v6 = a2;
    v4 = 0;
  }
  __dmb(0xBu);
  v8 = (unsigned __int8 *)a1 + 3;
  do
    v9 = __ldrex(v8);
  while ( __strex(v9 | 0x80, v8) );
  __dmb(0xBu);
  if ( v9 >> 7 )
    return 0;
  ++v3[928];
  for ( i = 0; ; ++i )
  {
    v11 = *a1;
    if ( (*a1 & 0xBFFFFFFF) == -2147483647 )
      break;
    if ( (v11 & 0x40000000) == 0 )
    {
      do
        v12 = __ldrex(a1);
      while ( v12 == v11 && __strex(v11 | 0x40000000, a1) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  ++v3[929];
  v3[930] += i;
  if ( v4 )
  {
    v13 = ReadTimeStampCounter();
    PerfLogSpinLockRelease((unsigned int)a1, a2, v13, v14);
    v15 = ReadTimeStampCounter();
    PerfLogSpinLockAcquire((int)a1, v16, v15, v16, v15 - v7, i, v6, 4);
  }
  return 1;
}
