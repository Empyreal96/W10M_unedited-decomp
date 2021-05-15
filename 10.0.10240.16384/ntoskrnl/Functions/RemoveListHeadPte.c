// RemoveListHeadPte 
 
int __fastcall RemoveListHeadPte(unsigned int *a1)
{
  int v1; // r4
  unsigned int *v2; // r5
  unsigned int v3; // r2
  unsigned int v4; // r3
  unsigned int v5; // r1
  int v6; // r3
  int v7; // r2
  int *v8; // r4

  v1 = a1[2];
  v2 = (unsigned int *)(v1 + 4 * (*a1 >> 12));
  v3 = *v2;
  if ( (*v2 & 2) != 0 || (v3 & 0x3E0) != 0 )
    KeBugCheckEx(26, 14336, v2);
  v4 = v2[1];
  if ( (v4 & 2) != 0 || (v4 & 0x3E0) != 0 )
    KeBugCheckEx(26, 14337, v2);
  v5 = v3 >> 12;
  *a1 = *a1 & 0xFFF | (v3 >> 12 << 12);
  v6 = (int)((((unsigned int)a1 >> 10) & 0x3FFFFC) - v1 - 0x40000000) >> 2;
  if ( v3 >> 12 == v6 )
  {
    a1[1] = a1[1] & 0xFFF | (v5 << 12);
  }
  else
  {
    v7 = v6 << 12;
    v8 = (int *)(v1 + 4 * (v5 + 1));
    if ( (unsigned int)(v8 + 0x10000000) > 0x3FFFFF )
    {
      *v8 = v7;
    }
    else
    {
      __dmb(0xBu);
      *v8 = v7;
      if ( (unsigned int)(v8 + 267649024) <= 0xFFF )
        return sub_53BAE0();
    }
  }
  return (int)v2;
}
