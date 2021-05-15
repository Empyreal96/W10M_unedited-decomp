// McGenEventRegister 
 
int __fastcall McGenEventRegister(int a1, int a2, int a3, _QWORD *a4)
{
  int result; // r0

  if ( *a4 )
    result = 0;
  else
    result = EtwRegister(a1, McGenControlCallbackV2, a3);
  return result;
}
