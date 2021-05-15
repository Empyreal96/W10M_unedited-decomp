// KdpLowWriteContent 
 
BOOL __fastcall KdpLowWriteContent(int a1)
{
  int v1; // r3
  int *v2; // r4
  int v3; // r3
  int v5; // r3
  int v6; // r0
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = 0;
  v7[1] = 0;
  v1 = KdpBreakpointChangeCount + 1;
  __dmb(0xBu);
  KdpBreakpointChangeCount = v1;
  v2 = &KdpBreakpointTable[8 * a1];
  v3 = v2[6];
  if ( (v3 & 2) != 0 )
  {
    v2[6] = v3 & 0xFFFFFFFD;
    return 1;
  }
  if ( (v3 & 0x10) == 0 && KdpIsBreakpoint((int)&KdpBreakpointTable[8 * a1], v2 + 4) )
    return 1;
  if ( KdpCopyCodeStream(*v2 & ~*((unsigned __int8 *)v2 + 29), 0, (int)v7, *((unsigned __int8 *)v2 + 28), 4) < 0 )
    goto LABEL_7;
  if ( !KdpIsBreakpoint((int)v2, v7) )
  {
    KdpOweBreakpoint = 1;
LABEL_7:
    v5 = v2[6];
LABEL_8:
    v2[6] = v5 | 8;
    return 0;
  }
  v6 = KdpRemoveBreakpoint(v2, v7);
  v5 = v2[6];
  if ( !v6 )
    goto LABEL_8;
  return (v2[6] & 8) == 0;
}
