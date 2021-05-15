// MfgInitSystem 
 
int __fastcall MfgInitSystem(int a1)
{
  int result; // r0

  ExpManufacturingInformation = 0;
  word_61A1C4 = 0;
  word_61A1C6 = 0;
  dword_61A1C8 = 0;
  if ( *(_WORD *)(*(_DWORD *)(a1 + 132) + 2280) )
    result = sub_970660();
  else
    result = 0;
  return result;
}
