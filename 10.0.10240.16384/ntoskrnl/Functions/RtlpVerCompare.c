// RtlpVerCompare 
 
int __fastcall RtlpVerCompare(int a1, int a2, int a3, bool *a4, char a5)
{
  if ( (a5 & 1) != 0 )
    return sub_553130();
  *a4 = a2 == a3;
  switch ( a1 )
  {
    case 3:
      return a3 >= a2;
    case 1:
      return a3 == a2;
    case 2:
      return a3 > a2;
    case 4:
      return a3 < a2;
    case 5:
      return a3 <= a2;
  }
  return 0;
}
