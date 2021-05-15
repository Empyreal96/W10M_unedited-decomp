// NtLoadKey2 
 
int __fastcall NtLoadKey2(int a1, int a2, int a3)
{
  return NtLoadKeyEx(a1, a2, a3, 0, 0, 0, 0);
}
