// VfDeadlockDeleteMemoryRange 
 
unsigned int __fastcall VfDeadlockDeleteMemoryRange(unsigned int a1, int a2)
{
  unsigned int result; // r0
  unsigned int v5; // r3
  unsigned int v6; // r6
  unsigned int v7; // r9
  _DWORD *v8; // r5
  int v9; // r4
  int v10; // r7
  _DWORD **v11; // r8
  _DWORD *v12; // r4
  _DWORD *v13; // r6
  unsigned int v14; // r3
  _DWORD *v15; // r0
  _DWORD *v16; // r4
  _DWORD *v17; // r4
  _DWORD *v18; // r5
  int v19; // r6
  int v20; // r3
  _DWORD *v21; // r7
  _DWORD *v22; // r8
  _DWORD *v23; // r4
  unsigned int v24; // r3
  _DWORD *v25; // r4
  bool v26; // zf
  unsigned int v27; // [sp+0h] [bp-38h]
  int v28; // [sp+4h] [bp-34h]
  unsigned int v29; // [sp+8h] [bp-30h]
  _DWORD *v30; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int v31; // [sp+10h] [bp-28h]
  unsigned int v32; // [sp+14h] [bp-24h]

  result = ViDeadlockCanProceed(0, 0);
  if ( result )
  {
    v5 = a1 + a2;
    v6 = a1;
    v27 = a1 + a2;
    v31 = ((a1 & 0xFFF) + a2 + 4095) >> 12;
    v29 = a1;
    if ( v31 )
    {
      do
      {
        v7 = v6 + 4096;
        if ( v6 + 4096 > v5 )
          v7 = v5;
        v30 = 0;
        v8 = 0;
        v9 = ViDeadlockDatabaseHashIndex(v6);
        v28 = v9;
        v10 = 0;
        v32 = ViRaiseIrqlToDpcLevel(v9);
LABEL_6:
        ViDeadlockDetectionLock(v10);
        v11 = (_DWORD **)(*(_DWORD *)(ViDeadlockGlobals + 16) + 8 * v9);
        v12 = *v11;
        if ( *v11 != v11 && VfUtilAddressRangeFit((unsigned int *)(ViDeadlockGlobals + 8 * (v28 + 3)), v6, v7) )
        {
          while ( v12 != v11 )
          {
            v13 = v12 - 6;
            v14 = *(v12 - 4);
            v12 = (_DWORD *)*v12;
            if ( v14 >= a1 && v14 < v27 )
            {
              if ( !v10 )
              {
                v10 = 1;
                if ( !ViDeadlockDetectionTryConvertSharedToExclusive() )
                {
                  ViDeadlockDetectionUnlock(0);
                  v9 = v28;
                  v6 = v29;
                  goto LABEL_6;
                }
              }
              ViDeadlockRemoveResource(v13, 0, &v30);
              *v13 = v8;
              v8 = v13;
            }
          }
        }
        ViDeadlockDetectionUnlock(v10);
        ViLowerIrql(v32);
        v15 = v30;
        if ( v30 )
        {
          do
          {
            v16 = (_DWORD *)*v15;
            ViDeadlockFree(v15, 2);
            v15 = v16;
          }
          while ( v16 );
        }
        if ( v8 )
        {
          do
          {
            v17 = (_DWORD *)*v8;
            v15 = (_DWORD *)ViDeadlockFree(v8, 1);
            v8 = v17;
          }
          while ( v17 );
        }
        v18 = 0;
        v19 = 0;
        v32 = ViRaiseIrqlToDpcLevel((int)v15);
LABEL_20:
        ViDeadlockDetectionLock(v19);
        v20 = *(_DWORD *)(ViDeadlockGlobals + 8208);
        v21 = *(_DWORD **)(v20 + 8 * v28);
        v22 = (_DWORD *)(v20 + 8 * v28);
        if ( v21 != v22 && VfUtilAddressRangeFit((unsigned int *)(ViDeadlockGlobals + 8 * (v28 + 1027)), v29, v7) )
        {
          while ( v21 != v22 )
          {
            v23 = v21 - 3;
            v24 = *(v21 - 3);
            v21 = (_DWORD *)*v21;
            if ( v24 >= a1 && v24 < v27 )
            {
              if ( !v19 )
              {
                v19 = 1;
                if ( !ViDeadlockDetectionTryConvertSharedToExclusive() )
                {
                  ViDeadlockDetectionUnlock(0);
                  goto LABEL_20;
                }
              }
              ViDeadlockRemoveThread(v23, 0);
              *v23 = v18;
              v18 = v23;
            }
          }
        }
        ViDeadlockDetectionUnlock(v19);
        result = ViLowerIrql(v32);
        if ( v18 )
        {
          do
          {
            v25 = (_DWORD *)*v18;
            result = ViDeadlockFree(v18, 3);
            v18 = v25;
          }
          while ( v25 );
        }
        v6 = v7;
        v26 = v31-- == 1;
        v5 = v27;
        v29 = v7;
      }
      while ( !v26 );
    }
  }
  return result;
}
