// CmpBuildAdminInformation 
 
int __fastcall CmpBuildAdminInformation(int a1)
{
  int v1; // r4
  int v2; // r7
  unsigned int v3; // r8
  unsigned int v4; // r4
  unsigned __int16 **v5; // r1
  int v6; // r0
  unsigned __int16 *v7; // r2
  int v8; // r10
  int v9; // r9
  int v10; // r5
  unsigned __int16 *v11; // r6
  unsigned __int16 *v12; // r8
  int v13; // r7
  unsigned int v14; // r4
  int *v15; // r6
  unsigned int v16; // r8
  int v17; // t1
  _DWORD *v18; // r3
  int v19; // r2
  int v20; // r1
  int *v21; // r0
  int *v22; // r6
  int v23; // r5
  unsigned int v24; // r1
  unsigned __int16 ***v25; // r2
  unsigned __int16 ***v26; // r2
  __int64 v27; // r2
  int v28; // r4
  int **v29; // r3
  char v31; // [sp+10h] [bp-50h] BYREF
  char v32[3]; // [sp+11h] [bp-4Fh] BYREF
  unsigned __int16 ***v33; // [sp+14h] [bp-4Ch] BYREF
  unsigned __int16 *v34; // [sp+18h] [bp-48h] BYREF
  int v35; // [sp+1Ch] [bp-44h] BYREF
  unsigned __int16 *v36; // [sp+20h] [bp-40h]
  int v37; // [sp+24h] [bp-3Ch] BYREF
  int **v38; // [sp+28h] [bp-38h]
  int v39[12]; // [sp+30h] [bp-30h] BYREF

  v38 = (int **)a1;
  v1 = PsReferenceImpersonationToken(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, (int)v32, (int)&v31, (int)&v37);
  if ( !v1 )
    v1 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  if ( !v1 )
    return -1073741670;
  v2 = SeQueryInformationToken(v1, 22, &v33);
  v37 = v2;
  ObfDereferenceObject(v1);
  if ( v2 >= 0 )
  {
    v3 = (unsigned int)v33;
    v4 = 0;
    v5 = *v33;
    v6 = SeExports;
    v7 = **v33;
    v8 = -1;
    v9 = -1;
    v10 = 8 * (_DWORD)v7;
    v34 = v7;
    v35 = SeExports;
    if ( v7 )
    {
      v11 = v5[1];
      v12 = v7;
      v13 = SeExports;
      do
      {
        v36 = *(unsigned __int16 **)v11;
        v34 = v36;
        v10 += RtlLengthSid((int)v36);
        if ( v8 == -1 && RtlEqualSid(*(unsigned __int16 **)(v13 + 228), v36) )
        {
          v8 = v4;
        }
        else if ( v9 == -1 && (*((_DWORD *)v11 + 1) & 0x60) == 96 )
        {
          v9 = v4;
        }
        ++v4;
        v11 += 4;
      }
      while ( v4 < (unsigned int)v12 );
      v2 = v37;
      v3 = (unsigned int)v33;
      v6 = v35;
    }
    v14 = 0;
    if ( v8 == -1 )
    {
      v39[0] = *(_DWORD *)(v6 + 228);
      v39[1] = 7;
      v14 = 1;
    }
    if ( v9 == -1 )
    {
      v39[2 * v14] = *(_DWORD *)(v6 + 384);
      v39[2 * v14++ + 1] = 96;
    }
    if ( v14 )
    {
      v10 += 8 * v14;
      v15 = v39;
      v16 = v14;
      do
      {
        v17 = *v15;
        v15 += 2;
        v10 += RtlLengthSid(v17);
        --v16;
      }
      while ( v16 );
      v3 = (unsigned int)v33;
    }
    v18 = *(_DWORD **)(v3 + 8);
    v33 = (unsigned __int16 ***)((v10 + 3) & 0xFFFFFFFC);
    v19 = 3 * *v18;
    v20 = (int)&v33[v19 + 120];
    if ( v19 * 4 )
      v20 = (int)&v33[v19 + 117];
    v21 = (int *)ExAllocatePoolWithTag(1, v20, 538987843);
    v22 = v21;
    if ( v21 )
    {
      v23 = (int)(v21 + 14);
      v21[3] = *(_DWORD *)(v3 + 12);
      v21[4] = *(_DWORD *)(v3 + 16);
      v21[5] = *(_DWORD *)(v3 + 20);
      v21[6] = *(_DWORD *)(v3 + 24);
      v21[7] = *(_DWORD *)(v3 + 28);
      v21[8] = *(_DWORD *)(v3 + 32) & 0xFFFF9FFF | 0x2000;
      v24 = **(_DWORD **)v3 + v14;
      v25 = v33;
      v21[14] = v24;
      v21[15] = (int)(v21 + 48);
      RtlCopySidAndAttributesArray(
        **(_DWORD **)v3,
        *(int **)(*(_DWORD *)v3 + 4),
        (unsigned int)&v25[-2 * v24],
        (int)(v21 + 48),
        (int)&v21[2 * v24 + 48],
        (int *)&v34,
        (unsigned int *)&v35);
      if ( v8 != -1 )
        *(_DWORD *)(*(_DWORD *)(v23 + 4) + 8 * v8 + 4) = 7;
      if ( v9 != -1 )
        *(_DWORD *)(*(_DWORD *)(v23 + 4) + 8 * v9 + 4) = 96;
      if ( v14 )
        RtlCopySidAndAttributesArray(
          v14,
          v39,
          v35,
          *(_DWORD *)(v23 + 4) + 8 * **(_DWORD **)v3,
          (int)v34,
          (int *)&v34,
          (unsigned int *)&v35);
      RtlSidHashInitialize(*(int **)(v23 + 4), *(_DWORD *)v23, v23);
      v26 = v33;
      *v22 = v23;
      HIDWORD(v27) = (char *)v26 + *(_DWORD *)(v23 + 4);
      LODWORD(v27) = 0;
      *(_QWORD *)HIDWORD(v27) = 0i64;
      v22[1] = HIDWORD(v27);
      *(_QWORD *)(HIDWORD(v27) + 136) = 0i64;
      HIDWORD(v27) += 136;
      *((_QWORD *)v22 + 5) = v27;
      v28 = HIDWORD(v27) + 136;
      *(_DWORD *)(HIDWORD(v27) + 136) = **(_DWORD **)(v3 + 8);
      RtlCopyLuidAndAttributesArray();
      v29 = v38;
      v22[2] = v28;
      *v29 = v22;
    }
    else
    {
      v2 = -1073741670;
    }
    ExFreePoolWithTag(v3);
  }
  return v2;
}
