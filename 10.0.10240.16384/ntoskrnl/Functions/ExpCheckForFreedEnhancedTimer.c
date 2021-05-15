// ExpCheckForFreedEnhancedTimer 
 
int __fastcall ExpCheckForFreedEnhancedTimer(int result)
{
  if ( *(unsigned __int8 *)(result + 96) != (unsigned __int8)ExpTimerFreedCookie )
    sub_52BED8();
  return result;
}
