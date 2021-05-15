// ObQueryNameString 
 
int __fastcall ObQueryNameString(int a1, int a2, int a3, _DWORD *a4)
{
  return ObQueryNameStringMode(a1, a2, a3, a4, 0);
}
