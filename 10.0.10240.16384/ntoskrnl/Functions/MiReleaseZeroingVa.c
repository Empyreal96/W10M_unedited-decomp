// MiReleaseZeroingVa 
 
unsigned int __fastcall MiReleaseZeroingVa(_DWORD **a1)
{
  _DWORD *v1; // r4
  unsigned int v2; // r6
  unsigned int v3; // r9
  unsigned int v4; // r5
  int v6; // r1
  int v7; // [sp+0h] [bp-B8h] BYREF
  char v8; // [sp+4h] [bp-B4h]
  char v9; // [sp+5h] [bp-B3h]
  int v10; // [sp+8h] [bp-B0h]
  int v11; // [sp+Ch] [bp-ACh]
  int v12; // [sp+10h] [bp-A8h]
  int v13; // [sp+14h] [bp-A4h]

  v1 = *a1;
  v2 = (unsigned int)(*a1 + 1024);
  v3 = (_DWORD)*a1 << 10;
  if ( (unsigned int)*a1 < v2 )
  {
    v4 = (unsigned int)(v1 + 0x10000000);
    do
    {
      if ( v4 > 0x3FFFFF )
      {
        *v1 = 0;
      }
      else
      {
        __dmb(0xBu);
        *v1 = 0;
        if ( (unsigned int)v1 >= 0xC0300000 )
          return sub_54E5F0();
      }
      ++v1;
      v4 += 4;
    }
    while ( (unsigned int)v1 < v2 );
  }
  v8 = 0;
  v10 = 33;
  v7 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v13 = 0;
  MiInsertTbFlushEntry((int)&v7, v3, 1024, 0);
  return MiFlushTbList((unsigned int)&v7, v6);
}
