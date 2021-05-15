// CmpCheckKeyBodyAccess 
 
int __fastcall CmpCheckKeyBodyAccess(int a1, int a2, int a3, char a4, _DWORD *a5)
{
  _DWORD *v6; // r0
  int v8; // r8
  int result; // r0
  int v10; // r7
  unsigned int *v11; // r9
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r4
  int v16; // r4
  unsigned int v17; // r1
  int v18; // r7
  int v19; // r2
  int v20; // r2
  int v21; // r0
  __int16 v22; // r2
  int v23; // r3
  int *v24; // t2
  unsigned int *v25; // r4
  int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // r2
  unsigned int v29; // r2
  int v30; // r0
  unsigned int v31; // r1
  int v32; // r3
  int *v33; // t2
  unsigned int *v34; // r4
  int v35; // r1
  unsigned int v36; // r0
  unsigned int v37; // r2
  _DWORD *v38; // [sp+18h] [bp-30h] BYREF
  int v39; // [sp+1Ch] [bp-2Ch] BYREF
  int v40; // [sp+20h] [bp-28h] BYREF
  int v41; // [sp+24h] [bp-24h] BYREF
  int v42; // [sp+28h] [bp-20h]

  v6 = *(_DWORD **)(a1 + 4);
  v39 = -1;
  v41 = -1;
  v42 = a2;
  v8 = a4;
  if ( (v6[1] & 0x20000) != 0 )
    return sub_7FEE7C();
  v10 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v6[5] + 4))(v6[5], v6[6], &v39);
  if ( !v10 )
    goto LABEL_50;
  v11 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 20) + 1928);
  v12 = KeAbPreAcquire((unsigned int)v11, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v11);
  while ( !v14 && __strex(0x11u, v11) );
  __dmb(0xBu);
  if ( v14 )
    ExfAcquirePushLockSharedEx(v11, v12, (unsigned int)v11);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  v15 = *(_DWORD *)(v10 + 44);
  (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 20) + 8))(
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 20),
    &v39);
  v16 = (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 20) + 4))(
          *(_DWORD *)(*(_DWORD *)(a1 + 4) + 20),
          v15,
          &v41);
  if ( !v16 )
  {
    v33 = (int *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 20) + 1928);
    __pld(v33);
    v34 = (unsigned int *)v33;
    v35 = *v33;
    if ( (*v33 & 0xFFFFFFF0) <= 0x10 )
      v36 = 0;
    else
      v36 = v35 - 16;
    if ( (v35 & 2) != 0 )
      goto LABEL_48;
    __dmb(0xBu);
    do
      v37 = __ldrex(v34);
    while ( v37 == v35 && __strex(v36, v34) );
    if ( v37 != v35 )
LABEL_48:
      ExfReleasePushLock(v34, v35);
    KeAbPostRelease((unsigned int)v34);
LABEL_50:
    result = 0;
    *a5 = -1073741670;
    return result;
  }
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v17 + 308);
  ExAcquireResourceSharedLite(*(_DWORD *)(*(_DWORD *)(a3 + 36) + 48), 1);
  if ( *(_DWORD *)(a3 + 28) )
  {
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v29 + 308);
    ExAcquireResourceSharedLite(*(_DWORD *)(*(_DWORD *)(a3 + 28) + 48), 1);
  }
  v40 = 0;
  v38 = 0;
  v18 = SeAccessCheck(
          v16 + 20,
          a3 + 28,
          1,
          *(_DWORD *)(a3 + 16),
          *(_DWORD *)(a3 + 20),
          (int)&v38,
          (int)CmKeyObjectType + 52,
          v8,
          (int)&v40,
          (int)a5);
  if ( v38 )
  {
    SeAppendPrivileges(a3, v38);
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v38);
  }
  if ( v18 )
  {
    v19 = v40;
    *(_DWORD *)(a3 + 20) |= v40;
    *(_DWORD *)(a3 + 16) &= ~(v19 | 0x2000000);
  }
  v20 = v42;
  *(_WORD *)(a1 + 24) |= 2u;
  if ( v20 )
  {
    SeOpenObjectAuditAlarmWithTransaction(
      (_DWORD *)CmKeyObjectType + 2,
      a1,
      0,
      v16 + 20,
      a3,
      0,
      v18,
      v8,
      (_DWORD *)(v20 + 40),
      (_BYTE *)(a3 + 10));
  }
  else if ( v8 )
  {
    SeOpenObjectAuditAlarmWithTransaction(
      (_DWORD *)CmKeyObjectType + 2,
      a1,
      0,
      v16 + 20,
      a3,
      0,
      v18,
      v8,
      0,
      (_BYTE *)(a3 + 10));
  }
  *(_WORD *)(a1 + 24) &= 0xFFFDu;
  ExReleaseResourceLite(*(_DWORD *)(*(_DWORD *)(a3 + 36) + 48));
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134);
  *(_WORD *)(v21 + 308) = v22 + 1;
  if ( v22 == -1 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v21);
  v23 = *(_DWORD *)(a3 + 28);
  if ( v23 )
  {
    v30 = ExReleaseResourceLite(*(_DWORD *)(v23 + 48));
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v32 = (__int16)(*(_WORD *)(v31 + 0x134) + 1);
    *(_WORD *)(v31 + 308) = v32;
    if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
      KiCheckForKernelApcDelivery(v30);
  }
  v24 = (int *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 20) + 1928);
  __pld(v24);
  v25 = (unsigned int *)v24;
  v26 = *v24;
  if ( (*v24 & 0xFFFFFFF0) > 0x10 )
    v27 = v26 - 16;
  else
    v27 = 0;
  if ( (v26 & 2) != 0 )
    goto LABEL_39;
  __dmb(0xBu);
  do
    v28 = __ldrex(v25);
  while ( v28 == v26 && __strex(v27, v25) );
  if ( v28 != v26 )
LABEL_39:
    ExfReleasePushLock(v25, v26);
  KeAbPostRelease((unsigned int)v25);
  (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 20) + 8))(
    *(_DWORD *)(*(_DWORD *)(a1 + 4) + 20),
    &v41);
  return v18;
}
