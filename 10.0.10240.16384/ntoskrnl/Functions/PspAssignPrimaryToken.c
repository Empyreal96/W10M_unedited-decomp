// PspAssignPrimaryToken 
 
int __fastcall PspAssignPrimaryToken(int a1, char a2, int a3, int a4)
{
  int v5; // r7
  int v7; // r5
  int v8; // r0
  int v9; // r4
  int v10; // r8
  unsigned int *v11; // r7
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r2
  __int16 v17; // r3
  int v18; // r3
  int v19; // r7
  __int16 v20; // r3
  int v21; // r1
  int v22; // r2
  int v23; // r3
  bool v25; // [sp+10h] [bp-30h] BYREF
  int v26; // [sp+14h] [bp-2Ch] BYREF
  int v27; // [sp+18h] [bp-28h] BYREF
  int v28[9]; // [sp+1Ch] [bp-24h] BYREF

  v5 = a2;
  v7 = ObReferenceObjectByHandle(a4, 1, SeTokenObjectType, a2, (int)&v26, 0);
  if ( v7 >= 0 )
  {
    v7 = SeIsTokenAssignableToProcess(v26, &v25);
    if ( v7 >= 0 )
    {
      if ( v25 || SeCheckPrivilegedObject(SeAssignPrimaryTokenPrivilege, dword_9227D4, a3, 512, v5) )
      {
        v8 = ObReferenceObjectByHandleWithTag(a3, 512, PsProcessType, v5, 1699967824, v28, 0);
        v7 = v8;
        if ( v8 >= 0 )
        {
          v9 = v28[0];
          v10 = 0;
          v27 = 0;
          if ( (*(_DWORD *)(v28[0] + 188) & 0x8000) != 0 )
          {
            v7 = -1073741637;
          }
          else
          {
            --*(_WORD *)(a1 + 308);
            v11 = (unsigned int *)(v9 + 168);
            v12 = KeAbPreAcquire(v9 + 168, 0, 0);
            v13 = v12;
            do
              v14 = __ldrex(v11);
            while ( !v14 && __strex(0x11u, v11) );
            __dmb(0xBu);
            if ( v14 )
              ExfAcquirePushLockSharedEx((_DWORD *)(v9 + 168), v12, v9 + 168);
            if ( v13 )
              *(_BYTE *)(v13 + 14) |= 1u;
            if ( (*(_DWORD *)(v9 + 188) & 0x8000) != 0 )
            {
              v7 = -1073741637;
            }
            else
            {
              v15 = SeExchangePrimaryToken(v9, v26, &v27);
              v10 = v27;
              v7 = v15;
            }
            __dmb(0xBu);
            do
              v16 = __ldrex(v11);
            while ( v16 == 17 && __strex(0, v11) );
            if ( v16 != 17 )
              ExfReleasePushLockShared((_DWORD *)(v9 + 168));
            v8 = KeAbPostRelease(v9 + 168);
            v17 = *(_WORD *)(a1 + 308) + 1;
            *(_WORD *)(a1 + 308) = v17;
            if ( !v17 && *(_DWORD *)(a1 + 100) != a1 + 100 && !*(_WORD *)(a1 + 310) )
              v8 = KiCheckForKernelApcDelivery(v8);
          }
          if ( v7 >= 0 )
          {
            --*(_WORD *)(a1 + 308);
            __dmb(0xFu);
            v18 = *(_DWORD *)(v9 + 168);
            __dmb(0xBu);
            if ( (v18 & 1) != 0 )
            {
              v19 = KeAbPreAcquire(v9 + 168, 0, 0);
              ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 168), v19, v9 + 168);
              if ( v19 )
                *(_BYTE *)(v19 + 14) |= 1u;
              v8 = (int)ExfReleasePushLockExclusive((unsigned int *)(v9 + 168));
              if ( v19 )
                v8 = KeAbPostRelease(v9 + 168);
            }
            v20 = *(_WORD *)(a1 + 308) + 1;
            *(_WORD *)(a1 + 308) = v20;
            if ( !v20 && *(_DWORD *)(a1 + 100) != a1 + 100 && !*(_WORD *)(a1 + 310) )
              KiCheckForKernelApcDelivery(v8);
            ObfDereferenceObject(v10);
            ObDereferenceDeviceMap(v9, v21, v22, v23);
          }
          ObfDereferenceObjectWithTag(v9);
        }
      }
      else
      {
        v7 = -1073741727;
      }
    }
    ObfDereferenceObject(v26);
  }
  return v7;
}
