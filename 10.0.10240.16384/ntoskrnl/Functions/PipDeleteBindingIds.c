// PipDeleteBindingIds 
 
int __fastcall PipDeleteBindingIds(int result)
{
  if ( *(_DWORD *)(result + 28) != result + 28 )
    result = sub_8119C0();
  return result;
}
