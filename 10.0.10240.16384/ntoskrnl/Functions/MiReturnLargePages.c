// MiReturnLargePages 
 
int __fastcall MiReturnLargePages(_DWORD *a1)
{
  int v1; // r5
  __int16 *v2; // r7
  _DWORD *v4; // r6
  __int64 v5; // r2
  unsigned int v6; // r4
  unsigned int v7; // r8
  unsigned int *v8; // lr
  int v9; // r2
  unsigned int v10; // r0
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r4
  int v14; // r2
  unsigned int v15; // r0
  unsigned int v16; // r3
  int v17; // r2
  unsigned int v18; // r0
  unsigned int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r4
  unsigned int v23; // [sp+0h] [bp-20h]

  v1 = 0;
  v2 = 0;
  while ( 1 )
  {
    v4 = (_DWORD *)*a1;
    if ( (_DWORD *)*a1 == a1 )
      break;
    v5 = *(_QWORD *)v4;
    if ( (_DWORD *)v4[1] != a1 || *(_DWORD **)(v5 + 4) != v4 )
      __fastfail(3u);
    *a1 = v5;
    *(_DWORD *)(v5 + 4) = a1;
    v6 = v4[2];
    v7 = v4[3] >> 10;
    v8 = (unsigned int *)(dword_634C94 + 4 * (v6 >> 15));
    v9 = (v6 >> 10) & 0x1F;
    v23 = v6;
    v10 = v7;
    if ( v9 + v7 <= 0x20 )
    {
      if ( v7 == 32 )
      {
        *v8 = 0;
        goto LABEL_22;
      }
      __dmb(0xBu);
      v11 = ~(((1 << v7) - 1) << v9);
      do
        v12 = __ldrex(v8);
      while ( __strex(v12 & v11, v8) );
      goto LABEL_21;
    }
    if ( v9 )
    {
      v13 = 32 - v9;
      __dmb(0xBu);
      v14 = ~(((1 << (32 - v9)) - 1) << v9);
      do
        v15 = __ldrex(v8);
      while ( __strex(v15 & v14, v8) );
      __dmb(0xBu);
      v10 = v7 - v13;
      v6 = v23;
      ++v8;
    }
    if ( v10 >= 0x20 )
    {
      v16 = v10 >> 5;
      do
      {
        v10 -= 32;
        --v16;
        *v8++ = 0;
      }
      while ( v16 );
    }
    if ( v10 )
    {
      __dmb(0xBu);
      v17 = ~((1 << v10) - 1);
      do
        v18 = __ldrex(v8);
      while ( __strex(v18 & v17, v8) );
LABEL_21:
      __dmb(0xBu);
    }
LABEL_22:
    if ( !v2 )
      v2 = MiSystemPartition;
    for ( ; v7; v6 += 1024 )
    {
      v1 += MiFreeLargePageMemory(v6);
      --v7;
    }
    ExFreePoolWithTag(v4);
  }
  if ( v1 )
  {
    if ( v2 == MiSystemPartition )
    {
      MiReturnResidentAvailable(v1);
      do
        v19 = __ldrex(&dword_634A2C[40]);
      while ( __strex(v19 + v1, &dword_634A2C[40]) );
    }
    else
    {
      v20 = (unsigned int *)(v2 + 1920);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 + v1, v20) );
    }
  }
  return v1;
}
