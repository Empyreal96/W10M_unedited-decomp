// VerifierMmMapIoSpace 
 
int __fastcall VerifierMmMapIoSpace(__int64 a1, int a2, int a3)
{
  unsigned int v5; // r0
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v11; // r3
  int v12; // r0
  int vars4; // [sp+1Ch] [bp+4h]
  int varg_r2; // [sp+28h] [bp+10h]
  int varg_r3; // [sp+2Ch] [bp+14h]

  varg_r2 = a2;
  varg_r3 = a3;
  v5 = KeGetCurrentIrql(a1);
  if ( v5 > 2 )
    VerifierBugCheckIfAppropriate(196, 115, v5, a1, a2);
  MmCheckMapIoSpace(a1, a2, v6);
  if ( VfFaultsInjectResourceFailure(0, v7, v8, v9) == 1 )
    return 0;
  if ( (MmVerifierData & 0x2000000) != 0 )
  {
    v11 = 4;
    if ( a3 != 1 )
    {
      if ( a3 == 2 )
        v11 = 1028;
      else
        v11 = 516;
    }
    v12 = MmMapIoSpaceEx(a1, SHIDWORD(a1), a2, v11);
  }
  else
  {
    v12 = pXdvMmMapIoSpace(a1, HIDWORD(a1), a2, a3);
  }
  v10 = v12;
  if ( VfPoolTraces )
    ViPoolLogStackTrace(v12, a2);
  if ( v10 && (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 112, 116, a2);
  return v10;
}
