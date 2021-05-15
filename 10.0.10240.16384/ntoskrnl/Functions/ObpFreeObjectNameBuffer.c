// ObpFreeObjectNameBuffer 
 
unsigned int __fastcall ObpFreeObjectNameBuffer(int a1)
{
  _DWORD *v1; // r5
  unsigned int v2; // r1
  int v3; // r4
  unsigned int v4; // r2
  unsigned int v6; // r2

  v1 = *(_DWORD **)(a1 + 4);
  if ( *(_WORD *)(a1 + 2) != 248 )
    return ExFreePoolWithTag(*(_DWORD *)(a1 + 4));
  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v3 = *(_DWORD *)(v2 + 2856);
  v4 = *(unsigned __int16 *)(v3 + 8);
  ++*(_DWORD *)(v3 + 20);
  if ( *(unsigned __int16 *)(v3 + 4) < v4 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)v3, v1);
  ++*(_DWORD *)(v3 + 24);
  v3 = *(_DWORD *)(v2 + 2860);
  v6 = *(unsigned __int16 *)(v3 + 8);
  ++*(_DWORD *)(v3 + 20);
  if ( *(unsigned __int16 *)(v3 + 4) < v6 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)v3, v1);
  ++*(_DWORD *)(v3 + 24);
  return (*(int (__fastcall **)(_DWORD *))(v3 + 44))(v1);
}
