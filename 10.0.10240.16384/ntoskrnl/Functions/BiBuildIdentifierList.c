// BiBuildIdentifierList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall BiBuildIdentifierList(int a1, int a2, int *a3)
{
  unsigned int v4; // r5
  int v6; // r4
  int v7; // r6
  int v8; // r10
  unsigned __int16 **i; // r3
  unsigned __int16 *v10; // t1
  unsigned int v12; // r10
  unsigned int v13; // r8
  _DWORD *v14; // r5
  int v15; // r0
  int v16; // r6
  int *v17; // r8
  int *v18; // r4
  int v19; // r1 OVERLAPPED
  _DWORD *v20; // r2 OVERLAPPED
  int **v21; // r2
  int *v22; // r0
  int **v23; // r1
  int *v24; // r9
  int v25; // r0
  unsigned __int16 **v26; // r0
  int v27; // r1 OVERLAPPED
  unsigned __int16 ***v28; // r2 OVERLAPPED
  int v29; // r2
  int v30; // r3
  int v31; // r4
  int *v32; // r1 OVERLAPPED
  int **v33; // r2 OVERLAPPED
  int **v34; // r2
  int **v35; // r2
  int **v36; // r3
  int **v37; // r2
  int **v38; // r3
  int **v39; // r2
  int **v40; // r3
  int v41[2]; // [sp+0h] [bp-80h] BYREF
  int *v42; // [sp+8h] [bp-78h] BYREF
  int **v43; // [sp+Ch] [bp-74h]
  int *v44; // [sp+10h] [bp-70h] BYREF
  int **v45; // [sp+14h] [bp-6Ch]
  int *v46; // [sp+18h] [bp-68h] BYREF
  int **v47; // [sp+1Ch] [bp-64h]
  int v48; // [sp+20h] [bp-60h] BYREF
  unsigned __int16 **v49; // [sp+24h] [bp-5Ch] BYREF
  unsigned int v50; // [sp+28h] [bp-58h]
  _DWORD *v51; // [sp+2Ch] [bp-54h] BYREF
  int v52[4]; // [sp+30h] [bp-50h] BYREF
  unsigned __int16 v53[4]; // [sp+40h] [bp-40h] BYREF
  char v54[4]; // [sp+48h] [bp-38h] BYREF
  int v55; // [sp+4Ch] [bp-34h]
  char v56[48]; // [sp+50h] [bp-30h] BYREF

  v51 = 0;
  v48 = 0;
  v45 = &v44;
  v44 = (int *)&v44;
  v47 = &v46;
  v46 = (int *)&v46;
  v43 = &v42;
  v42 = (int *)&v42;
  v4 = 0;
  v52[1] = a1;
  v41[0] = 0;
  *a3 = (int)a3;
  a3[1] = (int)a3;
  v6 = BiOpenKey(a1, L"Objects", 131097, &v48);
  v7 = v48;
  if ( v6 >= 0 )
  {
    v6 = BiEnumerateSubKeys(v48, v41, v52);
    v4 = v41[0];
    if ( v6 >= 0 )
    {
      v8 = 0;
      v50 = v41[0];
      if ( v52[0] )
      {
        for ( i = (unsigned __int16 **)v41[0]; ; i = v49 )
        {
          v10 = *i;
          v49 = i + 1;
          RtlInitUnicodeString((unsigned int)v53, v10);
          if ( RtlGUIDFromString(v53, v56) >= 0 && BcdOpenObject(a1, v56, v41) >= 0 )
          {
            if ( BiGetObjectDescription(v41[0], v54) >= 0
              && (v55 & 0xF0000000) == 0x10000000
              && (v55 & 0xF00000) == 0x100000
              && (v55 & 0xFFFFF) != 1 )
            {
              return sub_8138C4();
            }
            BcdCloseObject(v41[0]);
          }
          if ( (unsigned int)++v8 >= v52[0] )
            break;
        }
      }
      v6 = BiEnumerateBootEntries(&v51, &v49);
      v12 = (unsigned int)v51;
      if ( v6 < 0 )
        goto LABEL_29;
      v13 = (unsigned int)v49;
      v41[0] = 0;
      v14 = v51;
      if ( v49 )
      {
        while ( 1 )
        {
          if ( BiGetObjectReferenceFromEfiEntry(v14 + 1, v56) < 0
            || BiLookupObjectByIdentifierAndBootEntry(&v44, v56, v14[3], v41) < 0 )
          {
            v22 = (int *)ExAllocatePoolWithTag(1, 36, 1262764866);
            v18 = v22;
            v41[0] = (int)v22;
            if ( !v22 )
            {
LABEL_39:
              v6 = -1073741670;
              goto LABEL_29;
            }
            memset(v22, 0, 36);
            v18[8] |= 8u;
            v23 = v43;
            *v18 = (int)&v42;
            v18[1] = (int)v23;
            if ( *v23 != (int *)&v42 )
              __fastfail(3u);
            *v23 = v18;
            v43 = (int **)v18;
          }
          else
          {
            v18 = (int *)v41[0];
            *(_QWORD *)&v19 = *(_QWORD *)v41[0];
            if ( *(_DWORD *)(*(_DWORD *)v41[0] + 4) != v41[0] || *v20 != v41[0] )
              __fastfail(3u);
            *v20 = v19;
            *(_DWORD *)(v19 + 4) = v20;
            v21 = (int **)a3[1];
            *v18 = (int)a3;
            v18[1] = (int)v21;
            if ( *v21 != a3 )
              __fastfail(3u);
            *v21 = v18;
            a3[1] = (int)v18;
          }
          v15 = ExAllocatePoolWithTag(1, v14[2], 1262764866);
          v16 = v15;
          if ( !v15 )
            goto LABEL_39;
          memmove(v15, (int)(v14 + 1), v14[2]);
          v18[7] = v16;
          v18[6] = *(_DWORD *)(v16 + 8);
          v18[8] |= 1u;
          if ( *v14 )
          {
            v14 = (_DWORD *)((char *)v14 + *v14);
            if ( (unsigned int)v14 - v12 < v13 )
              continue;
          }
          break;
        }
      }
      v17 = v42;
      if ( v42 != (int *)&v42 )
      {
        do
        {
          v24 = v17;
          v25 = BiLookupObjectByBootEntry(&v46, v17[6], &v49);
          v17 = (int *)*v17;
          if ( v25 >= 0 )
          {
            v26 = v49;
            *(_QWORD *)&v27 = *(_QWORD *)v49;
            if ( *((unsigned __int16 ***)*v49 + 1) != v49 || *v28 != v49 )
              __fastfail(3u);
            *v28 = (unsigned __int16 **)v27;
            *(_DWORD *)(v27 + 4) = v28;
            v29 = (int)v26[3];
            v30 = (int)v26[4];
            v31 = (int)v26[5];
            v24[2] = (int)v26[2];
            v24[3] = v29;
            v24[4] = v30;
            v24[5] = v31;
            v24[8] ^= ((unsigned __int8)v26[8] ^ (unsigned __int8)v24[8]) & 2;
            ExFreePoolWithTag((unsigned int)v26);
            v24[8] |= 4u;
            *(_QWORD *)&v32 = *(_QWORD *)v24;
            if ( *(int **)(*v24 + 4) != v24 || *v33 != v24 )
              __fastfail(3u);
            *v33 = v32;
            v32[1] = (int)v33;
            v34 = (int **)a3[1];
            *v24 = (int)a3;
            v24[1] = (int)v34;
            if ( *v34 != a3 )
              __fastfail(3u);
            *v34 = v24;
            a3[1] = (int)v24;
          }
        }
        while ( v17 != (int *)&v42 );
        v17 = v42;
      }
      if ( v44 != (int *)&v44 )
      {
        v35 = (int **)a3[1];
        *v35 = v44;
        v36 = v45;
        a3[1] = (int)v45;
        *v36 = a3;
        v44[1] = (int)v35;
        v17 = v42;
      }
      if ( v46 != (int *)&v46 )
      {
        v37 = (int **)a3[1];
        *v37 = v46;
        v38 = v47;
        a3[1] = (int)v47;
        *v38 = a3;
        v46[1] = (int)v37;
        v17 = v42;
      }
      if ( v17 != (int *)&v42 )
      {
        v39 = (int **)a3[1];
        *v39 = v17;
        v40 = v43;
        a3[1] = (int)v43;
        *v40 = a3;
        v42[1] = (int)v39;
      }
      v6 = 0;
LABEL_29:
      if ( v12 )
        ExFreePoolWithTag(v12);
      v4 = v50;
      v7 = v48;
    }
  }
  if ( v7 )
    BiCloseKey(v7);
  if ( v4 )
    ExFreePoolWithTag(v4);
  if ( v6 < 0 )
  {
    BiFreeIdentifierList(&v42);
    BiFreeIdentifierList(&v46);
    BiFreeIdentifierList(&v44);
    BiFreeIdentifierList(a3);
  }
  return v6;
}
