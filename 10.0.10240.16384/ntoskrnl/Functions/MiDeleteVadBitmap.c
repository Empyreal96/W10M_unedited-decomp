// MiDeleteVadBitmap 
 
int __fastcall MiDeleteVadBitmap(int a1)
{
  int v2; // r5
  int v3; // r5
  int v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  if ( *(_DWORD *)(a1 + 272) )
    sub_520D78();
  v2 = MEMORY[0xC0402100];
  MiReturnFullProcessCharges();
  v3 = v2 + MEMORY[0xC0402118];
  v4 = -MEMORY[0xC0402118];
  do
    v5 = __ldrex((unsigned int *)&dword_634DA4);
  while ( __strex(v5 + v4, (unsigned int *)&dword_634DA4) );
  v6 = MiDeletePagablePteRange(a1);
  return MiReturnCommit(MiSystemPartition, v3 - v6);
}
