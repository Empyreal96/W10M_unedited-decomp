// ViThunkFindAllExportAddresses 
 
int __fastcall ViThunkFindAllExportAddresses(int result, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // r5
  unsigned int v5; // r6
  int i; // r9
  int v9[8]; // [sp+0h] [bp-20h] BYREF

  v9[0] = a4;
  v4 = a2;
  v5 = 0;
  for ( i = result; *v4; ++v5 )
  {
    result = ViThunkFindExportAddress(i, *v4, v9);
    if ( v9[0] )
    {
      result = v5 >> 3;
      *(_BYTE *)((v5 >> 3) + *(_DWORD *)(a4 + 4)) &= ~(unsigned __int8)(1 << (v5 & 7));
      v4[2] = 0;
    }
    else
    {
      v4[2] = result;
    }
    v4 = (_DWORD *)((char *)v4 + a3);
  }
  return result;
}
