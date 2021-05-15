// sub_7F76DC 
 
int __fastcall sub_7F76DC(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5

  if ( !v5 && (v4 >= 0 || v4 == -2 || v4 == -1) )
    VfCheckUserHandle(v4);
  return ObpCloseHandle(v4, v5, a3, a4);
}
