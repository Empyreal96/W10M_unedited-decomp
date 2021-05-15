// ViIsActiveChannelWcb 
 
int __fastcall ViIsActiveChannelWcb(int a1, _DWORD *a2)
{
  unsigned int *v3; // r4
  int v5; // r5
  int v6; // r9
  unsigned int v7; // r2
  _DWORD *i; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = (unsigned int *)(a1 + 76);
  v5 = 0;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v7 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  for ( i = *(_DWORD **)(a1 + 68); (_DWORD *)(a1 + 68) != i; i = (_DWORD *)*i )
  {
    if ( a2 == i - 10 )
    {
      v5 = 1;
      break;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  KfLowerIrql(v6);
  return v5;
}
