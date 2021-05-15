// AslFileMappingGetViewBase 
 
int __fastcall AslFileMappingGetViewBase(int a1)
{
  int result; // r0

  if ( a1 )
    result = *(_DWORD *)(a1 + 536);
  else
    result = 0;
  return result;
}
