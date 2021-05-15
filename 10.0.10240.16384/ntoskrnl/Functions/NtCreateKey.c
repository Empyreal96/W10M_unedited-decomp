// NtCreateKey 
 
int __fastcall NtCreateKey(int a1, int a2, int a3, int a4, int a5)
{
  return CmCreateKey(a1, a2, a3, a5);
}
