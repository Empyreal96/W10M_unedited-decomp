// IopCancelApcRequired 
 
int __fastcall IopCancelApcRequired(int a1, int a2, int a3)
{
  unsigned int *v4; // r5
  int v7; // r9
  unsigned int v9; // r2
  _DWORD *v10; // r1
  BOOL v11; // r4
  _DWORD *v12; // r2

  v4 = (unsigned int *)(a1 + 1024);
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52B34C();
  do
    v9 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(v4);
  v10 = (_DWORD *)(a1 + 908);
  v11 = *(_DWORD *)(a1 + 908) != a1 + 908;
  if ( v11 && (a3 || a2) )
  {
    v12 = (_DWORD *)*v10;
    v11 = 0;
    while ( v10 != v12 )
    {
      if ( (*(v12 - 2) & 2) == 0 && (v12[6] == a3 && (!a2 || v12[21] == a2) || !a3 && v12[21] == a2) )
      {
        v11 = 1;
        break;
      }
      v12 = (_DWORD *)*v12;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v7);
  return v11;
}
