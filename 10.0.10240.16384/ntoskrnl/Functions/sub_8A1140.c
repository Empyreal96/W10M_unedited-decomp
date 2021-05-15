// sub_8A1140 
 
int sub_8A1140()
{
  int result; // r0

  result = dword_922C38;
  if ( dword_922C38 )
    result = ExNotifyCallback(dword_922C38, 0, 0);
  return result;
}
