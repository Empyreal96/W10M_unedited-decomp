// SepBlockAccessForLogonSession 
 
int __fastcall SepBlockAccessForLogonSession(_DWORD *a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r2
  _DWORD *i; // r4
  int v6; // r0
  unsigned int v7; // r1
  __int16 v8; // r3
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v2 = *a1 & 0xF;
  v3 = SepLogonSessions;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (v2 & 3), 1, v4, v2 & 3);
  for ( i = *(_DWORD **)(v3 + 4 * v2); ; i = (_DWORD *)*i )
  {
    if ( !i )
    {
      v6 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v2 & 3));
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v8 = *(_WORD *)(v7 + 0x134) + 1;
      *(_WORD *)(v7 + 308) = v8;
      if ( !v8 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
        KiCheckForKernelApcDelivery(v6);
      return -1073741729;
    }
    if ( PsEqualCurrentServerSilo(i[22]) && *a1 == i[1] && a1[1] == i[2] )
      break;
  }
  i[6] |= 0x20u;
  v10 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (v2 & 3));
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return 0;
}
