// FilterEval 
 
int __fastcall FilterEval(int (__fastcall *a1)(int, int *, int *, int *, int *), int a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  if ( !a3 )
    return -1073741811;
  if ( (*a4 & 0xFF00000) != 0 )
    return FilterEvalStrict(a1, a2, a3, a4, a5);
  return FilterEvalImpliedAnd();
}
