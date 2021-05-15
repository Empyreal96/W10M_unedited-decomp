// MmCreatePeb 
 
int __fastcall MmCreatePeb(_DWORD *a1, unsigned __int8 *a2, int a3, _DWORD *a4)
{
  int v6; // r6
  int v7; // r10
  int v8; // r5
  int v9; // r4
  int v10; // r0
  int v11; // lr
  unsigned __int8 *v12; // r1
  int v13; // r10
  unsigned int v14; // r2
  __int16 v15; // r3
  int v16; // r4
  int v17; // r0
  int *v18; // r4
  int v19; // r9
  unsigned int v20; // r3
  int v22; // [sp+18h] [bp-110h] BYREF
  int v23; // [sp+1Ch] [bp-10Ch] BYREF
  unsigned int v24; // [sp+20h] [bp-108h]
  int v25; // [sp+24h] [bp-104h] BYREF
  int v26; // [sp+28h] [bp-100h]
  int v27; // [sp+2Ch] [bp-FCh]
  int v28; // [sp+30h] [bp-F8h]
  int v29; // [sp+34h] [bp-F4h]
  unsigned int v30; // [sp+38h] [bp-F0h]
  unsigned __int8 *v31; // [sp+3Ch] [bp-ECh]
  int v32; // [sp+40h] [bp-E8h]
  int v33; // [sp+44h] [bp-E4h]
  int v34; // [sp+48h] [bp-E0h]
  int v35; // [sp+4Ch] [bp-DCh]
  int *v36; // [sp+50h] [bp-D8h]
  int v37; // [sp+54h] [bp-D4h]
  int v38; // [sp+58h] [bp-D0h]
  int v39; // [sp+5Ch] [bp-CCh]
  int v40; // [sp+60h] [bp-C8h]
  int v41; // [sp+64h] [bp-C4h]
  int v42; // [sp+68h] [bp-C0h]
  int v43; // [sp+6Ch] [bp-BCh]
  _DWORD v44[2]; // [sp+70h] [bp-B8h] BYREF
  _DWORD v45[5]; // [sp+78h] [bp-B0h] BYREF
  int v46; // [sp+8Ch] [bp-9Ch]
  int v47; // [sp+90h] [bp-98h]
  unsigned int v48; // [sp+94h] [bp-94h]
  __int16 v49; // [sp+98h] [bp-90h]
  __int16 v50; // [sp+9Ah] [bp-8Eh]
  int v51; // [sp+9Ch] [bp-8Ch]
  int v52; // [sp+A0h] [bp-88h]
  int v53; // [sp+ACh] [bp-7Ch]
  int v54; // [sp+B0h] [bp-78h]
  int v55; // [sp+C0h] [bp-68h]
  char v56; // [sp+D0h] [bp-58h]
  char v57; // [sp+D1h] [bp-57h]
  int v58; // [sp+D4h] [bp-54h]
  int v59; // [sp+D8h] [bp-50h]
  int v60; // [sp+DCh] [bp-4Ch]
  int v61; // [sp+E0h] [bp-48h]
  int v62; // [sp+E4h] [bp-44h]
  int v63; // [sp+E8h] [bp-40h]
  unsigned int v64; // [sp+ECh] [bp-3Ch]
  _BYTE v65[56]; // [sp+F0h] [bp-38h] BYREF

  v36 = (int *)a3;
  v31 = a2;
  v33 = a3;
  v45[0] = a4;
  v22 = 0;
  v44[0] = 0;
  v44[1] = 0;
  v23 = 0;
  *a4 = 0;
  a4[1] = 0;
  a4[2] = 0;
  v64 = __clz(__rbit((a1[25] >> 8) & 1));
  *((_WORD *)a4 + 2) = v64;
  KiStackAttachProcess((int)a1, 0, (int)v65);
  v6 = MmMapViewOfSection(InitNlsSectionPointer, a1, &v22, 0, 0, v44, &v23, 1, 5242880, 2);
  if ( v6 < 0 )
    goto LABEL_2;
  v6 = MiCreatePebOrTeb(a1, 0, 592, &v25);
  if ( v6 < 0 )
    goto LABEL_2;
  v7 = a1[74];
  v23 = v7;
  v29 = 10;
  v46 = 10;
  v26 = 0;
  v47 = 0;
  v24 = 10240;
  v49 = 10240;
  v30 = 2;
  v48 = 2;
  v28 = (unsigned __int16)CmNtCSDVersion;
  v50 = CmNtCSDVersion;
  v37 = dword_681290;
  v51 = dword_681290;
  v39 = dword_68128C;
  v52 = dword_68128C;
  v42 = *v31;
  v56 = v42;
  v32 = v31[3];
  v57 = v32;
  v43 = *((_DWORD *)v31 + 1);
  v58 = v43;
  v38 = v7;
  v59 = v7;
  v41 = InitAnsiCodePageDataOffset + v22;
  v60 = InitAnsiCodePageDataOffset + v22;
  v40 = InitOemCodePageDataOffset + v22;
  v61 = InitOemCodePageDataOffset + v22;
  v44[0] = InitUnicodeCaseTableDataOffset + v22;
  v62 = InitUnicodeCaseTableDataOffset + v22;
  if ( a1[81] )
  {
    v27 = MmGetSessionId((int)a1);
    v54 = v27;
  }
  else
  {
    v27 = 0;
    v54 = 0;
  }
  v35 = 876;
  v53 = 876;
  v8 = v25;
  v34 = v25 + 592;
  v55 = v25 + 592;
  v9 = RtlImageNtHeader(v7);
  v63 = v9;
  if ( !v9 )
  {
    v6 = -1073741520;
LABEL_2:
    KiUnstackDetachProcess((unsigned int)v65, 0);
    return v6;
  }
  v10 = RtlImageDirectoryEntryToData(v7, 1, 10, (int)v45);
  if ( v10 && (v10 & 3) != 0 )
    ExRaiseDatatypeMisalignment(v10);
  v11 = *(unsigned __int16 *)(v9 + 92);
  v23 = v11;
  v45[2] = v11;
  v12 = (unsigned __int8 *)*(unsigned __int16 *)(v9 + 72);
  v31 = v12;
  v45[3] = v12;
  v13 = *(unsigned __int16 *)(v9 + 74);
  v45[4] = v13;
  v14 = *(_DWORD *)(v9 + 76);
  if ( v14 )
  {
    v29 = (unsigned __int8)v14;
    v46 = (unsigned __int8)v14;
    v26 = BYTE1(v14);
    v47 = BYTE1(v14);
    v24 = HIWORD(v14) & 0x3FFF;
    v49 = HIWORD(v14) & 0x3FFF;
    if ( v10 )
    {
      v15 = *(_WORD *)(v10 + 52);
      if ( v15 )
      {
        v28 = *(unsigned __int16 *)(v10 + 52);
        v50 = v15;
      }
    }
    v30 = (v14 ^ 0xBFFFFFFF) >> 30;
    v48 = v30;
  }
  if ( v10 )
  {
    v16 = *(_DWORD *)(v10 + 48);
    *a4 = v16;
    if ( (v16 & KeQueryGroupAffinity((unsigned __int16)v64)) != v16 )
      *a4 = 0;
    v11 = v23;
    v12 = v31;
  }
  v17 = v27;
  v18 = v36;
  v19 = v35;
  v20 = v30;
  *(_DWORD *)(v8 + 164) = v29;
  *(_DWORD *)(v8 + 168) = v26;
  *(_WORD *)(v8 + 172) = v24;
  *(_DWORD *)(v8 + 176) = v20;
  *(_WORD *)(v8 + 174) = v28;
  *(_DWORD *)(v8 + 120) = v37;
  *(_DWORD *)(v8 + 124) = v39;
  *(_DWORD *)(v8 + 100) = KeNumberProcessors_0;
  *(_DWORD *)(v8 + 104) = NtGlobalFlag;
  *(_DWORD *)(v8 + 112) = qword_6337C8;
  *(_DWORD *)(v8 + 116) = MEMORY[0x6337CC];
  *(_DWORD *)(v8 + 520) = dword_68127C;
  *(_DWORD *)(v8 + 144) = v34;
  *(_DWORD *)(v8 + 128) = dword_681288;
  *(_DWORD *)(v8 + 132) = dword_681284;
  *(_DWORD *)(v8 + 140) = v19;
  *(_DWORD *)(v8 + 468) = v17;
  *(_DWORD *)(v8 + 180) = v11;
  *(_DWORD *)(v8 + 184) = v12;
  *(_DWORD *)(v8 + 188) = v13;
  *(_BYTE *)v8 = v42;
  *(_BYTE *)(v8 + 3) = v32;
  *(_DWORD *)(v8 + 4) = v43;
  *(_DWORD *)(v8 + 8) = v38;
  *(_DWORD *)(v8 + 88) = v41;
  *(_DWORD *)(v8 + 92) = v40;
  *(_DWORD *)(v8 + 96) = v44[0];
  KiUnstackDetachProcess((unsigned int)v65, 0);
  *v18 = v8;
  return 0;
}
