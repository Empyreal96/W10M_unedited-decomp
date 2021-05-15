// ExpCheckForLookasideList 
 
int __fastcall ExpCheckForLookasideList(unsigned int a1, int a2, _DWORD **a3, unsigned int *a4)
{
  unsigned int v5; // r10
  int v8; // r9
  unsigned int v9; // r2
  _DWORD *i; // r4
  int vars4; // [sp+2Ch] [bp+4h]

  v5 = a1 + a2;
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)a4);
  }
  else
  {
    do
      v9 = __ldrex(a4);
    while ( __strex(1u, a4) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(a4);
  }
  for ( i = *a3; i != a3; i = (_DWORD *)*i )
  {
    if ( (unsigned int)(i - 12) >= a1 && (unsigned int)(i - 12) < v5 )
    {
      DbgPrintEx(
        0,
        0,
        (int)"EX: ExFreePool( %p, %Ix ) contains a lookaside structure that has not been deleted first\n",
        a1);
      __debugbreak();
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a4, vars4);
  }
  else
  {
    __dmb(0xBu);
    *a4 = 0;
  }
  return KfLowerIrql(v8);
}
