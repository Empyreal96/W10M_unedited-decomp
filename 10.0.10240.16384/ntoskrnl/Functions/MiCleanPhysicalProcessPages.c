// MiCleanPhysicalProcessPages 
 
unsigned int __fastcall MiCleanPhysicalProcessPages(unsigned int result)
{
  unsigned int *v1; // r8
  int v2; // r9
  char *v3; // r10
  int v4; // r6
  __int16 *v5; // r5
  unsigned int v6; // r7
  unsigned int *v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r4
  int v12; // [sp+4h] [bp-144h]
  int v13; // [sp+8h] [bp-140h] BYREF
  __int16 v14; // [sp+Ch] [bp-13Ch]
  __int16 v15; // [sp+Eh] [bp-13Ah]
  int v16; // [sp+18h] [bp-130h]
  int v17; // [sp+1Ch] [bp-12Ch]
  int v18; // [sp+20h] [bp-128h]
  char v19[292]; // [sp+24h] [bp-124h] BYREF

  v12 = result;
  v1 = **(unsigned int ***)(result + 328);
  if ( v1 && *(_DWORD *)(result + 648) )
  {
    v2 = 0;
    v3 = v19;
    v4 = 0;
    v5 = MiGetThreadPartition();
    result = RtlFindSetBits(v1, 1u, 0);
    v6 = result;
    do
    {
      if ( v6 == -1 )
        break;
      ++v4;
      *(_DWORD *)v3 = v6;
      v3 += 4;
      if ( v4 == 64 )
      {
        v7 = (unsigned int *)(v5 + 2062);
        do
          v8 = __ldrex(v7);
        while ( __strex(v8 - 64, v7) );
        v13 = 0;
        v14 = 284;
        v15 = 0;
        v16 = 0;
        v18 = 0;
        v17 = 0x40000;
        result = MiFreePagesFromMdl(v5, (int)&v13, 1);
        v3 = v19;
        v4 = 0;
        v2 += 64;
      }
      v9 = v6 + 1;
      if ( v6 + 1 >= *v1 )
        break;
      result = RtlFindSetBits(v1, 1u, v6 + 1);
      v6 = result;
    }
    while ( result >= v9 );
    if ( v4 )
    {
      v10 = (unsigned int *)(v5 + 2062);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 - v4, v10) );
      v13 = 0;
      v14 = 4 * (((unsigned int)((v4 << 12) + 4095) >> 12) + 7);
      v16 = 0;
      v17 = v4 << 12;
      v15 = 0;
      v18 = 0;
      result = MiFreePagesFromMdl(v5, (int)&v13, 1);
      v2 += v4;
    }
    if ( v2 )
    {
      *(_DWORD *)(v12 + 648) = 0;
      result = MiReturnProcessCommitment(v12, v2);
    }
  }
  return result;
}
