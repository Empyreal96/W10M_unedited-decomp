// IopCancelIrpsInCurrentThreadList 
 
int __fastcall IopCancelIrpsInCurrentThreadList(int a1, int a2, int a3, int a4)
{
  int v6; // r9
  unsigned int *v7; // r5
  unsigned int v9; // r2
  int *i; // r4
  unsigned int v11; // r2
  int v12; // r2
  int v15; // [sp+8h] [bp-20h]

  v6 = 0;
  v7 = (unsigned int *)(a2 + 1024);
  v15 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_529A68();
  do
    v9 = __ldrex(v7);
  while ( __strex(1u, v7) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(v7);
  for ( i = *(int **)(a2 + 908); (int *)(a2 + 908) != i; i = (int *)*i )
  {
    if ( *((char *)i + 19) < *((char *)i + 18) + 2 )
    {
      if ( a4 )
      {
        if ( a3 && i[6] != a3 )
          continue;
        v12 = *(i - 2);
        if ( (v12 & 0x402) != 0 || (v12 & 0x84) == 0 && (*((_BYTE *)i + 23) & 2) == 0 )
          continue;
        v6 = 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v7);
        }
        else
        {
          __dmb(0xBu);
          *v7 = 0;
        }
        KfLowerIrql(1);
        IoCancelIrp(i - 4);
        KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) == 0 )
        {
          do
            v11 = __ldrex(v7);
          while ( __strex(1u, v7) );
LABEL_17:
          __dmb(0xBu);
          if ( v11 )
            KxWaitForSpinLockAndAcquire(v7);
          continue;
        }
      }
      else
      {
        if ( (*(i - 2) & 2) != 0 || i[21] != a1 || a3 && i[6] != a3 )
          continue;
        v6 = 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v7);
        }
        else
        {
          __dmb(0xBu);
          *v7 = 0;
        }
        KfLowerIrql(1);
        IoCancelIrp(i - 4);
        KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) == 0 )
        {
          do
            v11 = __ldrex(v7);
          while ( __strex(1u, v7) );
          goto LABEL_17;
        }
      }
      KiAcquireSpinLockInstrumented(v7);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v7);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  KfLowerIrql(v15);
  return v6;
}
