// MiShowBadMapper 
 
int __fastcall MiShowBadMapper(int result, char a2)
{
  int v2; // r7
  int v3; // r4
  unsigned int v4; // r5
  unsigned int *v5; // r6
  unsigned int v6; // r0
  unsigned int v7; // t1
  int *v8; // r0
  char v9[4]; // [sp+8h] [bp-40h] BYREF
  char v10[4]; // [sp+Ch] [bp-3Ch] BYREF
  char v11[56]; // [sp+10h] [bp-38h] BYREF

  v2 = result;
  v3 = (unsigned __int8)byte_63442A;
  if ( !byte_63442A )
  {
    if ( (a2 & 1) != 0 && !KdPitchDebugger && !KdDebuggerNotPresent )
LABEL_14:
      KeBugCheckEx(26, 4659, v2, 0, 0);
    memset(v11, 0, 32);
    RtlCaptureStackBackTrace(1u, 8u, (int)v11, (int)v10);
    MmLockLoadedModuleListExclusive(v9);
    v4 = 0;
    v5 = (unsigned int *)v11;
    do
    {
      v7 = *v5++;
      v6 = v7;
      if ( v7 <= MmHighestUserAddress )
        break;
      v8 = MiLookupDataTableEntry(v6, 1);
      if ( v8 && (v8[13] & 0x2000000) != 0 )
      {
        v3 = 1;
        break;
      }
      ++v4;
    }
    while ( v4 < 8 );
    result = MmUnlockLoadedModuleListExclusive((unsigned __int8)v9[0]);
  }
  if ( v3 == 1 )
    goto LABEL_14;
  return result;
}
