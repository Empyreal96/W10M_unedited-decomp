// NtEnumerateDriverEntries 
 
int __fastcall NtEnumerateDriverEntries(int a1, unsigned int *a2)
{
  unsigned int v3; // r10
  int v4; // r5
  int v5; // r9
  unsigned int *v6; // r2
  unsigned int v7; // r6
  int v8; // r3
  int v9; // r2
  unsigned int v10; // r9
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int v20; // r9
  unsigned int v21; // r8
  _DWORD *v22; // r5
  unsigned int v23; // r4
  int v24; // r0
  int v25; // r2
  unsigned int v26; // r1
  unsigned int v27; // r3
  unsigned int v28; // r1
  BOOL v29; // r1
  unsigned int v30; // r3
  _DWORD *v31; // r1
  unsigned int v32; // r2
  bool v33; // zf
  unsigned int v35; // [sp+8h] [bp-68h] BYREF
  unsigned int v36; // [sp+Ch] [bp-64h]
  char v37; // [sp+10h] [bp-60h]
  int v38; // [sp+14h] [bp-5Ch] BYREF
  BOOL v39; // [sp+18h] [bp-58h]
  int v40; // [sp+1Ch] [bp-54h] BYREF
  int v41; // [sp+20h] [bp-50h]
  unsigned int v42; // [sp+24h] [bp-4Ch]
  int v43; // [sp+28h] [bp-48h]
  int v44; // [sp+2Ch] [bp-44h]
  unsigned int v45; // [sp+30h] [bp-40h]
  unsigned int v46; // [sp+34h] [bp-3Ch]
  int v47; // [sp+38h] [bp-38h]
  unsigned int *v48; // [sp+3Ch] [bp-34h]
  int v49; // [sp+40h] [bp-30h]
  int v50; // [sp+44h] [bp-2Ch] BYREF
  unsigned int v51; // [sp+48h] [bp-28h]
  unsigned int v52; // [sp+4Ch] [bp-24h]
  unsigned int v53; // [sp+50h] [bp-20h]
  int anonymous19; // [sp+78h] [bp+8h]
  unsigned int *anonymous20; // [sp+7Ch] [bp+Ch]

  v48 = a2;
  anonymous20 = a2;
  anonymous19 = a1;
  v3 = 0;
  v38 = 0;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( (a1 & 0xFFFFFFFC) != a1 )
    return -1073741811;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v37 = v5;
  if ( v5 )
  {
    v6 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v6 = (unsigned int *)MmUserProbeAddress;
    *v6 = *v6;
    v7 = *a2;
    v42 = *a2;
    if ( !a1 )
    {
      v7 = 0;
      v42 = 0;
    }
    if ( v7 )
      ProbeForWrite(a1, v7, 4);
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v5, (int)&SeSystemEnvironmentPrivilege) )
    {
      v4 = -1073741727;
      v41 = -1073741727;
      return v4;
    }
  }
  else
  {
    v7 = *a2;
    v42 = *a2;
    if ( !a1 )
    {
      v7 = 0;
      v42 = 0;
    }
  }
  if ( v7 )
  {
    v4 = ExLockUserBuffer(a1, v7, v5, 1, (int *)&v35, &v38);
    if ( v4 < 0 )
      return v4;
    v8 = v38;
    v9 = v35;
  }
  else
  {
    v9 = 0;
    v8 = 0;
  }
  v47 = v8;
  v38 = v9;
  v10 = v9;
  v36 = v9;
  v43 = 0;
  v39 = v7 != 0;
  v35 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
  while ( __strex(v14 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
  __dmb(0xBu);
  if ( (v14 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v12);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  dword_61A084 = v35;
  v40 = 0;
  v4 = IoEnumerateEnvironmentVariablesEx(2, 0, (int)&v40);
  v44 = v4;
  if ( v4 == -1073741789 )
  {
    v15 = ExAllocatePoolWithTag(512, v40, 1920364101);
    v3 = v15;
    if ( v15 )
      v4 = IoEnumerateEnvironmentVariablesEx(2, v15, (int)&v40);
    else
      v4 = -1073741670;
    v44 = v4;
  }
  else
  {
    v40 = 0;
  }
  dword_61A084 = 0;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&ExpEnvironmentLock);
  while ( !v16 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
  if ( v16 )
    ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v16);
  v17 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  if ( !v4 )
  {
    v49 = v40;
    if ( v40 )
    {
      v20 = v3;
      v21 = v36;
      v22 = 0;
      while ( 1 )
      {
        if ( !memcmp(v20 + 16, (unsigned int)EfiDriverVariablesGuid, 16) )
        {
          if ( ExpTranslateDriverEntryNameToId((unsigned __int16 *)(v20 + 32), &v50) )
          {
            v23 = *(_DWORD *)(v20 + 8);
            if ( v23 >= 8 )
            {
              v46 = *(_DWORD *)(v20 + 4) + v20;
              v35 = *(unsigned __int16 *)(v46 + 4);
              v24 = ExpSafeWcslen((_WORD *)(v46 + 6), v3 + 2 * v49);
              v25 = v24;
              v36 = v24;
              if ( v24 != -1 )
              {
                v25 = 2 * (v24 + 1);
                v36 = v25;
              }
              if ( v25 != -1 && v35 < v23 && v23 >= v25 + v35 + 6 )
                break;
            }
          }
        }
LABEL_65:
        if ( !*(_DWORD *)v20 )
        {
          v35 = (unsigned int)v22;
          v36 = v21;
          v33 = v22 == 0;
          v4 = v44;
          v10 = v21;
          if ( !v33 )
            *(_DWORD *)v35 = 0;
          goto LABEL_69;
        }
        v20 += *(_DWORD *)v20;
      }
      v51 = v46 + v25;
      v26 = v21 + 3;
      if ( ((v21 + 3) & 0xFFFFFFFC) != v21 )
      {
        v27 = v26 & 0xFFFFFFFC;
        v28 = (v26 & 0xFFFFFFFC) - v21;
        v21 = v27;
        if ( v7 < v28 )
        {
          v29 = 0;
          v39 = 0;
          v7 = 0;
          v43 = -1073741789;
LABEL_57:
          v45 = (v25 + 23) & 0xFFFFFFFC;
          v52 = v45 + v35 + 12;
          v30 = v45 + v35 + 16;
          v53 = v30;
          if ( v7 >= v30 )
          {
            v7 -= v30;
          }
          else
          {
            v7 = 0;
            v29 = 0;
            v39 = 0;
            v43 = -1073741789;
          }
          if ( v29 )
          {
            memset((_BYTE *)v21, 0, v30);
            *(_DWORD *)(v21 + 4) = 1;
            *(_DWORD *)(v21 + 8) = v52;
            *(_DWORD *)(v21 + 12) = v50;
            *(_DWORD *)(v21 + 16) = 20;
            *(_DWORD *)(v21 + 20) = v45;
            memmove(v21 + 24, v46 + 6, v36);
            v31 = (_DWORD *)(v21 + 4 + v45);
            *v31 = 1;
            v32 = v35;
            v31[1] = v35 + 12;
            v31[2] = 4;
            memmove((int)(v31 + 3), v51 + 6, v32);
            if ( v22 )
              *v22 = v21 - (_DWORD)v22;
            v22 = (_DWORD *)v21;
            v30 = v53;
          }
          v21 += v30;
          goto LABEL_65;
        }
        v7 -= v28;
      }
      v29 = v39;
      goto LABEL_57;
    }
  }
LABEL_69:
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( v47 )
    ExUnlockUserBuffer(v47);
  if ( v4 >= 0 )
    v4 = v43;
  *v48 = v10 - v38;
  v41 = v4;
  return v4;
}
