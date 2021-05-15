// IopCloseIoCompletion 
 
int __fastcall IopCloseIoCompletion(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = a2;
  if ( a4 == 1 )
    result = IopDeleteIoCompletionInternal(a2, 1, a3, 1);
  return result;
}
