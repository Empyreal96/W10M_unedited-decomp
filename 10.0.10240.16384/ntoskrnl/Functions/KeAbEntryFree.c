// KeAbEntryFree 
 
int __fastcall KeAbEntryFree(int result, int a2, int a3)
{
  int v3; // r5
  __int16 v5; // r3

  v3 = result;
  *(_BYTE *)(result + 16) |= 2u;
  if ( *(int *)(result + 16) < 0 )
    result = KiAbEntryRemoveFromTree(result);
  v5 = *(_WORD *)(v3 + 44);
  if ( !v5 )
    goto LABEL_4;
  if ( (v5 & 1) == 0 )
  {
    if ( (*(_WORD *)(v3 + 44) & 0xFFFE) != 0 )
      result = KiAbThreadUnboostCpuPriority(a2, v3, a3, *(_WORD *)(v3 + 44) & 0xFFFE);
    if ( (dword_682604 & 0x200) != 0 )
      result = EtwTraceAutoBoostClearFloor(
                 a2,
                 *(_DWORD *)(v3 + 16) & 0xFFFFFFFC | 0x80000000,
                 *(unsigned __int16 *)(v3 + 44));
    *(_WORD *)(v3 + 44) = 0;
LABEL_4:
    *(_BYTE *)(v3 + 13) &= 0xFEu;
    *(_DWORD *)(v3 + 16) = 0;
    return result;
  }
  return sub_50CE80(result);
}
