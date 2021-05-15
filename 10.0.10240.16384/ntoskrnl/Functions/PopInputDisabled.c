// PopInputDisabled 
 
int __fastcall PopInputDisabled(int result, int a2, int a3, int a4)
{
  if ( a3 )
    return sub_7F16A0();
  if ( a2 )
    result = PopSetSessionUserStatus(result, 0, 0, a4);
  return result;
}
