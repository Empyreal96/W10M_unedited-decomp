// NtStartProfile 
 
int __fastcall NtStartProfile(int a1)
{
  int v1; // r4
  int *v2; // r5
  unsigned int v3; // r0
  int v4; // r0
  unsigned int v5; // r8
  int v6; // r4
  int v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r4
  int *v12; // [sp+18h] [bp-30h] BYREF
  int v13; // [sp+1Ch] [bp-2Ch]
  int v14; // [sp+20h] [bp-28h]
  int v15; // [sp+24h] [bp-24h]

  v13 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v1 = ObReferenceObjectByHandle(a1, 1, ExProfileObjectType, v13, (int)&v12, 0);
  if ( v1 >= 0 )
  {
    KeWaitForSingleObject((unsigned int)&ExpProfileStateMutex, 0, 0, 0, 0);
    v2 = v12;
    if ( v12[7] )
    {
      v1 = -1073741640;
    }
    else if ( ExpCurrentProfileUsage == KeNumberProcessors_0 << 13 )
    {
      v1 = -1073741613;
    }
    else
    {
      v3 = MmSizeOfMdl(v12[3], v12[4]);
      v4 = ExAllocatePoolWithTag(512, v3 + 52, 1718579792);
      v5 = v4;
      v14 = v4;
      if ( v4 )
      {
        v15 = v4 + 52;
        v2[8] = v4 + 52;
        v2[6] = v4;
        v6 = v2[4];
        v7 = v2[3];
        *(_DWORD *)(v5 + 52) = 0;
        v8 = v7 & 0xFFF;
        *(_WORD *)(v5 + 56) = 4 * (((unsigned int)(v8 + v6 + 4095) >> 12) + 7);
        *(_WORD *)(v5 + 58) = 0;
        *(_DWORD *)(v5 + 68) = v7 & 0xFFFFF000;
        *(_DWORD *)(v5 + 76) = v8;
        *(_DWORD *)(v5 + 72) = v6;
        MmProbeAndLockPages(v5 + 52);
        v9 = MmMapLockedPagesSpecifyCache(v2[8], 0, 1, 0, 0, 1073741840);
        v10 = v9;
        if ( v9 )
        {
          KeInitializeProfile((_DWORD *)v5, *v2, v9, v2[1], v2[2], v2[5], v2[9], v2[10], (int)(v2 + 11));
          KeStartProfile(v5);
          v2[7] = v10;
          ++ExpCurrentProfileUsage;
          KeReleaseMutex((int)&ExpProfileStateMutex);
          ObfDereferenceObject((int)v2);
          return 0;
        }
        KeReleaseMutex((int)&ExpProfileStateMutex);
        MmUnlockPages(v5 + 52);
        ExFreePoolWithTag(v5);
        v1 = -1073741670;
        goto LABEL_11;
      }
      v1 = -1073741670;
    }
    KeReleaseMutex((int)&ExpProfileStateMutex);
LABEL_11:
    ObfDereferenceObject((int)v2);
  }
  return v1;
}
