// sub_7BDD60 
 
void __fastcall sub_7BDD60(int a1, int a2, int a3, int a4, unsigned __int16 *a5, int a6)
{
  const char *v6; // r1
  int v7; // r6
  int v8; // r3
  unsigned __int16 *v9; // r0

  if ( (PoDebug & 2) != 0 )
  {
    if ( a6 == 11 )
      v6 = "driver";
    else
      v6 = "device";
    DbgPrint("PopFilterCapabilities: disabling sleep states due to legacy %s: %ws\n", v6, a5);
  }
  v7 = 0;
  v8 = *a5;
  v9 = a5;
  while ( v8 )
  {
    v7 += wcslen(v9) + 1;
    v8 = a5[v7];
    v9 = &a5[v7];
  }
  PopLogSleepDisabled(4, 31, (int)a5, v7 * 2 + 2);
  JUMPOUT(0x77E706);
}
