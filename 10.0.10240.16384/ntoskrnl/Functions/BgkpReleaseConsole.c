// BgkpReleaseConsole 
 
unsigned __int8 *BgkpReleaseConsole()
{
  unsigned __int8 *result; // r0
  unsigned int v1; // r4
  unsigned int v2; // r1

  result = (unsigned __int8 *)&dword_61646C;
  __pld(&dword_61646C);
  v1 = dword_61646C & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&dword_61646C);
  while ( v2 == v1 && __strex(v1 - 2, (unsigned int *)&dword_61646C) );
  if ( v2 != v1 )
    result = ExfReleaseRundownProtection((unsigned __int8 *)&dword_61646C);
  return result;
}
