// BgkpAcquireConsole 
 
BOOL BgkpAcquireConsole()
{
  unsigned int v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r1

  __pld(&dword_61646C);
  v0 = dword_61646C & 0xFFFFFFFE;
  v1 = (dword_61646C & 0xFFFFFFFE) + 2;
  do
    v2 = __ldrex((unsigned int *)&dword_61646C);
  while ( v2 == v0 && __strex(v1, (unsigned int *)&dword_61646C) );
  __dmb(0xBu);
  return v2 == v0 || ExfAcquireRundownProtection(&dword_61646C);
}
