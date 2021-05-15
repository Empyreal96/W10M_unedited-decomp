// PiDmCacheDataDecode 
 
int __fastcall PiDmCacheDataDecode(int *a1, _DWORD *a2, int a3, unsigned int a4, unsigned int *a5)
{
  int v7; // r2
  int v8; // r4
  int v10; // r3
  unsigned int v11; // r2
  int v12; // r1
  _DWORD v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = a3;
  v14[1] = a4;
  v7 = *a1;
  v8 = 0;
  if ( *a1 == 5 )
  {
    v10 = a1[1];
    if ( v10 == 13 )
    {
      *a2 = 13;
      *a5 = 16;
      if ( a4 >= 0x10 )
      {
        RtlInitUnicodeString((unsigned int)v14, *(unsigned __int16 **)(a1[2] + 12));
        return RtlGUIDFromString(v14, a3);
      }
      return -1073741789;
    }
    if ( v10 != 18 )
      return -1073741595;
    *a2 = 18;
    v11 = 2 * (wcslen(*(unsigned __int16 **)(a1[2] + 12)) + 1);
    *a5 = v11;
    if ( a4 < v11 )
      return -1073741789;
    v12 = *(_DWORD *)(a1[2] + 12);
LABEL_8:
    memmove(a3, v12, v11);
    return v8;
  }
  if ( v7 == 2 )
  {
    *a2 = a1[1];
    v11 = a1[2];
    *a5 = v11;
    if ( a4 < v11 )
      return -1073741789;
    v12 = (int)(a1 + 3);
    goto LABEL_8;
  }
  if ( v7 == 1 )
    return -1073741275;
  return sub_7C6AE0();
}
