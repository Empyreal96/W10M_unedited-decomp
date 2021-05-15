// KiHeadlessDisplayString 
 
int __fastcall KiHeadlessDisplayString(int result, int a2)
{
  if ( result && a2 && HeadlessGlobals )
  {
    if ( *(_DWORD *)(HeadlessGlobals + 4) )
      result = HdlspDispatch(23, result, a2, 0);
  }
  return result;
}
