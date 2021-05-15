// PoSetPowerRequest 
 
int __fastcall PoSetPowerRequest(int a1, int a2)
{
  int result; // r0

  if ( a2 == 1 )
    result = PoSetPowerRequestInternal(a1, 1);
  else
    result = sub_52967C();
  return result;
}
