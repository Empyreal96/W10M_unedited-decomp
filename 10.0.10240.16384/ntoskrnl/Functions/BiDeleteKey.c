// BiDeleteKey 
 
int __fastcall BiDeleteKey(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  unsigned int v6; // r5
  int v7; // r4
  int v8; // r4
  int result; // r0
  int *v10; // r7
  int v11; // t1
  int *v12; // [sp+0h] [bp-18h] BYREF
  int v13[5]; // [sp+4h] [bp-14h] BYREF

  v13[0] = a4;
  v12 = 0;
  v5 = BiEnumerateSubKeys(a1, &v12, v13);
  v6 = (unsigned int)v12;
  if ( v5 >= 0 && (v7 = v13[0]) != 0 )
  {
    v10 = v12;
    while ( 1 )
    {
      v11 = *v10++;
      if ( BiOpenKey(a1, v11, 983103, &v12) >= 0 && BiDeleteKey(v12) < 0 )
        break;
      if ( !--v7 )
        goto LABEL_3;
    }
    result = sub_813818();
  }
  else
  {
LABEL_3:
    if ( v6 )
      ExFreePoolWithTag(v6);
    v8 = BiZwDeleteKey();
    if ( v8 >= 0 )
      BiZwClose();
    result = v8;
  }
  return result;
}
