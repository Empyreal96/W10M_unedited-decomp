// ExpGenuinePolicyPostProcess 
 
int __fastcall ExpGenuinePolicyPostProcess(_DWORD *a1, int *a2, unsigned int a3, _DWORD *a4, _BYTE *a5)
{
  int v5; // r10
  int *v6; // r4
  int v8; // r5
  unsigned int v9; // r7
  int v11; // r3
  int v12; // r0
  int v13; // r0
  char v15[4]; // [sp+8h] [bp-40h] BYREF
  int v16; // [sp+Ch] [bp-3Ch] BYREF
  int v17; // [sp+10h] [bp-38h]
  int v18; // [sp+14h] [bp-34h] BYREF
  int v19[2]; // [sp+18h] [bp-30h] BYREF
  _DWORD *v20; // [sp+20h] [bp-28h]
  _DWORD *v21; // [sp+24h] [bp-24h]

  v20 = a4;
  v21 = a1;
  v19[0] = 0;
  v5 = 0;
  v17 = 0;
  v19[1] = 4;
  v6 = off_920350;
  v18 = 0;
  v16 = 0;
  v8 = 0;
  v9 = 0;
  *a5 = 0;
  if ( v6 )
  {
    v8 = sub_6E29F0(a1, a2, a3, a4, 2);
    *a5 = 1;
    return v8;
  }
  if ( !a2
    || (a3 == 1 ? (v11 = *(unsigned __int8 *)a2) : a3 == 2 ? (v11 = *(unsigned __int16 *)a2) : (v11 = *a2), v11 != 1) )
  {
    v8 = ZwQueryLicenseValue();
    if ( v8 < 0 || v17 != 1 )
    {
      v8 = off_920498 ? ((int (__fastcall *)(int *))off_920498)(v19) : -1073741637;
      if ( v8 >= 0 )
      {
        if ( off_920480 )
        {
          v8 = ExpOsProductCacheProviderHelper(&dword_8C8258, 0, 0, 0, &v16, v15);
          if ( v8 == -1073741789 )
          {
            v12 = ExAllocatePoolWithTag(1, v16, 542329939);
            v9 = v12;
            if ( !v12 )
              return -1073741801;
            v8 = ExpOsProductCacheProviderHelper(&dword_8C8258, 0, v12, v16, &v16, v15);
          }
          if ( v8 < 0 )
            goto LABEL_33;
          v13 = off_920480(3, v9, 0, 0, 0, &v18);
          v8 = v13;
          if ( v13 >= 0 && (v18 & 0x40) != 0 )
          {
            v5 = 1;
LABEL_25:
            v8 = 0;
            goto LABEL_30;
          }
          if ( v13 == -1073741198 )
            goto LABEL_25;
        }
        else
        {
          v8 = -1073741637;
        }
        if ( v8 < 0 )
        {
LABEL_33:
          if ( v9 )
            ExFreePoolWithTag(v9);
          return v8;
        }
LABEL_30:
        if ( !v19[0] || v5 )
        {
          v8 = sub_6E29F0(v21, a2, a3, v20, 2);
          *a5 = 1;
        }
        goto LABEL_33;
      }
    }
  }
  return v8;
}
