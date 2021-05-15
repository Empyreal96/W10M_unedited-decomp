// CmpFreeExtraHashInfo 
 
int __fastcall CmpFreeExtraHashInfo(_DWORD *a1)
{
  unsigned int v1; // r1
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v5; // r2

  v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v2 = *(_DWORD *)(v1 + 2880);
  v3 = *(unsigned __int16 *)(v2 + 8);
  ++*(_DWORD *)(v2 + 20);
  if ( *(unsigned __int16 *)(v2 + 4) < v3 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)v2, a1);
  ++*(_DWORD *)(v2 + 24);
  v2 = *(_DWORD *)(v1 + 2884);
  v5 = *(unsigned __int16 *)(v2 + 8);
  ++*(_DWORD *)(v2 + 20);
  if ( *(unsigned __int16 *)(v2 + 4) < v5 )
    return RtlpInterlockedPushEntrySList((unsigned __int64 *)v2, a1);
  ++*(_DWORD *)(v2 + 24);
  return (*(int (**)(void))(v2 + 44))();
}
