// RawQueryFsAttributeInfo 
 
int __fastcall RawQueryFsAttributeInfo(int a1, _DWORD *a2, int *a3)
{
  int v3; // r4

  v3 = *a3;
  if ( (unsigned int)*a3 < 0x12 )
    return -2147483643;
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 6;
  qmemcpy(a2 + 3, "RAW", 6);
  *a3 = v3 - 18;
  return 0;
}
