// MiLogMdlRangeEvent 
 
int *__fastcall MiLogMdlRangeEvent(int *result, int a2, int a3)
{
  int *v3; // r5
  int v6; // r2
  unsigned int v7; // r4
  char v8; // r3
  char v9; // r7
  int *v10; // r1
  int v11[4]; // [sp+8h] [bp-40h] BYREF
  int v12[12]; // [sp+18h] [bp-30h] BYREF

  v3 = result;
  v6 = MmPfnDatabase + 24 * *result;
  if ( (*(_BYTE *)(v6 + 23) & 7) == 1 )
  {
    v7 = *(_DWORD *)v6;
    v8 = 9;
  }
  else
  {
    v8 = 10;
    v7 = 0;
  }
  if ( a3 )
  {
    v9 = v8 & 0xF;
    do
    {
      v10 = v3;
      v11[2] = *v3;
      v11[0] = v9 & 0xF | (16 * v7);
      v11[1] = v7 >> 28;
      do
      {
        ++v3;
        --a3;
      }
      while ( a3 && *v3 == *(v3 - 1) + 1 );
      v11[3] = v3 - v10;
      v12[0] = (int)v11;
      v12[1] = 0;
      v12[2] = 16;
      v12[3] = 0;
      result = EtwTraceKernelEvent(v12, 1, 0x20000001u, a2, 289413890);
    }
    while ( a3 );
  }
  return result;
}
