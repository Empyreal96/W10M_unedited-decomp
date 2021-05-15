// MmLockPagableDataSection 
 
int __fastcall MmLockPagableDataSection(unsigned int a1)
{
  int v2; // r4
  unsigned int v3; // r5
  int v4; // r3
  int v5; // r0
  unsigned int v6; // r8
  int v7; // r0
  unsigned int v8; // r6
  int v9; // r3
  unsigned int v10; // r0
  _DWORD *v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r2
  int v16; // r3

  if ( (*(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return 1;
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(__int16 *)(v3 + 0x134) - 1;
  *(_WORD *)(v3 + 308) = v4;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, 1026, v4);
  v5 = MiLookupDataTableEntry(a1, 1)[6];
  v6 = a1 - v5;
  v7 = RtlImageNtHeader(v5);
  v8 = 0;
  v9 = *(unsigned __int16 *)(v7 + 20) + v7;
  v10 = *(unsigned __int16 *)(v7 + 6);
  v11 = (_DWORD *)(v9 + 24);
  if ( v10 )
  {
    while ( 1 )
    {
      v12 = v11[4];
      if ( v12 < v11[2] )
        v12 = v11[2];
      v13 = v11[3];
      if ( v6 >= v13 && v6 < v12 + v13 )
        break;
      ++v8;
      v11 += 10;
      if ( v8 >= v10 )
        goto LABEL_10;
    }
    v2 = (int)v11;
  }
LABEL_10:
  v14 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v16 = (__int16)(*(_WORD *)(v3 + 308) + 1);
  *(_WORD *)(v3 + 308) = v16;
  if ( !(_WORD)v16 )
  {
    v16 = *(_DWORD *)(v3 + 100);
    v15 = v3 + 100;
    if ( v16 != v3 + 100 )
    {
      v16 = *(__int16 *)(v3 + 310);
      if ( !*(_WORD *)(v3 + 310) )
        v14 = KiCheckForKernelApcDelivery(v14);
    }
  }
  if ( !v2 )
    sub_7EF5BC(v14);
  MiLockPagableImageSection(v2, 1, v15, v16);
  return v2;
}
