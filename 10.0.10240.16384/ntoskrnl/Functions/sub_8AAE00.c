// sub_8AAE00 
 
int __fastcall sub_8AAE00(int a1, _DWORD *a2, int *a3)
{
  int v5; // r4
  int v6; // r5
  _DWORD *v7; // r7
  int v8; // t1
  int v10; // r5
  unsigned __int16 v11[2]; // [sp+10h] [bp-460h] BYREF
  char *v12; // [sp+14h] [bp-45Ch]
  int v13[8]; // [sp+18h] [bp-458h] BYREF
  unsigned __int16 v14[268]; // [sp+38h] [bp-438h] BYREF
  char v15; // [sp+250h] [bp-220h] BYREF

  v11[0] = 0;
  v11[1] = 520;
  v12 = &v15;
  v13[2] = 24;
  v13[3] = 0;
  v13[4] = a1;
  v13[5] = 576;
  v13[6] = 0;
  v13[7] = 0;
  v5 = ZwOpenSymbolicLinkObject();
  if ( v5 >= 0 )
  {
    v5 = ZwQuerySymbolicLinkObject();
    if ( v5 >= 0 )
    {
      v6 = 0;
      if ( *a2 )
      {
        v7 = a2;
        while ( 1 )
        {
          v8 = v7[1];
          ++v7;
          v13[0] = 0;
          v5 = ObQueryNameStringMode(v8, (int)v14, 530, v13, 0);
          if ( v5 < 0 )
            break;
          if ( RtlEqualUnicodeString(v11, v14, 1) )
          {
            v10 = a2[v6 + 1];
            ObfReferenceObject(v10);
            if ( !v10 )
              goto LABEL_8;
            *a3 = v10;
            return v5;
          }
          if ( (unsigned int)++v6 >= *a2 )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        v5 = -1073741772;
      }
    }
  }
  return v5;
}
