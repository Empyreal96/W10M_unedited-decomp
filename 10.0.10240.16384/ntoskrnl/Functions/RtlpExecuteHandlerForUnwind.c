// RtlpExecuteHandlerForUnwind 
 
int __fastcall RtlpExecuteHandlerForUnwind(int a1, int a2, int a3, int a4)
{
  return (*(int (**)(void))(a4 + 24))();
}
