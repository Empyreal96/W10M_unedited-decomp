// IopGetFileVolumeNameInformation 
 
int __fastcall IopGetFileVolumeNameInformation(int a1, int *a2, _DWORD *a3, int a4)
{
  unsigned int v6; // r6
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r6
  int v11; // [sp-4h] [bp-220h] BYREF
  unsigned __int16 v12; // [sp+4h] [bp-218h] BYREF
  int v13; // [sp+8h] [bp-214h]

  v6 = a4 - 4;
  v7 = ObQueryNameString(a1, &v12, 512, &v11);
  v8 = v7;
  if ( v7 >= 0 )
  {
    if ( v6 < v12 )
    {
      v8 = -2147483643;
      v9 = v6 & 0xFFFFFFFE;
    }
    else
    {
      v8 = 0;
      v9 = v12;
    }
    *a3 = v12;
    memmove((int)(a3 + 1), v13, v9);
    *a2 = v8;
    a2[1] = v9 + 4;
  }
  else
  {
    *a2 = v7;
    a2[1] = 0;
  }
  return v8;
}
