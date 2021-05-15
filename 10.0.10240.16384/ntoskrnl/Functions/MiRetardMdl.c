// MiRetardMdl 
 
int __fastcall MiRetardMdl(int a1)
{
  int *v1; // r4
  int *v2; // r2
  int v3; // r1
  int v4; // r5
  int *v5; // r6
  int v6; // t1
  __int16 v7; // r2

  v1 = (int *)(a1 + 28);
  v2 = (int *)(a1
             + 28
             + 4
             * ((*(_DWORD *)(a1 + 20)
               + (((unsigned __int16)*(_DWORD *)(a1 + 24) + (unsigned __int16)*(_DWORD *)(a1 + 16)) & 0xFFFu)
               + 4095) >> 12));
  v3 = 0;
  do
  {
    v4 = *v2;
    v5 = v2 + 1;
    while ( v2 != v1 )
    {
      v6 = *--v2;
      v2[1] = v6;
    }
    *v2 = v4 & 0x7FFFFFFF;
    ++v1;
    ++v3;
    v2 = v5;
  }
  while ( (v4 & 0x80000000) == 0 );
  v7 = *(_WORD *)(a1 + 6);
  *(_DWORD *)(a1 + 20) += v3 << 12;
  *(_DWORD *)(a1 + 16) -= v3 << 12;
  if ( (v7 & 1) != 0 )
    *(_DWORD *)(a1 + 12) -= v3 << 12;
  *(_WORD *)(a1 + 6) = v7 & 0xFDFF;
  return v3 << 12;
}
