// MiAdjustPteBins 
 
void MiAdjustPteBins()
{
  int *v0; // r7
  int v1; // r5
  int v2; // r4
  int v3; // t1
  int *v4; // r5
  int v5; // r4
  _DWORD *v6; // r0
  _DWORD *v7; // t1
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  v0 = v8;
  v8[0] = (int)&dword_634D58;
  v8[1] = (int)algn_63480C;
  v1 = 2;
  do
  {
    v3 = *v0++;
    v2 = v3;
    if ( (*(_DWORD *)(v3 + 12) & 1) != 0 )
    {
      MiEmptyPteBins(v2, 0);
      if ( MiPteBinsNeedTrimming(v2) == 1 )
        MiEmptyPteBins(v2, 1);
    }
    --v1;
  }
  while ( v1 );
  if ( (++byte_634855 & 0xF) == 0 )
  {
    v4 = v8;
    v5 = 2;
    do
    {
      v7 = (_DWORD *)*v4++;
      v6 = v7;
      if ( v7[12] > v7[9] / 0xAu )
        MiAttemptCoalesce(v6, 0, *v6);
      --v5;
    }
    while ( v5 );
  }
}
