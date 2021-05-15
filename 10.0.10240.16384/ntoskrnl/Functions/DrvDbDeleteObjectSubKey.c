// DrvDbDeleteObjectSubKey 
 
int __fastcall DrvDbDeleteObjectSubKey(int **a1, int a2, unsigned __int16 *a3, unsigned int a4)
{
  int *v6; // r0
  unsigned int v7; // r8
  unsigned int v8; // r9
  int v9; // r4
  int i; // r0
  unsigned int v11; // r4
  int v12; // r0
  unsigned int v13; // r5
  int v14; // r6
  int v15; // r0
  int v16; // r4
  unsigned __int16 *v17; // r0
  unsigned __int16 *v18; // r6
  int v19; // r9
  int v20; // r0
  int v21; // r0
  unsigned __int16 *v22; // r0
  bool v23; // zf
  int v24; // r0
  int v25; // r6
  int v26; // r0
  unsigned __int16 *v27; // r5
  int v28; // r0
  int v30; // [sp+4h] [bp-3Ch]
  unsigned int v31[2]; // [sp+18h] [bp-28h] BYREF
  int v32[8]; // [sp+20h] [bp-20h] BYREF

  v6 = *a1;
  v7 = 0;
  v8 = 0;
  v32[0] = a2;
  if ( a4 <= 1 )
  {
    v9 = PnpCtxRegDeleteTree(v6, a2, a3);
    goto LABEL_3;
  }
  v9 = PnpCtxRegOpenKey(v6, a2, (int)a3, 0);
  if ( v9 < 0 )
  {
LABEL_3:
    if ( v9 == -1073741444 )
      v9 = 0;
    return v9;
  }
  for ( i = PnpGetGenericStorePropertyKeys(*a1, 0, 0, 0, 0, 0, v31);
        ;
        i = PnpGetGenericStorePropertyKeys(*a1, 0, 0, 0, v12, v11, v31) )
  {
    v9 = i;
    if ( i != -1073741789 )
      break;
    v11 = v31[0];
    if ( v31[0] <= v8 )
    {
      v9 = -1073741595;
      goto LABEL_61;
    }
    if ( v7 )
      ExFreePoolWithTag(v7);
    v8 = v11;
    v12 = ExAllocatePoolWithTag(1, 20 * v11, 1111770192);
    v7 = v12;
    if ( !v12 )
    {
      v9 = -1073741801;
      break;
    }
  }
  if ( v9 != -1073741275 )
  {
    if ( v9 < 0 )
      goto LABEL_61;
    v13 = 0;
    if ( v8 )
    {
      v14 = v7;
      do
      {
        v15 = PnpDeletePropertyWorker(*a1, 0, 0, v14, 0, v30, 0);
        v9 = v15;
        if ( v15 == -1073741275 || v15 == -1073741790 )
        {
          v9 = 0;
        }
        else if ( v15 < 0 )
        {
          goto LABEL_61;
        }
        ++v13;
        v14 += 20;
      }
      while ( v13 < v8 );
    }
    if ( v9 < 0 )
      goto LABEL_61;
  }
  if ( !wcschr(a3, 92) )
  {
    v24 = PnpCtxRegDeleteKey(*a1, 0, 0);
    v9 = v24;
    if ( v24 == -1073741444 )
    {
      v9 = 0;
      goto LABEL_61;
    }
    if ( v24 != -1073741535 )
      goto LABEL_61;
    v9 = PnpCtxRegQueryInfoKey(-1073741535, 0, 0, (int)v31, (int)v31);
    if ( v9 < 0 )
      goto LABEL_61;
    v25 = v32[0] + 1;
    if ( !v31[0] )
      goto LABEL_61;
    v26 = ExAllocatePoolWithTag(1, 2 * v25, 1111770192);
    v27 = (unsigned __int16 *)v26;
    if ( v26 )
    {
      while ( 1 )
      {
        v32[0] = v25;
        v28 = PnpCtxRegEnumValue(v26, 0, 0, (int)v27, (int)v32, 0, 0, 0);
        v9 = v28;
        if ( v28 < 0 )
          break;
        v26 = RtlInitUnicodeStringEx((int)v31, v27);
        v9 = v26;
        if ( v26 >= 0 )
        {
          v26 = ZwDeleteValueKey();
          v9 = v26;
        }
        if ( v9 != -1073741772 && v9 < 0 )
          goto LABEL_58;
      }
      if ( v28 == -2147483622 )
        v9 = 0;
LABEL_58:
      ExFreePoolWithTag((unsigned int)v27);
      v18 = 0;
      goto LABEL_59;
    }
LABEL_28:
    v9 = -1073741801;
    goto LABEL_61;
  }
  v16 = wcslen(a3) + 1;
  v17 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 2 * v16, 1111770192);
  v18 = v17;
  if ( !v17 )
    goto LABEL_28;
  RtlStringCchCopyExW(v17, v16, a3);
  v19 = v32[0];
  while ( 1 )
  {
    v20 = PnpCtxRegOpenKey(*a1, v19, (int)v18, 0);
    v9 = v20;
    if ( v20 < 0 )
    {
      v23 = v20 == -1073741444;
      goto LABEL_40;
    }
    v9 = PnpCtxRegQueryInfoKey(v20, 0, (int)v32, (int)v31, (int)v31);
    if ( v9 < 0 || v32[0] || v31[0] )
      goto LABEL_59;
    v21 = PnpCtxRegDeleteKey(*a1, 0, 0);
    v9 = v21;
    if ( v21 == -1073741444 )
    {
      v9 = 0;
      goto LABEL_37;
    }
    if ( v21 < 0 )
      break;
LABEL_37:
    v22 = wcsrchr(v18, 92);
    if ( !v22 )
      goto LABEL_59;
    *v22 = 0;
    ZwClose();
  }
  v23 = v21 == -1073741535;
LABEL_40:
  if ( v23 )
    v9 = 0;
LABEL_59:
  if ( v18 )
    ExFreePoolWithTag((unsigned int)v18);
LABEL_61:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v9;
}
