// IoFreeMdl 
 
int __fastcall IoFreeMdl(int a1)
{
  unsigned int v2; // r1
  int v3; // r5
  unsigned int v4; // r2
  unsigned int v6; // r2

  if ( (*(_WORD *)(a1 + 6) & 0x20) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(a1 + 12), a1);
  if ( (*(_WORD *)(a1 + 6) & 8) == 0 )
    return ExFreePoolWithTag(a1, 0);
  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v3 = *(_DWORD *)(v2 + 2840);
  v4 = *(unsigned __int16 *)(v3 + 8);
  ++*(_DWORD *)(v3 + 20);
  if ( *(unsigned __int16 *)(v3 + 4) < v4 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)v3, (_DWORD *)a1);
  ++*(_DWORD *)(v3 + 24);
  v3 = *(_DWORD *)(v2 + 2844);
  v6 = *(unsigned __int16 *)(v3 + 8);
  ++*(_DWORD *)(v3 + 20);
  if ( *(unsigned __int16 *)(v3 + 4) < v6 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)v3, (_DWORD *)a1);
  ++*(_DWORD *)(v3 + 24);
  return (*(int (__fastcall **)(int))(v3 + 44))(a1);
}
