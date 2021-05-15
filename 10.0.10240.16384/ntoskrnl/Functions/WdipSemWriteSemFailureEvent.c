// WdipSemWriteSemFailureEvent 
 
int __fastcall WdipSemWriteSemFailureEvent(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 && a2 && a4 )
    result = WdipSemWriteEvent(WdipSemRegHandle, MEMORY[0x61CB14], a1, a4);
  else
    result = -1073741811;
  return result;
}
