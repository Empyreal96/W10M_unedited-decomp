// _RegRtlEnumKey 
 
int __fastcall RegRtlEnumKey(int a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v6; // r8
  int v7; // r4
  unsigned int v8; // r6
  char *v9; // r5
  unsigned int v10; // r10
  int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r2
  int v15; // r0
  unsigned int v16; // r3
  unsigned int v17; // r2
  int v18[4]; // [sp+8h] [bp-90h] BYREF
  char v19; // [sp+18h] [bp-80h] BYREF

  v18[1] = a1;
  v18[2] = a2;
  v6 = 0;
  if ( a3 )
  {
    v7 = RtlULongLongToULong(2 * *a4, (unsigned __int64)*a4 >> 31, v18);
    if ( v7 < 0 )
      return v7;
    v8 = v18[0];
  }
  else
  {
    v8 = 0;
  }
  if ( v8 > 0x60 )
  {
    v9 = (char *)a3;
    v10 = v8;
  }
  else
  {
    v9 = &v19;
    v10 = 96;
  }
  v11 = ZwEnumerateKey();
  v7 = v11;
  v18[3] = -2147483643;
  if ( v11 && v11 != -2147483643 )
    return v7;
  v12 = *((_DWORD *)v9 + 3);
  v13 = v12 + 2;
  if ( v12 + 2 < v12 )
    return -1073741675;
  v7 = 0;
  *a4 = v13 >> 1;
  if ( v13 > v8 )
    return -1073741789;
  if ( v18[0] <= v10 )
  {
LABEL_10:
    memmove(a3, (int)(v9 + 16), *((_DWORD *)v9 + 3));
    *(_WORD *)(a3 + 2 * *a4 - 2) = 0;
    goto LABEL_11;
  }
  if ( v8 >= 0xFFFFFFF0 )
    return -1073741675;
  v15 = ExAllocatePoolWithTag(1, v8 + 16, 1279739218);
  v6 = v15;
  if ( !v15 )
    return -1073741801;
  v9 = (char *)v15;
  if ( !ZwEnumerateKey() )
  {
    v16 = *(_DWORD *)(v6 + 12);
    v17 = v16 + 2;
    if ( v16 + 2 < v16 )
    {
      v7 = -1073741675;
    }
    else
    {
      v7 = 0;
      *a4 = v17 >> 1;
      if ( v17 <= v8 )
        goto LABEL_10;
      v7 = -1073741789;
    }
LABEL_11:
    if ( v6 )
      ExFreePoolWithTag(v6);
    return v7;
  }
  return sub_7EE870();
}
