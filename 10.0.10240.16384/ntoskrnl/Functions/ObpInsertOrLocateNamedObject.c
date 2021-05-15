// ObpInsertOrLocateNamedObject 
 
int __fastcall ObpInsertOrLocateNamedObject(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, char a5, _DWORD *a6, int *a7)
{
  int *v7; // r5
  int v9; // r6
  char v10; // r3
  char v12; // r3
  int v13; // r10
  int v14; // r10
  int *v15; // r3
  int v16; // r0
  int v17; // r3
  int v18; // r0
  int v19; // r0
  int v20; // r7
  int v21; // r0
  int v22; // r4
  int result; // r0
  int v24; // r1
  int v25; // r6
  _DWORD *v26; // r4
  int v27; // r8
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r1
  int v47; // r2
  int v48; // r3
  bool v49[4]; // [sp+1Ch] [bp-E0h] BYREF
  _DWORD *v50; // [sp+20h] [bp-DCh] BYREF
  int v51; // [sp+24h] [bp-D8h] BYREF
  _DWORD *v52; // [sp+28h] [bp-D4h] BYREF
  int v53; // [sp+2Ch] [bp-D0h]
  _DWORD *v54; // [sp+30h] [bp-CCh]
  BOOL v55; // [sp+34h] [bp-C8h]
  int v56; // [sp+38h] [bp-C4h]
  int *v57; // [sp+3Ch] [bp-C0h]
  int v58; // [sp+44h] [bp-B8h] BYREF
  int v59; // [sp+48h] [bp-B4h]
  char v60; // [sp+56h] [bp-A6h]
  int v61; // [sp+5Ch] [bp-A0h] BYREF
  _DWORD v62[11]; // [sp+64h] [bp-98h] BYREF
  int v63; // [sp+90h] [bp-6Ch]
  int v64; // [sp+94h] [bp-68h]
  int v65; // [sp+98h] [bp-64h]
  int v66; // [sp+9Ch] [bp-60h]
  int v67; // [sp+A0h] [bp-5Ch]
  int v68; // [sp+A4h] [bp-58h]
  int v69; // [sp+A8h] [bp-54h]
  int v70; // [sp+ACh] [bp-50h]
  int v71; // [sp+B0h] [bp-4Ch]
  int v72; // [sp+B4h] [bp-48h]
  int v73; // [sp+B8h] [bp-44h]
  int v74; // [sp+BCh] [bp-40h]
  int v75; // [sp+C0h] [bp-3Ch]
  int v76; // [sp+C4h] [bp-38h]
  int v77; // [sp+C8h] [bp-34h]
  int v78; // [sp+CCh] [bp-30h]
  int v79; // [sp+D0h] [bp-2Ch]
  int v80; // [sp+D4h] [bp-28h]

  v7 = a7;
  v52 = a3;
  v53 = a1;
  v9 = (int)(a2 - 6);
  *a7 = 0;
  v61 = 0;
  v10 = *((_BYTE *)a2 - 10);
  v50 = 0;
  v57 = a7;
  if ( (v10 & 2) != 0 )
    return sub_7C4AF0(0);
  v12 = *((_BYTE *)a2 - 9);
  v51 = 0;
  if ( (v12 & 2) != 0 )
    JUMPOUT(0x762C80);
  v13 = ObpLookupObjectName(
          a6[1],
          4,
          *a6,
          ObTypeIndexTable[*((unsigned __int8 *)a2 - 12) ^ (unsigned __int8)((unsigned __int16)((_WORD)a2 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie],
          1,
          0,
          a6[7],
          a2,
          a4,
          &v58,
          &v50);
  if ( v13 < 0 )
  {
    ObpDecrementHandleCount(v53, v9);
    return v13;
  }
  v14 = (int)v50;
  if ( v50 == a2 )
  {
    v54 = 0;
    v55 = 0;
    v50 = 0;
    v49[0] = 0;
    v56 = 0;
    v15 = (int *)v51;
    v16 = *(_DWORD *)v51;
    if ( *(_DWORD *)v51 )
    {
      if ( (*(_DWORD *)(v16 + 168) & 8) != 0 || ObpObjectSecurityInheritance )
        v56 = 3;
      v52 = (_DWORD *)ObpGetObjectSecurity(v16, &v50, v49, a5);
      if ( (int)v52 < 0 )
        JUMPOUT(0x762C8C);
      v54 = v50;
      v55 = v49[0];
      v15 = (int *)v51;
    }
    v17 = *v15;
    v18 = (int)a4;
    v50 = a4;
    if ( v17 && ((*(_DWORD *)(v17 + 168) & 8) != 0 || ObpObjectSecurityInheritance) )
    {
      v19 = a4[11];
      if ( v19 )
      {
        v51 = RtlGetDaclSecurityDescriptor(v19, &v51, &v61, v49);
        if ( v51 < 0 )
          JUMPOUT(0x762C98);
        v52 = (_DWORD *)RtlGetControlSecurityDescriptor(a4[11], &v51, &v52);
        if ( (int)v52 < 0 )
          JUMPOUT(0x762CA4);
        if ( !v61 && (v51 & 0x1000) == 0 )
        {
          v28 = a4[1];
          v29 = a4[2];
          v30 = a4[3];
          v62[0] = *a4;
          v62[1] = v28;
          v62[2] = v29;
          v62[3] = v30;
          v31 = a4[5];
          v32 = a4[6];
          v33 = a4[7];
          v62[4] = a4[4];
          v62[5] = v31;
          v62[6] = v32;
          v62[7] = v33;
          v34 = a4[9];
          v35 = a4[10];
          v36 = a4[11];
          v62[8] = a4[8];
          v62[9] = v34;
          v62[10] = v35;
          v63 = v36;
          v37 = a4[13];
          v38 = a4[14];
          v39 = a4[15];
          v64 = a4[12];
          v65 = v37;
          v66 = v38;
          v67 = v39;
          v40 = a4[17];
          v41 = a4[18];
          v42 = a4[19];
          v68 = a4[16];
          v69 = v40;
          v70 = v41;
          v71 = v42;
          v43 = a4[21];
          v44 = a4[22];
          v45 = a4[23];
          v72 = a4[20];
          v73 = v43;
          v74 = v44;
          v75 = v45;
          v46 = a4[25];
          v47 = a4[26];
          v48 = a4[27];
          v76 = a4[24];
          v77 = v46;
          v78 = v47;
          v79 = v48;
          v80 = a4[28];
          v63 = 0;
          v7 = v57;
          v50 = v62;
LABEL_34:
          v18 = (int)v50;
LABEL_20:
          v20 = (int)v54;
          v21 = ObpAssignSecurity(v18, v54);
          v22 = v21;
          if ( v20 )
          {
            ObReleaseObjectSecurity(v20, v55);
          }
          else
          {
            if ( v21 < 0 )
              goto LABEL_46;
            SeReleaseSecurityDescriptor(a6[6], *((char *)a6 + 8), 1);
            a6[6] = 0;
            a4[11] = 0;
          }
          if ( v22 >= 0 )
          {
            if ( v60 )
              JUMPOUT(0x762CBC);
            if ( v59 )
              JUMPOUT(0x762CC8);
            *v7 = v14;
            return v22;
          }
LABEL_46:
          JUMPOUT(0x762CB0);
        }
      }
      v18 = (int)a4;
    }
    if ( a4[11] )
      goto LABEL_20;
    goto LABEL_34;
  }
  v50 = 0;
  if ( v60 )
    JUMPOUT(0x762CD4);
  if ( v59 )
    JUMPOUT(0x762CE0);
  v24 = v9;
  v25 = v53;
  ObpDecrementHandleCount(v53, v24);
  if ( (*a6 & 0x80) != 0 )
  {
    a4[4] = a4[6];
    a4[5] = 0;
    v26 = v52;
    v27 = ObpGrantAccess(1, v14, (int)a4, a5, *a6, v52);
    if ( v27 >= 0 )
    {
      ObpIncrementHandleCountEx(1, v26, v25, v14, a5, *a6, 0);
      if ( v50 )
        JUMPOUT(0x7C4EBC);
      JUMPOUT(0x762CEC);
    }
    if ( v50 )
      JUMPOUT(0x762CF8);
    ObfDereferenceObject(v14);
    result = v27;
  }
  else
  {
    ObfDereferenceObject(v14);
    result = -1073741771;
  }
  return result;
}
