// MiCreateForkWsle 
 
int __fastcall MiCreateForkWsle(int result, int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  unsigned int v5; // r9
  unsigned int v6; // r4
  int v7; // r10
  unsigned int v8; // r3
  unsigned int v9; // r5
  int v10; // r8
  int v11; // r7
  unsigned int *v12; // r5
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  int v17; // [sp+8h] [bp-28h]

  v5 = a4;
  v6 = a3;
  v17 = a2;
  v7 = result;
  if ( a3 <= a4 )
  {
    v8 = a5;
    do
    {
      v9 = *(_DWORD *)v6;
      if ( (*(_DWORD *)v6 & 2) != 0 )
      {
        if ( v8 > 1 )
        {
          MiCreateForkWsle(v7, a2, v6 << 10, (v6 << 10) + 4092, v8 - 1);
LABEL_7:
          v10 = MmPfnDatabase;
          v11 = 3 * (v9 >> 12);
          if ( !*(_DWORD *)(MmPfnDatabase + 24 * (v9 >> 12))
            && !MiAllocateWsle(v7, v6, MmPfnDatabase + 24 * (v9 >> 12), 0, 0, 0) )
          {
            do
            {
              v12 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
              MiUnlockWorkingSetExclusive((int)v12, v17);
              KeDelayExecutionThread(0, 0, (unsigned int *)Mi30Milliseconds);
              v17 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v12);
              }
              else
              {
                v13 = (unsigned __int8 *)v12 + 3;
                do
                  v14 = __ldrex(v13);
                while ( __strex(v14 | 0x80, v13) );
                __dmb(0xBu);
                if ( v14 >> 7 )
                  ExpWaitForSpinLockExclusiveAndAcquire(v12);
                while ( 1 )
                {
                  v15 = *v12;
                  if ( (*v12 & 0xBFFFFFFF) == 0x80000000 )
                    break;
                  if ( (v15 & 0x40000000) == 0 )
                  {
                    do
                      v16 = __ldrex(v12);
                    while ( v16 == v15 && __strex(v15 | 0x40000000, v12) );
                    __dmb(0xBu);
                  }
                  __dmb(0xAu);
                  __yield();
                }
              }
            }
            while ( !MiAllocateWsle(v7, v6, v10 + 8 * v11, 0, 0, 0) );
            v5 = a4;
          }
          v8 = a5;
          goto LABEL_14;
        }
        if ( (v9 & 0x400) == 0 )
          goto LABEL_7;
      }
LABEL_14:
      v6 += 4;
      a2 = v17;
      result = 0;
    }
    while ( v6 <= v5 );
  }
  return result;
}
