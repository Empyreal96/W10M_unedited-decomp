// KiDispatchFastFail 
 
int __fastcall KiDispatchFastFail(_DWORD *a1, int a2, _DWORD *a3, int a4, char a5)
{
  int v8; // r5
  int v10; // r1

  a1[1] |= 1u;
  if ( a5 != 1 )
  {
    if ( a1[4] )
      v10 = a1[5];
    else
      v10 = -1;
    KeBugCheck2(313, v10, (unsigned int)a3, (unsigned int)a1, 0, 0);
  }
  v8 = KeGetCurrentIrql(a1);
  KfLowerIrql(0);
  KiDispatchException(a1, a2, a3, 1, 0);
  KfRaiseIrql(v8);
  return 1;
}
