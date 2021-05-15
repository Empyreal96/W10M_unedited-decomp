// EtwpKernelProvEnableCallback 
 
int __fastcall EtwpKernelProvEnableCallback(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return SeEtwEnableCallback(a1, a2, a3, a6, a5);
}
