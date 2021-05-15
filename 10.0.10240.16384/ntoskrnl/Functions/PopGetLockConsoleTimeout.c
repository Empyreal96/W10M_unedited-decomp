// PopGetLockConsoleTimeout 
 
int __fastcall PopGetLockConsoleTimeout(int a1)
{
  int result; // r0

  if ( PopConsoleContext == a1 && a1 != -1 && byte_61DE55 )
    result = sub_7F2334();
  else
    result = 0;
  return result;
}
