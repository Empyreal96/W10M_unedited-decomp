// SmProcessStatsRequest 
 
int __fastcall SmProcessStatsRequest(int a1, unsigned int *a2, int a3, _DWORD *a4, char a5)
{
  int v7; // r5
  unsigned int *v8; // r6
  int v9; // r0
  int v10; // r4
  int v11; // r9
  unsigned int v12; // r8
  int v13; // r0
  unsigned int *v14; // r0
  int v16; // [sp+8h] [bp-68h]
  int v18; // [sp+28h] [bp-48h]
  int v19; // [sp+2Ch] [bp-44h]
  unsigned int v20; // [sp+30h] [bp-40h]
  _DWORD _40[18]; // [sp+40h] [bp-30h] BYREF

  _40[14] = a1;
  _40[15] = a2;
  _40[16] = a3;
  _40[17] = a4;
  v7 = 0;
  v8 = 0;
  v16 = 0;
  v9 = KeInitializeEvent((int)_40, 0, 0);
  if ( a3 == 12 )
  {
    if ( a5 && ((unsigned __int8)a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v9);
    v20 = *a2;
    v11 = a2[1];
    v12 = a2[2];
    if ( (unsigned __int8)v20 == 2 && BYTE1(v20) < 4u )
    {
      if ( BYTE1(v20) <= 1u
        || SeSinglePrivilegeCheck(
             SeProfileSingleProcessPrivilege,
             dword_922B94,
             a5,
             (int)&SeProfileSingleProcessPrivilege) )
      {
        if ( (!v11 || (v13 = MmSizeOfMdl(v12, v11), (v7 = SmAlloc(v13, 1145924979)) != 0))
          && (v14 = (unsigned int *)SmAlloc(32, 1767337331), (v8 = v14) != 0) )
        {
          memset(v14, 0, 32);
          if ( v11 )
          {
            *(_DWORD *)v7 = 0;
            *(_WORD *)(v7 + 4) = 4 * ((((v12 & 0xFFF) + v11 + 4095) >> 12) + 7);
            *(_WORD *)(v7 + 6) = 0;
            *(_DWORD *)(v7 + 16) = v12 & 0xFFFFF000;
            *(_DWORD *)(v7 + 24) = v12 & 0xFFF;
            *(_DWORD *)(v7 + 20) = v11;
            MmProbeAndLockPages(v7);
            v16 = 1;
          }
          *v8 = *v8 & 0xFFFFFFF8 | 3;
          v8[1] = BYTE1(v20);
          v8[2] = v11;
          v8[3] = v7;
          v10 = SMKM_STORE_MGR<SM_TRAITS>::SmStoreRequest((int)SmGlobals, HIWORD(v20));
          if ( v10 >= 0 )
          {
            v8 = 0;
            KeWaitForSingleObject((unsigned int)_40, 0, 0, 0, 0);
            v10 = v18;
            *a4 = v19;
          }
        }
        else
        {
          v10 = -1073741670;
        }
      }
      else
      {
        v10 = -1073741790;
      }
    }
    else
    {
      v10 = -1073741811;
    }
  }
  else
  {
    v10 = -1073741306;
  }
  if ( v8 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v8);
  if ( v16 )
    MmUnlockPages(v7);
  if ( v7 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v7);
  return v10;
}
