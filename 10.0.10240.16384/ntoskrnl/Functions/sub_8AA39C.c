// sub_8AA39C 
 
int __fastcall sub_8AA39C(_DWORD *a1, _DWORD *a2)
{
  int v4; // r4
  _DWORD *v5; // r6
  int v6; // r5
  _DWORD *v7; // r7
  int v8; // t1
  char *v9; // r5
  unsigned int v10; // r7
  int v11; // r0
  _DWORD *v13; // [sp+8h] [bp-88h] BYREF
  int v14[6]; // [sp+10h] [bp-80h] BYREF
  char v15[104]; // [sp+28h] [bp-68h] BYREF

  sub_8AAD98(v15);
  memset(v14, 0, 20);
  v13 = 0;
  LOBYTE(v14[3]) = a1 == 0;
  v4 = sub_8AAD30(&v13);
  if ( v4 >= 0 )
  {
    v5 = v13;
    v6 = 0;
    if ( *v13 )
    {
      v7 = v13;
      while ( 1 )
      {
        v8 = v7[1];
        ++v7;
        if ( sub_8AAAAC(v8, v15) >= 0 )
        {
          v4 = sub_8AA5DC(*v7, v15);
          if ( v4 < 0 )
            break;
          v4 = sub_8AB028(v15, 0, v14);
          if ( v4 < 0 )
            break;
        }
        if ( (unsigned int)++v6 >= *v5 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      v9 = &byte_6181A8;
      v10 = 0;
      while ( 1 )
      {
        v11 = *v9 ? sub_8AB0EC(*((_DWORD *)v9 + 1), (unsigned __int8)v9[1], *((_DWORD *)v9 + 2), v5, v15, v14) : (*((int (__fastcall **)(int *, _DWORD, _DWORD))v9 + 2))(v14, 0, 0);
        v4 = v11;
        if ( v11 < 0 )
          break;
        ++v10;
        v9 += 12;
        if ( v10 >= 6 )
        {
          if ( a1 )
            *a1 = v14[4];
          *a2 = v14[1];
          v14[4] = 0;
          break;
        }
      }
    }
    PiPnpFreePdoDeviceList(v5);
  }
  sub_8AA9E4(v15);
  if ( v14[4] )
    ExFreePoolWithTag(v14[4]);
  return v4;
}
