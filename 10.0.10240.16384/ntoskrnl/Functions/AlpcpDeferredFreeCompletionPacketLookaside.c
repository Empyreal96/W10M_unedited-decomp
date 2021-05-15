// AlpcpDeferredFreeCompletionPacketLookaside 
 
int __fastcall AlpcpDeferredFreeCompletionPacketLookaside(int a1)
{
  int v1; // r4
  unsigned int v2; // r6
  int v3; // r5

  v1 = a1;
  v2 = 0;
  if ( *(_DWORD *)(a1 + 4) )
  {
    v3 = a1;
    do
    {
      IoFreeMiniCompletionPacket(*(_DWORD *)(v3 + 40));
      ++v2;
      v3 += 12;
    }
    while ( v2 < *(_DWORD *)(v1 + 4) );
  }
  return ExFreePoolWithTag(v1, 0);
}
