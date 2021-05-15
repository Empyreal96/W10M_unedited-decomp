// KiContinue 
 
int __fastcall KiContinue(_DWORD *a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r4

  v6 = KeGetCurrentIrql(a1);
  if ( !v6 )
    KfRaiseIrql(1);
  v7 = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    v7 = KiContinuePreviousModeUser(a1, a2, a3);
  else
    KeContextToKframes(a3, a2, a1, *a1);
  if ( !v6 )
    KfLowerIrql(0);
  return v7;
}
