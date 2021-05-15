// NtFlushInstructionCache 
 
int __fastcall NtFlushInstructionCache(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v6; // r3
  unsigned int v7; // r2
  int v8; // r6
  int result; // r0
  int v10[3]; // [sp+14h] [bp-44h] BYREF
  _DWORD _20[20]; // [sp+20h] [bp-38h] BYREF

  _20[16] = a1;
  _20[17] = a2;
  _20[19] = a4;
  _20[18] = a3;
  v10[0] = a1;
  v10[2] = a2;
  if ( !a2 || a3 )
  {
    v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( a2 )
    {
      if ( v6 )
      {
        if ( a3 )
        {
          v7 = a2 + a3;
          if ( a2 + a3 > MmUserProbeAddress || v7 < a2 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
    }
    v8 = 0;
    v10[0] = 0;
    if ( a1 != -1 )
    {
      result = ObReferenceObjectByHandleWithTag(a1, 32, PsProcessType, v6, 1816554829, v10, 0);
      if ( result < 0 )
        return result;
      v8 = v10[0];
      KiStackAttachProcess(v10[0], 0, (int)_20);
    }
    if ( a2 )
      KeSweepIcacheRange(0, a2, a3);
    else
      KeSweepIcache();
    if ( v8 )
    {
      KiUnstackDetachProcess((unsigned int)_20, 0);
      ObfDereferenceObjectWithTag(v8);
    }
  }
  return 0;
}
