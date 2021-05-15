// ObpCaptureBoundaryDescriptor 
 
int __fastcall ObpCaptureBoundaryDescriptor(int *a1, unsigned int *a2)
{
  int v2; // r5
  int *v3; // r2
  unsigned int v4; // r6
  int v5; // r4
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r3
  unsigned int v9; // r9
  unsigned int v10; // r1
  unsigned int v11; // r2
  unsigned int v12; // r0
  int v13; // r4
  int *v14; // r5
  int v15; // r0
  int v16; // r10
  unsigned int v17; // lr
  _DWORD *v18; // r2
  unsigned int v19; // r3
  int v20; // r4
  _DWORD v22[2]; // [sp+4h] [bp-64h] BYREF
  int *v23; // [sp+Ch] [bp-5Ch]
  int v24; // [sp+10h] [bp-58h]
  unsigned int *v25; // [sp+14h] [bp-54h]
  int v26; // [sp+18h] [bp-50h] BYREF
  int v27; // [sp+1Ch] [bp-4Ch]
  int v28; // [sp+20h] [bp-48h]
  int v29; // [sp+24h] [bp-44h]
  int v30; // [sp+28h] [bp-40h]
  int v31; // [sp+2Ch] [bp-3Ch]
  unsigned int v32; // [sp+30h] [bp-38h]
  int v33; // [sp+34h] [bp-34h]
  int _38[16]; // [sp+38h] [bp-30h] BYREF

  v25 = a2;
  _38[15] = (int)a2;
  v2 = (int)a1;
  _38[14] = (int)a1;
  *a2 = 0;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    v3 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v3 = (int *)MmUserProbeAddress;
    v30 = *v3;
    v31 = v3[1];
    v32 = v3[2];
    v33 = v3[3];
    v4 = v32;
    if ( v32 < 0x10 || v32 > 0x7FFF )
    {
      v5 = -1073741811;
      v22[1] = -1073741811;
      return v5;
    }
    if ( ((unsigned __int8)a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
    if ( (unsigned int)a1 + v32 > MmUserProbeAddress || (int *)((char *)a1 + v32) < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  else
  {
    v6 = a1[1];
    v7 = a1[2];
    v8 = a1[3];
    v30 = *a1;
    v31 = v6;
    v32 = v7;
    v33 = v8;
    v4 = v7;
  }
  v9 = 0;
  v26 = 0;
  v24 = 0;
  v10 = v4;
  v11 = 0;
  v23 = 0;
  v22[0] = 0;
  v27 = 0;
  v28 = 0;
  if ( (v33 & 1) == 0 )
  {
LABEL_22:
    v26 = v10 + 24;
    if ( (__PAIR64__(v11, v10) + 24) >> 32 )
    {
      v5 = -1073741675;
      goto LABEL_34;
    }
    v15 = ExAllocatePoolWithTag(1, v10 + 24, 1397645903);
    v9 = v15;
    v29 = v15;
    if ( !v15 )
    {
      v5 = -1073741670;
LABEL_34:
      v14 = v23;
      goto LABEL_35;
    }
    *(_DWORD *)(v15 + 12) = v26 - 24;
    v16 = v15 + 24;
    v26 = v15 + 24;
    memmove(v15 + 24, v2, v4);
    v14 = v23;
    v17 = v27;
    if ( v23 )
    {
      v18 = (_DWORD *)(v16 + v4);
      if ( v16 + v4 != ((v16 + v4 + 7) & 0xFFFFFFF8) )
      {
LABEL_27:
        v5 = -1073741811;
        goto LABEL_35;
      }
      *v18 = 2;
      v19 = ((v17 + 7) & 0xFFFFFFF8) + 8;
      v18[1] = v19;
      v4 += v19;
      v20 = v31 + 1;
      memmove((int)(v18 + 2), *v14, v17);
    }
    else
    {
      v20 = v31;
    }
    *(_DWORD *)(v9 + 32) = v4;
    *(_DWORD *)(v9 + 28) = v20;
    v5 = RtlEnumerateBoundaryDescriptorEntries(v9 + 24, 0, 0);
    if ( v5 < 0 || ObpCheckDuplicateEntries(v9) )
    {
      *(_BYTE *)(v9 + 20) = 0;
      RtlEnumerateBoundaryDescriptorEntries(v9 + 24, ObpHashBoundaryFunction, v9);
      *(_BYTE *)(v9 + 20) = *(unsigned __int8 *)(v9 + 20) % 37;
      goto LABEL_35;
    }
    goto LABEL_27;
  }
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = 1;
  SeCaptureSubjectContextEx((_DWORD *)v12, *(_DWORD **)(v12 + 116), _38);
  v13 = _38[0];
  if ( !_38[0] )
    v13 = _38[2];
  SeQueryInformationToken(v13, 29, &v26);
  if ( !v26 )
  {
    v10 = v4;
    v11 = 0;
    goto LABEL_22;
  }
  v5 = SeQueryInformationToken(v13, 31, v22);
  if ( v5 >= 0 )
  {
    v23 = (int *)v22[0];
    v27 = RtlLengthSid(*(_DWORD *)v22[0]);
    v28 = v27;
    v10 = ((v27 + 7) & 0xFFFFFFF8) + 8 + v4;
    v11 = (((v27 + 7) & 0xFFFFFFF8) + 8 + (unsigned __int64)v4) >> 32;
    goto LABEL_22;
  }
  v14 = (int *)v22[0];
LABEL_35:
  if ( v14 )
    ExFreePoolWithTag((unsigned int)v14);
  if ( v24 )
    SeReleaseSubjectContext((int)_38);
  if ( v5 < 0 )
  {
    if ( v9 )
      ExFreePoolWithTag(v9);
  }
  else
  {
    *v25 = v9;
  }
  return v5;
}
