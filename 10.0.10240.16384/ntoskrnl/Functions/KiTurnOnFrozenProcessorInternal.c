// KiTurnOnFrozenProcessorInternal 
 
int __fastcall KiTurnOnFrozenProcessorInternal(int a1)
{
  int result; // r0

  if ( (*(_DWORD *)(a1 + 18240) & 1) != 0 )
    result = sub_51C148();
  else
    result = 0;
  return result;
}
