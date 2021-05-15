// __C_ExecuteExceptionFilter 
 
int __fastcall _C_ExecuteExceptionFilter(int a1, int a2, int (*a3)(void))
{
  return a3();
}
