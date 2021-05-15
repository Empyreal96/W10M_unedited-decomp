// IoDisconnectInterruptEx 
 
int __fastcall IoDisconnectInterruptEx(_DWORD *a1)
{
  int result; // r0

  if ( *a1 == 1 )
    result = IoDisconnectInterrupt(a1[1]);
  else
    result = sub_7BF1E4((int)a1);
  return result;
}
