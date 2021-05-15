// PopPolicySystemIdle 
 
int PopPolicySystemIdle()
{
  int v0; // r5
  int v1; // r6
  int v2; // r2
  int v3; // r3
  int v4; // r7
  int v5; // r8
  BOOL v6; // r0
  char v7; // r7
  char v8; // r0
  int v9; // r0
  int v11; // [sp+20h] [bp-78h] BYREF
  int v12; // [sp+24h] [bp-74h]
  int v13; // [sp+28h] [bp-70h]
  int v14; // [sp+2Ch] [bp-6Ch]
  char v15[20]; // [sp+30h] [bp-68h] BYREF
  unsigned __int8 v16; // [sp+44h] [bp-54h]

  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v0 = 0;
  v1 = 0;
  PopAcquirePolicyLock();
  PopIdleCheckForUserInput();
  PopFilterCapabilities((int)&PopCapabilities, v15, v2, v3);
  v4 = v16;
  v5 = 0;
  if ( !v16 && dword_61E838 && dword_61E808 - dword_61E838 < (unsigned int)dword_61EC20 )
    v5 = 1;
  if ( !dword_61E80C || dword_61E808 < (unsigned int)dword_61E80C || v5 || PopUserShutdownInProgress )
    goto LABEL_14;
  if ( v16 )
  {
    if ( PopGetConsoleDisplayRequestCount() )
      goto LABEL_14;
  }
  else if ( dword_61E824 )
  {
    goto LABEL_22;
  }
  v0 = 1;
LABEL_14:
  if ( v4 && dword_61E814 == 2 && dword_61E820 == 1 )
    v1 = 1;
  if ( v0 )
  {
    if ( !v1 )
      PopResetIdleTime(5);
    byte_61E829 = 0;
  }
LABEL_22:
  v6 = PopIdleIsDozeS4Enabled(v15);
  v7 = v6;
  if ( v0 && v1 && v6 )
    v8 = PopIdleArmAoAcDozeS4Timer();
  else
    v8 = 0;
  PopTraceSystemIdleUpdate(
    dword_61E808,
    v0,
    dword_61E824 != 0,
    v5,
    PopUserShutdownInProgress,
    v7,
    *(_DWORD *)(PopPolicy + 88),
    v1,
    v8,
    dword_61E814,
    dword_61E820);
  if ( !v0 )
    goto LABEL_30;
  if ( !v1 )
  {
    v11 = 7;
    v12 = 128;
    PopExecutePowerAction(&v11, 0, &dword_61E814, dword_61E820, 1);
LABEL_30:
    PopReleasePolicyLock();
    goto LABEL_31;
  }
  v9 = PopReleasePolicyLock();
  dword_61EACC(v9);
LABEL_31:
  if ( !v0 )
    PopIdleDetection();
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
  return 0;
}
