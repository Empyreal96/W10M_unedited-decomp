// ExDeleteTimer 
 
int __fastcall ExDeleteTimer(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  int (*v10)(); // [sp+8h] [bp-18h] BYREF
  int v11; // [sp+Ch] [bp-14h]

  v10 = (int (*)())a3;
  v11 = a4;
  v8 = ExpCheckForFreedEnhancedTimer(a1);
  if ( a4 )
    return sub_555930(v8);
  v10 = ExpFinalizeTimerDeletion;
  v11 = a1;
  return KeDisableTimer2(a1, a2, a3, &v10);
}
