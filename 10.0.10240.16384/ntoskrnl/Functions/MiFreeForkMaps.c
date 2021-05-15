// MiFreeForkMaps 
 
int __fastcall MiFreeForkMaps(int result)
{
  int *v1; // r4
  unsigned int v2; // r3
  unsigned int v3; // r3
  int v4; // r1

  v1 = (int *)result;
  v2 = *(_DWORD *)(result + 20);
  if ( v2 )
    result = MiReleasePtes(&dword_634D58, ((v2 >> 10) & 0x3FFFFC) - 0x40000000, 1u);
  v3 = v1[7];
  if ( v3 )
    result = MiReleasePtes(&dword_634D58, ((v3 >> 10) & 0x3FFFFC) - 0x40000000, 1u);
  v4 = v1[1];
  if ( v4 != -1 )
    result = MiFinishLastForkPageTable(*v1, v4);
  return result;
}
