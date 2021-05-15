// KsepRegistryOpenKey 
 
int __fastcall KsepRegistryOpenKey(unsigned __int16 *a1, int a2, _DWORD *a3)
{
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r2
  _WORD *v12; // r3
  int v13; // [sp+0h] [bp-48h]
  _DWORD v14[16]; // [sp+8h] [bp-40h] BYREF

  v14[0] = 0;
  v14[1] = 0;
  if ( !a1 )
    return sub_7CE594();
  if ( !a3 )
  {
    __dmb(0xBu);
    do
    {
      v10 = __ldrex(&KsepHistoryErrorsIndex);
      v11 = v10 + 1;
    }
    while ( __strex(v11, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v12 = &KsepHistoryErrors[4 * (v11 & 0x3F)];
    *((_DWORD *)v12 + 1) = -1073740768;
    v12[1] = 4;
    LOBYTE(v12) = KsepDebugFlag;
    KsepHistoryErrors[4 * (v11 & 0x3F)] = 423;
    if ( ((unsigned __int8)v12 & 4) != 0 )
      RtlAssert((int)"Handle != NULL", (int)"minkernel\\ntos\\kshim\\kseregistry.c", 423, 0);
  }
  if ( a2 )
    v7 = KsepStringConcatenate(v14, a1, a2, 1);
  else
    v7 = KsepStringDuplicate((int)v14, a1);
  v8 = v7;
  if ( v7 >= 0 )
  {
    v14[2] = 24;
    v14[3] = 0;
    v14[5] = 576;
    v14[4] = v14;
    v14[6] = 0;
    v14[7] = 0;
    v8 = ZwOpenKey();
    if ( v8 >= 0 )
    {
      *a3 = v13;
      __dmb(0xBu);
      do
        v9 = __ldrex(&dword_621724[5]);
      while ( __strex(v9 + 1, &dword_621724[5]) );
      __dmb(0xBu);
    }
  }
  KsepStringFree(v14);
  return v8;
}
