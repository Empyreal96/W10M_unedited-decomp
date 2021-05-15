// _SysCtxRegCreateTree 
 
int __fastcall SysCtxRegCreateTree(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // r0

  if ( a1 )
    result = RegRtlCreateTreeTransacted(a2, a3, a4, a5, a6, 0, a8, a9, *(_DWORD *)(a1 + 4));
  else
    result = sub_7CBCC0();
  return result;
}
