// KiAcquireSpinLockInstrumented 
 
int __fastcall KiAcquireSpinLockInstrumented(int result)
{
  unsigned int *v1; // r8
  int v2; // r9
  _DWORD *v3; // r4
  int v4; // r5
  int v5; // r7
  int v6; // r6
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r1
  int v10; // [sp+10h] [bp-20h]

  v1 = (unsigned int *)result;
  v2 = 0;
  v3 = (_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v4 = 1;
    result = ReadTimeStampCounter();
    v5 = v3[576];
    v6 = result;
  }
  else
  {
    v6 = v10;
    v5 = v10;
    v4 = 0;
  }
  ++v3[928];
  do
    v7 = __ldrex(v1);
  while ( __strex(1u, v1) );
  __dmb(0xBu);
  if ( v7 )
  {
    result = KxWaitForSpinLockAndAcquire(v1);
    v2 = result;
    ++v3[929];
    v3[930] += result;
  }
  if ( v4 )
  {
    v8 = ReadTimeStampCounter();
    result = PerfLogSpinLockAcquire(v1, v9, v8, v9, v8 - v6, v2, v5, 0);
  }
  return result;
}
