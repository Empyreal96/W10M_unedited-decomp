// WmiQueryTraceInformation 
 
int __fastcall WmiQueryTraceInformation(int a1, _DWORD *a2, unsigned int a3, unsigned int *a4, unsigned int *a5)
{
  int v8; // r10
  unsigned int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r3
  unsigned int v14; // r3
  unsigned int v15; // r4
  int v16; // r3
  int v17; // r3
  __int16 v18; // r3
  unsigned int v19; // r1
  int v20; // r2
  unsigned int v21; // r1
  int v22; // r2
  unsigned int *v23; // r0
  unsigned int v24; // r4
  int v25; // r3
  unsigned int i; // r4
  _DWORD *v27; // r0
  int v28; // r2
  unsigned int v29; // r2
  unsigned int v30; // r1
  int v31; // r0
  _DWORD *v32; // r0
  int v33; // r4
  unsigned int v34; // r8
  _DWORD *v35; // lr
  unsigned int v36; // r1
  unsigned int v37; // r9
  unsigned int v38; // r2
  unsigned __int16 v39; // r3
  int v40; // r2
  unsigned int v41; // r2
  _DWORD *v42; // r0
  unsigned int v43; // r1
  int v44; // r3
  int *v45; // r3
  int v47; // [sp+0h] [bp-40h]
  unsigned int v48; // [sp+0h] [bp-40h]
  unsigned int v49; // [sp+10h] [bp-30h] BYREF
  int v50; // [sp+14h] [bp-2Ch]
  unsigned __int64 v51; // [sp+18h] [bp-28h]
  int varg_r0; // [sp+48h] [bp+8h]
  _DWORD *varg_r1; // [sp+4Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+50h] [bp+10h]
  unsigned int *varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v8 = 0;
  if ( a4 )
    *a4 = 0;
  switch ( a1 )
  {
    case 0:
      if ( a3 != 4 )
        return -1073741820;
      if ( !a5 )
        return -1073741776;
      v10 = a5[2];
      v11 = a5[3];
      v49 = v10;
      v50 = v11;
      if ( !(v10 | v11) || v10 == -1 && !v11 )
        return -1073741816;
      if ( (unsigned __int16)v49 >= 0x40u )
        return -1073741816;
      ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[(unsigned __int16)v49], 1);
      v12 = WmipLoggerContext[(unsigned __int16)v49];
      if ( (v12 & 1) != 0 || !PsEqualCurrentServerSilo(*(_DWORD *)(v12 + 652)) )
      {
        ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[(unsigned __int16)v49], 1);
        v13 = 0;
      }
      else
      {
        ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[(unsigned __int16)v49], 1);
        v13 = 1;
      }
      if ( v13 )
      {
        if ( a2 )
          *a2 = (unsigned __int16)v49;
        goto LABEL_23;
      }
      return -1073741816;
    case 1:
      if ( a3 != 8 )
        return -1073741820;
      if ( !a5 )
        return -1073741776;
      v15 = *a5;
      if ( *a5 >= 0x40 )
        return -1073741816;
      ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[*a5], 1);
      v16 = WmipLoggerContext[v15];
      if ( (v16 & 1) != 0 || !PsEqualCurrentServerSilo(*(_DWORD *)(v16 + 652)) )
      {
        ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v15], 1);
        v17 = 0;
      }
      else
      {
        ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v15], 1);
        v17 = 1;
      }
      if ( v17 )
      {
        v49 = 0;
        v50 = 0;
        if ( v15 )
          v18 = v15;
        else
          v18 = -1;
        LOWORD(v49) = v18;
        if ( a2 )
        {
          *a2 = v49;
          goto LABEL_43;
        }
        goto LABEL_44;
      }
      return -1073741816;
    case 2:
      if ( a3 < 4 )
        return -1073741820;
      if ( !a5 )
        return -1073741776;
      v19 = a5[2];
      v20 = a5[3];
      v49 = v19;
      v50 = v20;
      if ( v19 | v20 && (v19 != -1 || v20) )
      {
        if ( a2 )
          *a2 = v20;
        goto LABEL_23;
      }
      return -1073741816;
    case 3:
      if ( a3 < 4 )
        return -1073741820;
      if ( !a5 )
        return -1073741776;
      v21 = a5[2];
      v22 = a5[3];
      v49 = v21;
      v50 = v22;
      if ( v21 | v22 && (v21 != -1 || v22) )
      {
        if ( a2 )
          *a2 = BYTE2(v49);
LABEL_23:
        if ( a4 )
        {
          v14 = 4;
          goto LABEL_25;
        }
        return v8;
      }
      return -1073741816;
    case 4:
      if ( a3 != 8 )
        return -1073741820;
      v23 = (unsigned int *)EtwpAcquireLoggerContextByLoggerId(1u, 0);
      if ( v23 )
      {
        v24 = *v23;
        v49 = *v23;
        v50 = 0;
        EtwpReleaseLoggerContext(v23, 0);
        if ( a2 )
        {
          *a2 = v24;
LABEL_43:
          a2[1] = 0;
        }
        goto LABEL_44;
      }
      return -1073741275;
    case 5:
      return -1073741821;
    case 6:
      if ( a3 < 8 || !a2 )
        return -1073741820;
      v25 = 0;
      v47 = 0;
      for ( i = 1; i < 0x40; ++i )
      {
        v27 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(i, 0);
        v25 = v47;
        if ( v27 )
        {
          v28 = 2 * v47;
          if ( 8 * v47 + 8 <= a3 )
          {
            a2[v28] = i;
            a2[v28 + 1] = 0;
          }
          EtwpReleaseLoggerContext(v27, 0);
          v25 = ++v47;
        }
      }
      v14 = 8 * v25;
      if ( v14 > a3 )
        v8 = 261;
      if ( a4 )
        goto LABEL_25;
      return v8;
    case 7:
      if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) && *(_WORD *)a5 )
      {
        v29 = a5[1];
        if ( (v29 & 1) != 0 )
          ExRaiseDatatypeMisalignment(a1);
        v30 = *(unsigned __int16 *)a5 + v29;
        if ( v30 > MmUserProbeAddress || v30 < v29 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      if ( a3 != 8 )
        return -1073741820;
      v49 = 0;
      v50 = 0;
      v31 = EtwQueryTraceHandleByLoggerName((int)a5, (int)&v49);
      v8 = v31;
      if ( v31 < 0 )
        return v31;
      if ( a2 )
      {
        *a2 = v49;
        a2[1] = v50;
      }
      if ( a4 )
        *a4 = 8;
      return v8;
    case 8:
      if ( a3 != 4 )
        return -1073741820;
      if ( !a5 )
        return -1073741776;
      v32 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(*a5, 0);
      if ( !v32 )
        return -1073741275;
      v33 = v32[42];
      __dmb(0xBu);
      EtwpReleaseLoggerContext(v32, 0);
      if ( a2 )
        *a2 = v33;
      if ( a4 )
        *a4 = 4;
      return 0;
    case 9:
      if ( !a5 )
        return -1073741581;
      if ( !a4 )
        return -1073741582;
      *a4 = 32;
      if ( a3 < 0x20 )
        return -1073741820;
      if ( !a2 )
        return -1073741584;
      v40 = a5[1];
      v49 = *a5;
      v39 = v49;
      v50 = v40;
      v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v41 + 308);
      v42 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(v39, 0);
      if ( v42 )
      {
        *a2 = 1;
        a2[1] = v42[1];
        a2[2] = v42[38];
        a2[3] = v42[41];
        a2[4] = v42[3];
        a2[5] = v42[33];
        a2[7] = v42[31];
        a2[6] = v42[34];
        v42 = (_DWORD *)EtwpReleaseLoggerContext(v42, 0);
      }
      else
      {
        v8 = -1073741162;
      }
      v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v44 = (__int16)(*(_WORD *)(v43 + 0x134) + 1);
      *(_WORD *)(v43 + 308) = v44;
      if ( !v44 && *(_DWORD *)(v43 + 100) != v43 + 100 && !*(_WORD *)(v43 + 310) )
        KiCheckForKernelApcDelivery((int)v42);
      return v8;
    case 10:
      v49 = 0;
      v51 = 0i64;
      v48 = 0;
      if ( a3 != 8 )
        return -1073741820;
      if ( !a5 )
        return -1073741776;
      v34 = *a5;
      v35 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(*a5, 0);
      if ( !v35 )
        return -1073741275;
      v36 = 0;
      v37 = v49;
      while ( v36 < KeNumberProcessors_0 )
      {
        v38 = (__PAIR64__(v48, v37) + *(_QWORD *)(*((_DWORD *)*(&KiProcessorBlock + v36) + 899) + 8 * v34 + 384)) >> 32;
        v37 += *(_DWORD *)(*((_DWORD *)*(&KiProcessorBlock + v36) + 899) + 8 * v34 + 384);
        v48 = v38;
        v51 = __PAIR64__(v38, v37);
        ++v36;
      }
      EtwpReleaseLoggerContext(v35, 0);
      if ( a2 )
      {
        *a2 = v37;
        a2[1] = v48;
      }
LABEL_44:
      if ( a4 )
      {
        v14 = 8;
LABEL_25:
        *a4 = v14;
      }
      return v8;
    case 11:
      if ( a4 )
        *a4 = 4;
      if ( a3 != 4 )
        return -1073741820;
      if ( !a2 )
        return -1073741584;
      v45 = &EtwpDiskIoNotifyRoutines;
      goto LABEL_146;
    case 12:
      if ( a4 )
        *a4 = 60;
      if ( a3 != 60 )
        return -1073741820;
      if ( !a2 )
        return -1073741584;
      memmove((int)a2, (int)&EtwpAllNotifyRoutines, 0x3Cu);
      return 0;
    case 13:
      if ( a4 )
        *a4 = 4;
      if ( a3 != 4 )
        return -1073741820;
      if ( !a2 )
        return -1073741584;
      v45 = (int *)&EtwpFltIoNotifyRoutines;
      goto LABEL_146;
    case 15:
      if ( a4 )
        *a4 = 4;
      if ( a3 != 4 )
        return -1073741820;
      if ( !a2 )
        return -1073741584;
      v45 = (int *)&EtwpWdfNotifyRoutines;
LABEL_146:
      *a2 = v45;
      return 0;
    default:
      return -1073741821;
  }
}
