// AuthzBasepCompareUnsigned 
 
BOOL __fastcall AuthzBasepCompareUnsigned(int a1, unsigned __int64 a2, unsigned __int64 a3)
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
