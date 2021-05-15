// PoNotifySystemTimeSet 
 
int PoNotifySystemTimeSet()
{
  int result; // r0

  if ( PsWin32CalloutsEstablished )
    result = sub_555CEC();
  return result;
}
