// BvgaSaveResources 
 
void BvgaSaveResources()
{
  unsigned int i; // r4
  _DWORD *v1; // r5
  int v2; // r0
  int v3; // r7

  for ( i = 1; i < 7; ++i )
  {
    v1 = &ResourceList[i];
    if ( ResourceList[i - 1] )
    {
      v2 = ExAllocatePoolWithTag(512, *(_DWORD *)((char *)&ResourceSize + i * 4 - 4), 1833072194);
      v3 = v2;
      if ( !v2 )
        KeBugCheck(125);
      memmove(v2, *(v1 - 1), *(_DWORD *)((char *)&ResourceSize + i * 4 - 4));
      *(v1 - 1) = v3;
    }
  }
}
