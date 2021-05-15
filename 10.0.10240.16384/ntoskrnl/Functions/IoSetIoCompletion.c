// IoSetIoCompletion 
 
int __fastcall IoSetIoCompletion(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6)
{
  return IoSetIoCompletionEx2(a1, a2, a3, a4, a5, a6, 0, 0);
}
