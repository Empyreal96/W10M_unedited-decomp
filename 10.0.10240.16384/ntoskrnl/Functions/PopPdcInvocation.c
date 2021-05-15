// PopPdcInvocation 
 
int __fastcall PopPdcInvocation(_DWORD *a1)
{
  int result; // r0

  if ( !*a1 )
    return PopPdcRegister(a1);
  if ( *a1 != 1 )
    return -1073741811;
  result = -1073741822;
  if ( dword_61EAB0 )
    result = dword_61EAB0(a1[2], a1[1]);
  return result;
}
