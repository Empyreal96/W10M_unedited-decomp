// sub_8A0B04 
 
int __fastcall sub_8A0B04(_DWORD *a1, int a2, unsigned int a3, _DWORD *a4, _BYTE *a5)
{
  int *v9; // r0
  int v10; // r5
  int v11; // r4
  unsigned int v12; // r2
  int v14; // [sp+0h] [bp-20h] BYREF
  int v15[7]; // [sp+4h] [bp-1Ch] BYREF

  v15[0] = (int)a4;
  v14 = 0;
  *a5 = 1;
  if ( a2 )
    v9 = &v14;
  else
    v9 = 0;
  v10 = sub_8AA39C(v9, v15);
  v11 = v14;
  if ( v10 >= 0 )
  {
    v12 = v15[0];
    *a4 = v15[0];
    if ( a1 )
      *a1 = 3;
    if ( v12 <= a3 )
    {
      if ( a2 )
        memmove(a2, v11, v12);
    }
    else
    {
      v10 = -1073741789;
    }
  }
  if ( v11 )
    ExFreePoolWithTag(v11);
  return v10;
}
