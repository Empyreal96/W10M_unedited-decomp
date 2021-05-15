// KiTryToAcquireQueuedSpinLockInstrumented 
 
int __fastcall KiTryToAcquireQueuedSpinLockInstrumented(unsigned int a1, unsigned int *a2)
{
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // r7
  int v8; // r6
  unsigned int v9; // r2
  int result; // r0
  int v11; // r0
  int v12; // r1
  int v13; // [sp+10h] [bp-20h]

  v4 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    v5 = 1;
    v6 = ReadTimeStampCounter();
    v7 = *(_DWORD *)(v4 + 2304);
    v8 = v6;
  }
  else
  {
    v8 = v13;
    v7 = v13;
    v5 = 0;
  }
  do
    v9 = __ldrex(a2);
  while ( !v9 && __strex(a1, a2) );
  __dmb(0xBu);
  if ( v9 )
  {
    __dmb(0xAu);
    __yield();
    result = 0;
  }
  else
  {
    ++*(_DWORD *)(v4 + 3712);
    if ( v5 )
    {
      v11 = ReadTimeStampCounter();
      PerfLogSpinLockAcquire(a2, v12, v11, v12, v11 - v8, 0, v7, 1);
    }
    result = 1;
  }
  return result;
}
