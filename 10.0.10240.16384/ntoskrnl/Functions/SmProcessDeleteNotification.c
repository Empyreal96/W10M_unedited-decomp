// SmProcessDeleteNotification 
 
unsigned __int8 *__fastcall SmProcessDeleteNotification(int a1, int a2, int a3, int a4)
{
  unsigned __int8 *result; // r0
  __int16 v5; // r4
  int v6; // r3
  int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r1
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[1] = a4;
  v10[0] = a1;
  result = (unsigned __int8 *)SmpKeyedStoreEntryGet((int)&unk_636CC4, (int)v10, 2, 0);
  if ( result )
  {
    v5 = *((_WORD *)result + 4);
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)result);
    v6 = 3 * (v5 & 0x1F);
    v7 = 24 * (v5 & 0x1F);
    SmKmStoreDeleteWhenEmpty((int)SmGlobals, (_DWORD *)SmGlobals[v7], 1, v6);
    __pld(&SmGlobals[v7 + 1]);
    result = (unsigned __int8 *)&SmGlobals[v7 + 1];
    v8 = SmGlobals[v7 + 1] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex((unsigned int *)result);
    while ( v9 == v8 && __strex(v8 - 2, (unsigned int *)result) );
    if ( v9 != v8 )
      result = ExfReleaseRundownProtection(result);
  }
  return result;
}
