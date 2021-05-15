// MiAddLoaderHalIoMappings 
 
int __fastcall MiAddLoaderHalIoMappings(unsigned int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r6
  unsigned int v5; // r4
  unsigned int v6; // r7
  unsigned int v8; // r0
  unsigned int v9; // r5
  unsigned int v10; // t1
  int v11; // r2
  int v12; // r3
  int v13[8]; // [sp+8h] [bp-20h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 0x136);
  v5 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v6 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  while ( v5 <= v6 )
  {
    v8 = MiGetNextPageTable(v5, v6, 1, 17, 1, v13);
    v5 = v8;
    if ( !v8 )
      break;
    if ( v13[0] != 1 )
    {
      while ( 1 )
      {
        v10 = *(_DWORD *)v5;
        v5 += 4;
        v9 = v10;
        if ( (v10 & 2) != 0 && !MI_IS_PFN(v9 >> 12) )
        {
          v11 = (v9 >> 2) & 3;
          v12 = 1;
          if ( v11 == 3 )
          {
            v12 = 2;
          }
          else if ( v11 == 1 )
          {
            v12 = 0;
          }
          MiReferenceIoPages(1, v9 >> 12, 1, v12, 0, 0);
        }
        if ( v5 > v6 )
          return sub_96A790();
        if ( (v5 & 0xFFF) == 0 )
          goto LABEL_12;
      }
    }
    v5 = (((v8 >> 10) & 0x3FFFFC) + 4) << 10;
LABEL_12:
    ;
  }
  return sub_96A790();
}
