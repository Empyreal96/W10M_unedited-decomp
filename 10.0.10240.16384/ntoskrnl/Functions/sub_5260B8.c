// sub_5260B8 
 
void sub_5260B8()
{
  unsigned int v0; // r4
  int v1; // r6
  unsigned int v2; // r1
  unsigned int v3; // r5
  int v4; // r0

  v2 = (unsigned __int16)KiProcessNodeSeed++;
  if ( (unsigned __int16)KiProcessNodeSeed >= v0 )
    KiProcessNodeSeed = 0;
  v3 = 0;
  while ( 1 )
  {
    if ( v2 >= v0 )
      v2 = 0;
    v4 = (int)*(&KeNodeBlock + v2);
    if ( *(unsigned __int16 *)(v4 + 264) != *(unsigned __int16 *)(v1 + 4)
      || (*(_DWORD *)(v4 + 260) & *(_DWORD *)v1) == 0 )
    {
      ++v3;
      v2 = (unsigned __int16)(v2 + 1);
      if ( v3 < v0 )
        continue;
    }
    JUMPOUT(0x460EFC);
  }
}
