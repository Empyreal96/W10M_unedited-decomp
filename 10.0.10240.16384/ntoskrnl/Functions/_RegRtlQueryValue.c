// _RegRtlQueryValue 
 
int __fastcall RegRtlQueryValue(int a1, unsigned __int16 *a2, _DWORD *a3, int a4, unsigned int *a5)
{
  unsigned int v7; // r6
  int v8; // r4
  unsigned int v9; // r1
  int v10; // r0
  char *v11; // r5
  int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r3
  char v16[8]; // [sp+8h] [bp-C0h] BYREF
  char v17; // [sp+18h] [bp-B0h] BYREF

  v7 = 0;
  v8 = RtlInitUnicodeStringEx((int)v16, a2);
  if ( v8 >= 0 )
  {
    if ( a4 && (v9 = *a5, *a5 > 0x80) )
    {
      if ( v9 >= 0xFFFFFFF4 )
        return -1073741675;
      v10 = ExAllocatePoolWithTag(1, v9 + 12, 1279739218);
      v7 = v10;
      if ( !v10 )
        return -1073741801;
      v11 = (char *)v10;
    }
    else
    {
      v11 = &v17;
    }
    v12 = ZwQueryValueKey();
    v8 = v12;
    if ( !v12 || v12 == -2147483643 )
    {
      v13 = *a5;
      v14 = *((_DWORD *)v11 + 2);
      *a5 = v14;
      if ( v13 < v14 )
        v8 = -1073741789;
      else
        memmove(a4, (int)(v11 + 12), *((_DWORD *)v11 + 2));
      if ( a3 )
        *a3 = *((_DWORD *)v11 + 1);
    }
    if ( v7 )
      ExFreePoolWithTag(v7);
  }
  return v8;
}
