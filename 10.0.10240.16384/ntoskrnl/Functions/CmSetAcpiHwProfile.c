// CmSetAcpiHwProfile 
 
int __fastcall CmSetAcpiHwProfile(unsigned __int16 *a1, int (__fastcall *a2)(unsigned int, int *, _DWORD), int a3, int a4, _BYTE *a5)
{
  int *v5; // r8
  unsigned int v6; // r7
  int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r6
  int v11; // r8
  int v12; // r0
  int v13; // r3
  int v14; // r9
  unsigned __int16 *v15; // r10
  int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // r0
  int v21; // r0
  int v22; // r0
  int v23; // [sp+4h] [bp-294h]
  int v24; // [sp+1Ch] [bp-27Ch] BYREF
  __int16 v25; // [sp+20h] [bp-278h] BYREF
  unsigned int v26; // [sp+28h] [bp-270h] BYREF
  unsigned int v27; // [sp+2Ch] [bp-26Ch] BYREF
  int v28; // [sp+30h] [bp-268h] BYREF
  int v29; // [sp+38h] [bp-260h]
  int v30; // [sp+3Ch] [bp-25Ch]
  __int16 *v31; // [sp+40h] [bp-258h]
  int v32; // [sp+44h] [bp-254h]
  int v33; // [sp+48h] [bp-250h]
  int v34; // [sp+4Ch] [bp-24Ch]
  unsigned int i; // [sp+50h] [bp-248h]
  int *v36; // [sp+54h] [bp-244h]
  int v37; // [sp+58h] [bp-240h]
  unsigned __int16 *v38; // [sp+5Ch] [bp-23Ch]
  int v39; // [sp+60h] [bp-238h] BYREF
  char v40[4]; // [sp+68h] [bp-230h] BYREF
  _BYTE *v41; // [sp+6Ch] [bp-22Ch]
  int v42; // [sp+70h] [bp-228h]
  int (__fastcall *v43)(unsigned int, int *, _DWORD); // [sp+74h] [bp-224h]
  char v44[4]; // [sp+78h] [bp-220h] BYREF
  int v45; // [sp+7Ch] [bp-21Ch]
  int v46; // [sp+80h] [bp-218h]
  unsigned int v47; // [sp+84h] [bp-214h]
  unsigned __int16 v48[144]; // [sp+178h] [bp-120h] BYREF

  v5 = (int *)a4;
  v36 = (int *)a4;
  v43 = a2;
  v38 = a1;
  v41 = a5;
  *a5 = 0;
  v24 = 0;
  v37 = 0;
  v6 = 0;
  v26 = 0;
  v27 = 0;
  RtlInitUnicodeString((unsigned int)&v25, L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\IDConfigDB");
  v29 = 24;
  v30 = 0;
  v31 = &v25;
  v33 = 0;
  v34 = 0;
  v32 = 576;
  if ( ZwOpenKey() < 0 )
    return sub_80BB98();
  v8 = CmpGetAcpiProfileInformation(0, &v27, &v26);
  if ( v8 < 0 )
    goto LABEL_49;
  RtlInitUnicodeString(
    (unsigned int)&v25,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\Current");
  v29 = 24;
  v30 = 0;
  v31 = &v25;
  v32 = 576;
  v33 = 0;
  v34 = 0;
  v8 = ZwOpenKey();
  if ( v8 < 0 )
  {
    v16 = 0;
    v10 = v26;
    v9 = v27;
    v24 = 0;
  }
  else
  {
    RtlInitUnicodeString((unsigned int)&v25, L"CurrentDockInfo");
    v29 = 24;
    v30 = 0;
    v31 = &v25;
    v32 = 576;
    v33 = 0;
    v34 = 0;
    v8 = ZwOpenKey();
    if ( v8 < 0 )
    {
      v16 = v24;
      v10 = v26;
      v9 = v27;
    }
    else
    {
      RtlInitUnicodeString((unsigned int)&v25, L"DockingState");
      if ( ZwQueryValueKey() < 0 || v45 != 4 )
      {
        v8 = -1073741492;
        v10 = v26;
        v9 = v27;
        goto LABEL_24;
      }
      v42 = *(_DWORD *)&v44[v46];
      RtlInitUnicodeString((unsigned int)&v25, L"AcpiSerialNumber");
      if ( ZwQueryValueKey() >= 0 && v45 == 3 )
      {
        v21 = ExAllocatePoolWithTag(1, v47, 538987843);
        v6 = v21;
        if ( !v21 )
        {
          v8 = -1073741670;
LABEL_49:
          v10 = v26;
          v9 = v27;
          goto LABEL_50;
        }
        memmove(v21, (int)&v44[v46], v47);
      }
      else
      {
        v6 = 0;
      }
      RtlInitUnicodeString((unsigned int)&v25, L"CurrentConfig");
      if ( ZwQueryValueKey() < 0 || v45 != 4 )
      {
        v8 = -1073741492;
        goto LABEL_49;
      }
      v10 = v26;
      v9 = v27;
      v11 = *(_DWORD *)&v44[v46];
      v8 = CmpFilterAcpiDockingState(v38, v42, v6, v11, v27, v26);
      if ( v8 < 0 )
        goto LABEL_50;
      v12 = v43(v9, &v39, 0);
      v8 = v12;
      if ( v39 == -1 )
      {
LABEL_23:
        v5 = v36;
LABEL_24:
        v16 = v24;
        goto LABEL_25;
      }
      if ( v12 < 0 )
      {
LABEL_50:
        v16 = v24;
LABEL_51:
        if ( v16 )
          ZwClose();
        goto LABEL_27;
      }
      RtlInitUnicodeString((unsigned int)&v25, L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles");
      v29 = 24;
      v30 = 0;
      v31 = &v25;
      v32 = 576;
      v33 = 0;
      v34 = 0;
      v8 = ZwOpenKey();
      if ( v8 < 0 )
      {
        v16 = v24;
        v5 = v36;
      }
      else
      {
        v14 = *(_DWORD *)(v9 + 20 * v39 + 24);
        v13 = *(_DWORD *)(v9 + 20 * v39 + 20);
        v28 = v13;
        if ( (v14 & 8) != 0 )
        {
          v8 = CmpMoveBiosAliasTable(0, 0, v11);
          if ( v8 < 0 )
            goto LABEL_50;
          v13 = v28;
        }
        if ( (v14 & 4) == 0 && v13 == v11 )
          goto LABEL_19;
        *v41 = 1;
        ZwClose();
        if ( (v14 & 4) != 0 )
        {
          v22 = CmpCloneHwProfile(0, 0, v24, v28, *v38, &v24, &v28);
        }
        else
        {
          ZwClose();
          swprintf_s((int)v48, 128, (int)L"%04d", v28);
          RtlInitUnicodeString((unsigned int)&v25, v48);
          v29 = 24;
          v30 = 0;
          v32 = 576;
          v31 = &v25;
          v33 = 0;
          v34 = 0;
          v22 = ZwOpenKey();
        }
        v8 = v22;
        if ( v22 >= 0 )
        {
          RtlInitUnicodeString((unsigned int)&v25, L"CurrentDockInfo");
          v29 = 24;
          v30 = 0;
          v32 = 576;
          v31 = &v25;
          v33 = 0;
          v34 = 0;
          v8 = ZwCreateKey();
          if ( v8 >= 0 )
          {
            RtlInitUnicodeString((unsigned int)&v25, L"CurrentConfig");
            if ( ZwSetValueKey() < 0 )
            {
              v8 = -1073741492;
              goto LABEL_50;
            }
LABEL_19:
            v15 = v38;
            i = *v38;
            RtlInitUnicodeString((unsigned int)&v25, L"DockingState");
            ZwSetValueKey();
            RtlInitUnicodeString((unsigned int)&v25, L"AcpiSerialNumber");
            v23 = v15[1];
            v8 = ZwSetValueKey();
            if ( (v14 & 2) == 0 )
              v8 = CmpAddAcpiAliasEntry(0, v15, v28, v48, v15 + 2, v23);
            if ( v28 != v11 )
            {
              RtlInitUnicodeString(
                (unsigned int)&v25,
                L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\Current");
              v29 = 24;
              v30 = 0;
              v32 = 832;
              v31 = &v25;
              v33 = 0;
              v34 = 0;
              ZwCreateKey();
              swprintf_s(
                (int)v48,
                128,
                (int)L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\%04d",
                v28,
                0,
                8,
                v40);
              RtlInitUnicodeString((unsigned int)&v25, v48);
              v8 = ZwSetValueKey();
            }
            goto LABEL_23;
          }
          v16 = v24;
          v5 = v36;
        }
        else
        {
          v16 = 0;
          v5 = v36;
          v24 = 0;
        }
      }
    }
  }
LABEL_25:
  if ( v8 < 0 )
    goto LABEL_51;
  *v5 = v16;
LABEL_27:
  if ( v37 )
    ZwClose();
  if ( v6 )
    ExFreePoolWithTag(v6);
  if ( v9 )
  {
    v17 = 0;
    for ( i = 0; v17 < *(_DWORD *)(v9 + 4); i = v17 )
    {
      v18 = *(_DWORD *)(v9 + 20 * v17 + 12);
      if ( v18 )
      {
        ExFreePoolWithTag(v18);
        v17 = i;
      }
      ++v17;
    }
    ExFreePoolWithTag(v9);
  }
  if ( v10 )
  {
    v19 = 0;
    for ( i = 0; v19 < *(_DWORD *)(v10 + 4); i = v19 )
    {
      v20 = *(_DWORD *)(v10 + 16 * v19 + 20);
      if ( v20 )
      {
        ExFreePoolWithTag(v20);
        v19 = i;
      }
      ++v19;
    }
    ExFreePoolWithTag(v10);
  }
  return v8;
}
