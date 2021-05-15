// RtlULongLongSub 
 
int __fastcall RtlULongLongSub(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 *a3)
{
  int result; // r0
  unsigned __int64 v4; // kr00_8

  if ( a1 < a2 )
    return sub_53EB0C();
  v4 = a1 - a2;
  result = 0;
  *a3 = v4;
  return result;
}
