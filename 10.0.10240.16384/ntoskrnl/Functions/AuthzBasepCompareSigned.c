// AuthzBasepCompareSigned 
 
BOOL __fastcall AuthzBasepCompareSigned(int a1, __int64 a2, __int64 a3)
{
  switch ( a1 )
  {
    case 128:
      return a2 == a3;
    case 129:
      return a2 != a3;
    case 130:
      return a2 < a3;
    case 131:
      return a2 <= a3;
    case 132:
      return a2 > a3;
  }
  return a1 == 133 && a2 >= a3;
}
