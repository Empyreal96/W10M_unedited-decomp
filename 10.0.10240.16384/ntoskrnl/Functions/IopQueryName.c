// IopQueryName 
 
int __fastcall IopQueryName(_DWORD *a1, int a2, int a3, unsigned int a4, unsigned int *a5, char a6)
{
  return IopQueryNameInternal(a1, a4, 0, a3, a4, a5, a6);
}
