// MiSessionUpdateImageCharges 
 
int __fastcall MiSessionUpdateImageCharges(int a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r3
  int v5; // r4
  int v6; // r6
  unsigned int *v7; // r2
  unsigned int v8; // r0

  v2 = MiSessionLookupImage(*(_DWORD *)(a1 + 24));
  v3 = MiCountSystemImageCommitment(a1);
  v4 = *(_DWORD *)(v2 + 40);
  v5 = v3;
  v6 = v4 - v3;
  if ( v4 != v3 )
  {
    MiReturnCommit((int)MiSystemPartition, v6);
    *(_DWORD *)(v2 + 40) = v5;
    v7 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 32);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 - v6, v7) );
  }
  return 0;
}
