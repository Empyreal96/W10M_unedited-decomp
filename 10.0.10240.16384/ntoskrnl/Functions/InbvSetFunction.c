// InbvSetFunction 
 
int InbvSetFunction()
{
  int result; // r0

  result = dword_6328F8;
  if ( dword_6328F8 == 3 || dword_6328F8 == 4 )
    result = sub_50B7F8();
  return result;
}
