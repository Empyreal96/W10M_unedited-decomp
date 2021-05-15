// MiCheckSecuredImageVad 
 
int __fastcall MiCheckSecuredImageVad(_DWORD *a1, unsigned int a2, unsigned int *a3, unsigned int *a4)
{
  bool v7; // zf
  unsigned int v9; // r0
  unsigned int v10; // r4
  unsigned int *v11; // r1
  unsigned int v12; // r2
  __int64 v13; // kr00_8
  unsigned int *v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = a3;
  v14[1] = a4;
  if ( (a1[7] & 0xF8) == 8 )
  {
    v7 = a4 == (unsigned int *)1;
  }
  else
  {
    v9 = MiGetProtoPteAddress(a1, a2 >> 12, 5, v14);
    v10 = v9 + 4 * (((int)(((((unsigned int)a3 + a2 - 1) >> 10) & 0x3FFFFC) - ((a2 >> 10) & 0x3FFFFC)) >> 2) + 1);
    if ( v9 >= v10 )
      return 0;
    v11 = v14[0];
    while ( v11 )
    {
      if ( a4 != (unsigned int *)((*((unsigned __int16 *)v11 + 8) >> 1) & 0x1F) )
        return -1073741755;
      v12 = v11[7];
      v13 = *(_QWORD *)(v11 + 1);
      v11 = (unsigned int *)v11[2];
      if ( (unsigned int)v13 + 4 * v12 >= v10 )
        return 0;
    }
    v7 = a4 == (unsigned int *)24;
  }
  if ( !v7 )
    return -1073741755;
  return 0;
}
