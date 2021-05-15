// ObIsKernelHandle 
 
BOOL __fastcall ObIsKernelHandle(int a1)
{
  return a1 < 0 && a1 != -2 && a1 != -1;
}
