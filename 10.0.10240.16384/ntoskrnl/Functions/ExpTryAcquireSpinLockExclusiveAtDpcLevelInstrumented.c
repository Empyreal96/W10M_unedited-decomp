// ExpTryAcquireSpinLockExclusiveAtDpcLevelInstrumented 
 
int __fastcall ExpTryAcquireSpinLockExclusiveAtDpcLevelInstrumented(unsigned int *a1)
{
  unsigned int v2; // r4
  int v3; // r5
  int v4; // r0
  int v5; // r7
  int v6; // r6
  unsigned int v7; // r1
  int v9; // r0
  int v10; // r1
  int v11; // [sp+10h] [bp-20h]

  v2 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v3 = 1;
    v4 = ReadTimeStampCounter();
    v5 = *(_DWORD *)(v2 + 2304);
    v6 = v4;
  }
  else
  {
    v6 = v11;
    v5 = v11;
    v3 = 0;
  }
  do
    v7 = __ldrex(a1);
  while ( !v7 && __strex(0x80000000, a1) );
  __dmb(0xBu);
  if ( v7 )
    return 0;
  ++*(_DWORD *)(v2 + 3712);
  if ( v3 )
  {
    v9 = ReadTimeStampCounter();
    PerfLogSpinLockAcquire((int)a1, v10, v9, v10, v9 - v6, 0, v5, 3);
  }
  return 1;
}
