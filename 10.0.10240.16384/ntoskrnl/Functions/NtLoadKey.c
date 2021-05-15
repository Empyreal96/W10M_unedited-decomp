// NtLoadKey 
 
int __fastcall NtLoadKey(int a1, int a2)
{
  return NtLoadKeyEx(a1, a2, 0, 0, 0, 0, 0);
}
