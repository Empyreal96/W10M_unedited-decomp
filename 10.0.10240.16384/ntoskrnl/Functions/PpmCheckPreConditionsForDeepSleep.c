// PpmCheckPreConditionsForDeepSleep 
 
BOOL __fastcall PpmCheckPreConditionsForDeepSleep(int a1)
{
  return *(_BYTE *)(a1 + 17) && PopCheckForDeepSleep();
}
