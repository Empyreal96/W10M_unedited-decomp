// NtCreateToken 
 
int __fastcall NtCreateToken(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7, unsigned int *a8, unsigned int *a9, _DWORD *a10, int a11, int a12, _DWORD *a13)
{
  return NtCreateTokenEx(a1, a2, a3, a4, a5, a6, a7, a8, a9, 0, 0, 0, 0, a10, a11, a12, a13);
}
