// CmpCompleteLazyWrite 
 
int __fastcall CmpCompleteLazyWrite(int a1, int a2)
{
  unsigned int *v3; // r5
  int v5; // r10
  unsigned int v6; // r2
  int v7; // r7
  int v8; // r0
  int v9; // r0
  __int64 v11; // [sp+10h] [bp-30h]

  v3 = (unsigned int *)(a1 + 96);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v3);
  }
  else
  {
    do
      v6 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  if ( a2 || (*(_DWORD *)(a1 + 104) & 7) == 3 )
  {
    v7 = 1;
    if ( !a2 )
    {
      do
      {
        v8 = MEMORY[0xFFFF900C];
        v11 = MEMORY[0xFFFF93B0];
        __dmb(0xBu);
        __dmb(0xBu);
        if ( v8 != MEMORY[0xFFFF9010] )
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v9 = MEMORY[0xFFFF900C];
            __dmb(0xBu);
            __dmb(0xBu);
          }
          while ( v9 != MEMORY[0xFFFF9010] );
        }
      }
      while ( v11 != MEMORY[0xFFFF93B0] );
      v3 = (unsigned int *)(a1 + 96);
      v7 = 1;
    }
    KeSetCoalescableTimer(a1);
  }
  else
  {
    v7 = 0;
  }
  *(_QWORD *)(a1 + 104) = (unsigned int)v7;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v5);
}
