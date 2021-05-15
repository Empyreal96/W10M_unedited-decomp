// RtlpDeleteFromMergedRange 
 
int __fastcall RtlpDeleteFromMergedRange(int a1)
{
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 28) + 4) != a1 + 28 )
    JUMPOUT(0x80D51A);
  return sub_80D460();
}
