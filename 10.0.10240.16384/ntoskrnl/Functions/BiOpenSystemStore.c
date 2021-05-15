// BiOpenSystemStore 
 
int __fastcall BiOpenSystemStore(int *a1)
{
  int *v1; // r6
  int v2; // r5
  int v3; // r10
  int v4; // r4
  int v5; // r9
  unsigned int v6; // r8
  unsigned int v7; // r7
  unsigned int v8; // r4
  int *v9; // r6
  int v11; // r0
  int v12; // r0
  int v13; // r1
  char v14; // r1
  int v15; // [sp+0h] [bp-30h] BYREF
  unsigned int v16; // [sp+4h] [bp-2Ch] BYREF
  int *v17; // [sp+8h] [bp-28h] BYREF
  int *v18; // [sp+Ch] [bp-24h]

  v1 = a1;
  v2 = 0;
  v17 = 0;
  v18 = a1;
  *a1 = 0;
  v15 = 0;
  v16 = 0;
  v3 = 0;
  BiCleanupLoadedStores(0);
  v4 = BiOpenKeyNonBcd(0, L"\\Registry\\Machine", 983103, &v16);
  v5 = v16;
  if ( v4 < 0 )
  {
LABEL_13:
    if ( v5 )
      ZwClose();
    return v4;
  }
  v4 = BiEnumerateSubKeys(v16, &v17, &v16);
  v6 = (unsigned int)v17;
  if ( v4 < 0 )
  {
LABEL_11:
    if ( v6 )
      ExFreePoolWithTag(v6);
    goto LABEL_13;
  }
  v7 = v16;
  v8 = 0;
  if ( !v16 )
  {
LABEL_8:
    if ( v8 == v7 )
    {
      v15 = 0;
      v4 = BiLoadSystemStore();
      v2 = v15;
      if ( v4 < 0 )
        goto LABEL_10;
      v3 = 1;
    }
    v12 = BiGetFirmwareType();
    switch ( v12 )
    {
      case 2:
        v4 = BiBindEfiNamespaceObjects(v2, v13);
        break;
      case 1:
        v4 = 0;
        break;
      case 3:
        v4 = 0;
LABEL_23:
        *v1 = v2;
        goto LABEL_11;
      default:
        v4 = -1073741637;
        break;
    }
    if ( v4 < 0 )
    {
LABEL_10:
      if ( v2 )
      {
        if ( v3 )
          v14 = 2;
        else
          v14 = 0;
        BiCloseStore(v2, v14);
      }
      goto LABEL_11;
    }
    goto LABEL_23;
  }
  v9 = v17;
  while ( 1 )
  {
    if ( !wcsnicmp(*v9, L"BCD", 3) && wcstoul((unsigned __int16 *)(*v9 + 6), 0, 10) != -1 )
    {
      v11 = BiOpenKey(v5, *v9, 131097, &v15);
      v2 = v15;
      if ( v11 >= 0 )
        break;
    }
    ++v8;
    ++v9;
    if ( v8 >= v7 )
      goto LABEL_7;
  }
  if ( BiIsSystemStore(v15) )
  {
LABEL_7:
    v1 = v18;
    goto LABEL_8;
  }
  return sub_813624();
}
