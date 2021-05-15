// HvpViewMapGrowFile 
 
int __fastcall HvpViewMapGrowFile(unsigned int *a1, int a2, unsigned int a3)
{
  unsigned int v3; // r6
  int v4; // r3
  unsigned int v5; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r7
  int i; // r0
  int v11; // r8
  unsigned int v13; // r4
  int v14[9]; // [sp+Ch] [bp-24h] BYREF

  v3 = *a1;
  v4 = *a1 & 0x3FFFF;
  v5 = a3 - *a1;
  v14[0] = v4;
  *a1 = a3;
  if ( (v3 & 0x3FFFF) != 0 )
  {
    v7 = v5 + v4;
    v8 = v3 & 0xFFFC0000;
    v9 = 0x40000;
    if ( v7 < 0x40000 )
      v9 = v7;
    i = HvpViewRemapViewOfPrimaryFile(a1);
    v11 = i;
    if ( i < 0 )
    {
      v13 = v3;
      if ( !v14[0] )
        goto LABEL_15;
      if ( v8 > v3 )
      {
        v13 = v3 & 0xFFFC0000;
        for ( i = HvpViewRemapViewOfPrimaryFile(i); ; i = HvpViewUnmapViewOfPrimaryFile(i, a1[3], v13, v14) )
        {
          v13 += 0x40000;
LABEL_15:
          if ( v13 >= v8 )
            break;
        }
      }
      *a1 = v3;
      return v11;
    }
    v5 = v7 - v9;
  }
  if ( v5 )
    return sub_7EAA1C();
  return 0;
}
