// MiReturnSystemImageCommitment 
 
unsigned int __fastcall MiReturnSystemImageCommitment(int a1, int a2)
{
  unsigned int result; // r0
  __int64 v3; // kr00_8

  if ( !*(_DWORD *)a1 )
    return sub_7CE9C8();
  v3 = *(_QWORD *)(a1 + 116);
  result = MiReturnCommit((int)MiSystemPartition, v3 - *(_DWORD *)(a2 + 4));
  if ( HIDWORD(v3) )
  {
    MiReturnResidentAvailable(SHIDWORD(v3));
    do
      result = __ldrex(&dword_634A2C[53]);
    while ( __strex(result + HIDWORD(v3), &dword_634A2C[53]) );
  }
  return result;
}
