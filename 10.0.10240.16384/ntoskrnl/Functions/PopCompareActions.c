// PopCompareActions 
 
int __fastcall PopCompareActions(int a1, int a2)
{
  if ( a1 == 7 )
  {
    a1 = 2;
  }
  else if ( a1 >= 2 )
  {
    ++a1;
  }
  if ( a2 == 7 )
  {
    a2 = 2;
  }
  else if ( a2 >= 2 )
  {
    ++a2;
  }
  return a1 - a2;
}
