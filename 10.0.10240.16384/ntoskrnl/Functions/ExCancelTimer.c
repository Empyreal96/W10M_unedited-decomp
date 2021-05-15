// ExCancelTimer 
 
int __fastcall ExCancelTimer(int a1, int a2)
{
  ExpCheckForFreedEnhancedTimer();
  return KeCancelTimer2(a1, a2);
}
