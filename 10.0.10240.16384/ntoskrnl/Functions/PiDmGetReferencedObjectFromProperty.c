// PiDmGetReferencedObjectFromProperty 
 
int __fastcall PiDmGetReferencedObjectFromProperty(int a1, int a2, int a3, int a4, int a5, int a6, int *a7)
{
  int v9; // r0
  int v10; // r4
  unsigned int v12; // r5
  char *v13; // r1
  int v14; // [sp+4h] [bp-9Ch]
  int v15; // [sp+20h] [bp-80h] BYREF
  int v16; // [sp+24h] [bp-7Ch] BYREF
  int v17; // [sp+28h] [bp-78h] BYREF
  char v18[112]; // [sp+30h] [bp-70h] BYREF

  *a7 = 0;
  v15 = 0;
  v9 = PiDmObjectGetCachedObjectReference(a1, a2, a3, a5, a7);
  v10 = v9;
  if ( v9 < 0 )
  {
    if ( v9 != -1073741802 )
      return v10;
    v10 = PnpGetObjectProperty(1517317712, 16, a2, a1, 0, v14, a5, (int)&v16, (unsigned int *)&v15, &v17, 0);
    v12 = v15;
    if ( v10 >= 0 )
    {
      if ( v16 == 13 )
      {
        v10 = PnpStringFromGuid(v15, (int)v18);
        if ( v10 < 0 )
          goto LABEL_11;
        v13 = v18;
        goto LABEL_10;
      }
      if ( v16 == 18 )
      {
        v13 = (char *)v15;
LABEL_10:
        v10 = PiDmGetObject(a6, (int)v13, a7);
        goto LABEL_11;
      }
      v10 = -1073741772;
    }
LABEL_11:
    if ( v12 )
      ExFreePoolWithTag(v12);
    return v10;
  }
  if ( *(_DWORD *)(*a7 + 20) != a6 )
    return sub_7EEC80();
  return v10;
}
