// MiAdvanceVadView 
 
int __fastcall MiAdvanceVadView(int result, int a2)
{
  if ( (*(_DWORD *)(result + 28) & 0x8000) == 0 )
    return sub_549F84();
  *(_DWORD *)(result + 12) += a2;
  return result;
}
