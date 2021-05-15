// NtConnectPort 
 
int __fastcall NtConnectPort(int *a1, int a2, int *a3, unsigned int a4, unsigned int a5, int *a6, int a7, int *a8)
{
  return NtSecureConnectPort(a1, a2, a3, a4, 0, a5, a6, a7, a8);
}
