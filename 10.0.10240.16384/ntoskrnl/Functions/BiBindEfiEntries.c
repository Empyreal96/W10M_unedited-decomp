// BiBindEfiEntries 
 
int __fastcall BiBindEfiEntries(int a1, _DWORD *a2)
{
  int v2; // r4
  _DWORD *v3; // r7
  int v4; // r5
  int v5; // r8
  int v6; // r3
  int v8; // r0
  int v9; // r10
  int v10; // r0
  unsigned __int16 *v11; // r9
  int v12; // r2
  int v13; // r3
  int v14; // r4
  int v15; // [sp+8h] [bp-58h] BYREF
  unsigned __int16 *v16; // [sp+Ch] [bp-54h] BYREF
  _DWORD *v17; // [sp+10h] [bp-50h]
  int v18; // [sp+18h] [bp-48h]
  int v19[2]; // [sp+20h] [bp-40h] BYREF
  unsigned __int16 v20[4]; // [sp+28h] [bp-38h] BYREF
  _DWORD v21[12]; // [sp+30h] [bp-30h] BYREF

  v2 = (int)a2;
  v3 = (_DWORD *)*a2;
  v4 = a1;
  v17 = a2;
  v18 = a1;
  v5 = 0;
  if ( v3 == a2 )
    return v5;
  while ( 1 )
  {
    v6 = v3[8];
    if ( (v6 & 1) == 0 )
      return sub_812E88();
    v15 = 0;
    v16 = 0;
    if ( (v6 & 4) != 0 )
      goto LABEL_20;
    v19[0] = 1;
    v19[1] = 270532607;
    v8 = BiCreateObject(v4, 0, v19, 1, &v15);
    v9 = v15;
    v5 = v8;
    if ( v8 >= 0 )
    {
      v10 = BiGetKeyName(v15, &v16);
      v11 = v16;
      v5 = v10;
      if ( v10 >= 0 )
      {
        RtlInitUnicodeString((unsigned int)v20, v16);
        v5 = RtlGUIDFromString(v20, v21);
        if ( v5 >= 0 )
        {
          v3[8] |= 4u;
          v12 = v21[1];
          v13 = v21[2];
          v14 = v21[3];
          v3[2] = v21[0];
          v3[3] = v12;
          v3[4] = v13;
          v3[5] = v14;
          v2 = (int)v17;
          v4 = v18;
        }
      }
      if ( v11 )
        ExFreePoolWithTag((unsigned int)v11);
    }
    if ( v9 )
      BcdCloseObject(v9);
    if ( v5 >= 0 )
    {
LABEL_20:
      v5 = BiUpdateBcdObject(v4, v3);
      if ( v5 >= 0 )
      {
        v3 = (_DWORD *)*v3;
        if ( v3 != (_DWORD *)v2 )
          continue;
      }
    }
    return v5;
  }
}
