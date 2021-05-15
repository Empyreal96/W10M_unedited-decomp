// KeShouldYieldProcessor 
 
int KeShouldYieldProcessor()
{
  int v0; // r4
  unsigned int v1; // r1
  unsigned int v2; // r0
  int v3; // r6
  int v4; // r2
  int v6; // r5
  int v7; // r4

  v0 = 0;
  v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v2 = *(_DWORD *)(v1 + 3264);
  v3 = *(_DWORD *)(v1 + 3740);
  if ( v2 > 7 )
    v0 = 1;
  v4 = *(_DWORD *)(v1 + 3164);
  if ( (v4 & 1) != 0 )
    return sub_519E18();
  if ( (v4 & 0x1E) != 0 )
  {
    v7 = 2;
  }
  else if ( *(_BYTE *)(v1 + 3161) )
  {
    v7 = 3;
  }
  else
  {
    v6 = *(_DWORD *)(v1 + 1416);
    if ( !v6 || v6 == *(_DWORD *)(v1 + 1412) )
    {
      if ( !v0 )
        return 0;
      __disable_irq();
      *(_DWORD *)(v1 + 3264) = 0;
      *(_DWORD *)(v1 + 3740) = 0;
      __enable_irq();
      v7 = 0;
    }
    else
    {
      v7 = 4;
    }
  }
  if ( (dword_682604 & 0x4000000) != 0 )
    EtwTraceShouldYieldProcessor(v7, v2, v3);
  return v7 != 0;
}
