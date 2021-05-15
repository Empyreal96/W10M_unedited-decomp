// NtEnumerateBootEntries 
 
int __fastcall NtEnumerateBootEntries(int a1, unsigned int *a2)
{
  unsigned int v3; // r10
  int v4; // r4
  int v5; // r9
  unsigned int *v6; // r2
  unsigned int v7; // r5
  int v8; // r3
  int v9; // r2
  int v10; // r9
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  _DWORD *v20; // r9
  int v21; // r4
  unsigned int v22; // r6
  int v23; // r0
  int v24; // r1
  unsigned int v25; // r2
  int v26; // r6
  int v27; // r2
  unsigned int v28; // r3
  unsigned int v29; // r2
  BOOL v30; // lr
  unsigned int v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r3
  int v34; // r6
  unsigned int v35; // r9
  unsigned int v36; // r9
  unsigned int v37; // r2
  int v39; // [sp+8h] [bp-78h]
  char *v40; // [sp+8h] [bp-78h]
  int v41; // [sp+8h] [bp-78h]
  unsigned int v42; // [sp+10h] [bp-70h] BYREF
  int v43; // [sp+14h] [bp-6Ch] BYREF
  BOOL v44; // [sp+18h] [bp-68h]
  int v45; // [sp+1Ch] [bp-64h] BYREF
  unsigned int v46; // [sp+20h] [bp-60h]
  int v47; // [sp+24h] [bp-5Ch]
  unsigned int v48; // [sp+28h] [bp-58h]
  int v49; // [sp+2Ch] [bp-54h]
  char *v50; // [sp+30h] [bp-50h]
  int v51; // [sp+34h] [bp-4Ch]
  _DWORD *v52; // [sp+38h] [bp-48h]
  unsigned int v53; // [sp+3Ch] [bp-44h]
  int v54; // [sp+40h] [bp-40h]
  unsigned int v55; // [sp+44h] [bp-3Ch]
  int v56; // [sp+48h] [bp-38h]
  unsigned int *v57; // [sp+4Ch] [bp-34h]
  int v58; // [sp+50h] [bp-30h]
  int v59; // [sp+54h] [bp-2Ch] BYREF
  int v60; // [sp+58h] [bp-28h]
  unsigned int v61; // [sp+5Ch] [bp-24h]
  unsigned int v62; // [sp+60h] [bp-20h]
  int anonymous21; // [sp+88h] [bp+8h]
  unsigned int *anonymous22; // [sp+8Ch] [bp+Ch]

  v57 = a2;
  anonymous22 = a2;
  anonymous21 = a1;
  v3 = 0;
  v43 = 0;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( (a1 & 0xFFFFFFFC) != a1 )
    return -1073741811;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v5 )
  {
    v6 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v6 = (unsigned int *)MmUserProbeAddress;
    *v6 = *v6;
    v7 = *a2;
    v46 = *a2;
    if ( !a1 )
    {
      v7 = 0;
      v46 = 0;
    }
    if ( v7 )
      ProbeForWrite(a1, v7, 4);
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v5, (int)&SeSystemEnvironmentPrivilege) )
    {
      v4 = -1073741727;
      v47 = -1073741727;
      return v4;
    }
  }
  else
  {
    v7 = *a2;
    v46 = *a2;
    if ( !a1 )
    {
      v7 = 0;
      v46 = 0;
    }
  }
  if ( v7 )
  {
    v4 = ExLockUserBuffer(a1, v7, v5, 1, (int *)&v42, &v43);
    if ( v4 < 0 )
      return v4;
    v8 = v43;
    v9 = v42;
  }
  else
  {
    v9 = 0;
    v8 = 0;
  }
  v54 = v8;
  v43 = v9;
  v10 = v9;
  v39 = v9;
  v44 = v7 != 0;
  v49 = 0;
  v52 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v11 + 308);
  v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
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
  dword_61A084 = v42;
  v45 = 0;
  v4 = IoEnumerateEnvironmentVariablesEx(2, 0, &v45);
  v51 = v4;
  if ( v4 == -1073741789 )
  {
    v15 = ExAllocatePoolWithTag(512, v45, 1920364101);
    v3 = v15;
    if ( v15 )
      v4 = IoEnumerateEnvironmentVariablesEx(2, v15, &v45);
    else
      v4 = -1073741670;
    v51 = v4;
  }
  else
  {
    v45 = 0;
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
    v58 = v45;
    if ( v45 )
    {
      v20 = (_DWORD *)v3;
      v21 = v39;
      while ( 1 )
      {
        v42 = (unsigned int)v20;
        if ( !memcmp((unsigned int)(v20 + 4), (unsigned int)EfiBootVariablesGuid, 16) )
        {
          if ( ExpTranslateBootEntryNameToId(v20 + 8, &v59) )
          {
            v22 = v20[2];
            if ( v22 >= 8 )
            {
              v40 = (char *)v20 + v20[1];
              v48 = *((unsigned __int16 *)v40 + 2);
              v23 = ExpSafeWcslen(v40 + 6, v3 + 2 * v58);
              v24 = v23;
              v56 = v23;
              if ( v23 != -1 )
              {
                v24 = 2 * (v23 + 1);
                v56 = v24;
              }
              v25 = v24 + v48 + 6;
              if ( v24 != -1 && v48 < v22 && v22 >= v25 )
                break;
            }
          }
        }
LABEL_80:
        if ( !*v20 )
        {
          v41 = v21;
          v4 = v51;
          v10 = v41;
          if ( v52 )
            *v52 = 0;
          goto LABEL_84;
        }
        v20 = (_DWORD *)((char *)v20 + *v20);
      }
      v50 = &v40[v24 + 6];
      v26 = v22 - v25;
      v60 = v26;
      v27 = v21 + 3;
      if ( ((v21 + 3) & 0xFFFFFFFC) != v21 )
      {
        v28 = v27 & 0xFFFFFFFC;
        v29 = (v27 & 0xFFFFFFFC) - v21;
        v21 = v28;
        if ( v7 < v29 )
        {
          v30 = 0;
          v44 = 0;
          v7 = 0;
          v49 = -1073741789;
LABEL_57:
          v53 = (v26 + 31) & 0xFFFFFFFC;
          v55 = (v53 + v24 + 3) & 0xFFFFFFFC;
          v31 = v55 + 12;
          if ( v48 <= 4 )
            v32 = 4;
          else
            v32 = v48;
          v61 = v31 + v32;
          v33 = v31 + v32 + 4;
          v62 = v33;
          if ( v7 >= v33 )
          {
            v7 -= v33;
          }
          else
          {
            v7 = 0;
            v30 = 0;
            v44 = 0;
            v49 = -1073741789;
          }
          if ( v30 )
          {
            v34 = v21 + 4;
            memset((_BYTE *)v21, 0, v33);
            *(_DWORD *)(v21 + 4) = 1;
            *(_DWORD *)(v21 + 8) = v61;
            *(_DWORD *)(v21 + 12) = v59;
            *(_DWORD *)(v21 + 16) = 0;
            if ( (*(_DWORD *)v40 & 1) != 0 )
              *(_DWORD *)(v21 + 16) = 1;
            if ( (*(_DWORD *)v40 & 8) != 0 )
              *(_DWORD *)(v21 + 16) |= 0x10u;
            *(_DWORD *)(v21 + 20) = v53;
            *(_DWORD *)(v21 + 24) = v55;
            v35 = v60;
            *(_DWORD *)(v21 + 28) = v60;
            memmove(v21 + 32, (int)&v50[v48], v35);
            if ( v35 > 0x14
              && !strcmp(v21 + 32, (unsigned int *)"WINDOWS")
              && ExpVerifyWindowsOsOptions((_DWORD *)(v21 + 32), v35) >= 0 )
            {
              *(_DWORD *)(v21 + 16) |= 4u;
            }
            memmove(v34 + v53, (int)(v40 + 6), v56);
            v36 = v34 + v55;
            *(_DWORD *)v36 = 1;
            v37 = v48;
            *(_DWORD *)(v36 + 4) = v48 + 12;
            *(_DWORD *)(v36 + 8) = 4;
            memmove(v36 + 12, (int)v50, v37);
            if ( ExpVerifyFilePath(v36) < 0 )
            {
              *(_DWORD *)(v21 + 16) |= 0x20u;
              *(_DWORD *)(v36 + 4) = 4;
              *(_BYTE *)(v36 + 12) = 127;
              *(_BYTE *)(v36 + 13) = -1;
              *(_BYTE *)(v36 + 14) = 4;
              *(_BYTE *)(v36 + 15) = 0;
            }
            else if ( ExpIsDevicePathForRemovableMedia(v50) )
            {
              *(_DWORD *)(v21 + 16) |= 8u;
            }
            if ( v52 )
              *v52 = v21 - (_DWORD)v52;
            v52 = (_DWORD *)v21;
            v20 = (_DWORD *)v42;
            v33 = v62;
          }
          v21 += v33;
          goto LABEL_80;
        }
        v7 -= v29;
      }
      v30 = v44;
      goto LABEL_57;
    }
  }
LABEL_84:
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( v54 )
    ExUnlockUserBuffer(v54);
  if ( v4 >= 0 )
    v4 = v49;
  *v57 = v10 - v43;
  v47 = v4;
  return v4;
}
