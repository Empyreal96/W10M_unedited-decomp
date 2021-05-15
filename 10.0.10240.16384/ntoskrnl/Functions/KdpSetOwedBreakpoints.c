// KdpSetOwedBreakpoints 
 
unsigned int __fastcall KdpSetOwedBreakpoints(unsigned int result)
{
  int v1; // r9
  int v2; // r5
  int v3; // r6
  int *v4; // r4
  __int64 v5; // r2
  unsigned int v6; // r5
  int v7; // r3
  unsigned int v8; // r1
  int v9; // r0
  int v10; // r1
  int v11; // r6
  int v12; // r7
  int v13; // r3
  int v14; // r0
  int v15; // [sp+8h] [bp-30h]
  int v16; // [sp+10h] [bp-28h] BYREF
  int v17; // [sp+14h] [bp-24h]

  v16 = 0;
  v17 = 0;
  if ( KdpOweBreakpoint )
  {
    v1 = KdpBreakpointChangeCount;
    __dmb(0xBu);
    v2 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v3 = 0;
    result &= 0xFFFFF000;
    v4 = KdpBreakpointTable;
    v15 = v2;
    LODWORD(v5) = KdpBreakpointTable;
    do
    {
      if ( (*(_DWORD *)(v5 + 24) & 0xA) != 0
        && (*(_DWORD *)v5 >= (unsigned int)MmSystemRangeStart || *(_DWORD *)(v5 + 4) == v2) )
      {
        v6 = *(_DWORD *)v5 & ~*(unsigned __int8 *)(v5 + 29);
        if ( v6 >= result )
        {
          HIDWORD(v5) = result + 4096;
          if ( v6 < result + 4096 )
            goto LABEL_14;
        }
        v7 = *(unsigned __int8 *)(v5 + 28);
        v8 = v7 + v6;
        if ( v7 + v6 >= v6 && v8 > result )
        {
          HIDWORD(v5) = result + 4096;
          if ( v8 <= result + 4096 )
            goto LABEL_14;
        }
        v2 = v15;
      }
      ++v3;
      LODWORD(v5) = v5 + 32;
    }
    while ( v3 < 32 );
    HIDWORD(v5) = KdpBreakpointChangeCount;
    __dmb(0xBu);
    if ( v1 == HIDWORD(v5) )
      return result;
LABEL_14:
    v9 = KdEnterDebugger(0, 0, v5);
    v11 = 32;
    KdpOweBreakpoint = 0;
    v12 = v9;
    do
    {
      v13 = v4[6];
      if ( (v13 & 0xA) != 0 )
      {
        if ( *v4 >= (unsigned int)MmSystemRangeStart || v4[1] == v15 )
        {
          if ( KdpCopyCodeStream(*v4 & ~*((unsigned __int8 *)v4 + 29), 0, (int)&v16, *((unsigned __int8 *)v4 + 28), 4) >= 0 )
          {
            if ( (v4[6] & 2) != 0 )
            {
              v4[4] = v16;
              v4[5] = v17;
              v14 = KdpInsertBreakpoint(v4, &v16);
              if ( v14 )
                v4[6] = v14;
            }
            else
            {
              KdpRemoveBreakpoint(v4, &v16);
            }
          }
        }
        else
        {
          v13 = 1;
          KdpOweBreakpoint = 1;
        }
      }
      v4 += 8;
      --v11;
    }
    while ( v11 );
    result = KdExitDebugger(v12, v10, 10, v13);
  }
  return result;
}
