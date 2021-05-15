// PspBuildCreateProcessContext 
 
int __fastcall PspBuildCreateProcessContext(_DWORD *a1, int a2, int a3, _BYTE *a4)
{
  int v4; // r10
  int v5; // lr
  int v6; // r2
  unsigned int v8; // r3
  unsigned int *v9; // r6
  unsigned int i; // r3
  unsigned int v11; // r2
  int v12; // r5
  int v13; // r1
  unsigned int v14; // r4
  unsigned int v15; // r8
  int v16; // r0
  unsigned int v17; // r2
  unsigned int v18; // r2
  int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r2
  unsigned int v22; // r4
  unsigned int v23; // r8
  int v24; // r0
  unsigned int v25; // r4
  unsigned int v26; // r8
  int v27; // r0
  _DWORD *v28; // r1
  int v29; // r0
  _DWORD *v30; // r2
  unsigned __int16 *v31; // r2
  unsigned int v32; // r2
  int *v33; // r2
  int v34; // r2
  _DWORD *v35; // r0
  int v36; // r2
  int v37; // r3
  unsigned int v38; // r0
  unsigned int v39; // r2
  unsigned int v40; // r4
  unsigned int v41; // r8
  int v42; // r0
  unsigned int v43; // r4
  __int64 v44; // kr00_8
  int v45; // r1
  unsigned int v46; // r3
  int v47; // [sp+4h] [bp-3Ch]
  int v48; // [sp+8h] [bp-38h]
  unsigned int v49; // [sp+Ch] [bp-34h]
  unsigned int v50; // [sp+10h] [bp-30h]
  int v51; // [sp+14h] [bp-2Ch]
  unsigned int *v52; // [sp+18h] [bp-28h]
  int varg_r1; // [sp+4Ch] [bp+Ch]

  varg_r1 = a2;
  v4 = (int)a4;
  v47 = a3;
  a2 = (char)a2;
  v5 = a2;
  v48 = (char)a2;
  *a4 = a2;
  if ( (_BYTE)a2 && ((unsigned __int8)a1 & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  v6 = *a1;
  if ( *a1 < 0x14u )
    return -1073741811;
  if ( (_BYTE)a2 && v6 != 20 )
  {
    if ( ((unsigned __int8)a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( (unsigned int)a1 + v6 > MmUserProbeAddress || (_DWORD *)((char *)a1 + v6) < a1 + 5 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v8 = v6 - 4;
  if ( ((v6 - 4) & 0xF) != 0 )
    return -1073741811;
  v49 = v8 >> 4;
  v50 = v8 >> 4;
  v9 = a1 + 1;
  v52 = a1 + 1;
  for ( i = v8 >> 4; i; v50 = i )
  {
    v11 = *v9;
    if ( v47 && (v11 & 0x10000) == 0 )
      goto LABEL_19;
    if ( (v11 & 0x20000) != 0 && v9[3] )
      goto LABEL_19;
    v13 = *(_DWORD *)(v4 + 4);
    if ( (v13 & (1 << v11)) != 0 )
      goto LABEL_19;
    *(_DWORD *)(v4 + 4) = (1 << v11) | v13;
    if ( v11 > 0x2000D )
    {
      if ( v11 > 0x60000 )
      {
        switch ( v11 )
        {
          case 0x60001u:
            if ( v9[1] != 4 )
              goto LABEL_19;
            *(_DWORD *)(v4 + 84) = v9[2];
            break;
          case 0x60002u:
            if ( v9[1] != 4 )
              goto LABEL_19;
            *(_DWORD *)(v4 + 88) = v9[2];
            break;
          case 0x60011u:
            if ( v9[1] != 1 )
              goto LABEL_19;
            v46 = v9[2];
            *(_BYTE *)(v4 + 216) = v46;
            if ( !RtlValidProcessProtection((unsigned __int8)v46) )
              goto LABEL_19;
            goto LABEL_190;
          default:
            goto LABEL_19;
        }
      }
      else
      {
        switch ( v11 )
        {
          case 0x60000u:
            if ( v9[1] != 4 )
              goto LABEL_19;
            *(_DWORD *)(v4 + 76) = v9[2];
            break;
          case 0x20010u:
            if ( v9[1] != 8 )
              goto LABEL_19;
            if ( v5 && (v9[2] & 7) != 0 )
              ExRaiseDatatypeMisalignment(1);
            v44 = *(_QWORD *)v9[2];
            v43 = *(_DWORD *)v9[2];
            __dmb(0xBu);
            v12 = PspValidateMitigationOptions(__SPAIR64__(HIDWORD(v44), v43), 0x4444444444444i64);
            if ( v12 < 0 )
              goto LABEL_193;
            *(_DWORD *)(v4 + 208) = v43;
            *(_DWORD *)(v4 + 212) = v45;
            v49 = v50;
            v9 = v52;
LABEL_190:
            v5 = v48;
            break;
          case 0x20013u:
            v40 = v9[1];
            if ( !v40 || (v40 & 3) != 0 )
              goto LABEL_19;
            v41 = v9[2];
            if ( v5 )
            {
              if ( (v41 & 3) != 0 )
                ExRaiseDatatypeMisalignment(1);
              if ( v41 + v40 > MmUserProbeAddress || v41 + v40 < v41 )
                *(_BYTE *)MmUserProbeAddress = 0;
            }
            v42 = ExAllocatePoolWithQuotaTag(0x208u, v40, 1816818512);
            *(_DWORD *)(v4 + 232) = v42;
            if ( !v42 )
            {
LABEL_40:
              v12 = -1073741670;
              goto LABEL_193;
            }
            memmove(v42, v41, v40);
            *(_DWORD *)(v4 + 236) = v40 >> 2;
            goto LABEL_190;
          case 0x3000Cu:
            if ( !v47 || v9[1] != 12 )
              goto LABEL_19;
            v35 = (_DWORD *)v9[2];
            if ( v5 && ((unsigned __int8)v35 & 3) != 0 )
              ExRaiseDatatypeMisalignment(v35);
            v36 = v35[1];
            v37 = v35[2];
            *(_DWORD *)(v4 + 192) = *v35;
            *(_DWORD *)(v4 + 196) = v36;
            *(_DWORD *)(v4 + 200) = v37;
            v38 = KeQueryActiveGroupCount();
            v39 = *(unsigned __int16 *)(v4 + 196);
            if ( v39 >= v38
              || (dword_681D78[v39] & *(_DWORD *)(v4 + 192)) != *(_DWORD *)(v4 + 192)
              || *(unsigned __int16 *)(v4 + 198) | *(unsigned __int16 *)(v4 + 202) | *(unsigned __int16 *)(v4 + 200) )
            {
LABEL_19:
              v12 = -1073741811;
              goto LABEL_193;
            }
            goto LABEL_190;
          default:
            if ( v11 != 196622 || !v47 || v9[1] != 4 )
              goto LABEL_19;
            v33 = (int *)v9[2];
            if ( v5 && ((unsigned __int8)v33 & 1) != 0 )
              ExRaiseDatatypeMisalignment(1);
            v51 = *v33;
            if ( HIBYTE(*v33) || (_WORD)v51 || (v34 = BYTE2(v51), BYTE2(v51) >= (unsigned int)KeNumberProcessors_0) )
              v34 = -1;
            *(_DWORD *)(v4 + 148) = v34;
            if ( v34 == -1 )
              goto LABEL_19;
            break;
        }
      }
    }
    else if ( v11 == 131085 )
    {
      if ( v9[1] != 2 )
        goto LABEL_19;
      v31 = (unsigned __int16 *)v9[2];
      if ( v5 && ((unsigned __int8)v31 & 1) != 0 )
        ExRaiseDatatypeMisalignment(1);
      v32 = *v31;
      if ( v32 >= (unsigned __int16)KeNumberNodes || !*((_DWORD *)*(&KeNodeBlock + v32) + 65) )
        goto LABEL_19;
      *(_WORD *)(v4 + 146) = v32;
    }
    else if ( v11 > 0x20007 )
    {
      switch ( v11 )
      {
        case 0x20008u:
          if ( v9[1] != 1 )
            goto LABEL_19;
          *(_BYTE *)(v4 + 144) = *(_BYTE *)v9[2];
          break;
        case 0x20009u:
          if ( v9[1] != 4 )
            goto LABEL_19;
          v30 = (_DWORD *)v9[2];
          if ( v5 && ((unsigned __int8)v30 & 3) != 0 )
            ExRaiseDatatypeMisalignment(1);
          *(_DWORD *)(v4 + 188) = *v30;
          break;
        case 0x2000Au:
          if ( v9[1] != 8 )
            goto LABEL_19;
          v28 = (_DWORD *)v9[2];
          if ( v5 && ((unsigned __int8)v28 & 3) != 0 )
            ExRaiseDatatypeMisalignment(1);
          if ( (*v28 & 0x1C) != 0 )
          {
            v12 = -1073741637;
            goto LABEL_193;
          }
          v29 = *v28 & 3;
          if ( v29 == 3 )
            goto LABEL_19;
          *(_BYTE *)(v4 + 9) ^= (*(_BYTE *)(v4 + 9) ^ (2 * v29)) & 6;
          if ( v29 == 1 )
            *(_DWORD *)(v4 + 168) = v28[1];
          break;
        case 0x2000Bu:
          v25 = v9[1];
          if ( !v25 || (v25 & 3) != 0 )
            goto LABEL_19;
          v26 = v9[2];
          if ( v5 )
          {
            if ( (v26 & 3) != 0 )
              ExRaiseDatatypeMisalignment(1);
            if ( v26 + v25 > MmUserProbeAddress || v26 + v25 < v26 )
              *(_BYTE *)MmUserProbeAddress = 0;
          }
          v27 = ExAllocatePoolWithQuotaTag(0x208u, v25, 1816687440);
          *(_DWORD *)(v4 + 176) = v27;
          if ( !v27 )
            goto LABEL_40;
          memmove(v27, v26, v25);
          *(_DWORD *)(v4 + 172) = v25 >> 2;
          goto LABEL_190;
        default:
          goto LABEL_19;
      }
    }
    else
    {
      switch ( v11 )
      {
        case 0x20007u:
          v22 = v9[1];
          if ( !v22 || (v22 & 7) != 0 )
            goto LABEL_19;
          v23 = v9[2];
          if ( v5 )
          {
            if ( (v23 & 3) != 0 )
              ExRaiseDatatypeMisalignment(1);
            if ( v23 + v22 > MmUserProbeAddress || v23 + v22 < v23 )
              *(_BYTE *)MmUserProbeAddress = 0;
          }
          if ( v22 > 8 )
          {
            v24 = ExAllocatePoolWithQuotaTag(0x208u, v22, 1817342800);
            *(_DWORD *)(v4 + 164) = v24;
            if ( !v24 )
              goto LABEL_40;
          }
          else
          {
            *(_DWORD *)(v4 + 164) = v4 + 156;
          }
          memmove(*(_DWORD *)(v4 + 164), v23, v22);
          *(_DWORD *)(v4 + 152) = v22 >> 3;
          goto LABEL_190;
        case 6u:
          if ( v9[1] != 48 )
            goto LABEL_19;
          v21 = v9[2];
          if ( v5 )
          {
            if ( (v21 & 3) != 0 )
              ExRaiseDatatypeMisalignment(1);
            if ( v21 >= MmUserProbeAddress )
              *(_BYTE *)MmUserProbeAddress = 0;
            *(_BYTE *)v21 = *(_BYTE *)v21;
            *(_BYTE *)(v21 + 44) = *(_BYTE *)(v21 + 44);
          }
          *(_DWORD *)(v4 + 20) = v21;
          v18 = v9[3];
          if ( v18 )
          {
            if ( v5 )
            {
              if ( (v18 & 3) != 0 )
                ExRaiseDatatypeMisalignment(1);
              if ( v18 >= MmUserProbeAddress )
                *(_BYTE *)MmUserProbeAddress = 0;
              *(_BYTE *)v18 = *(_BYTE *)v18;
            }
            v19 = 48;
            goto LABEL_71;
          }
          break;
        case 0x10003u:
          if ( v9[1] != 8 )
            goto LABEL_19;
          v20 = v9[2];
          if ( v5 )
          {
            if ( (v20 & 3) != 0 )
              ExRaiseDatatypeMisalignment(1);
            if ( v20 >= MmUserProbeAddress )
              *(_BYTE *)MmUserProbeAddress = 0;
            *(_BYTE *)v20 = *(_BYTE *)v20;
            *(_BYTE *)(v20 + 4) = *(_BYTE *)(v20 + 4);
          }
          *(_DWORD *)(v4 + 12) = v20;
          v18 = v9[3];
          if ( v18 )
          {
            if ( v5 )
            {
              if ( (v18 & 3) != 0 )
                ExRaiseDatatypeMisalignment(1);
              if ( v18 >= MmUserProbeAddress )
                *(_BYTE *)MmUserProbeAddress = 0;
              *(_BYTE *)v18 = *(_BYTE *)v18;
            }
            v19 = 8;
            goto LABEL_71;
          }
          break;
        case 0x10004u:
          if ( v9[1] != 4 )
            goto LABEL_19;
          v17 = v9[2];
          if ( v5 )
          {
            if ( (v17 & 3) != 0 )
              ExRaiseDatatypeMisalignment(1);
            if ( v17 >= MmUserProbeAddress )
              *(_BYTE *)MmUserProbeAddress = 0;
            *(_BYTE *)v17 = *(_BYTE *)v17;
          }
          *(_DWORD *)(v4 + 16) = v17;
          v18 = v9[3];
          if ( v18 )
          {
            if ( v5 )
            {
              if ( (v18 & 3) != 0 )
                ExRaiseDatatypeMisalignment(1);
              if ( v18 >= MmUserProbeAddress )
                *(_BYTE *)MmUserProbeAddress = 0;
              *(_BYTE *)v18 = *(_BYTE *)v18;
            }
            v19 = 4;
LABEL_71:
            *(_DWORD *)v18 = v19;
            break;
          }
          break;
        case 0x20005u:
          v14 = v9[1];
          if ( !v14 || (v14 & 1) != 0 || v14 > 0xFFFF )
            goto LABEL_19;
          v15 = v9[2];
          if ( v5 && (v15 + v14 > MmUserProbeAddress || v15 + v14 < v15) )
            *(_BYTE *)MmUserProbeAddress = 0;
          v16 = ExAllocatePoolWithQuotaTag(0x208u, v14, 1850110800);
          if ( !v16 )
            goto LABEL_40;
          *(_WORD *)(v4 + 136) = 0;
          *(_WORD *)(v4 + 138) = v14;
          *(_DWORD *)(v4 + 140) = v16;
          memmove(v16, v15, v14);
          *(_WORD *)(v4 + 136) = v14;
          goto LABEL_190;
        default:
          goto LABEL_19;
      }
    }
    v9 += 4;
    v52 = v9;
    i = v49 - 1;
    v49 = i;
  }
  v12 = 0;
LABEL_193:
  if ( v12 < 0 )
    goto LABEL_199;
  if ( (*(_DWORD *)(v4 + 4) & 0x800) != 0 )
  {
    qsort(
      *(_DWORD *)(v4 + 176),
      *(_DWORD *)(v4 + 172),
      4u,
      (int (__fastcall *)(unsigned int, _BYTE *))PspSortHandleList);
    if ( **(int **)(v4 + 176) < 0 )
      v12 = -1073741811;
    *(_BYTE *)(v4 + 8) ^= (*(_BYTE *)(v4 + 8) ^ (v47 != 0)) & 1;
  }
  if ( v12 < 0 )
LABEL_199:
    PspDeleteCreateProcessContext(v4);
  return v12;
}
