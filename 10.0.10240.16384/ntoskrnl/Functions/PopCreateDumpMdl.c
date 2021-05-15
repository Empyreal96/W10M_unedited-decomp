// PopCreateDumpMdl 
 
int __fastcall PopCreateDumpMdl(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // r5
  int v6; // r4
  int v7; // r1
  _DWORD *v8; // r3
  int result; // r0

  v4 = a3;
  v6 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  if ( a3 >= a4 )
    PopInternalError(660557);
  v7 = a4 - a3;
  if ( a4 - a3 >= *(_DWORD *)(a1 + 176) )
    v7 = *(_DWORD *)(a1 + 176);
  *(_WORD *)(a2 + 4) = 4 * (((unsigned int)((v7 << 12) + 4095) >> 12) + 7);
  v8 = (_DWORD *)(a2 + 28);
  *(_DWORD *)a2 = 0;
  *(_WORD *)(a2 + 6) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = v7 << 12;
  for ( *(_DWORD *)(a2 + 24) = 0; v7; --v7 )
    *v8++ = v4++;
  result = MmMapMemoryDumpMdlEx(*(_DWORD *)(*(_DWORD *)(a1 + 164) + 112 * v6 + 4), v7, a2, 0);
  *(_WORD *)(a2 + 6) |= 1u;
  if ( (*(_DWORD *)(a2 + 20) & 0xFFF) != 0 )
  {
    PopInternalAddToDumpFile(a2, 28, 0);
    KeBugCheckEx(160, 262, 10, a2, 0);
  }
  return result;
}
