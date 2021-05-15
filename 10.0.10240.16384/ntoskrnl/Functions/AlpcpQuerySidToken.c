// AlpcpQuerySidToken 
 
int __fastcall AlpcpQuerySidToken(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v7; // r5
  unsigned int v8; // r2
  unsigned int v10; // [sp+0h] [bp-68h] BYREF
  _BYTE v11[96]; // [sp+8h] [bp-60h] BYREF

  SeQueryUserSidToken(a1, (int)v11, 0x44u, &v10);
  v7 = 0;
  v8 = v10;
  if ( v10 > a3 )
    v7 = -1073741789;
  if ( a4 )
    *a4 = v10;
  if ( v7 >= 0 )
    memmove(a2, (int)v11, v8);
  return v7;
}
