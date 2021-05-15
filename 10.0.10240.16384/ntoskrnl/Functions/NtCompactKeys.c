// NtCompactKeys 
 
int __fastcall NtCompactKeys(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // r5
  int v4; // r4
  int v5; // r10
  int v6; // r8
  int v7; // r0
  int *v8; // r9
  int v9; // r2
  unsigned int v10; // r6
  int *v11; // r3
  int v12; // r6
  unsigned int v13; // r2
  int *v14; // r0
  int v15; // t1
  int v16; // r1
  unsigned int v17; // r3
  unsigned int v18; // r10
  int v19; // t1
  int v20; // r0
  int *v21; // r6
  int v22; // t1
  int *v24; // [sp+10h] [bp-28h]
  int *v25; // [sp+14h] [bp-24h]
  unsigned int _44; // [sp+44h] [bp+Ch]

  _44 = a2;
  v3 = a1;
  v4 = CmCheckNoTxContext();
  if ( v4 >= 0 )
  {
    v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( SeSinglePrivilegeCheck(SeBackupPrivilege, dword_922BA4, v5, (int)&SeBackupPrivilege) )
    {
      if ( v3 )
      {
        if ( v3 < 0x3FFFFFFF )
        {
          v6 = 4 * v3;
          v7 = ExAllocatePoolWithQuotaTag(0x208u, 4 * v3, 1633832259);
          v8 = (int *)v7;
          v24 = (int *)v7;
          if ( v7 )
          {
            if ( v5 == 1 && v6 )
            {
              if ( (a2 & 3) != 0 )
                ExRaiseDatatypeMisalignment(v7);
              if ( v6 + a2 > MmUserProbeAddress || v6 + a2 < a2 )
                *(_BYTE *)MmUserProbeAddress = 0;
            }
            memmove(v7, a2, 4 * v3);
            v9 = v5;
            v10 = 0;
            v11 = v8;
            do
            {
              v25 = v11 + 1;
              v4 = CmObReferenceObjectByHandle(*v11, 131078, (int)CmKeyObjectType, v9, v11, 0);
              if ( v4 < 0 )
              {
                v3 = v10;
                goto LABEL_40;
              }
              ++v10;
              v11 = v25;
              v9 = v5;
            }
            while ( v10 < v3 );
            v12 = 0;
            CmpLockRegistryExclusive();
            v13 = 0;
            v14 = v8;
            do
            {
              v15 = *v14++;
              v16 = *(_DWORD *)(v15 + 4);
              if ( (*(_DWORD *)(v16 + 4) & 0x20000) != 0 )
              {
                v4 = -1073741444;
                goto LABEL_39;
              }
              if ( v13 )
              {
                if ( v12 != *(_DWORD *)(v16 + 20) )
                {
                  v4 = -1073741811;
                  goto LABEL_39;
                }
              }
              else
              {
                v12 = *(_DWORD *)(v16 + 20);
              }
              ++v13;
            }
            while ( v13 < v3 );
            *(_BYTE *)(v12 + 2560) = 1;
            v17 = (*(_DWORD *)(v12 + 952) + 4096) & 0xFFFC0000;
            *(_DWORD *)(v12 + 2564) = v17;
            if ( v17 )
              *(_DWORD *)(v12 + 2564) = v17 - 4096;
            v18 = v3;
            do
            {
              v19 = *v8++;
              v20 = CmMoveKey(v19);
              if ( v20 < 0 && v4 >= 0 )
                v4 = v20;
              --v18;
            }
            while ( v18 );
            v8 = v24;
            *(_BYTE *)(v12 + 2560) = 0;
            *(_DWORD *)(v12 + 2564) = 0;
LABEL_39:
            CmpUnlockRegistry();
LABEL_40:
            if ( v3 )
            {
              v21 = v8;
              do
              {
                v22 = *v21++;
                ObfDereferenceObject(v22);
                --v3;
              }
              while ( v3 );
            }
            ExFreePoolWithTag((unsigned int)v8);
          }
          else
          {
            v4 = -1073741670;
          }
        }
        else
        {
          v4 = -1073741811;
        }
      }
      else
      {
        v4 = 0;
      }
    }
    else
    {
      v4 = -1073741727;
    }
  }
  return v4;
}
