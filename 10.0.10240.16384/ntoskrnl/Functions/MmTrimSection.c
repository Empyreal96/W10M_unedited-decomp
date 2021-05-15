// MmTrimSection 
 
int __fastcall MmTrimSection(int a1, int *a2, int a3)
{
  int v3; // r3
  int v4; // r0
  int v5; // r7
  int v6; // r6
  unsigned int *v7; // r4
  int v8; // r8
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // [sp+0h] [bp-38h] BYREF
  int v15; // [sp+4h] [bp-34h]
  int v16[12]; // [sp+8h] [bp-30h] BYREF

  if ( a2 )
  {
    v14 = *a2;
    v3 = a2[1];
    a2 = &v14;
    v15 = v3;
  }
  if ( !MiComputeFlushRange(a1, a2, a3, v16, v14, v15) )
    return 0;
  v4 = MiTrimSection(v16, 0, 0);
  v5 = v16[0];
  v6 = v4;
  v7 = (unsigned int *)(v16[0] + 36);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_511C1C();
  v10 = (unsigned __int8 *)v7 + 3;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v7);
  while ( 1 )
  {
    v12 = *v7;
    if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v12 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(v7);
      while ( v13 == v12 && __strex(v12 | 0x40000000, v7) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  MiDecrementSubsections(v16[3]);
  MiDecrementSubsections(v16[4]);
  --*(_DWORD *)(v5 + 20);
  MiCheckControlArea(v5, v8);
  return v6;
}
