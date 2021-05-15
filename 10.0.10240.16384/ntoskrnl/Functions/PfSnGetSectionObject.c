// PfSnGetSectionObject 
 
int __fastcall PfSnGetSectionObject(unsigned int *a1, int *a2, int a3, int a4, int a5, unsigned int a6, int a7, int a8, _DWORD *a9, _BYTE *a10)
{
  _DWORD *v14; // r5
  int v15; // r4
  unsigned int *v16; // r4
  unsigned int v17; // r2
  int v18; // r6
  unsigned int v19; // r2
  unsigned int v20; // r2
  int v21; // r2
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r6
  int v26; // r4
  int v27; // r0
  int v28; // r2
  int v29; // r3
  char v30; // r2
  int v31; // [sp+10h] [bp-80h] BYREF
  int v32; // [sp+14h] [bp-7Ch] BYREF
  int v33; // [sp+18h] [bp-78h] BYREF
  int v34; // [sp+1Ch] [bp-74h]
  int v35[5]; // [sp+20h] [bp-70h] BYREF
  _DWORD *v36; // [sp+34h] [bp-5Ch]
  int v37[2]; // [sp+38h] [bp-58h] BYREF
  int v38[6]; // [sp+40h] [bp-50h] BYREF
  _QWORD v39[7]; // [sp+58h] [bp-38h] BYREF

  v33 = a3;
  *a9 = 0;
  *a10 = 0;
  v36 = a9;
  memset(v35, 0, sizeof(v35));
  v32 = 0;
  v31 = v35[4] | 2;
  v35[4] |= 2u;
  if ( a7 )
    v34 = 285212672;
  else
    v34 = 0x4000000;
  if ( a6 >= *(_DWORD *)(*a1 + 88) )
    return sub_8014A8(4, 2);
  v14 = (_DWORD *)(a1[26] + 32 * a6);
  if ( (v14[4] & 4) == 0 )
  {
    if ( (a2[16] & 1) == 0 )
    {
      memset(v39, 0, 24);
      v39[0] = 0x100000003i64;
      v39[2] = *(_QWORD *)(a4 + 24);
      if ( v39[2] )
        PfSnPrefetchFileMetadata((int)a1, a2[4], (int)v39, 0, 1u, a8);
    }
    v15 = PfpOpenHandleCreate(v35, a1 + 1, v33, a2[9], 161, 64, 128, a2 + 4);
    if ( v15 < 0 || (v15 = PfpFileCheckAttributesForPrefetch(v35[0]), v15 < 0) )
    {
      v30 = v35[4];
      v31 = v35[4];
      goto LABEL_34;
    }
    v16 = a1 + 35;
    v17 = a1[35];
    __dmb(0xBu);
    if ( v17 < a1[36] )
    {
      v18 = v35[1];
      if ( IoQueryFileInformation(v35[1], 6, 8, (int)v37, (int)&v31) >= 0 )
      {
        __dmb(0xBu);
        do
        {
          v19 = __ldrex(v16);
          v20 = v19 + 1;
        }
        while ( __strex(v20, v16) );
        __dmb(0xBu);
        v21 = a1[34] + 16 * v20;
        *(_DWORD *)(v21 - 8) = v37[0];
        *(_DWORD *)(v21 - 4) = v37[1];
        *(_DWORD *)(v21 - 16) = *(_DWORD *)(v18 + 12);
        *(_DWORD *)(v21 - 12) = v35[3];
      }
    }
    v22 = v35[1];
    v23 = v35[2];
    v24 = v35[3];
    *v14 = v35[0];
    v14[1] = v22;
    v14[2] = v23;
    v14[3] = v24;
    v14[4] = v35[4];
    memset(v35, 0, sizeof(v35));
    v31 = v35[4] | 2;
    v35[4] |= 2u;
  }
  if ( a7 )
  {
    if ( v14[5] )
    {
      v26 = a5;
      v27 = a4;
      v28 = a5;
LABEL_43:
      if ( !PfSnIsSectionPrefetchedAfterPhase(v27, 1, v28) )
      {
        v29 = v14[7] | 1;
        goto LABEL_24;
      }
      goto LABEL_25;
    }
  }
  else if ( v14[6] )
  {
    v26 = a5;
    if ( !PfSnIsSectionPrefetchedAfterPhase(a4, 0, a5) )
    {
LABEL_23:
      v29 = v14[7] | 2;
LABEL_24:
      v14[7] = v29;
      *a10 = 1;
    }
LABEL_25:
    *v36 = v14[1];
    v25 = 0;
    if ( !PfSnIsSectionPrefetchedAfterPhase(a4, 1, v26)
      && !PfSnIsSectionPrefetchedAfterPhase(a4, 0, v26)
      && ((v26 & (*(_DWORD *)(a4 + 20) >> 8) & 0x7F) == 0 || a7) )
    {
      v14[7] |= 4u;
    }
    v15 = 0;
    goto LABEL_31;
  }
  v38[0] = 24;
  v38[1] = 0;
  v38[3] = 576;
  v38[2] = 0;
  v38[4] = 0;
  v38[5] = 0;
  v15 = NtCreateSection(&v32, 5, v38, 0, 2, v34, *v14);
  if ( v15 >= 0 )
  {
    v15 = ObReferenceObjectByHandle(v32, 5, MmSectionObjectType, 0, (int)&v33, 0);
    v25 = v33;
    if ( v15 < 0 )
    {
LABEL_31:
      if ( v25 )
        ObfDereferenceObject(v25);
      goto LABEL_33;
    }
    v26 = a5;
    v27 = a4;
    v28 = a5;
    if ( !a7 )
    {
      v14[6] = v33;
      if ( PfSnIsSectionPrefetchedAfterPhase(a4, 0, a5)
        && (v14[5] || !PfSnIsSectionPrefetchedAfterPhase(a4, 1, a5) && (a5 & (*(_DWORD *)(a4 + 20) >> 8) & 0x7F) == 0) )
      {
        goto LABEL_25;
      }
      goto LABEL_23;
    }
    v14[5] = v33;
    goto LABEL_43;
  }
LABEL_33:
  v30 = v31;
LABEL_34:
  if ( v32 )
  {
    NtClose();
    v30 = v31;
  }
  if ( (v30 & 4) != 0 )
    PfpOpenHandleClose(v35, a1 + 1);
  return v15;
}
