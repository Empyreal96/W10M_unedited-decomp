// IoWMIQueryAllData 
 
int __fastcall IoWMIQueryAllData(int a1, unsigned int *a2, char *a3)
{
  unsigned int v5; // r2
  int result; // r0
  int v7; // r3
  unsigned int v8; // [sp+8h] [bp-60h] BYREF
  char v9[88]; // [sp+10h] [bp-58h] BYREF

  v5 = *a2;
  if ( !a3 || v5 < 0x48 )
  {
    a3 = v9;
    v5 = 72;
  }
  *((_DWORD *)a3 + 11) = 1;
  *(_DWORD *)a3 = 48;
  *((_DWORD *)a3 + 3) = 0;
  *((_DWORD *)a3 + 4) = 0;
  result = WmipQueryAllData(a1, 0, 0, a3, v5, &v8);
  if ( result >= 0 )
  {
    v7 = *((_DWORD *)a3 + 11);
    if ( (v7 & 0x100) != 0 )
      return -1073741637;
    if ( (v7 & 0x20) != 0 )
    {
      *a2 = *((_DWORD *)a3 + 12);
    }
    else
    {
      *a2 = v8;
      if ( a3 != v9 )
        return result;
    }
    result = -1073741789;
  }
  return result;
}
