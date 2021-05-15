// _PnpCtxRegCopyTree 
 
int __fastcall PnpCtxRegCopyTree(int a1, int a2, int a3, int a4, int a5)
{
  int result; // r0

  if ( a1 && *(_DWORD *)a1 )
    result = RegRtlCopyTreeInternal(a2, a3, a4, a5, 0, *(_DWORD *)(*(_DWORD *)a1 + 4), 0, a4);
  else
    result = RegRtlCopyTreeInternal(a2, a3, a4, a5, 0, 0, 0, a4);
  return result;
}
