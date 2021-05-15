// ExpAcquireSpinLockSharedAtDpcLevelInstrumented 
 
int __fastcall ExpAcquireSpinLockSharedAtDpcLevelInstrumented(unsigned int *a1)
{
  int v2; // r6
  _DWORD *v3; // r4
  int v4; // r5
  int v5; // r0
  int v6; // r9
  int v7; // r8
  int result; // r0
  unsigned int v9; // r1
  int v10; // r0
  int v11; // r1
  int v12; // [sp+10h] [bp-20h]

  v2 = 0;
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
    v7 = v12;
    v6 = v12;
    v4 = 0;
  }
  ++v3[928];
  result = *a1 & 0x7FFFFFFF;
  do
    v9 = __ldrex(a1);
  while ( v9 == result && __strex(result + 1, a1) );
  __dmb(0xBu);
  if ( v9 != result )
  {
    result = ExpWaitForSpinLockSharedAndAcquire(a1);
    v2 = result;
    ++v3[929];
    v3[930] += result;
  }
  if ( v4 )
  {
    v10 = ReadTimeStampCounter();
    result = PerfLogSpinLockAcquire((int)a1, v11, v10, v11, v10 - v7, v2, v6, 2);
  }
  return result;
}
