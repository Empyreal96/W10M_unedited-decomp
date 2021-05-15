// IoWMIQuerySingleInstanceMultiple 
 
int __fastcall IoWMIQuerySingleInstanceMultiple(int a1, int a2, int a3, unsigned int *a4, char *a5)
{
  char *v5; // r4
  unsigned int v7; // r3
  int result; // r0
  unsigned int v9; // [sp+18h] [bp-50h] BYREF
  char v10[72]; // [sp+20h] [bp-48h] BYREF

  v5 = a5;
  if ( !a1 || !a2 || !a3 || !a4 )
    return -1073741811;
  v7 = *a4;
  if ( !a5 || v7 < 0x38 )
  {
    v5 = v10;
    v7 = 56;
  }
  result = WmipQuerySingleMultiple(0, 0, v5, v7, 0, a3, a1, a2, &v9);
  if ( result >= 0 )
  {
    if ( (*((_DWORD *)v5 + 11) & 0x20) != 0 )
    {
      *a4 = *((_DWORD *)v5 + 12);
      return -1073741789;
    }
    *a4 = v9;
    if ( v5 == v10 )
      return -1073741789;
  }
  return result;
}
