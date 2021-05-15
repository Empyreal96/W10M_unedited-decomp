// encode_digit 
 
int __fastcall encode_digit(int a1)
{
  unsigned __int16 v1; // r3

  if ( a1 <= 25 )
    v1 = a1 + 97;
  else
    v1 = a1 + 22;
  return v1;
}
