// WdipSemEnableDisableTrace 
 
int __fastcall WdipSemEnableDisableTrace(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // r0

  if ( a2 && a1 )
    result = EtwEnableTrace(a2, 0, a1, 0, a8, a3, a5, a6, 0, 0, a7);
  else
    result = -1073741811;
  return result;
}
