// PopMapInternalActionToIrpAction 
 
int __fastcall PopMapInternalActionToIrpAction(int result, int a2, int a3)
{
  if ( result != 7 )
  {
    if ( a2 != 5 )
      return result;
    return 3;
  }
  if ( !a3 )
    return 7;
  if ( a2 == 5 )
    return 3;
  return 2;
}
