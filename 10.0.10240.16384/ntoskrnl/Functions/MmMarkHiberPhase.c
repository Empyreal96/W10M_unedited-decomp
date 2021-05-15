// MmMarkHiberPhase 
 
unsigned int MmMarkHiberPhase()
{
  unsigned int i; // r4
  const void *v1; // r2
  int *v2; // r5
  int v3; // r6
  _DWORD *v4; // r3
  _DWORD *v5; // r4
  _DWORD *v6; // r3
  const void *v7; // r1
  _DWORD *v8; // r2
  int v10[10]; // [sp+8h] [bp-28h] BYREF

  v10[2] = 0;
  v10[3] = 0;
  v10[4] = 0;
  MiMarkKernelPageTablePages();
  v10[0] = (int)MiGatherHiberRange;
  v10[1] = 0;
  if ( MiGatherHiberRange((int)v10, (const void *)(*(_DWORD *)(PsInitialSystemProcess + 24) >> 12), 1, 2) < 0 )
    ((void (__fastcall *)(int *, _DWORD, int, _DWORD))v10[0])(v10, *(_DWORD *)(PsInitialSystemProcess + 32), 4, 0);
  MiEnumerateLeafPtes(
    MmPfnDatabase,
    (MmPfnDatabase + 24 * dword_640504 + 23) & 0xFFFFF000,
    (int (__fastcall *)(int, unsigned int, unsigned int))MiMarkNonPagedHiberPhasePages,
    0);
  PoSetHiberRange(
    0,
    0x10000,
    (const void *)dword_634C9C,
    (const void *)(4 * (((dword_634C98 & 0x1F) != 0) + ((unsigned int)dword_634C98 >> 5))),
    1651535181);
  MiEnumerateLeafPtes(
    0xFFC00000,
    0xFFFFF000,
    (int (__fastcall *)(int, unsigned int, unsigned int))MiMarkNonPagedHiberPhasePages,
    0);
  PoSetHiberRange(0, 0x10000, (const void *)0xFFFF9000, (const void *)0x1000, 1685286221);
  PoSetHiberRange(0, 0x10000, (const void *)dword_634F88, (const void *)0x4B0, 1685286221);
  for ( i = 0; i < 0x4B0; i += 24 )
  {
    v1 = *(const void **)(dword_634F88 + i + 4);
    if ( v1 )
      PoSetHiberRange(0, 0x10000, v1, (const void *)*(unsigned __int16 *)(dword_634F88 + i), 1685286221);
  }
  v2 = &dword_632A84;
  v3 = 2;
  do
  {
    v4 = (_DWORD *)v2[1921];
    v5 = 0;
    while ( v4 )
    {
      v5 = v4;
      v4 = (_DWORD *)*v4;
    }
    while ( v5 )
    {
      v6 = (_DWORD *)v5[1];
      v7 = v5;
      v8 = v5;
      if ( v6 )
      {
        do
        {
          v5 = v6;
          v6 = (_DWORD *)*v6;
        }
        while ( v6 );
      }
      else
      {
        while ( 1 )
        {
          v5 = (_DWORD *)(v5[2] & 0xFFFFFFFC);
          if ( !v5 || (_DWORD *)*v5 == v8 )
            break;
          v8 = v5;
        }
      }
      PoSetHiberRange(0, 0x10000, v7, (const void *)0x420, 1867083085);
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  return MiEnumerateKernelLeafPtes();
}
