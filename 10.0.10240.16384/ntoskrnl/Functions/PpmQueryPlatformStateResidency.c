// PpmQueryPlatformStateResidency 
 
int __fastcall PpmQueryPlatformStateResidency(unsigned int a1)
{
  int v1; // r6
  unsigned int v3; // r4
  unsigned int *v4; // r0
  unsigned int *v5; // r7
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r2
  int v10; // r3
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r4
  __int16 v16; // r3

  v1 = -1;
  if ( PpmPlatformStates )
  {
    if ( *(_DWORD *)(PpmPlatformStates + 28) )
    {
      v3 = *(_DWORD *)PpmPlatformStates;
      if ( a1 != -1 && a1 < v3 )
      {
        v4 = (unsigned int *)ExAllocatePoolWithTag(512, 16 * v3 + 8, 1766674512);
        v5 = v4;
        if ( v4 )
        {
          memset(v4, 0, 16 * v3 + 8);
          *v5 = v3;
          v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v6 + 308);
          v7 = KeAbPreAcquire(&PpmIdlePolicyLock, 0, 0);
          do
            v8 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
          while ( !v8 && __strex(0x11u, (unsigned int *)&PpmIdlePolicyLock) );
          __dmb(0xBu);
          if ( v8 )
            return sub_5290D8(v7, 17);
          if ( v7 )
            *(_BYTE *)(v7 + 14) |= 1u;
          v10 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1100);
          if ( v10
            && (*(int (__fastcall **)(_DWORD, unsigned int *))(PpmPlatformStates + 28))(*(_DWORD *)(v10 + 120), v5) >= 0 )
          {
            v1 = v5[4 * a1 + 2];
          }
          dword_61E89C = 0;
          __pld(&PpmIdlePolicyLock);
          v11 = PpmIdlePolicyLock;
          if ( (PpmIdlePolicyLock & 0xFFFFFFF0) > 0x10 )
            v12 = PpmIdlePolicyLock - 16;
          else
            v12 = 0;
          if ( (PpmIdlePolicyLock & 2) != 0 )
            goto LABEL_30;
          __dmb(0xBu);
          do
            v13 = __ldrex((unsigned int *)&PpmIdlePolicyLock);
          while ( v13 == v11 && __strex(v12, (unsigned int *)&PpmIdlePolicyLock) );
          if ( v13 != v11 )
LABEL_30:
            ExfReleasePushLock(&PpmIdlePolicyLock);
          v14 = KeAbPostRelease(&PpmIdlePolicyLock);
          v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v16 = *(_WORD *)(v15 + 0x134) + 1;
          *(_WORD *)(v15 + 308) = v16;
          if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
            KiCheckForKernelApcDelivery(v14);
          ExFreePoolWithTag(v5, 1766674512);
        }
      }
    }
  }
  return v1;
}
