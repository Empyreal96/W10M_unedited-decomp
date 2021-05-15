// MmProbeAndLockPages 
 
int __fastcall MmProbeAndLockPages(int a1)
{
  int v2; // r0
  _DWORD *v3; // r1
  int v4; // r4
  _DWORD *v5; // r1
  int v6; // r2
  int result; // r0
  int v8[2]; // [sp+10h] [bp-58h] BYREF
  int v9; // [sp+18h] [bp-50h]
  unsigned int v10; // [sp+1Ch] [bp-4Ch]
  _DWORD *v11; // [sp+20h] [bp-48h]
  int v12; // [sp+28h] [bp-40h]
  int v13; // [sp+44h] [bp-24h]

  while ( 1 )
  {
    v2 = MiProbeAndLockPrepare((char)v8, a1, *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 16));
    if ( v2 < 0 )
      RtlRaiseStatus(v2);
    v3 = v11;
    do
    {
      *v3 = -1;
      v4 = MiProbeLeafFrame(v8);
      if ( v4 < 0 )
        break;
      v4 = MiProbeLockFrame(v8);
      if ( v4 < 0 )
        break;
      v5 = v11;
      v6 = v9;
      *v11 = v13;
      v3 = v5 + 1;
      v11 = v3;
      v8[0] += 4096;
      v9 = v6 + 4;
    }
    while ( v6 + 4 <= v10 );
    result = MiUnlockProbePacketWorkingSet(v8);
    if ( (MmTrackLockedPages & 1) != 0 )
      break;
    if ( v4 >= 0 )
      return result;
    MmUnlockPages(v12);
    ++dword_6343E8;
    if ( v4 != -1073741267 )
      RtlRaiseStatus(v4);
  }
  return sub_545114(result);
}
