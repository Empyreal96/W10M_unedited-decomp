// BiCreateObject 
 
int __fastcall BiCreateObject(int a1, int a2, int a3, int a4, int *a5)
{
  int v9; // r4
  int v10; // r6
  int v11; // r5
  char v12[4]; // [sp+8h] [bp-48h] BYREF
  int v13; // [sp+Ch] [bp-44h] BYREF
  int v14; // [sp+10h] [bp-40h] BYREF
  int v15; // [sp+14h] [bp-3Ch] BYREF
  int v16; // [sp+18h] [bp-38h] BYREF
  int v17; // [sp+1Ch] [bp-34h]
  char v18[48]; // [sp+20h] [bp-30h] BYREF

  *a5 = 0;
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v17 = 0;
  if ( !BiIsValidObject(a3, a2, a4) )
    return -1073741637;
  if ( !a2 )
    return sub_8136D4();
  if ( BiIsObjectAliased(a2, v18) )
    return -1073741773;
  v9 = BiOpenKey(a1, L"Objects", 4, &v14);
  v10 = v14;
  if ( v9 >= 0 )
  {
    v9 = RtlStringFromGUIDEx(a2, (int)&v16, 1);
    if ( v9 >= 0 )
    {
      v9 = BiCreateKey(v10, v17, 983103, 0, &v15, v12);
      RtlFreeAnsiString(&v16);
      v11 = v15;
      if ( v9 < 0 )
        goto LABEL_19;
      v9 = BiSetObjectDescription(v15, a3);
      if ( v9 < 0 )
        goto LABEL_19;
      v9 = BiCreateKey(v11, L"Elements", 131097, 0, &v13, v12);
      if ( v9 >= 0 )
      {
        *a5 = v11;
        v9 = 0;
      }
      if ( v13 )
        BiCloseKey(v13);
      if ( v9 < 0 )
      {
LABEL_19:
        if ( v11 )
          BiCloseKey(v11);
      }
    }
  }
  if ( v10 )
    BiCloseKey(v10);
  return v9;
}
