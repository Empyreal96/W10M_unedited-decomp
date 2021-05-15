// MiDeleteSessionDriverProtos 
 
unsigned int __fastcall MiDeleteSessionDriverProtos(unsigned int result, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r5
  int v5; // r0

  v3 = result + 80;
  if ( result != -80 )
  {
    do
    {
      if ( (*(_WORD *)(v3 + 18) & 2) == 0 )
      {
        v4 = *(_DWORD *)(v3 + 12);
        if ( v4 )
        {
          *(_DWORD *)(v3 + 12) = 0;
          *(_DWORD *)(v4 + 12) = v3;
          v5 = MiDeletePerSessionProtos(v4, a2, a3, 0);
          MiReturnCommit((int)MiSystemPartition, v5);
          ExFreePoolWithTag(*(_DWORD *)(v4 + 16));
          result = ExFreePoolWithTag(v4);
        }
      }
      v3 = *(_DWORD *)(v3 + 8);
    }
    while ( v3 );
  }
  return result;
}
