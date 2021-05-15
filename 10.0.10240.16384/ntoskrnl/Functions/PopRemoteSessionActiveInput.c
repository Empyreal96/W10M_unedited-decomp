// PopRemoteSessionActiveInput 
 
int __fastcall PopRemoteSessionActiveInput(int a1, int a2, _DWORD *a3)
{
  int result; // r0

  PopSetSessionUserStatus(a1, 0);
  result = PopGetDisplayTimeout(a1);
  a3[1] = result;
  *a3 = PopInputTimeout;
  return result;
}
