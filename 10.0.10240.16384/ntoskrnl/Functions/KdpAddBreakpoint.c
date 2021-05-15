// KdpAddBreakpoint 
 
int __fastcall KdpAddBreakpoint(unsigned int a1, int a2, int a3, int a4, unsigned __int8 a5, unsigned __int8 a6)
{
  int v10; // r3
  int *v11; // r4
  unsigned int v12; // r1
  int *v13; // r2
  int v14; // r0
  int v15; // r0
  int v16; // r3
  int v17; // r3
  char v18; // r6
  int v19; // r0
  int v20; // [sp+8h] [bp-28h] BYREF
  int v21; // [sp+Ch] [bp-24h]

  v20 = 0;
  v21 = 0;
  if ( ((a5 - 1) & a5) != 0 || a1 >= MmSystemRangeStart && (a3 != 57086 || a4 || a5 != 2 || a6 != 1) )
    return 0;
  v10 = KdpBreakpointChangeCount + 1;
  __dmb(0xBu);
  KdpBreakpointChangeCount = v10;
  v11 = 0;
  v12 = 0;
  v13 = KdpBreakpointTable;
  do
  {
    v14 = v13[6];
    if ( (v14 & 1) != 0 && *v13 == a1 )
    {
      v16 = v13[6];
      if ( (v16 & 8) == 0 )
        return 0;
      v13[6] = v16 & 0xFFFFFFF7;
      return v12 + 1;
    }
    if ( !v11 && !v14 )
      v11 = v13;
    ++v12;
    v13 += 8;
  }
  while ( v12 < 0x20 );
  if ( !v11 )
    return 0;
  v15 = KdpCopyCodeStream(a1 & ~a6, 0, (int)&v20, a5, 4);
  *v11 = a1;
  *((_BYTE *)v11 + 28) = a5;
  *((_BYTE *)v11 + 29) = a6;
  v11[2] = a3;
  v11[3] = a4;
  if ( v15 >= 0 )
  {
    v11[4] = v20;
    v11[5] = v21;
    v17 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v18 = KdpOweBreakpoint;
    v11[1] = v17;
    v19 = KdpInsertBreakpoint(v11, &v20);
    if ( !v19 )
    {
      KdpOweBreakpoint = v18;
      return 0;
    }
    v11[6] = v19;
  }
  else
  {
    v11[1] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v11[6] = 3;
  }
  return (((char *)v11 - (char *)KdpBreakpointTable) >> 5) + 1;
}
