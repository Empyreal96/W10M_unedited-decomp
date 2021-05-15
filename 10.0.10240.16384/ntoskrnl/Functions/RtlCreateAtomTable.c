// RtlCreateAtomTable 
 
int __fastcall RtlCreateAtomTable(unsigned int a1, _DWORD *a2, int a3, int a4)
{
  return RtlCreateAtomTableEx(a1, 0, a2, a4);
}
