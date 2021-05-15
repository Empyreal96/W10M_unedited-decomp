// IopSymlinkProcessReparse 
 
unsigned int __fastcall IopSymlinkProcessReparse(int a1, int a2, int a3, int a4)
{
  unsigned int result; // r0

  result = *(_DWORD *)(a1 + 28);
  if ( result == -1610612733 || result == -1610612724 || result == -2147483623 )
  {
    if ( !a4 )
      result = IopGraftName(a1, a2);
  }
  else if ( result > 1 )
  {
    result = sub_7F9CE8();
  }
  return result;
}
