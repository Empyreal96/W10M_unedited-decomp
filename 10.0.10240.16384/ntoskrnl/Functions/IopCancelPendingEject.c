// IopCancelPendingEject 
 
int __fastcall IopCancelPendingEject(int result)
{
  int v1; // r4
  unsigned int *v2; // r5
  unsigned int v3; // r2
  unsigned int v4; // r2

  v1 = result;
  if ( *(_DWORD *)(result + 36) )
  {
    __dmb(0xBu);
    v2 = (unsigned int *)(result + 40);
    do
      v3 = __ldrex(v2);
    while ( __strex(1u, v2) );
    __dmb(0xBu);
    if ( !v3 )
    {
      result = IoCancelIrp(*(_DWORD *)(result + 36));
      __dmb(0xBu);
      do
        v4 = __ldrex(v2);
      while ( __strex(2u, v2) );
      __dmb(0xBu);
      if ( v4 == 3 )
        result = IoFreeIrp(*(_DWORD *)(v1 + 36));
    }
  }
  return result;
}
