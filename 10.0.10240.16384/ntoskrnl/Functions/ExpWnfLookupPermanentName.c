// ExpWnfLookupPermanentName 
 
int __fastcall ExpWnfLookupPermanentName(__int64 a1, _DWORD *a2, int a3)
{
  _DWORD *v4; // r4
  int v5; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r6
  int v10; // r0
  _DWORD *v11; // r2
  int v13; // [sp+Ch] [bp-54h] BYREF
  __int16 v14; // [sp+10h] [bp-50h]
  __int16 v15; // [sp+12h] [bp-4Eh]
  char *v16; // [sp+14h] [bp-4Ch]
  char v17; // [sp+18h] [bp-48h] BYREF
  __int64 varg_r0; // [sp+68h] [bp+8h]
  _DWORD *varg_r2; // [sp+70h] [bp+10h]
  int varg_r3; // [sp+74h] [bp+14h]

  varg_r2 = a2;
  varg_r3 = a3;
  v14 = 0;
  v15 = 34;
  v16 = &v17;
  varg_r0 = a1;
  v4 = 0;
  ExpWnfComposeValueName(a1, HIDWORD(a1));
  v5 = ExpWnfGetNameStoreRegistryRoot((varg_r0 >> 4) & 3, &v13);
  if ( v5 < 0 )
    return v5;
  v6 = 0;
  v5 = ZwQueryValueKey();
  if ( v5 != -1073741789 )
  {
LABEL_6:
    if ( v5 >= 0 )
    {
      if ( *(_DWORD *)(v6 + 4) == 3 )
      {
        *v4 = 0;
        v4[1] = 0;
        v4[2] = 0;
        v8 = v6 + 12;
        v9 = *(_DWORD *)(v6 + 8);
        v4[2] = v8;
        if ( RtlValidRelativeSecurityDescriptor(v8, v9, 0, 0) )
        {
          ExpWnfSpecializeSecurityDescriptor(v4[2]);
          v10 = RtlLengthSecurityDescriptor(v4[2]);
          v11 = (_DWORD *)(v10 + v8);
          if ( v9 - v10 >= 4 )
          {
            *v4 = *v11;
            if ( v9 - v10 - 4 >= 0x10 )
              v4[1] = v11 + 1;
            else
              v4[1] = 0;
            *a2 = v4;
            return 0;
          }
        }
      }
      v5 = -1073741823;
    }
LABEL_14:
    if ( v4 )
      ExFreePoolWithTag((unsigned int)v4);
    return v5;
  }
  while ( !v4 )
  {
    v7 = ExAllocatePoolWithTag(1, 12, 543583831);
    v4 = (_DWORD *)v7;
    if ( !v7 )
    {
      v5 = -1073741670;
      goto LABEL_14;
    }
    v6 = v7 + 12;
    v5 = ZwQueryValueKey();
    if ( v5 != -1073741789 )
      goto LABEL_6;
  }
  return sub_7C4984();
}
