// MmFreeBootRegistry 
 
void MmFreeBootRegistry()
{
  unsigned int *v0; // r4
  unsigned int v1; // r5
  unsigned int *v2; // r8
  int v3; // r1
  unsigned int i; // r6
  unsigned int v5; // r2
  unsigned int v6; // t1
  unsigned int v7; // r0

  do
    v0 = (unsigned int *)__ldrex((unsigned int *)&dword_634C88);
  while ( !v0 && __strex(1u, (unsigned int *)&dword_634C88) );
  __dmb(0xBu);
  if ( v0 )
  {
    v1 = *v0;
    v2 = v0 + 1;
    qsort((unsigned int)(v0 + 1), *v0, 4u, (int (__fastcall *)(unsigned int, _BYTE *))MiRegistryVaSort);
    v3 = 0;
    for ( i = 0; i < v1; ++i )
    {
      v6 = *v2++;
      v5 = v6;
      ++v3;
      v7 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
      if ( i == v1 - 1 || v5 + 4096 != *v2 )
      {
        if ( v3 == 1 )
          v3 = 1;
        else
          v7 = v7 - 4 * v3 + 4;
        MiDeleteBootRange(v7, v3);
        v3 = 0;
      }
    }
    MiChargeWsles((int)dword_634F00, -v1, 0);
    ExFreePoolWithTag((unsigned int)v0);
    dword_634C88 = 0;
  }
}
