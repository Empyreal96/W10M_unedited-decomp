// PfProcessExitNotification 
 
int __fastcall PfProcessExitNotification(int a1)
{
  int result; // r0

  result = PfpLogApplicationEvent();
  if ( PfSnNumActiveTraces )
    result = PfSnEndProcessTrace(a1, 2, 0);
  return result;
}
