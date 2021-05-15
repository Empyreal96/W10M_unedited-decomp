// _SysCtxOpenControlSet 
 
int __fastcall SysCtxOpenControlSet(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // r0

  *a4 = 0;
  if ( RegRtlOpenKeyTransacted(a2, L"CurrentControlSet", 0, 0x2000000, (int)a4, a3) )
    result = sub_818F28();
  else
    result = 0;
  return result;
}
