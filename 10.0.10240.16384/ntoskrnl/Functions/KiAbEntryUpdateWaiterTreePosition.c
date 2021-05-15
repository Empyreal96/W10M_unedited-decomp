// KiAbEntryUpdateWaiterTreePosition 
 
int __fastcall KiAbEntryUpdateWaiterTreePosition(int a1, int a2)
{
  int result; // r0
  unsigned int v5; // r1
  int v6; // r2
  unsigned int v7; // r3

  result = KiAbWaiterComputeCpuPriorityKey(a1);
  if ( *(char *)(a1 + 24) == result )
    return result;
  *(_BYTE *)(a1 + 24) = result;
  RtlRbRemoveNode((int *)(a2 + 32), (_DWORD *)a1);
  v5 = *(_DWORD *)(a2 + 32);
  v6 = 0;
  if ( !v5 )
    return RtlRbInsertNodeEx(a2 + 32, v5, v6, (_DWORD *)a1);
  while ( *(char *)(v5 + 24) >= *(char *)(a1 + 24) )
  {
    v7 = *(_DWORD *)(v5 + 4);
    if ( !v7 )
    {
      v6 = 1;
      return RtlRbInsertNodeEx(a2 + 32, v5, v6, (_DWORD *)a1);
    }
LABEL_9:
    v5 = v7;
  }
  v7 = *(_DWORD *)v5;
  if ( *(_DWORD *)v5 )
    goto LABEL_9;
  v6 = 0;
  return RtlRbInsertNodeEx(a2 + 32, v5, v6, (_DWORD *)a1);
}
