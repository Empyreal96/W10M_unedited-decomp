// __C_ExecuteExceptionFilter 
 
int __fastcall _C_ExecuteExceptionFilter(int a1, int a2, int (*a3)(void))
{
  return ((int (__fastcall *)(int, int))a3)(a1, a2);
}
