// ExpCloseWorkerFactory 
 
int __fastcall ExpCloseWorkerFactory(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0

  if ( a4 == 1 )
    result = ExpShutdownWorkerFactory(a2);
  return result;
}
