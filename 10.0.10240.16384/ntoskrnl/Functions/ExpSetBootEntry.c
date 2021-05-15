// ExpSetBootEntry 
 
int __fastcall ExpSetBootEntry(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int *v4; // r10
  unsigned int v6; // r3
  int v7; // r5
  unsigned int *v8; // r3
  unsigned int v9; // r8
  int v10; // r4
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int *v13; // r1
  int v14; // r0
  _DWORD *v15; // r6
  unsigned int v16; // r4
  int v17; // r8
  int v18; // r0
  int v19; // r2
  unsigned int v20; // r2
  unsigned int v21; // r5
  int v22; // r4
  _BYTE *v23; // r0
  _DWORD *v24; // r2
  int v25; // r4
  int v26; // r4
  unsigned int v27; // r2
  unsigned int v28; // r8
  int v29; // r0
  int v30; // r4
  unsigned int v31; // r2
  unsigned int v32; // r2
  unsigned int v33; // r1
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int v38; // [sp+8h] [bp-88h]
  int v39; // [sp+Ch] [bp-84h] BYREF
  unsigned int v40; // [sp+10h] [bp-80h]
  int v41; // [sp+14h] [bp-7Ch]
  int v42; // [sp+18h] [bp-78h]
  int v43; // [sp+1Ch] [bp-74h]
  _DWORD *v44; // [sp+20h] [bp-70h]
  int v45; // [sp+24h] [bp-6Ch]
  unsigned int v46; // [sp+28h] [bp-68h]
  int v47; // [sp+2Ch] [bp-64h]
  unsigned int v48; // [sp+30h] [bp-60h]
  int v49; // [sp+34h] [bp-5Ch]
  int v50; // [sp+38h] [bp-58h]
  unsigned int *v51; // [sp+3Ch] [bp-54h]
  unsigned int *v52; // [sp+40h] [bp-50h]
  unsigned int v53; // [sp+44h] [bp-4Ch]
  int v54; // [sp+48h] [bp-48h]
  int v55; // [sp+4Ch] [bp-44h]
  unsigned int v56; // [sp+50h] [bp-40h]
  _DWORD _58[20]; // [sp+58h] [bp-38h] BYREF

  _58[17] = a2;
  _58[18] = a3;
  _58[19] = a4;
  v4 = a3;
  v52 = a3;
  v41 = a1;
  _58[16] = a1;
  v51 = a3;
  v54 = 0;
  v40 = 0;
  v48 = 0;
  v46 = 0;
  v43 = 0;
  v47 = 0;
  v45 = 0;
  v44 = 0;
  v50 = 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(char *)(v6 + 346);
  if ( *(_BYTE *)(v6 + 346) )
  {
    v8 = (unsigned int *)(a2 + 4);
    if ( a2 + 4 >= MmUserProbeAddress )
      v8 = (unsigned int *)MmUserProbeAddress;
    v9 = *v8;
    v53 = *v8;
  }
  else
  {
    v9 = *(_DWORD *)(a2 + 4);
    v53 = v9;
  }
  if ( v9 < 0x1C )
  {
    v10 = -1073741811;
    v42 = -1073741811;
    return v10;
  }
  if ( v7 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(0);
    v11 = a2 + v9;
    v12 = MmUserProbeAddress;
    if ( a2 + v9 > MmUserProbeAddress || v11 < a2 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v12 = MmUserProbeAddress;
      v4 = v52;
    }
    if ( v4 )
    {
      v13 = v4;
      if ( (unsigned int)v4 >= v12 )
        v13 = (unsigned int *)v12;
      *v13 = *v13;
    }
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v7, (int)&SeSystemEnvironmentPrivilege) )
    {
      v10 = -1073741727;
      v42 = -1073741727;
      return v10;
    }
  }
  v14 = ExAllocatePoolWithTag(512, v9, 1920364101);
  v15 = (_DWORD *)v14;
  v54 = v14;
  if ( !v14 )
  {
    v10 = -1073741670;
    v42 = -1073741670;
    return v10;
  }
  memmove(v14, a2, v9);
  v50 = (int)v15 + v9;
  if ( !*v15 || *v15 > 1u || !v41 && v15[2] > 0xFFFFu )
    goto LABEL_92;
  v15[3] &= 3u;
  v51 = (unsigned int *)v15[4];
  if ( ((unsigned __int8)v51 & 1) != 0 )
    goto LABEL_92;
  v55 = v15[5];
  if ( (v55 & 3) != 0 )
    goto LABEL_92;
  v16 = v15[6];
  if ( v16 > v9 )
    goto LABEL_92;
  v56 = (unsigned int)v15 + v16 + 28;
  if ( v56 >= (unsigned int)v15 + v9 )
    goto LABEL_92;
  if ( v16 >= 8 && !strcmp((int)(v15 + 7), (unsigned int *)"WINDOWS") )
  {
    if ( v16 <= 0x14 )
      goto LABEL_92;
    v10 = ExpVerifyWindowsOsOptions(v15 + 7, v16);
    if ( v10 < 0 )
      goto LABEL_93;
    v45 = 1;
    v17 = (int)v15 + v15[11] + 28;
  }
  else
  {
    v45 = 0;
    v17 = 0;
  }
  v48 = (unsigned int)v15 + (_DWORD)v51;
  v18 = ExpSafeWcslen((char *)v15 + (_DWORD)v51, v50);
  if ( v18 == -1 )
    goto LABEL_92;
  v43 = v18 + 1;
  v46 = (unsigned int)v15 + v55;
  v10 = ExpVerifyFilePath((char *)v15 + v55);
  if ( v10 < 0 )
    goto LABEL_93;
  if ( v56 > v48 || v48 + 2 * v43 > v46 )
  {
LABEL_92:
    v10 = -1073741811;
    goto LABEL_93;
  }
  if ( *(_DWORD *)(v46 + 8) == 4 )
  {
    v19 = *(_DWORD *)(v46 + 4);
    v47 = v46;
    goto LABEL_47;
  }
  v10 = ZwTranslateFilePath();
  if ( v10 == -1073741789 )
  {
    v47 = ExAllocatePoolWithTag(512, 0, 1920364101);
    if ( !v47 )
    {
LABEL_43:
      v10 = -1073741670;
      goto LABEL_93;
    }
    v39 = 0;
    v10 = ZwTranslateFilePath();
    if ( v10 < 0 )
      goto LABEL_93;
    v19 = 0;
LABEL_47:
    v20 = v19 - 12;
    v38 = v20;
    v49 = 0;
    if ( !v45 || *(_DWORD *)(v17 + 8) == 4 )
    {
      v21 = v15[6];
    }
    else
    {
      v10 = ZwTranslateFilePath();
      if ( v10 != -1073741789 )
        goto LABEL_93;
      v21 = v15[6] - *(_DWORD *)(v17 + 4) + v49;
      v20 = v38;
    }
    v22 = v43;
    v43 = v21 + v20 + 2 * v43;
    v23 = (_BYTE *)ExAllocatePoolWithTag(512, v43 + 6, 1920364101);
    v44 = v23;
    if ( !v23 )
      goto LABEL_43;
    memset(v23, 0, v43 + 6);
    v24 = v44;
    *v44 = 0;
    if ( (v15[3] & 1) != 0 )
      *v24 = 1;
    *((_WORD *)v24 + 2) = v38;
    memmove((int)v24 + 6, v48, 2 * v22);
    v25 = (int)v44 + 2 * v22 + 6;
    memmove(v25, v47 + 12, v38);
    v26 = v25 + v38;
    if ( !v45 || *(_DWORD *)(v17 + 8) == 4 )
    {
      memmove(v26, (int)(v15 + 7), v21);
    }
    else
    {
      memmove(v26, (int)(v15 + 7), v15[11]);
      *(_DWORD *)(v26 + 12) = v21;
      v39 = v49;
      v10 = ZwTranslateFilePath();
      if ( v10 )
        goto LABEL_93;
    }
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v27 + 308);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
    v30 = v29;
    do
      v31 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
    while ( __strex(v31 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
    __dmb(0xBu);
    if ( (v31 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v29);
    if ( v30 )
      *(_BYTE *)(v30 + 14) |= 1u;
    dword_61A084 = v28;
    if ( v41 )
    {
      v32 = 0;
      v40 = 0;
      do
      {
        swprintf_s((int)_58, 9, (int)L"Boot%04x", v32);
        v39 = 0;
        v10 = IoGetEnvironmentVariableEx((int)_58, (int)EfiBootVariablesGuid, 0, (int)&v39, 0);
        v32 = v40;
        if ( v10 == -1073741568 )
        {
          if ( (v40 & (2 * ((v40 | (2 * v40)) & 0xC4444444))) != 0 )
          {
            swprintf_s((int)_58, 9, (int)L"Boot%04X", v40);
            v39 = 0;
            v10 = IoGetEnvironmentVariableEx((int)_58, (int)EfiBootVariablesGuid, 0, (int)&v39, 0);
            v32 = v40;
          }
          if ( v10 == -1073741568 )
            break;
        }
        if ( v10 && v10 != -1073741789 )
          goto LABEL_83;
        v40 = ++v32;
      }
      while ( v32 <= 0xFFFF );
      if ( v32 > 0xFFFF )
      {
        v10 = -1073741670;
        goto LABEL_83;
      }
    }
    else
    {
      v40 = v15[2];
      swprintf_s((int)_58, 9, (int)L"Boot%04X");
      v39 = 0;
      v10 = IoGetEnvironmentVariableEx((int)_58, (int)EfiBootVariablesGuid, 0, (int)&v39, 0);
      if ( v10 == -1073741568 && (v15[2] & (2 * ((v15[2] | (2 * v15[2])) & 0xC4444444))) != 0 )
      {
        swprintf_s((int)_58, 9, (int)L"Boot%04x");
        v39 = 0;
        v10 = IoGetEnvironmentVariableEx((int)_58, (int)EfiBootVariablesGuid, 0, (int)&v39, 0);
      }
      if ( v10 && v10 != -1073741789 )
        goto LABEL_83;
    }
    v10 = IoSetEnvironmentVariableEx(_58, EfiBootVariablesGuid, v44, v43 + 6, 1);
LABEL_83:
    dword_61A084 = 0;
    __dmb(0xBu);
    do
      v33 = __ldrex((unsigned int *)&ExpEnvironmentLock);
    while ( !v33 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
    if ( v33 )
      ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v33);
    v34 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
    v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v36 = *(_WORD *)(v35 + 0x134) + 1;
    *(_WORD *)(v35 + 308) = v36;
    if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
      KiCheckForKernelApcDelivery(v34);
  }
LABEL_93:
  if ( v44 )
    ExFreePoolWithTag((unsigned int)v44);
  if ( v47 && v47 != v46 )
    ExFreePoolWithTag(v47);
  ExFreePoolWithTag((unsigned int)v15);
  if ( v41 && v52 && v10 >= 0 )
    *v52 = v40;
  v42 = v10;
  return v10;
}
