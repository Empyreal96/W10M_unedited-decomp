// PopSuspendResumeInvocation 
 
int __fastcall PopSuspendResumeInvocation(int a1)
{
  int result; // r0

  result = 0;
  if ( dword_61EAC0 )
    result = dword_61EAC0(
               *(_DWORD *)a1,
               *(unsigned __int8 *)(a1 + 4),
               *(unsigned __int8 *)(a1 + 5),
               *(unsigned __int8 *)(a1 + 6));
  return result;
}
