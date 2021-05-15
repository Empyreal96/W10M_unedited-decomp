// BgpFwReservePoolSwap 
 
int *__fastcall BgpFwReservePoolSwap(int *result, int a2, int a3, int a4)
{
  int v4; // r2

  if ( result )
  {
    if ( result != (int *)1 )
      return result;
    dword_6416B8 = dword_6533FC;
    dword_6416BC = dword_6533F4;
    dword_6416C0 = dword_6533F8;
    dword_6416CC = dword_653400;
    dword_6416C8 = dword_6533F0;
    v4 = 1;
  }
  else
  {
    dword_6533F0 = dword_6416C8;
    dword_6533FC = dword_6416B8;
    dword_6533F4 = dword_6416BC;
    dword_6533F8 = dword_6416C0;
    dword_653400 = dword_6416CC;
    result = BgpFwInitializeReservePool(a2, a3, a4);
    v4 = 0;
  }
  dword_618D08 = v4;
  return result;
}
