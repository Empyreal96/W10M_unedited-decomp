// InbvGetDisplayState 
 
int InbvGetDisplayState()
{
  int (*v0)(void); // r3
  int result; // r0

  if ( dword_6328F4 && (v0 = *(int (**)(void))(dword_6328F4 + 72)) != 0 )
    result = v0();
  else
    result = 2;
  return result;
}
