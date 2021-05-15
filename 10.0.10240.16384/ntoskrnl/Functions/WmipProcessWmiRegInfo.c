// WmipProcessWmiRegInfo 
 
int __fastcall WmipProcessWmiRegInfo(_DWORD *a1, unsigned int *a2, unsigned int a3, int a4)
{
  unsigned int *v4; // r6
  unsigned int v5; // r5
  int v6; // r7
  int result; // r0
  int v10; // r1
  unsigned int v11; // r3
  int v12; // [sp+8h] [bp-20h] BYREF
  int v13[7]; // [sp+Ch] [bp-1Ch] BYREF

  v12 = a3;
  v13[0] = a4;
  v4 = a2;
  v5 = a3;
  v6 = 0;
  if ( *a2 > a3 )
  {
LABEL_17:
    result = -1073741811;
  }
  else
  {
    while ( 1 )
    {
      result = WmipValidateWmiRegInfoString(v4, v5, v4[2], v13);
      if ( result < 0 )
        break;
      result = WmipValidateWmiRegInfoString(v4, v10, v4[3], &v12);
      if ( result < 0 )
        break;
      if ( 28 * v4[4] + 20 > v5 )
        goto LABEL_17;
      if ( a4 )
        result = WmipUpdateDataSource(a1, v4, v5);
      else
        result = WmipAddDataSource(a1, (int)v4, v5, v13[0], v12);
      v11 = v4[1];
      if ( result >= 0 )
        ++v6;
      if ( !v11 )
        break;
      if ( v5 < v11 )
        break;
      v5 -= v11;
      if ( v5 < 0x14 )
        break;
      v4 = (unsigned int *)((char *)v4 + v11);
      if ( (unsigned int *)(((unsigned int)v4 + 3) & 0xFFFFFFFC) != v4 )
        break;
      if ( *v4 > v5 )
        goto LABEL_17;
    }
  }
  if ( v6 )
    result = 0;
  return result;
}
