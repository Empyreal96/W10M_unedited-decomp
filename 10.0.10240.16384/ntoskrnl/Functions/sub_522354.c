// sub_522354 
 
void __fastcall sub_522354(int a1)
{
  int v1; // r5
  int v2; // r7
  int v3; // r10
  unsigned int *v4; // r2
  unsigned int v5; // r0
  unsigned int v6; // r0
  unsigned int v7; // r3
  unsigned int v8; // t1
  int v9; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r0
  unsigned int v12; // r0
  int v13; // [sp+1Ch] [bp-2Ch]

  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 12);
  if ( v1 )
  {
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 & 0x7FFFFFFF, v4) );
    while ( 1 )
    {
      do
      {
        do
        {
          v8 = *(_DWORD *)(v2 - 4);
          v2 -= 4;
          v7 = v8;
        }
        while ( (v8 & 2) != 0 );
      }
      while ( (v7 & 0x400) != 0 || (v7 & 0x800) == 0 );
      --v1;
      v9 = MmPfnDatabase + 24 * (v7 >> 12);
      __dmb(0xBu);
      v10 = (unsigned int *)(v9 + 12);
      if ( !v1 )
        break;
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 & 0x7FFFFFFF, v10) );
    }
    do
      v12 = __ldrex(v10);
    while ( __strex(v12 & 0x7FFFFFFF, v10) );
    v3 = v13;
  }
  else
  {
    do
      v6 = __ldrex(v4);
    while ( __strex(v6 & 0x7FFFFFFF, v4) );
  }
  *(_DWORD *)(v3 + 8) = 128;
  JUMPOUT(0x4568BC);
}
