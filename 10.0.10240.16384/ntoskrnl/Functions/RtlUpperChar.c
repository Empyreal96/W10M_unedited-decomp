// RtlUpperChar 
 
int __fastcall RtlUpperChar(int result)
{
  result = (char)result;
  if ( (char)result > 122 )
    return sub_7E6E58();
  if ( (char)result >= 97 )
    result = (char)(result ^ 0x20);
  return result;
}
