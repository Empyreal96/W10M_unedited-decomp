// IoWMIQueryAllDataMultiple 
 
int __fastcall IoWMIQueryAllDataMultiple(int a1, int a2, unsigned int *a3, char *a4)
{
  char *v4; // r4
  unsigned int v6; // r2
  int result; // r0
  unsigned int v8; // [sp+10h] [bp-60h] BYREF
  char v9[88]; // [sp+18h] [bp-58h] BYREF

  v4 = a4;
  if ( !a1 || !a2 || !a3 )
    return -1073741811;
  v6 = *a3;
  if ( !a4 || v6 < 0x48 )
  {
    v4 = v9;
    v6 = 72;
  }
  result = WmipQueryAllDataMultiple(a2, a1, 0, 0, v4, v6, 0, &v8);
  if ( result >= 0 )
  {
    if ( (*((_DWORD *)v4 + 11) & 0x20) != 0 )
    {
      *a3 = *((_DWORD *)v4 + 12);
      return -1073741789;
    }
    *a3 = v8;
    if ( v4 == v9 )
      return -1073741789;
  }
  return result;
}
