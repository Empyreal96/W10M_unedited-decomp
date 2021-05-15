// NtCreateKeyTransacted_Stub 
 
int __fastcall NtCreateKeyTransacted_Stub(int a1, int a2, int a3)
{
  int (*v3)(); // r3
  int result; // r0

  if ( byte_653580 )
  {
    v3 = (int (*)())dword_653578;
  }
  else
  {
    v3 = ZwCreateKeyTransacted;
    byte_653580 = 1;
    dword_653578 = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))ZwCreateKeyTransacted;
  }
  if ( v3 )
    result = dword_653578(a1, a2, a3, 0);
  else
    result = -1073741702;
  return result;
}
