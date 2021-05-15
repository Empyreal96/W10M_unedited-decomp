// __GSHandlerCheck_SEH 
 
int __fastcall _GSHandlerCheck_SEH(int *a1, int a2, int a3, int a4)
{
  int *v5; // r3

  v5 = *(int **)(a4 + 28);
  if ( *v5 < 0 )
    v5 = (int *)((*v5 & 0x7FFFFFFF) + *(_DWORD *)(a4 + 4));
  _GSHandlerCheckCommon(a2, a4, &v5[4 * *v5 + 1]);
  return _C_specific_handler(a1, a2, a3, a4);
}
