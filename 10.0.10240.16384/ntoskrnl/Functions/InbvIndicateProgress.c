// InbvIndicateProgress 
 
int InbvIndicateProgress()
{
  int (*v0)(void); // r3
  int result; // r0

  if ( dword_6328F4 )
  {
    v0 = *(int (**)(void))(dword_6328F4 + 60);
    if ( v0 )
      result = v0();
  }
  return result;
}
