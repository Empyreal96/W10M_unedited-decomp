// ExSetTimer 
 
int __fastcall ExSetTimer(int a1, __int64 a2, int a3, int a4, int *a5)
{
  if ( a2 > 0 )
    return sub_52BEF8();
  if ( a4 <= 0 && a4 < 0 )
    KeBugCheckEx(199, 9, 4);
  if ( a5 )
  {
    if ( !ExpTimerSetParametersAreValid(a5) )
      KeBugCheckEx(199, 9, 1);
  }
  ExpCheckForFreedEnhancedTimer(a1);
  return KeSetTimer2(a1);
}
