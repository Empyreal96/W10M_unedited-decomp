// CmpCloneHwProfile 
 
int __fastcall CmpCloneHwProfile(int a1, int a2, int a3, unsigned int a4, unsigned __int16 a5, int *a6, unsigned int *a7)
{
  int *v7; // r9
  int v9; // r0
  int v10; // r4
  int v11; // r5
  int v13; // r5
  unsigned int v14; // r5
  unsigned int v15; // r4
  unsigned int v16; // r3
  int v17; // r5
  int v18; // r7
  int v19; // r6
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // [sp+10h] [bp-210h] BYREF
  unsigned int v25; // [sp+14h] [bp-20Ch] BYREF
  __int16 v26[2]; // [sp+18h] [bp-208h] BYREF
  _WORD *v27; // [sp+1Ch] [bp-204h]
  int v28; // [sp+20h] [bp-200h]
  int v29; // [sp+24h] [bp-1FCh] BYREF
  int v30; // [sp+28h] [bp-1F8h]
  int v31; // [sp+2Ch] [bp-1F4h]
  int v32; // [sp+30h] [bp-1F0h]
  int v33; // [sp+34h] [bp-1ECh]
  __int16 *v34; // [sp+38h] [bp-1E8h]
  int v35; // [sp+3Ch] [bp-1E4h]
  int v36; // [sp+40h] [bp-1E0h]
  int v37; // [sp+44h] [bp-1DCh]
  int v38[3]; // [sp+48h] [bp-1D8h] BYREF
  int v39; // [sp+54h] [bp-1CCh] BYREF
  int v40; // [sp+60h] [bp-1C0h] BYREF
  char v41[8]; // [sp+68h] [bp-1B8h] BYREF
  char v42[20]; // [sp+70h] [bp-1B0h] BYREF
  int v43; // [sp+84h] [bp-19Ch]
  int v44; // [sp+88h] [bp-198h]
  unsigned int v45; // [sp+8Ch] [bp-194h]
  _WORD v46[2]; // [sp+90h] [bp-190h] BYREF
  unsigned int v47; // [sp+94h] [bp-18Ch]
  unsigned __int16 v48[80]; // [sp+180h] [bp-A0h] BYREF

  v7 = a6;
  *a6 = 0;
  v28 = 0;
  v29 = a1;
  v30 = 0;
  v31 = 0;
  v24 = a3;
  v38[0] = (int)a6;
  *a7 = a4;
  if ( a4 >= 0xC8 )
    goto LABEL_8;
  while ( 1 )
  {
    ++*a7;
    swprintf_s((int)v48, 64, (int)L"%04d");
    RtlInitUnicodeString((unsigned int)v41, v48);
    v32 = 24;
    v33 = a2;
    v34 = (__int16 *)v41;
    v35 = 576;
    v36 = 0;
    v37 = 0;
    v9 = ZwOpenKey();
    v10 = v9;
    if ( v9 < 0 )
      break;
    ZwClose();
    if ( *a7 >= 0xC8 )
      goto LABEL_7;
  }
  if ( v9 == -1073741772 )
    v10 = 0;
LABEL_7:
  if ( v10 >= 0 )
  {
LABEL_8:
    if ( ZwQuerySecurityObject() == -1073741789 )
    {
      v11 = ExAllocatePoolWithTag(1, v38[2], 538987843);
      if ( !v11 || ZwQuerySecurityObject() >= 0 )
        goto LABEL_13;
      ExFreePoolWithTag(v11);
    }
    v11 = 0;
LABEL_13:
    v32 = 24;
    v33 = a2;
    v34 = (__int16 *)v41;
    v35 = 576;
    v36 = v11;
    v37 = 0;
    v10 = ZwCreateKey();
    if ( v11 )
      ExFreePoolWithTag(v11);
    if ( v10 >= 0 )
    {
      if ( v39 == 1 )
      {
        swprintf_s((int)v48, 64, (int)L"Hardware Profiles\\%04d", *a7, 0, 0, &v39);
        RtlInitUnicodeString((unsigned int)v26, v48);
        v32 = 24;
        v34 = v26;
        v35 = 576;
        v13 = v29;
        v36 = 0;
        v37 = 0;
        v33 = v29;
        v10 = ZwCreateKey();
        if ( v10 >= 0 )
        {
          RtlInitUnicodeString((unsigned int)v26, L"Hardware Profiles");
          v32 = 24;
          v33 = v13;
          v34 = v26;
          v35 = 576;
          v36 = 0;
          v37 = 0;
          v10 = ZwOpenKey();
          if ( v10 >= 0 )
          {
            v10 = ZwQueryKey();
            if ( v10 >= 0 )
            {
              v14 = v47;
              v15 = 0;
              v16 = -1;
              v25 = -1;
              if ( v47 )
              {
                do
                {
                  if ( ZwEnumerateKey() < 0 )
                    break;
                  v46[v45 >> 1] = 0;
                  if ( wtol((int)v46) && wtol((int)v46) != *a7 )
                  {
                    v26[0] = v45;
                    v26[1] = v45 + 2;
                    v27 = v46;
                    v32 = 24;
                    v35 = 576;
                    v33 = v31;
                    v34 = v26;
                    v36 = 0;
                    v37 = 0;
                    if ( ZwOpenKey() >= 0 )
                    {
                      RtlInitUnicodeString((unsigned int)v26, L"PreferenceOrder");
                      if ( ZwQueryValueKey() >= 0 && v43 == 4 && (*(_DWORD *)&v42[v44 + 16] > v25 || v25 == -1) )
                        v25 = *(_DWORD *)&v42[v44 + 16];
                      ZwClose();
                    }
                    v30 = 0;
                  }
                  ++v15;
                }
                while ( v15 < v14 );
                v16 = v25;
                v7 = (int *)v38[0];
              }
              v25 = v16 + 1;
              RtlInitUnicodeString((unsigned int)v26, L"PreferenceOrder");
              ZwSetValueKey();
              if ( CmpCreateHwProfileFriendlyName(v29, a5, *a7, &v40, &v25, 4, &v39) >= 0 )
              {
                RtlInitUnicodeString((unsigned int)v26, L"FriendlyName");
                ZwSetValueKey();
                RtlFreeAnsiString(&v40);
              }
              v25 = 0;
              RtlInitUnicodeString((unsigned int)v26, L"Aliasable");
              ZwSetValueKey();
              v25 = 1;
              RtlInitUnicodeString((unsigned int)v26, L"Cloned");
              ZwSetValueKey();
              if ( ExUuidCreate((int)v42) >= 0 && RtlStringFromGUIDEx((int)v42, (int)v38, 1) >= 0 )
              {
                RtlInitUnicodeString((unsigned int)v26, L"HwProfileGuid");
                ZwSetValueKey();
                RtlFreeAnsiString(v38);
              }
              v10 = ObReferenceObjectByHandle(v24, 131097, (int)CmKeyObjectType, 0, (int)&v29, 0);
              if ( v10 >= 0 )
              {
                v10 = ObReferenceObjectByHandle(*v7, 131078, (int)CmKeyObjectType, 0, (int)v38, 0);
                if ( v10 >= 0 )
                {
                  CmpLockRegistryExclusive();
                  v17 = v38[0];
                  v18 = v29;
                  if ( CmpCopySyncTree(
                         *(_DWORD *)(*(_DWORD *)(v29 + 4) + 20),
                         *(_DWORD *)(*(_DWORD *)(v29 + 4) + 24),
                         *(_DWORD *)(*(_DWORD *)(v38[0] + 4) + 20),
                         *(_DWORD *)(*(_DWORD *)(v38[0] + 4) + 24),
                         2,
                         0) )
                  {
                    v24 = -1;
                    v29 = -1;
                    v19 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v18 + 4) + 20) + 4))(
                            *(_DWORD *)(*(_DWORD *)(v18 + 4) + 20),
                            *(_DWORD *)(*(_DWORD *)(v18 + 4) + 24),
                            &v24);
                    if ( v19 )
                    {
                      v20 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v17 + 4) + 20) + 4))(
                              *(_DWORD *)(*(_DWORD *)(v17 + 4) + 20),
                              *(_DWORD *)(*(_DWORD *)(v17 + 4) + 24),
                              &v29);
                      if ( v20 )
                      {
                        *(_WORD *)(v20 + 52) = *(_DWORD *)(v19 + 52);
                        v23 = *(_DWORD *)(v19 + 56);
                        *(_DWORD *)(v20 + 56) = v23;
                        CmpRebuildKcbCache(*(_DWORD *)(v17 + 4), v21, v22, v23);
                        (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v17 + 4) + 20) + 8))(
                          *(_DWORD *)(*(_DWORD *)(v17 + 4) + 20),
                          &v29);
                        v10 = 0;
                      }
                      else
                      {
                        v10 = -1073741670;
                      }
                      (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(*(_DWORD *)(v18 + 4) + 20) + 8))(
                        *(_DWORD *)(*(_DWORD *)(v18 + 4) + 20),
                        &v24);
                    }
                    else
                    {
                      v10 = -1073741670;
                    }
                  }
                  else
                  {
                    v10 = -1073741492;
                  }
                  CmpUnlockRegistry();
                }
              }
            }
          }
          else
          {
            v31 = 0;
          }
        }
        else
        {
          v28 = 0;
        }
      }
      else
      {
        v10 = 0;
      }
    }
  }
  ZwClose();
  if ( v28 )
    ZwClose();
  if ( v31 )
    ZwClose();
  if ( v10 < 0 && *v7 )
    ZwClose();
  return v10;
}
