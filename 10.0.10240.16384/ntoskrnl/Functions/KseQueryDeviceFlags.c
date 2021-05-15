// KseQueryDeviceFlags 
 
int __fastcall KseQueryDeviceFlags(int a1, int a2, _DWORD *a3)
{
  int v3; // r3
  int v4; // r6
  int v6; // [sp+8h] [bp-38h] BYREF
  int v7[13]; // [sp+Ch] [bp-34h] BYREF

  v7[1] = 0;
  v7[2] = 0;
  v3 = dword_6416D4;
  __dmb(0xBu);
  if ( v3 != 2 || (KseEngine & 2) != 0 )
    return -1073741275;
  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  *a3 = 0;
  a3[1] = 0;
  v6 = 11;
  v7[0] = 8;
  v4 = KseQueryDeviceData(a1, a2, &v6, (int)v7);
  if ( v4 >= 0 )
    return sub_7CEF48();
  return v4;
}
