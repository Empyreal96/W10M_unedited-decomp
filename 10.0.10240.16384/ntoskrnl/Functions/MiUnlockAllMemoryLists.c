// MiUnlockAllMemoryLists 
 
int __fastcall MiUnlockAllMemoryLists(int a1)
{
  unsigned int v2; // r8
  unsigned int **v3; // r4
  unsigned int **v4; // r5
  int v5; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1
  unsigned int *v8; // r2
  unsigned int v9; // r0
  int vars4; // [sp+24h] [bp+4h]

  v2 = 1;
  if ( (unsigned int)(unsigned __int16)KeNumberNodes + 2 * dword_633818 + 27 > 1 )
  {
    v3 = (unsigned int **)(a1 + 16);
    do
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented((int *)v3 - 1, vars4);
      }
      else
      {
        v4 = v3 - 1;
        v5 = (int)*(v3 - 1);
        if ( !v5 )
        {
          v6 = *v3;
          __dmb(0xBu);
          do
            v7 = __ldrex(v6);
          while ( (unsigned int **)v7 == v4 && __strex(0, v6) );
          if ( (unsigned int **)v7 == v3 - 1 )
            goto LABEL_13;
          v5 = KxWaitForLockChainValid((int *)v3 - 1);
        }
        *v4 = 0;
        __dmb(0xBu);
        v8 = (unsigned int *)(v5 + 4);
        do
          v9 = __ldrex(v8);
        while ( __strex(v9 ^ 1, v8) );
      }
LABEL_13:
      ++v2;
      v3 += 3;
    }
    while ( v2 < (unsigned int)(unsigned __int16)KeNumberNodes + 2 * dword_633818 + 27 );
  }
  return KeReleaseInStackQueuedSpinLock(a1);
}
