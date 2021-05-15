// NtCreateProfileEx 
 
int __fastcall NtCreateProfileEx(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6, unsigned int a7, int a8, unsigned __int16 a9, unsigned int a10)
{
  return ExpProfileCreate(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, 0);
}
