// ExpQueryChannelInformation 
 
int __fastcall ExpQueryChannelInformation(unsigned int *a1, unsigned int a2, _DWORD *a3, int a4)
{
  unsigned int v7; // r5
  int v8; // r4
  unsigned int v9; // r0
  unsigned int v10; // r2
  unsigned int v12; // [sp+0h] [bp-28h] BYREF
  unsigned int v13; // [sp+4h] [bp-24h]
  _DWORD _8[14]; // [sp+8h] [bp-20h] BYREF

  _8[13] = a4;
  v13 = a2;
  _8[0] = a3;
  _8[1] = a4;
  _8[12] = a3;
  _8[11] = a2;
  _8[10] = a1;
  v7 = 0;
  v12 = 0;
  if ( a2 < 4 )
  {
    v8 = -1073741306;
    goto LABEL_8;
  }
  v9 = *a1;
  v13 = *a1;
  v8 = MmGetChannelInformation(v9, &v12, _8);
  if ( v8 >= 0 )
  {
    v10 = _8[0];
    *a3 = _8[0];
    if ( a2 >= v10 )
    {
      v7 = v12;
      memmove((int)a1, v12, v10);
      v8 = 0;
      goto LABEL_8;
    }
    v8 = -1073741789;
  }
  v7 = v12;
LABEL_8:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v8;
}
