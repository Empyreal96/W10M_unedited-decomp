// _PnpCtxRegQueryValueIndirect 
 
int __fastcall PnpCtxRegQueryValueIndirect(int a1, unsigned int a2, int a3, unsigned int *a4, unsigned __int16 *a5, unsigned int *a6, bool *a7)
{
  int (__fastcall *v7)(int, unsigned int, int, unsigned int *, unsigned __int16 *, unsigned int *, bool *); // r5

  v7 = *(int (__fastcall **)(int, unsigned int, int, unsigned int *, unsigned __int16 *, unsigned int *, bool *))(a1 + 168);
  if ( !v7 )
    v7 = PnpRegQueryValueIndirect;
  return v7(a1, a2, a3, a4, a5, a6, a7);
}
