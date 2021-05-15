// PsLookupProcessByProcessId 
 
int __fastcall PsLookupProcessByProcessId(int a1, int *a2)
{
  unsigned int v3; // r7
  int v4; // r0
  int v5; // r4
  int v7; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 310);
  v4 = PspReferenceCidTableEntry(a1, 3);
  v5 = v4;
  if ( v4 )
  {
    v4 = PsGetCurrentSilo();
    if ( (*(_DWORD *)(v5 + 192) & 0x4000000) == 0 )
      return sub_7C5444(v4);
    if ( v4 )
      v4 = PspDereferenceSiloObject(v4);
  }
  v7 = (__int16)(*(_WORD *)(v3 + 310) + 1);
  *(_WORD *)(v3 + 310) = v7;
  if ( !v7 && *(_DWORD *)(v3 + 100) != v3 + 100 )
    KiCheckForKernelApcDelivery(v4);
  if ( !v5 )
    return -1073741813;
  *a2 = v5;
  return 0;
}
