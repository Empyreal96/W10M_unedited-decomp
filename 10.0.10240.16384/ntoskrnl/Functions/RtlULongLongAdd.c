// RtlULongLongAdd 
 
int __fastcall RtlULongLongAdd(unsigned __int64 a1, __int64 a2, unsigned __int64 *a3)
{
  unsigned __int64 v3; // kr00_8
  int result; // r0

  v3 = a2 + a1;
  if ( v3 < a1 )
    return sub_50DF28();
  result = 0;
  *a3 = v3;
  return result;
}
