// KiAbEntryUpdateOwnerTreePosition 
 
unsigned int __fastcall KiAbEntryUpdateOwnerTreePosition(int a1, int a2)
{
  unsigned int result; // r0
  int v5; // r0
  unsigned int v6; // r1
  int v7; // r2

  result = KiAbOwnerComputeCpuPriorityKey(a1);
  if ( *(char *)(a1 + 24) != result )
  {
    *(_BYTE *)(a1 + 24) = result;
    v5 = RtlRbRemoveNode((int *)(a2 + 24), (_DWORD *)a1);
    v6 = *(_DWORD *)(a2 + 24);
    v7 = 0;
    if ( v6 )
    {
      while ( 1 )
      {
        if ( *(char *)(v6 + 24) > *(char *)(a1 + 24) )
          return sub_54A134(v5);
        if ( !*(_DWORD *)(v6 + 4) )
          break;
        v6 = *(_DWORD *)(v6 + 4);
      }
      v7 = 1;
    }
    result = RtlRbInsertNodeEx(a2 + 24, v6, v7, (_DWORD *)a1);
  }
  return result;
}
