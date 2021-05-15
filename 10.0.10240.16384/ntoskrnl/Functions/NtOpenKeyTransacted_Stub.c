// NtOpenKeyTransacted_Stub 
 
int NtOpenKeyTransacted_Stub()
{
  int (*v0)(); // r4
  int result; // r0

  if ( byte_653581 )
  {
    v0 = dword_65357C;
  }
  else
  {
    v0 = ZwOpenKeyTransacted;
    byte_653581 = 1;
    dword_65357C = ZwOpenKeyTransacted;
  }
  if ( v0 )
    result = dword_65357C();
  else
    result = -1073741702;
  return result;
}
