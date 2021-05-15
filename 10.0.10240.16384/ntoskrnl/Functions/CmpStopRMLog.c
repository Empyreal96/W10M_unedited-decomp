// CmpStopRMLog 
 
void __fastcall CmpStopRMLog(_DWORD *a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r1
  int v5; // r0
  unsigned int v6; // r1
  __int16 v7; // r3

  CmpLockRegistry();
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite(a1[20], 1, v2, v3);
  if ( a1[13] )
  {
    if ( a1[14] )
    {
      CmpLogCheckpoint(a1, v4, 0);
      ClfsDeleteMarshallingArea(a1[14]);
      a1[14] = 0;
    }
    if ( a1 != (_DWORD *)CmRmSystem && (_DWORD *)a1[2] == a1 + 2 )
      ClfsDeleteLogByPointer(a1[13]);
    ClfsCloseLogFileObject(a1[13], v4);
    a1[13] = 0;
  }
  v5 = ExReleaseResourceLite(a1[20]);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery(v5);
  CmpUnlockRegistry();
}
