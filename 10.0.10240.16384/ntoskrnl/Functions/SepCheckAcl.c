// SepCheckAcl 
 
int __fastcall SepCheckAcl(int a1, unsigned int a2)
{
  int result; // r0

  if ( a2 >= 8 && a2 == *(unsigned __int16 *)(a1 + 2) )
    result = RtlValidAcl();
  else
    result = 0;
  return result;
}
