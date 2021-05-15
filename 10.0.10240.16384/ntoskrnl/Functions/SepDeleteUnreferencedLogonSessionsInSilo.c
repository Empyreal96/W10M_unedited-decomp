// SepDeleteUnreferencedLogonSessionsInSilo 
 
int __fastcall SepDeleteUnreferencedLogonSessionsInSilo(int a1, int a2, int a3, int a4)
{
  int v5; // r8
  unsigned int i; // r5
  int v7; // r4
  int v8; // r2
  _DWORD *j; // r2
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19; // [sp+0h] [bp-28h] BYREF
  int v20; // [sp+4h] [bp-24h]
  int v21; // [sp+8h] [bp-20h]

  v19 = a2;
  v20 = a3;
  v21 = a4;
  v5 = PsAttachSiloToCurrentThread(a1);
  for ( i = 0; i < 0x10; ++i )
  {
    v7 = SepLogonSessions;
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (i & 3), 1, v8, i & 3);
    for ( j = *(_DWORD **)(v7 + 4 * i); j; j = (_DWORD *)*j )
    {
      if ( j[22] == a1 && !j[5] )
      {
        v19 = j[1];
        v20 = j[2];
        v10 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (i & 3));
        v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v12 = *(_WORD *)(v11 + 0x134) + 1;
        *(_WORD *)(v11 + 308) = v12;
        if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
          KiCheckForKernelApcDelivery(v10);
        SepDeleteLogonSessionTrack(&v19, 0);
        v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v14 = *(__int16 *)(v13 + 0x134) - 1;
        *(_WORD *)(v13 + 308) = v14;
        ExAcquireResourceExclusiveLite((int)&SepRmDbLock + 56 * (i & 3), 1, v13, v14);
        j = (_DWORD *)(SepLogonSessions + 4 * i);
      }
    }
    v15 = ExReleaseResourceLite((int)&SepRmDbLock + 56 * (i & 3));
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
  }
  return PsDetachSiloFromCurrentThread(v5);
}
