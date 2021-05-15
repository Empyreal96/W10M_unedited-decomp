// PsGetProcessSessionIdEx 
 
int __fastcall PsGetProcessSessionIdEx(int a1)
{
  return MmGetSessionIdEx(a1);
}
