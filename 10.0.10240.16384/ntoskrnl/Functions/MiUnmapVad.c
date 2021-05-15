// MiUnmapVad 
 
unsigned int *__fastcall MiUnmapVad(int a1, int a2)
{
  int v5; // r4
  int v6; // r0

  if ( (*(_DWORD *)(a1 + 40) & 0x2000000) != 0 )
  {
    v5 = **(_DWORD **)(a1 + 44);
    v6 = MI_REFERENCE_CONTROL_AREA_FILE(v5);
    MI_DEREFERENCE_CONTROL_AREA_FILE(v5, v6);
    if ( (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 192) & 0x4000) != 0 )
      return (unsigned int *)sub_8030D0();
  }
  if ( (PerfGlobalGroupMask & 0x8000) != 0 )
  {
    if ( *(_DWORD *)(a1 + 44) )
      MiLogMapFileEvent(a1, 1062);
  }
  return MiDeleteVad(a1, a2);
}
