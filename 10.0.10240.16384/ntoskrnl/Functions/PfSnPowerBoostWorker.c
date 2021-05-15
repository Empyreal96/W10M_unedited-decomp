// PfSnPowerBoostWorker 
 
unsigned __int8 *__fastcall PfSnPowerBoostWorker(_DWORD *a1)
{
  unsigned __int8 *result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r1

  result = (unsigned __int8 *)PfSnPowerBoostUpdate(0);
  __pld(a1);
  v3 = *a1 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v4 = __ldrex(a1);
  while ( v4 == v3 && __strex(v3 - 2, a1) );
  if ( v4 != v3 )
    result = ExfReleaseRundownProtection((unsigned __int8 *)a1);
  return result;
}
