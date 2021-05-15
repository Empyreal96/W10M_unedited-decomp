// PspSetQuotaLimits 
 
int __fastcall PspSetQuotaLimits(int a1, int a2, int a3, int a4)
{
  int v4; // r10
  int v5; // r8
  int v6; // r5
  int v7; // r4
  int v8; // r6
  int v9; // r2
  unsigned int v10; // r4
  int v11; // r3
  _DWORD *v12; // r5
  int v13; // r8
  int v14; // r2
  int v15; // r3
  _DWORD *v16; // r5
  unsigned int v17; // r8
  unsigned int v18; // r10
  int v19; // r6
  unsigned int v20; // r1
  int v21; // r0
  unsigned int v22; // r6
  __int16 v23; // r3
  unsigned int v24; // r0
  int v25; // r10
  _DWORD *v26; // r3
  char v28[3]; // [sp+11h] [bp-C7h] BYREF
  int v29; // [sp+14h] [bp-C4h]
  int v30; // [sp+18h] [bp-C0h] BYREF
  int v31; // [sp+1Ch] [bp-BCh]
  int v32; // [sp+20h] [bp-B8h]
  int v33; // [sp+24h] [bp-B4h]
  unsigned int v34; // [sp+28h] [bp-B0h]
  int v35; // [sp+2Ch] [bp-ACh]
  int v36; // [sp+30h] [bp-A8h]
  _DWORD *v37; // [sp+34h] [bp-A4h]
  int v38; // [sp+38h] [bp-A0h]
  _DWORD v39[14]; // [sp+40h] [bp-98h] BYREF
  _BYTE v40[24]; // [sp+78h] [bp-60h] BYREF
  _DWORD _90[23]; // [sp+90h] [bp-48h] BYREF
  int varg_r3; // [sp+ECh] [bp+14h]

  _90[20] = a1;
  _90[21] = a2;
  _90[22] = a3;
  varg_r3 = a4;
  v4 = (char)a4;
  LOBYTE(varg_r3) = a4;
  v29 = a1;
  v31 = a1;
  if ( a3 == 32 )
  {
    memmove((int)v39, a2, 0x20u);
    memset(&v39[8], 0, 24);
    v5 = 1;
  }
  else
  {
    if ( a3 != 56 )
    {
      v6 = -1073741820;
      v29 = -1073741820;
      return v6;
    }
    v5 = 0;
    memmove((int)v39, a2, 0x38u);
  }
  if ( (v39[12] & 0xFFFFFFE0) != 0 || (v39[12] & 3) == 3 || (v39[12] & 0xC) == 12 )
    return -1073741811;
  v7 = 0;
  if ( (v39[12] & 1) != 0 )
  {
    v7 = 4;
  }
  else if ( (v39[12] & 2) != 0 )
  {
    v7 = 8;
  }
  if ( (v39[12] & 4) != 0 )
  {
    v7 |= 1u;
  }
  else if ( (v39[12] & 8) != 0 )
  {
    v7 |= 2u;
  }
  if ( v39[9] | v39[13] | v39[11] | v39[10] )
    return -1073741811;
  v6 = ObReferenceObjectByHandleWithTag(v29, 256, PsProcessType, v4, 2035381072, &v30, 0);
  if ( v6 >= 0 )
  {
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = 0;
    v8 = v30;
    if ( *(int **)(v30 + 332) == PspSystemQuotaBlock )
    {
      if ( !v39[2] || (v9 = v39[3]) == 0 )
      {
        if ( v5 == 1 )
        {
          memset(v39, 0, sizeof(v39));
          v39[12] = 16;
        }
        if ( !SeSinglePrivilegeCheck(SeIncreaseQuotaPrivilege, dword_922794, v4) )
        {
          v6 = -1073741727;
LABEL_28:
          ObfDereferenceObjectWithTag(v8);
          return v6;
        }
        v10 = PsReferencePrimaryToken(v8);
        v6 = PspAssignProcessQuotaBlock(v39, v8, v10);
        ObFastDereferenceObject((_DWORD *)(v8 + 244), v10);
        if ( v6 < 0 )
          goto LABEL_28;
LABEL_72:
        ObfDereferenceObjectWithTag(v8);
        return v29;
      }
    }
    else
    {
      v9 = v39[3];
    }
    if ( v39[2] && v9 )
    {
      if ( v39[2] == -1 && v9 == -1 )
      {
        v35 = 1;
        v32 = 0;
        v11 = 0;
      }
      else
      {
        v35 = 0;
        v32 = (unsigned __int8)PspSinglePrivCheck();
        v11 = 1;
      }
      v31 = v11;
      v33 = 0;
      v12 = (_DWORD *)(v8 + 288);
      v37 = (_DWORD *)(v8 + 288);
      v13 = v34;
      while ( 1 )
      {
        v38 = 0;
        v36 = 0;
        KiStackAttachProcess(v8, 0, (int)v40);
        v15 = *(__int16 *)(v13 + 310) - 1;
        *(_WORD *)(v13 + 310) = v15;
        v16 = (_DWORD *)*v12;
        __dmb(0xBu);
        if ( v16 )
        {
          ExAcquireResourceExclusiveLite((int)(v16 + 8), 1, v14, v15);
          if ( (v16[100] & 1) == 0 || (v7 = 1, v32 = 1, v36 = 1, v38 = 1, v35) )
          {
            v18 = v39[3];
            v17 = v39[2];
          }
          else
          {
            v17 = v16[92];
            v39[2] = v17;
            v18 = v16[93];
            v39[3] = v18;
          }
          v19 = KeAbPreAcquire((unsigned int)&dword_618E28, 0, 0);
          do
            v20 = __ldrex((unsigned __int8 *)&dword_618E28);
          while ( __strex(v20 | 1, (unsigned __int8 *)&dword_618E28) );
          __dmb(0xBu);
          if ( (v20 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&dword_618E28, v19, (unsigned int)&dword_618E28);
          if ( v19 )
            *(_BYTE *)(v19 + 14) |= 1u;
          ExReleaseResourceLite((int)(v16 + 8));
        }
        else
        {
          v18 = v39[3];
          v17 = v39[2];
        }
        v21 = MmAdjustWorkingSetSizeEx(v17, v18, 0, v32, v7, v28);
        v29 = v21;
        if ( v21 < 0 && v38 == 1 )
          v21 = MmEnforceWorkingSetLimit(v30, v7);
        if ( v16 )
        {
          __dmb(0xBu);
          do
            v22 = __ldrex((unsigned int *)&dword_618E28);
          while ( __strex(v22 - 1, (unsigned int *)&dword_618E28) );
          if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)&dword_618E28);
          v21 = KeAbPostRelease((unsigned int)&dword_618E28);
        }
        v13 = v34;
        v23 = *(_WORD *)(v34 + 310) + 1;
        *(_WORD *)(v34 + 310) = v23;
        if ( !v23 && *(_DWORD *)(v13 + 100) != v13 + 100 )
          KiCheckForKernelApcDelivery(v21);
        v24 = KiUnstackDetachProcess((unsigned int)v40, 0);
        if ( v28[0] != 1 || v36 )
        {
          v25 = v33;
        }
        else
        {
          v25 = 1;
          v33 = 1;
        }
        v26 = (_DWORD *)*v37;
        __dmb(0xBu);
        if ( v26 == v16 )
          break;
        v8 = v30;
        v12 = v37;
      }
      if ( v31 == 1 )
        PspSinglePrivCheckAudit(v24, v25, _90);
      v8 = v30;
    }
    goto LABEL_72;
  }
  return v6;
}
