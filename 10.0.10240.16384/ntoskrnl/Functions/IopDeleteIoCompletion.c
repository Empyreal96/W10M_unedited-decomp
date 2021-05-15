// IopDeleteIoCompletion 
 
int __fastcall IopDeleteIoCompletion(int a1, int a2, int a3, int a4)
{
  return IopDeleteIoCompletionInternal(a1, 0, a3, a4);
}
