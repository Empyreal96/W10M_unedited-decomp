// KiAcquireQueuedSpinLockInstrumented 
 
int __fastcall KiAcquireQueuedSpinLockInstrumented(int result, unsigned int *a2)
{
  unsigned int v3; // r9
  int v4; // r10
  _DWORD *v5; // r4
  int v6; // r5
  int v7; // r7
  int v8; // r6
  _DWORD *v9; // r1
  int v10; // r0
  int v11; // r1
  int v12; // [sp+10h] [bp-28h]

  v3 = result;
  v4 = 0;
  v5 = (_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v6 = 1;
    result = ReadTimeStampCounter();
    v7 = v5[576];
    v8 = result;
  }
  else
  {
    v8 = v12;
    v7 = v12;
    v6 = 0;
  }
  ++v5[928];
  do
    v9 = (_DWORD *)__ldrex(a2);
  while ( __strex(v3, a2) );
  __dmb(0xBu);
  if ( v9 )
  {
    result = KxWaitForLockOwnerShip(v3, v9);
    v4 = result;
    ++v5[929];
    v5[930] += result;
  }
  if ( v6 )
  {
    v10 = ReadTimeStampCounter();
    result = PerfLogSpinLockAcquire(a2, v11, v10, v11, v10 - v8, v4, v7, 1);
  }
  return result;
}
