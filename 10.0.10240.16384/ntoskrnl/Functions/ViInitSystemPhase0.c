// ViInitSystemPhase0 
 
_BYTE *__fastcall ViInitSystemPhase0(int a1)
{
  _BYTE *result; // r0
  int v3; // r1
  unsigned int v4; // r0
  int v5; // r2
  __int16 *v6; // r1
  __int16 *v7; // r5
  int v8; // r3
  __int16 *i; // r4
  int v10; // r3
  int v11; // r6
  unsigned int v12; // r8
  unsigned int v13; // r0
  int v14; // r3
  int v15; // r3
  unsigned int v16; // r2
  unsigned int v17; // r3
  unsigned __int16 v18[2]; // [sp+0h] [bp-30h] BYREF
  __int16 *v19; // [sp+4h] [bp-2Ch]
  int v20[10]; // [sp+8h] [bp-28h] BYREF

  if ( (VfOptionFlags & 0xFFFFFC00) != 0 )
    return (_BYTE *)sub_96EE24();
  if ( (VfOptionFlags & 4) != 0 )
    MmVerifierTrimFrequency = 7;
  if ( (VfOptionFlags & 0x80) != 0 )
    VfDisableCodeIntegrityBreaks();
  KiInitializeMutant((int)&ViDriversLoadLock, 0, 1);
  VfSuspectDriversList = (int)&VfSuspectDriversList;
  dword_61D36C = (int)&VfSuspectDriversList;
  VfExcludedDriversList = (int)&VfExcludedDriversList;
  dword_61CF0C = (int)&VfExcludedDriversList;
  VfXdvExcludedDriversList = (int)&VfXdvExcludedDriversList;
  dword_61CF14 = (int)&VfXdvExcludedDriversList;
  if ( VfVerifyMode == -1 )
  {
    VfVerifyMode = 4;
    __dmb(0xBu);
    dword_620DEC = 4;
  }
  result = strstr(*(_BYTE **)(a1 + 120), "SAFEBOOT:");
  if ( result )
  {
    MmVerifyDriverLevel = 0;
    MmVerifyDriverBufferLength = -1;
    ViVerifyAllDrivers = 0;
    VfSafeMode = 1;
    return result;
  }
  VfTriageSystem(a1);
  result = (_BYTE *)KeQueryPerformanceCounter(v20, 0);
  ViRandomSeed = v20[0];
  if ( MmVerifyDriverLevel != -1 && MmVerifyDriverBufferLength == -1 )
  {
    v4 = wcslen(L"*");
    result = (_BYTE *)VfInitSetVerifyDriverTargets(L"*", 2 * (v4 + 1));
  }
  v3 = ViVerifyAllDrivers;
  if ( ViVerifyAllDrivers == 1 )
    goto LABEL_21;
  if ( ViVerifyAllDrivers == 2 )
  {
    KernelVerifier = 1;
    v3 = 1;
    ViForceAllDriversSuspect = 1;
    ViVerifyAllDrivers = 1;
LABEL_21:
    MmVerifyDriverBufferLength = 0;
    goto LABEL_22;
  }
  if ( MmVerifyDriverBufferLength != -1 )
  {
LABEL_22:
    v5 = 0;
    VfRandomVerifiedDrivers = 0;
    goto LABEL_23;
  }
  if ( !VfRandomVerifiedDrivers )
    return result;
  result = (_BYTE *)VfRandomGetNumber(0, 0xFu);
  if ( (unsigned int)result < 8 )
  {
    VfRandomVerifiedDrivers = 0;
    return result;
  }
  VfRandomTargetsBitMapHeader = 256;
  dword_90800C = (int)&VfRandomTargetsBitMap;
  RtlClearAllBits((int)&VfRandomTargetsBitMapHeader);
  v10 = VfRandomVerifiedDrivers;
  if ( (unsigned int)VfRandomVerifiedDrivers > 0x100 )
  {
    v10 = 256;
    VfRandomVerifiedDrivers = 256;
  }
  v11 = 0;
  v12 = 0;
  if ( v10 )
  {
    do
    {
      v13 = VfRandomGetNumber(1u, 0xFFu);
      if ( ((*(char *)((v13 >> 3) + dword_90800C) >> (v13 & 7)) & 1) != 0 )
        ++v11;
      else
        *(_BYTE *)((v13 >> 3) + dword_90800C) |= 1 << (v13 & 7);
      v10 = VfRandomVerifiedDrivers;
      ++v12;
    }
    while ( v12 < VfRandomVerifiedDrivers );
  }
  v5 = v10 - v11;
  VfRandomVerifiedDrivers = v10 - v11;
  MmVerifyDriverLevel = 1;
  MmVerifyDriverBufferLength = 0;
  if ( VfVerifyMode > 2 )
  {
    VfSetVerifierRunningMode(2);
    v5 = VfRandomVerifiedDrivers;
  }
  v3 = ViVerifyAllDrivers;
LABEL_23:
  if ( (VfOptionFlags & 1) != 0 && !v5 )
  {
LABEL_70:
    ViVerifyAllDrivers = 1;
  }
  else if ( !v3 && !v5 )
  {
    v6 = MmVerifyDriverBuffer;
    v7 = &MmVerifyDriverBuffer[(unsigned int)(MmVerifyDriverBufferLength - 2) >> 1];
    if ( MmVerifyDriverBuffer < v7 )
    {
      do
      {
        v8 = (unsigned __int16)*v6;
        if ( v8 == 9 || v8 == 10 || v8 == 13 || v8 == 32 || v8 == 12288 || !*v6 )
        {
          ++v6;
        }
        else
        {
          if ( v8 == 42 )
            goto LABEL_70;
          if ( v8 == 34 )
          {
            i = ++v6 + 1;
            if ( v6 + 1 >= v7 )
              return (_BYTE *)VfInitSystemNoRebootNeeded(KernelVerifier, 1);
            do
            {
              if ( *i == 34 )
                break;
              ++i;
            }
            while ( i < v7 );
            if ( i >= v7 )
              return (_BYTE *)VfInitSystemNoRebootNeeded(KernelVerifier, 1);
          }
          else
          {
            for ( i = v6 + 1; i < v7; ++i )
            {
              v14 = (unsigned __int16)*i;
              if ( v14 == 9 || v14 == 10 || v14 == 13 || v14 == 32 || v14 == 12288 || !*i )
                break;
            }
          }
          v15 = 2 * (i - v6);
          if ( v15 )
          {
            v16 = (unsigned __int16)v15;
            v17 = (unsigned __int16)(v15 + 2);
            v18[1] = v17;
            v18[0] = v16;
            if ( v17 < v16 )
              return (_BYTE *)VfInitSystemNoRebootNeeded(KernelVerifier, 1);
            v19 = v6;
            if ( RtlEqualUnicodeString((unsigned __int16 *)&VfKernelImageName, v18, 1) )
            {
              KernelVerifier = 1;
              return (_BYTE *)VfInitSystemNoRebootNeeded(KernelVerifier, 1);
            }
          }
          v6 = i + 1;
        }
      }
      while ( v6 < v7 );
    }
  }
  return (_BYTE *)VfInitSystemNoRebootNeeded(KernelVerifier, 1);
}
