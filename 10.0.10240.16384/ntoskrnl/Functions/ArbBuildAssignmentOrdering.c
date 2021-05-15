// ArbBuildAssignmentOrdering 
 
int __fastcall ArbBuildAssignmentOrdering(int a1, int a2, int a3, int (__fastcall *a4)(int *, int *))
{
  unsigned int v5; // r1
  int v6; // r0
  unsigned int v7; // r6
  int v9; // r9
  int *v10; // r8
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r6
  char *v19; // r1
  int v20; // r9
  int *v21; // r8
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r0
  unsigned int v29; // r1
  int v30; // r3
  int v31; // r1
  int v32; // r1
  int v33; // r1
  int v34; // [sp+8h] [bp-A0h]
  _DWORD *v35; // [sp+14h] [bp-94h] BYREF
  int v36; // [sp+18h] [bp-90h]
  __int16 v37; // [sp+20h] [bp-88h] BYREF
  __int16 v38; // [sp+22h] [bp-86h]
  const __int16 *v39; // [sp+24h] [bp-84h]
  int v40; // [sp+28h] [bp-80h] BYREF
  int v41; // [sp+2Ch] [bp-7Ch]
  unsigned int v42; // [sp+30h] [bp-78h] BYREF
  int v43; // [sp+38h] [bp-70h] BYREF
  int v44; // [sp+3Ch] [bp-6Ch]
  int v45; // [sp+40h] [bp-68h]
  int v46; // [sp+44h] [bp-64h]
  __int16 *v47; // [sp+48h] [bp-60h]
  int v48; // [sp+4Ch] [bp-5Ch]
  int v49; // [sp+50h] [bp-58h]
  int v50; // [sp+54h] [bp-54h]
  int (__fastcall *v51)(int *, int *); // [sp+58h] [bp-50h]
  char v52[8]; // [sp+60h] [bp-48h] BYREF
  int v53; // [sp+68h] [bp-40h] BYREF
  int v54; // [sp+6Ch] [bp-3Ch]
  int v55; // [sp+70h] [bp-38h]
  int v56; // [sp+74h] [bp-34h]
  int v57; // [sp+78h] [bp-30h]
  int v58; // [sp+7Ch] [bp-2Ch]
  int v59; // [sp+80h] [bp-28h]
  int v60; // [sp+84h] [bp-24h]

  v51 = a4;
  v35 = 0;
  v36 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  KeWaitForSingleObject(*(_DWORD *)(a1 + 4), 0, 0, 0, 0);
  ArbFreeOrderingList(a1 + 28);
  ArbFreeOrderingList(a1 + 36);
  if ( ArbInitializeOrderingList(a1 + 28) < 0 )
    goto LABEL_40;
  if ( ArbInitializeOrderingList(a1 + 36) < 0 )
    goto LABEL_40;
  v38 = 118;
  v37 = 118;
  v39 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Arbiters";
  v45 = 24;
  v46 = 0;
  v47 = &v37;
  v48 = 576;
  v49 = 0;
  v50 = 0;
  v42 = 131097;
  if ( ZwOpenKey() < 0 )
    goto LABEL_40;
  v38 = 30;
  v37 = 30;
  v39 = L"AllocationOrder";
  v45 = 24;
  v48 = 576;
  v46 = v36;
  v47 = &v37;
  v49 = 0;
  v50 = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_40;
  v6 = ArbpGetRegistryValue(0, L"Root", &v35);
  v7 = (unsigned int)v35;
  if ( v6 < 0 || !v35 )
    goto LABEL_40;
  if ( v35[1] != 1 )
  {
    ZwClose();
    if ( *(_DWORD *)(v7 + 4) == 10 )
    {
      v9 = *(_DWORD *)(v7 + 8) + v7 + 32;
      v10 = (int *)(*(_DWORD *)(v7 + 8) + v7 + 40);
      if ( (unsigned int)v10 < v9 + 32 * *(_DWORD *)(*(_DWORD *)(v7 + 8) + v7 + 36) + 8 )
      {
        do
        {
          if ( v51 )
          {
            if ( v51(&v53, v10) < 0 )
              goto LABEL_40;
          }
          else
          {
            v11 = v10[1];
            v12 = v10[2];
            v13 = v10[3];
            v53 = *v10;
            v54 = v11;
            v55 = v12;
            v56 = v13;
            v14 = v10[5];
            v15 = v10[6];
            v16 = v10[7];
            v57 = v10[4];
            v58 = v14;
            v59 = v15;
            v60 = v16;
          }
          if ( BYTE1(v53) == *(_DWORD *)(a1 + 16) )
          {
            if ( (*(int (__fastcall **)(int *, int *, int *, char *, char *))(a1 + 60))(&v53, &v40, &v43, v52, v52) < 0
              || ArbAddOrdering(a1 + 28, v31, v40, v41, v43, v44) < 0 )
            {
              goto LABEL_40;
            }
          }
          else if ( BYTE1(v53) == 7 )
          {
            JUMPOUT(0x80D7DE);
          }
          v10 += 8;
        }
        while ( (unsigned int)v10 < v9 + 32 * *(_DWORD *)(v9 + 4) + 8 );
      }
      ExFreePoolWithTag(v7);
      v38 = 34;
      v37 = 34;
      v39 = L"ReservedResources";
      v45 = 24;
      v46 = v36;
      v48 = 576;
      v47 = &v37;
      v49 = 0;
      v50 = 0;
      v35 = 0;
      v34 = 0;
      if ( ZwCreateKey() < 0 )
        goto LABEL_40;
      v17 = ArbpGetRegistryValue(0, L"Root", &v35);
      v18 = (unsigned int)v35;
      if ( v17 < 0 )
        goto LABEL_40;
      if ( v35[1] != 1 )
        goto LABEL_22;
      v19 = (char *)v35 + v35[2];
      if ( !*(_WORD *)&v19[2 * (v35[3] >> 1) - 2] )
      {
        if ( ArbpGetRegistryValue(0, v19, &v42) >= 0 )
        {
          ExFreePoolWithTag(v18);
          v18 = v42;
LABEL_22:
          ZwClose();
          v20 = *(_DWORD *)(v18 + 8) + v18 + 32;
          v21 = (int *)(*(_DWORD *)(v18 + 8) + v18 + 40);
          if ( (unsigned int)v21 >= v20 + 32 * *(_DWORD *)(*(_DWORD *)(v18 + 8) + v18 + 36) + 8 )
          {
LABEL_28:
            ExFreePoolWithTag(v18);
            ZwClose();
            v28 = *(_DWORD *)(a1 + 4);
            v36 = 0;
            KeSetEvent(v28, 0, 0);
            v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v30 = (__int16)(*(_WORD *)(v29 + 0x134) + 1);
            *(_WORD *)(v29 + 308) = v30;
            if ( !v30 )
              JUMPOUT(0x80D7F2);
            JUMPOUT(0x80D806);
          }
          while ( 1 )
          {
            if ( v51 )
            {
              if ( v51(&v53, v21) < 0 )
                break;
            }
            else
            {
              v22 = v21[1];
              v23 = v21[2];
              v24 = v21[3];
              v53 = *v21;
              v54 = v22;
              v55 = v23;
              v56 = v24;
              v25 = v21[5];
              v26 = v21[6];
              v27 = v21[7];
              v57 = v21[4];
              v58 = v25;
              v59 = v26;
              v60 = v27;
            }
            if ( BYTE1(v53) == *(_DWORD *)(a1 + 16) )
            {
              if ( (*(int (__fastcall **)(int *, int *, int *, char *, char *))(a1 + 60))(&v53, &v40, &v43, v52, v52) < 0
                || ArbAddOrdering(a1 + 36, v32, v40, v41, v43, v44) < 0
                || ArbPruneOrdering(a1 + 28, v33, v40, v41, v43, v44, v34) < 0 )
              {
                break;
              }
            }
            else if ( BYTE1(v53) == 7 )
            {
              JUMPOUT(0x80D7E8);
            }
            v21 += 8;
            if ( (unsigned int)v21 >= v20 + 32 * *(_DWORD *)(v20 + 4) + 8 )
              goto LABEL_28;
          }
        }
LABEL_40:
        JUMPOUT(0x80D80A);
      }
    }
    JUMPOUT(0x80D7DA);
  }
  return sub_80D7AC();
}
