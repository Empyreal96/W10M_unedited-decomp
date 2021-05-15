// MiComputeProcessUserVa 
 
int __fastcall MiComputeProcessUserVa(int a1, int a2, int a3, int a4, unsigned int *a5)
{
  int result; // r0
  int v8; // r1
  unsigned int v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r0

  *a5 = 0;
  *(_DWORD *)(a1 + 392) = MmUserProbeAddress;
  MEMORY[0xC0402134] = MmHighestUserAddress - 0xFFFF;
  if ( (unsigned int)(MmHighestUserAddress - 0x10000) > 0x7FFE0000 )
    return sub_7F5608();
  v8 = 1;
  v9 = 0;
  if ( (unsigned int)(MmHighestUserAddress - 0x10000) > 0x7FFE0000
    && !a2
    && a3
    && (*(_DWORD *)(a3 + 32) & 0x20) != 0
    && (*(_WORD *)(*(_DWORD *)(*(_DWORD *)MiSectionControlArea(a3) + 36) + 28) & 0x20) == 0 )
  {
    v9 = 0x80000000;
    *(_DWORD *)(a1 + 392) = 0x80000000;
    MEMORY[0xC0402134] = 0x80000000;
    v8 = 0;
  }
  MEMORY[0xC0402138] = MEMORY[0xC0402134];
  if ( dword_681274 && v8 == 1 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(a1 + 192);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x200000, v10) );
    __dmb(0xBu);
  }
  result = 0;
  *a5 = v9;
  return result;
}
