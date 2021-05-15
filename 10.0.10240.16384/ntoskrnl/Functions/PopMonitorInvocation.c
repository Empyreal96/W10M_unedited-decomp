// PopMonitorInvocation 
 
int __fastcall PopMonitorInvocation(unsigned __int8 *a1)
{
  int result; // r0

  result = 0;
  if ( dword_61EAB4 )
    result = dword_61EAB4(*a1, a1[1], *((_DWORD *)a1 + 1));
  return result;
}
