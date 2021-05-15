// CmpGetAcpiProfileInformation 
 
int __fastcall CmpGetAcpiProfileInformation(int a1, unsigned int *a2, unsigned int *a3, int a4, _DWORD *a5)
{
  int v9; // r4
  _BYTE *v10; // r0
  unsigned int v11; // r3
  int v12; // r3
  unsigned int v13; // r5
  int v14; // r0
  unsigned int v15; // r2
  _DWORD *v16; // r1
  unsigned int v17; // r4
  unsigned int v18; // r0
  int v19; // r2
  unsigned int *v20; // r5
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r0
  unsigned int v25; // r9
  int v26; // r5
  int v27; // r3
  int v28; // r1
  int v29; // r0
  unsigned int v30; // r2
  int v31; // r0
  int v32; // r0
  unsigned int v33; // r6
  int v34; // r5
  unsigned int v35; // r0
  unsigned int v36; // r6
  int v37; // r5
  unsigned int v38; // r0
  int v39; // [sp+10h] [bp-B8h]
  unsigned __int16 v40; // [sp+18h] [bp-B0h] BYREF
  __int16 v41; // [sp+1Ah] [bp-AEh]
  _DWORD *v42; // [sp+1Ch] [bp-ACh]
  int v43; // [sp+20h] [bp-A8h]
  int v44; // [sp+28h] [bp-A0h]
  int v45; // [sp+2Ch] [bp-9Ch]
  unsigned __int16 *v46; // [sp+30h] [bp-98h]
  int v47; // [sp+34h] [bp-94h]
  int v48; // [sp+38h] [bp-90h]
  int v49; // [sp+3Ch] [bp-8Ch]
  unsigned int v50; // [sp+40h] [bp-88h]
  unsigned int v51; // [sp+48h] [bp-80h]
  int v52; // [sp+4Ch] [bp-7Ch]
  int v53; // [sp+50h] [bp-78h]
  int v54; // [sp+54h] [bp-74h] BYREF
  unsigned int v55; // [sp+58h] [bp-70h]
  int v56; // [sp+5Ch] [bp-6Ch]
  int v57; // [sp+60h] [bp-68h]
  unsigned int v58; // [sp+7Ch] [bp-4Ch]
  char v59[48]; // [sp+98h] [bp-30h] BYREF

  *a2 = 0;
  v56 = a1;
  v43 = 0;
  *a3 = 0;
  RtlInitUnicodeString((unsigned int)&v40, L"Hardware Profiles");
  v44 = 24;
  v45 = a1;
  v46 = &v40;
  v48 = 0;
  v49 = 0;
  v47 = 576;
  v57 = 131097;
  if ( ZwOpenKey() < 0 )
    return sub_80BE68();
  v9 = ZwQueryKey();
  if ( v9 < 0 )
    goto LABEL_48;
  v39 = 20 * (v58 - 1) + 28;
  v10 = (_BYTE *)ExAllocatePoolWithTag(1, v39, 538987843);
  *a2 = (unsigned int)v10;
  if ( !v10 )
    goto LABEL_54;
  memset(v10, 0, v39);
  *(_DWORD *)*a2 = v58;
  v11 = *a2;
  v50 = 0;
  for ( *(_DWORD *)(v11 + 4) = 0; v50 < v58; ++v50 )
  {
    if ( ZwEnumerateKey() < 0 )
      break;
    *((_WORD *)a5 + (a5[3] >> 1) + 8) = 0;
    v12 = a5[3];
    v40 = v12;
    v41 = v12 + 2;
    v44 = 24;
    v42 = a5 + 4;
    v47 = 576;
    v45 = 0;
    v46 = &v40;
    v48 = 0;
    v49 = 0;
    if ( ZwOpenKey() < 0 )
      break;
    RtlUnicodeStringToInteger(&v40, 0, &v54);
    RtlInitUnicodeString((unsigned int)&v40, L"PreferenceOrder");
    if ( ZwQueryValueKey() >= 0 && a5[1] == 4 )
    {
      v13 = *(_DWORD *)((char *)a5 + a5[2]);
      v53 = v13;
    }
    else
    {
      v13 = -1;
      v53 = -1;
    }
    RtlInitUnicodeString((unsigned int)&v40, L"FriendlyName");
    if ( ZwQueryValueKey() >= 0 && a5[1] == 1 )
    {
      v14 = ExAllocatePoolWithTag(1, a5[3], 538987843);
      v15 = a5[3];
      v51 = v15;
      v52 = v14;
      if ( !v14 )
        goto LABEL_61;
      memmove(v14, (int)a5 + a5[2], v15);
    }
    else
    {
      qmemcpy(v59, "-------", 14);
      v32 = ExAllocatePoolWithTag(1, 16, 538987843);
      v51 = 16;
      v52 = v32;
      if ( !v32 )
      {
LABEL_61:
        v9 = -1073741670;
LABEL_62:
        ZwClose();
        goto LABEL_48;
      }
      memmove(v32, (int)v59, a5[3]);
    }
    v55 = 0;
    RtlInitUnicodeString((unsigned int)&v40, L"Aliasable");
    if ( ZwQueryValueKey() < 0 || a5[1] != 4 || *(_DWORD *)((char *)a5 + a5[2]) )
      v55 = 1;
    RtlInitUnicodeString((unsigned int)&v40, L"Pristine");
    if ( ZwQueryValueKey() >= 0 && a5[1] == 4 && *(_DWORD *)((char *)a5 + a5[2]) )
      v55 = 4;
    if ( !v54 )
    {
      v55 = 4;
      v13 = -1;
      v53 = -1;
    }
    v16 = (_DWORD *)*a2;
    v17 = 0;
    v18 = *(_DWORD *)(*a2 + 4);
    if ( v18 )
    {
      v19 = 0;
      while ( v16[v19 + 4] < v13 )
      {
        ++v17;
        v19 += 5;
        if ( v17 >= v18 )
          goto LABEL_28;
      }
      memmove((int)&v16[5 * v17 + 7], (int)&v16[5 * v17 + 2], 20 * (*v16 - v17 - 1));
    }
LABEL_28:
    v20 = (unsigned int *)(*a2 + 20 * v17 + 8);
    v21 = v52;
    v22 = v53;
    v23 = v54;
    *v20 = v51;
    v20[1] = v21;
    v20[2] = v22;
    v20[3] = v23;
    v20[4] = v55;
    ++*(_DWORD *)(*a2 + 4);
    ZwClose();
  }
  RtlInitUnicodeString((unsigned int)&v40, L"AcpiAlias");
  v44 = 24;
  v45 = v56;
  v46 = &v40;
  v47 = 576;
  v48 = 0;
  v49 = 0;
  if ( ZwOpenKey() >= 0 )
  {
    v9 = ZwQueryKey();
    if ( v9 < 0 )
      goto LABEL_48;
    v24 = ExAllocatePoolWithTag(1, 20 * (v58 - 1) + 28, 538987843);
    *a3 = v24;
    if ( v24 )
    {
      v25 = 0;
      *(_DWORD *)(v24 + 4) = v58;
      *(_DWORD *)*a3 = v58;
      if ( v58 )
      {
        v26 = 0;
        while ( 1 )
        {
          v9 = ZwEnumerateKey();
          if ( v9 < 0 )
            break;
          *((_WORD *)a5 + (a5[3] >> 1) + 8) = 0;
          v27 = a5[3];
          v40 = v27;
          v41 = v27 + 2;
          v42 = a5 + 4;
          v44 = 24;
          v45 = v43;
          v47 = 64;
          v46 = &v40;
          v48 = 0;
          v49 = 0;
          v9 = ZwOpenKey();
          if ( v9 < 0 )
            break;
          RtlInitUnicodeString((unsigned int)&v40, L"ProfileNumber");
          if ( ZwQueryValueKey() < 0
            || a5[1] != 4
            || (*(_DWORD *)(*a3 + v26 + 8) = *(_DWORD *)((char *)a5 + a5[2]),
                RtlInitUnicodeString((unsigned int)&v40, L"DockingState"),
                ZwQueryValueKey() < 0)
            || a5[1] != 4
            || (*(_DWORD *)(*a3 + v26 + 12) = *(_DWORD *)((char *)a5 + a5[2]),
                RtlInitUnicodeString((unsigned int)&v40, L"AcpiSerialNumber"),
                v9 = ZwQueryValueKey(),
                v9 < 0)
            || a5[1] != 3 )
          {
            v9 = -1073741492;
            goto LABEL_62;
          }
          *(_DWORD *)(*a3 + v26 + 16) = a5[3];
          v28 = a5[3];
          if ( v28 )
            v29 = ExAllocatePoolWithTag(1, v28, 538987843);
          else
            v29 = 0;
          *(_DWORD *)(*a3 + v26 + 20) = v29;
          v30 = a5[3];
          if ( v30 )
          {
            v31 = *(_DWORD *)(*a3 + v26 + 20);
            if ( !v31 )
              goto LABEL_61;
            memmove(v31, (int)a5 + a5[2], v30);
          }
          ZwClose();
          ++v25;
          v26 += 16;
          if ( v25 >= v58 )
            goto LABEL_48;
        }
      }
      goto LABEL_48;
    }
LABEL_54:
    v9 = -1073741670;
LABEL_48:
    if ( v43 )
      ZwClose();
    goto LABEL_50;
  }
  v9 = 0;
  v43 = 0;
LABEL_50:
  if ( v9 < 0 )
  {
    if ( *a2 )
    {
      v33 = 0;
      if ( *(_DWORD *)(*a2 + 4) )
      {
        v34 = 0;
        do
        {
          v35 = *(_DWORD *)(*a2 + v34 + 12);
          if ( v35 )
            ExFreePoolWithTag(v35);
          ++v33;
          v34 += 20;
        }
        while ( v33 < *(_DWORD *)(*a2 + 4) );
      }
      ExFreePoolWithTag(*a2);
      *a2 = 0;
    }
    if ( *a3 )
    {
      v36 = 0;
      if ( *(_DWORD *)(*a3 + 4) )
      {
        v37 = 0;
        do
        {
          v38 = *(_DWORD *)(*a3 + v37 + 20);
          if ( v38 )
            ExFreePoolWithTag(v38);
          ++v36;
          v37 += 16;
        }
        while ( v36 < *(_DWORD *)(*a3 + 4) );
      }
      ExFreePoolWithTag(*a3);
      *a3 = 0;
    }
  }
  return v9;
}
