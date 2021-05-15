// PsEstablishWin32Callouts 
 
int *__fastcall PsEstablishWin32Callouts(int a1)
{
  int *result; // r0

  result = (int *)ExAllocateCallBack(a1, 0);
  if ( result )
  {
    result = (int *)ExCompareExchangeCallBack(&PsWin32CallBack, result, 0);
    if ( result )
      PsWin32CalloutsEstablished = 1;
    else
      result = (int *)sub_7F1F40();
  }
  return result;
}
