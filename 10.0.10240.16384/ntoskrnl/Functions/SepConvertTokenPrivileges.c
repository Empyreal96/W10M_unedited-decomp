// SepConvertTokenPrivileges 
 
int __fastcall SepConvertTokenPrivileges(int a1, int *a2)
{
  int result; // r0

  result = SepConvertTokenPrivilegesToLuidAndAttributes(a1, a2 + 1);
  *a2 = result;
  return result;
}
