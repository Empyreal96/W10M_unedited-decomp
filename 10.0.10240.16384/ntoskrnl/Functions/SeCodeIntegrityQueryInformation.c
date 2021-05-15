// SeCodeIntegrityQueryInformation 
 
int __fastcall SeCodeIntegrityQueryInformation(int a1, int a2, int a3)
{
  int result; // r0

  if ( dword_61D88C )
    result = dword_61D88C(a1, a2, SeILSigningPolicy != 0, a3);
  else
    result = -1073741823;
  return result;
}
