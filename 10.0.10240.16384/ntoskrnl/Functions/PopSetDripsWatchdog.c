// PopSetDripsWatchdog 
 
void PopSetDripsWatchdog()
{
  int v0; // r2
  int v1; // r3
  __int64 v2; // r0
  int v3; // r5
  int v4; // r6
  int v5; // r0
  int v6; // r1
  int v7; // r3
  _DWORD v8[2]; // [sp+10h] [bp-28h] BYREF
  int v9; // [sp+18h] [bp-20h]
  int v10; // [sp+1Ch] [bp-1Ch]
  int v11; // [sp+20h] [bp-18h]

  if ( PopDripsWatchdog )
  {
    v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v1 = *(__int16 *)(v0 + 0x134) - 1;
    *(_WORD *)(v0 + 308) = v1;
    ExAcquireResourceExclusiveLite((int)&byte_637480[24], 1, v0, v1);
    unk_637468 = 0;
    unk_63746C = 0;
    LODWORD(v2) = KeQueryInterruptTime();
    v3 = HIDWORD(v2);
    v4 = v2;
    if ( !qword_637460 )
    {
      qword_637460 = v2;
      PopCalculateIdleInformation((int)v8);
      dword_637450 = v9;
      dword_637454 = v10;
      dword_637448 = v11;
    }
    if ( !unk_637458 )
    {
      unk_637458 = v4;
      unk_63745C = v3;
      dword_63744C = dword_61ED88;
    }
    if ( !*(_QWORD *)&dword_637470 )
    {
      dword_637470 = dword_6353E8;
      dword_637474 = dword_6353EC;
    }
    unk_637478 = 0;
    unk_63747C = 0;
    v8[0] = 0;
    v8[1] = 0;
    v9 = -1;
    v10 = -1;
    KeSetTimer2((int *)&byte_637480[80], -10000000i64 * (unsigned int)PopDripsWatchdog, 0i64, (int)v8);
    v5 = ExReleaseResourceLite((int)&byte_637480[24]);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7 = (__int16)(*(_WORD *)(v6 + 0x134) + 1);
    *(_WORD *)(v6 + 308) = v7;
    if ( !v7 )
      sub_7BF148(v5, v6);
  }
}
