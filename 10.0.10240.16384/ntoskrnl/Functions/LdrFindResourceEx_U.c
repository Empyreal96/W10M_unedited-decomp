// LdrFindResourceEx_U 
 
int __fastcall LdrFindResourceEx_U(int a1, int a2, int a3, unsigned int a4, int **a5)
{
  return LdrpSearchResourceSection_U(a2, a3, a4, a1, a5);
}
