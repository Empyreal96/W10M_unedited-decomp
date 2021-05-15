// ExpSetDriverEntry 
 
int __fastcall ExpSetDriverEntry(int a1, unsigned int a2, unsigned int *a3, int a4)
{
  unsigned int i; // r10
  unsigned int v6; // r3
  int v7; // lr
  unsigned int *v8; // r3
  unsigned int v9; // r8
  int v10; // r4
  unsigned int v11; // r3
  unsigned int *v12; // r1
  int v13; // r0
  _DWORD *v14; // r5
  int v15; // r3
  int v16; // r4
  int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r8
  int v20; // r4
  _BYTE *v21; // r0
  _BYTE *v22; // r6
  int v23; // r3
  _BYTE *v24; // r0
  _BYTE *v25; // r10
  unsigned int v26; // r2
  unsigned int v27; // r10
  int v28; // r0
  int v29; // r4
  unsigned int v30; // r2
  unsigned int v31; // r1
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  int v36; // [sp+8h] [bp-78h] BYREF
  int v37; // [sp+Ch] [bp-74h]
  int v38; // [sp+10h] [bp-70h]
  int v39; // [sp+14h] [bp-6Ch]
  unsigned int v40; // [sp+18h] [bp-68h]
  int v41; // [sp+1Ch] [bp-64h]
  unsigned int v42; // [sp+20h] [bp-60h]
  _BYTE *v43; // [sp+24h] [bp-5Ch]
  int v44; // [sp+28h] [bp-58h]
  int v45; // [sp+2Ch] [bp-54h]
  unsigned int v46; // [sp+30h] [bp-50h]
  unsigned int *v47; // [sp+34h] [bp-4Ch]
  int v48; // [sp+38h] [bp-48h]
  unsigned int *v49; // [sp+3Ch] [bp-44h]
  int v50; // [sp+40h] [bp-40h]
  _DWORD _48[20]; // [sp+48h] [bp-38h] BYREF

  _48[17] = a2;
  _48[18] = a3;
  _48[19] = a4;
  v47 = a3;
  v38 = a1;
  _48[16] = a1;
  v49 = a3;
  v45 = 0;
  i = 0;
  v44 = 0;
  v40 = 0;
  v41 = 0;
  v43 = 0;
  v48 = 0;
  v42 = 0;
  v50 = 0;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(char *)(v6 + 346);
  if ( *(_BYTE *)(v6 + 346) )
  {
    v8 = (unsigned int *)(a2 + 4);
    if ( a2 + 4 >= MmUserProbeAddress )
      v8 = (unsigned int *)MmUserProbeAddress;
    v9 = *v8;
    v46 = *v8;
  }
  else
  {
    v9 = *(_DWORD *)(a2 + 4);
    v46 = v9;
  }
  if ( v9 < 0x14 )
  {
    v10 = -1073741811;
    v39 = -1073741811;
    return v10;
  }
  if ( v7 )
  {
    if ( (a2 & 3) != 0 )
      ExRaiseDatatypeMisalignment(0);
    v11 = MmUserProbeAddress;
    if ( a2 + v9 > MmUserProbeAddress || a2 + v9 < a2 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v11 = MmUserProbeAddress;
    }
    if ( a3 )
    {
      v12 = a3;
      if ( (unsigned int)a3 >= v11 )
        v12 = (unsigned int *)v11;
      *v12 = *v12;
    }
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v7, (int)&SeSystemEnvironmentPrivilege) )
    {
      v10 = -1073741727;
      v39 = -1073741727;
      return v10;
    }
  }
  v13 = ExAllocatePoolWithTag(512, v9, 1920364101);
  v14 = (_DWORD *)v13;
  v45 = v13;
  if ( !v13 )
  {
    v10 = -1073741670;
    v39 = -1073741670;
    return v10;
  }
  memmove(v13, a2, v9);
  if ( !*v14
    || *v14 > 1u
    || !v38 && v14[2] > 0xFFFFu
    || (v15 = v14[3], (v15 & 1) != 0)
    || (v16 = v14[4], (v16 & 3) != 0)
    || (v44 = (int)v14 + v15, v17 = ExpSafeWcslen((_DWORD *)((char *)v14 + v15), (unsigned int)v14 + v9), v17 == -1) )
  {
    v19 = v40;
    goto LABEL_72;
  }
  v41 = v17 + 1;
  v40 = (unsigned int)v14 + v16;
  v18 = (unsigned int)v14 + v9;
  v19 = (unsigned int)v14 + v16;
  v10 = ExpVerifyFilePath((_DWORD *)((char *)v14 + v16), v18);
  if ( v10 < 0 )
    goto LABEL_73;
  v20 = v41;
  if ( v44 + 2 * v41 > v19 )
  {
LABEL_72:
    v10 = -1073741811;
    goto LABEL_73;
  }
  if ( *(_DWORD *)(v19 + 8) == 4 )
  {
    v23 = *(_DWORD *)(v19 + 4);
    v22 = (_BYTE *)v19;
    v43 = (_BYTE *)v19;
    goto LABEL_38;
  }
  v37 = 0;
  v10 = ZwTranslateFilePath();
  if ( v10 == -1073741789 )
  {
    v21 = (_BYTE *)ExAllocatePoolWithTag(512, v37, 1920364101);
    v22 = v21;
    v43 = v21;
    if ( !v21 )
    {
LABEL_34:
      v10 = -1073741670;
      goto LABEL_73;
    }
    memset(v21, 0, v37);
    v36 = v37;
    v10 = ZwTranslateFilePath();
    if ( v10 < 0 )
      goto LABEL_73;
    v23 = v37;
    v20 = v41;
LABEL_38:
    v37 = v23 - 12;
    v41 = v23 - 12 + 2 * v20;
    v24 = (_BYTE *)ExAllocatePoolWithTag(512, v41 + 6, 1920364101);
    v42 = (unsigned int)v24;
    if ( !v24 )
      goto LABEL_34;
    v25 = v24;
    memset(v24, 0, v41 + 6);
    *((_WORD *)v25 + 2) = v37;
    memmove((int)(v25 + 6), v44, 2 * v20);
    memmove((int)&v25[2 * v20 + 6], (int)(v22 + 12), v37);
    v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v26 + 308);
    v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v28 = KeAbPreAcquire((unsigned int)&ExpEnvironmentLock, 0, 0);
    v29 = v28;
    do
      v30 = __ldrex((unsigned __int8 *)&ExpEnvironmentLock);
    while ( __strex(v30 & 0xFE, (unsigned __int8 *)&ExpEnvironmentLock) );
    __dmb(0xBu);
    if ( (v30 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&ExpEnvironmentLock, v28);
    if ( v29 )
      *(_BYTE *)(v29 + 14) |= 1u;
    dword_61A084 = v27;
    if ( v38 )
    {
      for ( i = 0; i <= 0xFFFF; ++i )
      {
        swprintf_s((int)_48, 11, (int)L"Driver%04x", i);
        v36 = 0;
        v10 = IoGetEnvironmentVariableEx((int)_48, (int)EfiDriverVariablesGuid, 0, (int)&v36, 0);
        if ( v10 == -1073741568 )
        {
          if ( (i & (2 * ((i | (2 * i)) & 0xC4444444))) != 0 )
          {
            swprintf_s((int)_48, 11, (int)L"Driver%04X", i);
            v36 = 0;
            v10 = IoGetEnvironmentVariableEx((int)_48, (int)EfiDriverVariablesGuid, 0, (int)&v36, 0);
          }
          if ( v10 == -1073741568 )
            break;
        }
        if ( v10 && v10 != -1073741789 )
          goto LABEL_62;
      }
      if ( i > 0xFFFF )
      {
        v10 = -1073741670;
        goto LABEL_62;
      }
    }
    else
    {
      i = v14[2];
      swprintf_s((int)_48, 11, (int)L"Driver%04X", i);
      v36 = 0;
      v10 = IoGetEnvironmentVariableEx((int)_48, (int)EfiDriverVariablesGuid, 0, (int)&v36, 0);
      if ( v10 == -1073741568 && (v14[2] & (2 * ((v14[2] | (2 * v14[2])) & 0xC4444444))) != 0 )
      {
        swprintf_s((int)_48, 11, (int)L"Driver%04x");
        v36 = 0;
        v10 = IoGetEnvironmentVariableEx((int)_48, (int)EfiDriverVariablesGuid, 0, (int)&v36, 0);
      }
      if ( v10 && v10 != -1073741789 )
        goto LABEL_62;
    }
    v10 = IoSetEnvironmentVariableEx((int)_48, (int)EfiDriverVariablesGuid, v42, v41 + 6, 1);
LABEL_62:
    dword_61A084 = 0;
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)&ExpEnvironmentLock);
    while ( !v31 && __strex(1u, (unsigned int *)&ExpEnvironmentLock) );
    if ( v31 )
      ExpReleaseFastMutexContended((unsigned int *)&ExpEnvironmentLock, v31);
    v32 = KeAbPostRelease((unsigned int)&ExpEnvironmentLock);
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v34 = *(_WORD *)(v33 + 0x134) + 1;
    *(_WORD *)(v33 + 308) = v34;
    if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      KiCheckForKernelApcDelivery(v32);
  }
LABEL_73:
  if ( v42 )
    ExFreePoolWithTag(v42);
  if ( v43 && v43 != (_BYTE *)v19 )
    ExFreePoolWithTag((unsigned int)v43);
  ExFreePoolWithTag((unsigned int)v14);
  if ( v38 && v47 && v10 >= 0 )
    *v47 = i;
  v39 = v10;
  return v10;
}
