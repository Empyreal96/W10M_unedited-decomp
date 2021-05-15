// MiDeletePartialCloneVad 
 
unsigned int __fastcall MiDeletePartialCloneVad(unsigned int a1, char a2)
{
  int v4; // r6
  int v5; // r0
  unsigned int v6; // r7
  int v7; // r0
  int v8; // r2

  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( (a2 & 1) != 0 )
  {
    v5 = MiGetVadWakeList(a1, 4);
    v6 = v5;
    if ( v5 )
    {
      PsReturnProcessNonPagedPoolQuota(v4, 4 * (((*(_DWORD *)(v5 + 8) & 0x1F) != 0) + (*(_DWORD *)(v5 + 8) >> 5) + 6));
      ExFreePoolWithTag(v6);
    }
  }
  if ( (a2 & 2) != 0 )
    MiFreeLargePageView(v4, a1, 2);
  if ( (a2 & 4) != 0 )
  {
    v7 = MmGetSessionIdEx(v4);
    MiDereferencePerSessionProtos(**(_DWORD ***)(a1 + 44), v7);
  }
  if ( (a2 & 8) != 0 )
    ObfDereferenceObject(*(_DWORD *)(a1 + 72));
  if ( (a2 & 0x10) != 0 )
    MiRemoveSharedCommitNode(**(_DWORD ***)(a1 + 44), v4, 0);
  v8 = *(_DWORD *)(a1 + 28);
  if ( (v8 & 7) == 2 && (v8 & 0x20000) != 0 )
    --MEMORY[0xC0402148];
  if ( (*(_DWORD *)(a1 + 28) & 0x8000) == 0 && *(int *)(a1 + 68) < 0 )
    MiDereferenceExtendInfo(a1, **(_DWORD **)(a1 + 44));
  MiFreeVadEvents(a1);
  return ExFreePoolWithTag(a1);
}
