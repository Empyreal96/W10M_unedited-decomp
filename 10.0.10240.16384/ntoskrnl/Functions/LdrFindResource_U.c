// LdrFindResource_U 
 
int __fastcall LdrFindResource_U(int a1, int a2, unsigned int a3, int **a4)
{
  return LdrpSearchResourceSection_U(a1, a2, a3, 0, a4);
}
