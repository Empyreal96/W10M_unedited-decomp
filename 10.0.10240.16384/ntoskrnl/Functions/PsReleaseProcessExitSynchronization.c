// PsReleaseProcessExitSynchronization 
 
unsigned __int8 *__fastcall PsReleaseProcessExitSynchronization(int a1)
{
  unsigned __int8 *result; // r0
  unsigned int v2; // r4
  unsigned int v3; // r1

  result = (unsigned __int8 *)(a1 + 172);
  __pld(result);
  v2 = *(_DWORD *)result & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)result);
  while ( v3 == v2 && __strex(v2 - 2, (unsigned int *)result) );
  if ( v3 != v2 )
    result = ExfReleaseRundownProtection(result);
  return result;
}
