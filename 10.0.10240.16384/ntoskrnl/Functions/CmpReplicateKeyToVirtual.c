// CmpReplicateKeyToVirtual 
 
int __fastcall CmpReplicateKeyToVirtual(int a1, _DWORD *a2)
{
  int (__fastcall *v2)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // r3
  int v3; // r7
  __int64 v5; // r0
  int v6; // r5
  int v7; // r10
  int v8; // r8
  int v9; // r0
  int v10; // r4
  int v11; // r2
  int v12; // r3
  unsigned int v13; // r7
  unsigned int v14; // r9
  unsigned int v15; // r4
  int v16; // r0
  int v17; // r3
  _DWORD *v18; // r4
  unsigned int v19; // r6
  int v21; // [sp+8h] [bp-58h] BYREF
  _DWORD *v22; // [sp+Ch] [bp-54h]
  unsigned int v23; // [sp+10h] [bp-50h] BYREF
  int v24; // [sp+14h] [bp-4Ch]
  int v25; // [sp+18h] [bp-48h] BYREF
  int v26; // [sp+1Ch] [bp-44h] BYREF
  int v27[2]; // [sp+20h] [bp-40h] BYREF
  unsigned int v28; // [sp+28h] [bp-38h] BYREF
  _DWORD v29[12]; // [sp+30h] [bp-30h] BYREF

  v25 = -1;
  v26 = -1;
  v29[0] = 0;
  v29[1] = 0;
  v29[2] = 0;
  v29[3] = 0;
  v2 = CmpTraceRoutine;
  v3 = 0;
  v22 = a2;
  v24 = 0;
  if ( CmpTraceRoutine )
  {
    LODWORD(v5) = v29;
    HIDWORD(v5) = 0x20000;
    EtwGetKernelTraceTimestamp(v5);
    v2 = CmpTraceRoutine;
  }
  v6 = 0;
  v21 = 0;
  v7 = 0;
  v8 = 0;
  if ( v2 && a1 )
  {
    v3 = a1;
    v24 = a1;
  }
  v9 = CmRealKCBToVirtualPath(a1, 0, (int)v27);
  v10 = v9;
  if ( v9 >= 0 )
  {
    if ( CmpBuildVirtualReplicationStack(a1, v27, &v23, &v28) >= 0 )
    {
      v13 = v23;
      v14 = v28;
      if ( v23 )
      {
        v10 = CmpGetVirtualStoreRoot(&v21, &v23, v11, v12);
        v6 = v21;
        if ( v10 >= 0 )
        {
          v15 = v23;
          v16 = v21;
          *v22 = v21;
          *(_DWORD *)(v14 + 8) = (*(int (__fastcall **)(int, unsigned int, unsigned int))(v6 + 4))(v16, v15, v14 + 12);
          *(_DWORD *)(v14 + 16) = v15;
          if ( *(_DWORD *)(v14 + 8) )
          {
            if ( ExTryConvertSharedToExclusiveLite() )
            {
              v10 = CmpDoBuildVirtualStack((unsigned __int16 *)v14, v13, v6, v17);
              v22 = *(_DWORD **)(v14 + 28 * v13 - 8);
              if ( v10 >= 0 )
              {
                if ( HvpMarkCellDirty(*(_DWORD *)(a1 + 20), *(_DWORD *)(a1 + 24), 0, 0)
                  && (v18 = v22, HvpMarkCellDirty(v6, (int)v22, 0, 0)) )
                {
                  v7 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(a1 + 20) + 4))(
                         *(_DWORD *)(a1 + 20),
                         *(_DWORD *)(a1 + 24),
                         &v26);
                  if ( v7 && (v8 = (*(int (__fastcall **)(int, _DWORD *, int *))(v6 + 4))(v6, v18, &v25)) != 0 )
                  {
                    CmpLockTwoSecurityCachesExclusiveShared(v6, *(_DWORD *)(a1 + 20));
                    v10 = CmpCopySaclToVirtualKey(*(_DWORD *)(a1 + 20), v7, v6, v8, v18);
                    CmpUnlockTwoSecurityCaches(v6, *(_DWORD *)(a1 + 20));
                    if ( v10 >= 0 )
                    {
                      if ( (*(_WORD *)(v8 + 2) & 0x100) == 0 )
                        *(_WORD *)(v8 + 2) |= 0x100u;
                      *(_WORD *)(a1 + 106) |= 0x80u;
                      *(_WORD *)(v7 + 2) |= 0x80u;
                    }
                  }
                  else
                  {
                    v10 = -1073741670;
                  }
                }
                else
                {
                  v10 = -1073741443;
                }
              }
              ExConvertExclusiveToSharedLite((int)&CmpRegistryLock);
              if ( v7 )
                (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v26);
              if ( v8 )
                (*(void (__fastcall **)(int, int *))(v6 + 8))(v6, &v25);
            }
            else
            {
              v10 = -1073741739;
            }
          }
          else
          {
            v10 = -1073741670;
          }
        }
      }
      else
      {
        v10 = -1073741811;
      }
      if ( v14 )
      {
        if ( v13 )
        {
          v19 = v14;
          do
          {
            if ( *(_DWORD *)(v19 + 8) )
            {
              (*(void (__fastcall **)(int, unsigned int))(v6 + 8))(v6, v19 + 12);
              *(_DWORD *)(v19 + 8) = 0;
            }
            v19 += 28;
            --v13;
          }
          while ( v13 );
        }
        ExFreePoolWithTag(v14);
      }
    }
    else
    {
      v10 = -1073741670;
    }
    if ( CmpTraceRoutine )
      CmpTraceRoutine(26, v29, v10, 0, v24, v27);
    RtlFreeAnsiString(v27);
  }
  else if ( CmpTraceRoutine )
  {
    CmpTraceRoutine(26, v29, v9, 0, v3, v27);
  }
  return v10;
}
