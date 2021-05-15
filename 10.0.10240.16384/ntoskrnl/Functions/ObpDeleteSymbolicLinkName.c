// ObpDeleteSymbolicLinkName 
 
int __fastcall ObpDeleteSymbolicLinkName(int result)
{
  if ( *(_DWORD *)(result + 16) )
    result = sub_7EB0B0();
  return result;
}
