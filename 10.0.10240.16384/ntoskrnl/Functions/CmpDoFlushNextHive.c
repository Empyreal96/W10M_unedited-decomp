// CmpDoFlushNextHive 
 
int __fastcall CmpDoFlushNextHive(_BYTE *a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // r8
  int v3; // r5
  int v5; // r0
  int v6; // r4
  unsigned __int64 v7; // r6
  __int64 v8; // r0
  int v9; // r0
  int v10; // r0
  unsigned __int64 v11; // kr00_8
  unsigned __int64 v12; // kr08_8
  unsigned __int64 v13; // kr10_8
  unsigned int v14; // r10
  unsigned int v15; // lr
  int v16; // [sp+0h] [bp-28h]

  v2 = -1i64;
  v3 = 0;
  v16 = -1;
  if ( CmpNoWrite )
    return sub_7D3978();
  v5 = CmpGetNextActiveHive(0);
  v6 = v5;
  if ( v5 )
  {
    do
    {
      v7 = -1i64;
      if ( (*(_DWORD *)(v6 + 92) & 3) == 0 )
      {
        if ( *(_DWORD *)(v6 + 44) || *(_BYTE *)(v6 + 123) )
        {
          do
          {
            v8 = MEMORY[0xFFFF93B0];
            while ( 1 )
            {
              v14 = MEMORY[0xFFFF900C];
              __dmb(0xBu);
              v15 = MEMORY[0xFFFF9008];
              __dmb(0xBu);
              if ( v14 == MEMORY[0xFFFF9010] )
                break;
              __dmb(0xAu);
              __yield();
            }
          }
          while ( v8 != MEMORY[0xFFFF93B0] );
          v11 = __PAIR64__(v14, v15) - v8;
          LODWORD(v2) = v16;
          v12 = (unsigned int)dword_60E2A0 * (unsigned __int64)(unsigned int)dword_989680;
          v5 = HIDWORD(v12);
          v13 = *(_QWORD *)(v6 + 3240) + v12;
          if ( v11 < v13 )
          {
            v3 = 1;
            v7 = v13 - v11;
          }
          else
          {
            v5 = CmpFlushHive(v6, 18);
            if ( v5 < 0 )
            {
              v3 = 1;
              *a1 = 1;
              v7 = (unsigned int)dword_60E2AC * (unsigned __int64)(unsigned int)dword_989680;
            }
          }
        }
        else if ( (*(_DWORD *)(v6 + 3312) & 4) == 0 )
        {
          v5 = CmpFlushHive(v6, 34);
        }
      }
      if ( *(_BYTE *)(v6 + 2532) == 1 )
      {
        LOCK_HIVE_LOAD(v5);
        v9 = CmpLockRegistryFreezeAware(0);
        if ( *(_BYTE *)(v6 + 2532) == 1 )
          v9 = CmpDoQueueLateUnloadWorker(v6);
        v10 = CmpUnlockRegistry(v9);
        UNLOCK_HIVE_LOAD(v10);
      }
      if ( v7 < v2 )
      {
        v2 = v7;
        v16 = v7;
      }
      v5 = CmpGetNextActiveHive(v6);
      v6 = v5;
    }
    while ( v5 );
    if ( v3 )
      *a2 = v2;
  }
  return v3;
}
