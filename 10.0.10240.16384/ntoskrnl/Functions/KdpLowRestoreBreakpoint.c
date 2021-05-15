// KdpLowRestoreBreakpoint 
 
int __fastcall KdpLowRestoreBreakpoint(int a1)
{
  int v1; // r3
  int *v2; // r4
  int v3; // r3
  unsigned int v4; // r3
  int v5; // r3
  int v7; // r0
  _DWORD v8[4]; // [sp+8h] [bp-10h] BYREF

  v8[0] = 0;
  v8[1] = 0;
  v1 = KdpBreakpointChangeCount + 1;
  __dmb(0xBu);
  KdpBreakpointChangeCount = v1;
  v2 = &KdpBreakpointTable[8 * a1];
  v3 = v2[6];
  if ( (v3 & 8) == 0 )
  {
    if ( (v3 & 0x10) == 0 && KdpIsBreakpoint((int)&KdpBreakpointTable[8 * a1], v2 + 4) )
      return 1;
    if ( KdpCopyCodeStream(*v2 & ~*((unsigned __int8 *)v2 + 29), 0, (int)v8, *((unsigned __int8 *)v2 + 28), 4) >= 0 )
    {
      v7 = KdpInsertBreakpoint(v2, v8);
      v5 = v2[6];
      if ( v7 )
      {
        v4 = v2[6] ^ ((unsigned __int8)v5 ^ (unsigned __int8)v7) & 2;
        goto LABEL_10;
      }
    }
    else
    {
      v5 = v2[6];
    }
    v2[6] = v5 | 2;
    return 0;
  }
  v4 = v3 & 0xFFFFFFF7;
LABEL_10:
  v2[6] = v4;
  return 1;
}
