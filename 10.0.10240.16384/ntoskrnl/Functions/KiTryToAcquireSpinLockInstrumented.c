// KiTryToAcquireSpinLockInstrumented 
 
BOOL __fastcall KiTryToAcquireSpinLockInstrumented(unsigned int *a1)
{
  unsigned int v2; // r5
  int v3; // r6
  int v4; // r0
  int v5; // r8
  int v6; // r7
  unsigned int v7; // r2
  BOOL v8; // r4
  int v9; // r0
  int v10; // r1
  int v12; // [sp+10h] [bp-20h]

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
    v6 = v12;
    v5 = v12;
    v3 = 0;
  }
  do
    v7 = __ldrex(a1);
  while ( __strex(1u, a1) );
  __dmb(0xBu);
  v8 = v7 == 0;
  if ( v7 )
  {
    __dmb(0xAu);
    __yield();
  }
  else
  {
    ++*(_DWORD *)(v2 + 3712);
    if ( v3 )
    {
      v9 = ReadTimeStampCounter();
      PerfLogSpinLockAcquire(a1, v10, v9, v10, v9 - v6, 0, v5, 0);
    }
  }
  return v8;
}
