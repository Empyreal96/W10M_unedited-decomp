// KeQueryGroupAffinity 
 
int __fastcall KeQueryGroupAffinity(int a1)
{
  int result; // r0

  if ( a1 )
    result = 0;
  else
    result = dword_681D78[0];
  return result;
}
