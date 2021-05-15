// WheapCreatePerProcessorInfo 
 
int WheapCreatePerProcessorInfo()
{
  unsigned int v0; // r5
  int v1; // r7
  _BYTE *v2; // r0
  _BYTE *v3; // r4
  unsigned int v4; // r1
  void **v5; // r2
  _DWORD *v6; // r3

  v0 = KeNumberProcessors_0;
  v1 = 3 * KeNumberProcessors_0;
  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 12 * KeNumberProcessors_0, 1634035799);
  v3 = v2;
  if ( !v2 )
    sub_96FC10();
  memset(v2, 0, 4 * v1);
  v4 = 0;
  if ( v0 )
  {
    v5 = &KiProcessorBlock;
    do
    {
      if ( v4 >= KeNumberProcessors_0 )
        v6 = 0;
      else
        v6 = *v5;
      v6[898] = v3;
      ++v4;
      v3 += 12;
      ++v5;
    }
    while ( v4 < v0 );
  }
  return 0;
}
