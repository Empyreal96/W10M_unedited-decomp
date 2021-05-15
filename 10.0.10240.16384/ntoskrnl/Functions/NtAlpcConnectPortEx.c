// NtAlpcConnectPortEx 
 
int __fastcall NtAlpcConnectPortEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  return AlpcpConnectPort(a1, 0, a2, a3, a4, a5, a6, 0, a7, a8, a9, a10, a11);
}
