// InbvReleaseResources 
 
int InbvReleaseResources()
{
  int (*v0)(void); // r3
  int result; // r0

  if ( dword_6328F4 )
  {
    v0 = *(int (**)(void))(dword_6328F4 + 84);
    if ( v0 )
      result = v0();
  }
  return result;
}
