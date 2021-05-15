// WmipQueryAllData 
 
int __fastcall WmipQueryAllData(int a1, int a2, char a3, char *a4, unsigned int a5, unsigned int *a6)
{
  int v8; // r8
  int v9; // r0
  unsigned int v10; // r4
  char *v11; // r7
  int v12; // r2
  unsigned int v13; // r6
  int v14; // r10
  char *v15; // r1
  char *v16; // r9
  int v17; // r5
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r3
  int v24; // r0
  int v25; // r2
  int v26; // r5
  unsigned int v27; // r3
  char *v28; // r9
  unsigned int v29; // r3
  unsigned int *v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r3
  int v35; // [sp+8h] [bp-F8h]
  char *v36; // [sp+Ch] [bp-F4h]
  char v37[4]; // [sp+10h] [bp-F0h] BYREF
  int v38; // [sp+14h] [bp-ECh] BYREF
  int v39; // [sp+18h] [bp-E8h]
  int v40; // [sp+1Ch] [bp-E4h]
  unsigned int v41; // [sp+20h] [bp-E0h]
  int v42; // [sp+24h] [bp-DCh]
  char *v43; // [sp+28h] [bp-D8h] BYREF
  int v44; // [sp+2Ch] [bp-D4h]
  int v45; // [sp+30h] [bp-D0h]
  unsigned int *v46; // [sp+34h] [bp-CCh]
  int v47; // [sp+38h] [bp-C8h]
  char *v48; // [sp+3Ch] [bp-C4h]
  int v49; // [sp+40h] [bp-C0h] BYREF
  int v50; // [sp+44h] [bp-BCh]
  int v51; // [sp+48h] [bp-B8h]
  int v52; // [sp+4Ch] [bp-B4h]
  char v53[8]; // [sp+50h] [bp-B0h] BYREF
  char v54[72]; // [sp+58h] [bp-A8h] BYREF
  char v55[96]; // [sp+A0h] [bp-60h] BYREF

  v46 = a6;
  v47 = a2;
  v48 = a4;
  v42 = a1;
  if ( !a1 )
    return sub_7D6258();
  v8 = ObReferenceObjectByPointer(a1, 1, WmipGuidObjectType, a3);
  if ( v8 < 0 )
    return v8;
  v43 = v55;
  v38 = 16;
  v8 = WmipPrepareForWnodeAD(v42, &v49, &v38, &v43, v37);
  if ( v8 < 0 )
    goto LABEL_38;
  if ( v37[0] )
  {
    v31 = v50;
    v32 = v51;
    v33 = v52;
    *((_DWORD *)a4 + 6) = v49;
    *((_DWORD *)a4 + 7) = v31;
    *((_DWORD *)a4 + 8) = v32;
    *((_DWORD *)a4 + 9) = v33;
    v34 = *((_DWORD *)a4 + 11);
    *((_DWORD *)a4 + 3) = 0;
    v8 = 0;
    *((_DWORD *)a4 + 11) = v34 | 0x100;
    *a6 = 48;
    goto LABEL_38;
  }
  v9 = *((_DWORD *)a4 + 11);
  v10 = a5;
  v11 = a4;
  v12 = 0;
  v8 = -1073741163;
  v13 = 0;
  v40 = v9;
  v41 = a5;
  v44 = 0;
  v45 = v38;
  v36 = a4;
  v14 = 0;
  if ( !v38 )
    goto LABEL_37;
  v15 = v43;
  v38 = (int)v43;
  v16 = 0;
  do
  {
    v17 = *(_DWORD *)v15;
    v35 = *(_DWORD *)v15;
    if ( v14 || v12 || v10 < 0x48 )
    {
      v11 = v54;
      memset(v54, 0, sizeof(v54));
      v41 = 72;
      v9 = v40;
      v44 = 1;
    }
    *(_DWORD *)v11 = 48;
    if ( (*(_DWORD *)(v17 + 8) & 3) != 0 )
    {
      v39 = 1;
      v18 = 128;
    }
    else
    {
      v39 = 0;
      v18 = 0;
    }
    *((_DWORD *)v11 + 11) = v18 | v9;
    v19 = v50;
    v20 = v51;
    v21 = v52;
    *((_DWORD *)v11 + 6) = v49;
    *((_DWORD *)v11 + 7) = v19;
    *((_DWORD *)v11 + 8) = v20;
    *((_DWORD *)v11 + 9) = v21;
    v22 = v47;
    v10 = v41;
    v23 = *(_DWORD *)(*(_DWORD *)v38 + 44);
    v38 += 4;
    *((_DWORD *)v11 + 1) = v23;
    *((_DWORD *)v11 + 3) = 0;
    if ( v22 )
      v24 = WmipForwardWmiIrp(v22, 0, *((_DWORD *)v11 + 1), v11 + 24, v10, v11);
    else
      v24 = WmipSendWmiIrp(0, *((_DWORD *)v11 + 1), v11 + 24, v10, v11, v53);
    if ( v24 < 0 )
      goto LABEL_27;
    v25 = *((_DWORD *)v11 + 11) & 0x20;
    if ( v25 )
    {
      if ( *((_DWORD *)v11 + 12) <= v10 )
        v24 = -1073741823;
    }
    else if ( !*((_DWORD *)v11 + 13) )
    {
      v24 = -1073741163;
    }
    if ( v24 < 0 )
    {
LABEL_27:
      v26 = v35;
      goto LABEL_28;
    }
    if ( v25 )
    {
      v29 = *((_DWORD *)v11 + 12);
      goto LABEL_43;
    }
    if ( v44 )
    {
      v29 = *(_DWORD *)v11;
LABEL_43:
      if ( v29 < 0x48 )
        v29 = 72;
      v13 += v29;
      if ( v39 )
      {
        if ( v13 + 3 >= v13 )
          v13 = (v13 + 3) & 0xFFFFFFFC;
        v26 = v35;
        v13 += WmipStaticInstanceNameSize(v35);
      }
      else
      {
        v26 = v35;
      }
      if ( v13 + 7 >= v13 )
        v13 = (v13 + 7) & 0xFFFFFFF8;
LABEL_53:
      v14 = 1;
LABEL_28:
      v11 = v36;
      goto LABEL_32;
    }
    if ( v16 )
      *((_DWORD *)v16 + 3) = v11 - v16;
    v26 = v35;
    v16 = v11;
    if ( v39 && (WmipInsertStaticNames(v11, v10, v35), (*((_DWORD *)v11 + 11) & 0x20) != 0) )
    {
      v27 = *((_DWORD *)v11 + 12);
      v14 = 1;
    }
    else
    {
      v27 = *(_DWORD *)v11;
    }
    if ( v27 + 7 >= v27 )
      v27 = (v27 + 7) & 0xFFFFFFF8;
    v13 += v27;
    if ( v14 || v10 < v27 )
      goto LABEL_53;
    v10 -= v27;
    v41 = v10;
    v11 = &v36[v27];
    v36 += v27;
LABEL_32:
    WmipUnreferenceEntry(&WmipISChunkInfo, v26);
    v12 = v44;
    v15 = (char *)v38;
    v9 = v40;
    --v45;
  }
  while ( v45 );
  v28 = v48;
  if ( v13 )
  {
    if ( v14 )
    {
      if ( v13 <= a5 )
        v13 = a5 + 64;
      *((_DWORD *)v48 + 11) = 32;
      *((_DWORD *)v28 + 12) = v13;
      v30 = v46;
      *(_DWORD *)v28 = 56;
      *v30 = 56;
    }
    else
    {
      *v46 = v13;
    }
    v8 = 0;
  }
LABEL_37:
  if ( v43 != v55 )
  {
    if ( v43 )
      ExFreePoolWithTag((unsigned int)v43);
  }
LABEL_38:
  ObfDereferenceObject(v42);
  return v8;
}
