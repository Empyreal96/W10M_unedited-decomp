// MiDeleteParentDecayNode 
 
int __fastcall MiDeleteParentDecayNode(int a1)
{
  int v1; // r1
  int v2; // r4
  int v3; // r0
  int result; // r0

  v1 = *(_DWORD *)(a1 + 12) & 0xFFFFF;
  v2 = MmPfnDatabase + 24 * v1;
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(v2 + 8) & 0xFFF | (*(_DWORD *)(a1 + 12) << 12);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(v2 + 20) & 0xFFF00000 | v1 & 0xFFFFF;
  MiUnlinkPageFromList(v2, 1);
  v3 = MiRemoveDecayClusterTimer(v2);
  if ( (*(_BYTE *)(v2 + 19) & 8) != 0 )
    result = sub_51F6F0(v3);
  else
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&dword_634698, (_DWORD *)v2);
  return result;
}
