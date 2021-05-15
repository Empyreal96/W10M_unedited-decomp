// DbgSetDebugPrintCallback 
 
int __fastcall DbgSetDebugPrintCallback(int a1, int a2)
{
  if ( !a1 )
    return -1073741811;
  if ( a2 == 1 )
    return DbgpInsertDebugPrintCallback();
  return sub_519CF8();
}
