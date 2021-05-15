// PopCancelDripsWatchdog 
 
void PopCancelDripsWatchdog()
{
  int v0; // r2
  int v1; // r3
  int v2; // r0
  int v3; // r1
  int v4; // r3

  if ( PopDripsWatchdog )
  {
    v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v1 = *(__int16 *)(v0 + 0x134) - 1;
    *(_WORD *)(v0 + 308) = v1;
    ExAcquireResourceExclusiveLite((int)&byte_637480[24], 1, v0, v1);
    KeCancelTimer2((int)&byte_637480[80]);
    dword_637448 = 0;
    dword_637450 = 0;
    dword_637454 = 0;
    unk_637458 = 0;
    unk_63745C = 0;
    dword_63744C = 0;
    unk_637460 = 0;
    unk_637464 = 0;
    unk_637468 = 0;
    unk_63746C = 0;
    dword_637470 = 0;
    dword_637474 = 0;
    unk_637478 = 0;
    unk_63747C = 0;
    memset(byte_637480, 0, 24);
    v2 = ExReleaseResourceLite((int)&byte_637480[24]);
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = (__int16)(*(_WORD *)(v3 + 0x134) + 1);
    *(_WORD *)(v3 + 308) = v4;
    if ( !v4 )
      sub_7BF128(v2, v3);
  }
}
