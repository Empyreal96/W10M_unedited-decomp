// MiCheckControlArea 
 
int __fastcall MiCheckControlArea(_DWORD *a1, int a2)
{
  int v3; // r5
  _DWORD *v5; // r9
  int v7; // r3
  int v8; // r3
  _DWORD *v9; // r4
  int var30[13]; // [sp+0h] [bp-30h] BYREF

  var30[1] = 0;
  var30[2] = 0;
  var30[3] = 0;
  var30[0] = -1;
  v3 = 0;
  v5 = 0;
  if ( a1[5] || a1[3] )
  {
    if ( a1[11] )
      v3 = 4;
  }
  else if ( (a1[8] & 0xFFFFFFF8) != 0 )
  {
    v7 = a1[7];
    if ( a1[4] )
    {
      if ( (v7 & 0x40000) != 0 )
      {
        v3 = 1;
      }
      else
      {
        if ( (v7 & 0x20) == 0 || (v7 & 0x20000) == 0 )
          MiInsertUnusedSegment(a1, a2);
        if ( (a1[7] & 0x20) != 0 )
          MiImageUnused(a1, 1, (int)var30);
      }
      v8 = a1[7];
      if ( (v8 & 0x20) != 0 && (v8 & 0x20000) != 0 )
        return sub_546594();
    }
    else
    {
      a1[7] = v7 | 1;
      v3 = 2;
      MiClearFilePointer((int)a1);
    }
  }
  else
  {
    a1[7] |= 1u;
    v3 = 2;
  }
  if ( (v3 & 4) != 0 )
  {
    v5 = (_DWORD *)MiBuildWakeList(a1, 3);
    v3 &= 0xFFFFFFFB;
  }
  if ( !v3 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
    }
    else
    {
      __dmb(0xBu);
      a1[9] = 0;
    }
    KfLowerIrql(a2);
    if ( v5 )
    {
      do
      {
        v9 = (_DWORD *)*v5;
        KeSignalGate((int)(v5 + 3), 1);
        v5 = v9;
      }
      while ( v9 );
    }
    MiFreeExcessSegments(1);
    return MiReturnImageBase(var30);
  }
  if ( (v3 & 1) != 0 )
  {
    a1[5] = 1;
    MiCleanSection(a1, a2, 0);
    return MiReturnImageBase(var30);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1 + 9);
  }
  else
  {
    __dmb(0xBu);
    a1[9] = 0;
  }
  KfLowerIrql(a2);
  MiSegmentDelete(a1);
  return MiReturnImageBase(var30);
}
