// CmEnumerateValueKey 
 
int __fastcall CmEnumerateValueKey(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, int a6)
{
  int v8; // r0
  _DWORD *v9; // r5
  int v11; // r4
  int v12; // r0
  int v13; // r8
  int v14; // r0
  int v15; // r6
  int v16; // r6
  int v17; // r4
  int v18; // [sp+10h] [bp-38h] BYREF
  _DWORD v19[2]; // [sp+14h] [bp-34h] BYREF
  int v20; // [sp+1Ch] [bp-2Ch] BYREF
  int v21; // [sp+20h] [bp-28h]
  int v22; // [sp+24h] [bp-24h]

  v18 = -1;
  v19[0] = -1;
  v19[1] = 0;
  v20 = -1;
  v21 = a4;
  v22 = a3;
  v8 = CmpLockRegistry(a1, a2);
  v9 = (_DWORD *)a1[1];
  if ( a1[7] || a1[8] )
    return sub_80456C(v8);
  CmpLockKcbShared((_DWORD *)a1[1]);
  while ( CmRmIsKCBDeleted((int)v9, 0) != 1 )
  {
    v11 = v9[5];
    ExAcquireResourceSharedLite(*(_DWORD *)(v11 + 1872), 1);
    v12 = (*(int (__fastcall **)(int, _DWORD, int *))(v11 + 4))(v11, v9[6], &v18);
    v13 = v12;
    if ( !v12 )
    {
      ExReleaseResourceLite(*(_DWORD *)(v11 + 1872));
      goto LABEL_21;
    }
    CmpUpdateKeyNodeAccessBits(v11, v12, v9[6]);
    ExReleaseResourceLite(*(_DWORD *)(v11 + 1872));
    if ( a2 >= v9[13] )
    {
      (*(void (__fastcall **)(int, int *))(v11 + 8))(v11, &v18);
      CmpUnlockKcb(v9);
      CmpUnlockRegistry();
      return -2147483622;
    }
    if ( (v9[1] & 8) == 0 )
      goto LABEL_9;
    if ( CmpIsKcbLockedExclusive(v9) || CmpTryConvertKcbLockSharedToExclusive(v9) )
    {
      CmpCleanUpKcbValueCache(v9);
      v9[13] = *(_DWORD *)(v13 + 36);
      v9[14] = *(_DWORD *)(v13 + 40);
LABEL_9:
      (*(void (__fastcall **)(int, int *))(v11 + 8))(v11, &v18);
      v14 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v9[5] + 4))(v9[5], v9[14], &v20);
      if ( v14 )
      {
        v15 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD *))(v9[5] + 4))(v9[5], *(_DWORD *)(v14 + 4 * a2), v19);
        (*(void (__fastcall **)(_DWORD, int *))(v9[5] + 8))(v9[5], &v20);
        if ( v15 )
        {
          v16 = CmpQueryKeyValueData(v9, -1, v15, v22, v21, a5, a6);
          (*(void (__fastcall **)(int, _DWORD *))(v11 + 8))(v11, v19);
        }
        else
        {
          v16 = -1073741670;
        }
        CmpUnlockKcb(v9);
        CmpUnlockRegistry();
        return v16;
      }
LABEL_21:
      CmpUnlockKcb(v9);
      CmpUnlockRegistry();
      return -1073741670;
    }
    (*(void (__fastcall **)(int, int *))(v11 + 8))(v11, &v18);
    CmpUnlockKcb(v9);
    CmpLockKcbExclusive(v9);
  }
  if ( (a1[6] & 1) != 0 )
    v17 = -1073740763;
  else
    v17 = -1073741444;
  CmpUnlockKcb(v9);
  CmpUnlockRegistry();
  return v17;
}
