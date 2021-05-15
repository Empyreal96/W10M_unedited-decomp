// KiAbProcessThreadLocks 
 
int __fastcall KiAbProcessThreadLocks(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int result; // r0
  int v10; // r2
  int v11; // r4
  int v12; // r7
  unsigned int v13; // r4
  int v14; // r4
  int v15; // r3
  int v16; // r3
  int v17; // r5
  int v18; // r1
  int v19; // r4
  int v20; // r0
  unsigned int *v21; // r1
  int v22; // r0
  unsigned int *v23; // r1
  unsigned int *v24; // r2
  unsigned int *v25; // r2
  __int16 v26; // [sp+8h] [bp-40h] BYREF
  int v27; // [sp+Ch] [bp-3Ch]
  int v28; // [sp+10h] [bp-38h]
  int v29; // [sp+14h] [bp-34h]
  unsigned int v30; // [sp+18h] [bp-30h]
  int v31; // [sp+20h] [bp-28h] BYREF
  unsigned int *v32; // [sp+24h] [bp-24h]

  v28 = a4;
  v29 = a3;
  result = KeAbThreadAreAllEntriesFree(a1);
  if ( !result )
  {
    v10 = a1 + 488;
    v11 = *(char *)(a1 + 484);
    v27 = a1 + 488;
    __dmb(0xBu);
    v12 = (*(char *)(a1 + 810) | v11) ^ 0x3F;
    v13 = __clz(__rbit(v12));
    result = (unsigned __int8)(1 - (v13 >> 5));
    v30 = v13;
    if ( 1 != (unsigned __int8)(v13 >> 5) )
    {
      while ( 1 )
      {
        v12 &= v12 - 1;
        v14 = v10 + 48 * v13;
        v15 = *(_DWORD *)(v14 + 16);
        if ( !v15 || (v15 & 2) != 0 )
        {
          v16 = 0;
        }
        else
        {
          if ( a2 )
            return sub_54A0DC();
          if ( *(int *)(v14 + 16) >= 0 )
            v16 = 0;
          else
            v16 = (*(_BYTE *)(v14 + 13) & 1) != 0 ? v29 : v28;
        }
        if ( v16 )
          break;
LABEL_25:
        v13 = __clz(__rbit(v12));
        v30 = v13;
        if ( 1 == (unsigned __int8)(v13 >> 5) )
          return result;
      }
      result = KiAbEntryGetLockedHeadEntry(v14, a2, &v31);
      v17 = result;
      if ( !result )
        goto LABEL_24;
      if ( (*(_BYTE *)(v14 + 13) & 1) == 0 )
      {
        if ( v28 )
        {
          if ( v14 != result )
            KiAbEntryUpdateOwnerTreePosition(v14, result);
          KiAbDetermineMaxWaiterPriority(__SPAIR64__(&v26, v17));
          if ( !v26 )
          {
LABEL_18:
            if ( (dword_682604 & 0x10000) == 0 )
            {
              v20 = v31;
              if ( !v31 )
              {
                v21 = v32;
                __dmb(0xBu);
                do
                  result = __ldrex(v21);
                while ( (int *)result == &v31 && __strex(0, v21) );
                if ( (int *)result == &v31 )
                  goto LABEL_24;
                v20 = KxWaitForLockChainValid(&v31);
              }
              v31 = 0;
              __dmb(0xBu);
              v25 = (unsigned int *)(v20 + 4);
              do
                result = __ldrex(v25);
              while ( __strex(result ^ 1, v25) );
LABEL_24:
              v10 = v27;
              goto LABEL_25;
            }
            goto LABEL_53;
          }
          if ( KiAbSetMinimumThreadPriority(v14, &v26, a5, a6, a7) && v14 != v17 )
            KiAbEntryUpdateOwnerTreePosition(v14, v17);
        }
LABEL_30:
        if ( (dword_682604 & 0x10000) == 0 )
        {
          v22 = v31;
          if ( !v31 )
          {
            v23 = v32;
            __dmb(0xBu);
            do
              result = __ldrex(v23);
            while ( (int *)result == &v31 && __strex(0, v23) );
            if ( (int *)result == &v31 )
              goto LABEL_24;
            v22 = KxWaitForLockChainValid(&v31);
          }
          v31 = 0;
          __dmb(0xBu);
          v24 = (unsigned int *)(v22 + 4);
          do
            result = __ldrex(v24);
          while ( __strex(result ^ 1, v24) );
          goto LABEL_24;
        }
LABEL_53:
        result = KiReleaseQueuedSpinLockInstrumented(&v31);
        goto LABEL_24;
      }
      if ( !v29 )
        goto LABEL_30;
      if ( v14 != result )
        KiAbEntryUpdateWaiterTreePosition(v14, result);
      KiAbDetermineMinOwnerPriority(v17, &v26);
      KiAbTryIncrementIoWaiterCount(v14, v17);
      v19 = KiAbEntryGetCpuPriorityKey(v14);
      if ( (char)v26 < v19 )
      {
        if ( !v18 )
        {
LABEL_29:
          KiAbCpuBoostOwners(v17, v19, a5, a6, a7);
          goto LABEL_30;
        }
      }
      else if ( !v18 )
      {
        goto LABEL_18;
      }
      KiAbIoBoostOwners(v17, a5, a6, a7);
      goto LABEL_29;
    }
  }
  return result;
}
