// SmKmStoreDeleteWhenEmpty 
 
int __fastcall SmKmStoreDeleteWhenEmpty(int a1, _DWORD *a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r5
  unsigned __int8 *v7; // r4
  char v8; // r3
  unsigned int v9; // r1
  int v10; // r2
  unsigned int v11; // r1
  int v13; // [sp+0h] [bp-18h] BYREF
  int v14[5]; // [sp+4h] [bp-14h] BYREF

  v13 = a3;
  v14[0] = a4;
  v4 = 0;
  v6 = a1 + 96 * (a2[878] & 0x1F);
  if ( a3 )
  {
    __dmb(0xBu);
    v7 = (unsigned __int8 *)(v6 + 14);
    do
      v9 = __ldrex(v7);
    while ( __strex(v9 | 1, v7) );
    __dmb(0xBu);
  }
  else
  {
    v7 = (unsigned __int8 *)(v6 + 14);
    v8 = *(_BYTE *)(v6 + 14);
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      return v4;
  }
  ST_STORE<SM_TRAITS>::StDmGetSpaceStats((int)(a2 + 14), v14, &v13);
  v10 = a2[46] << (a2[7] - 6);
  if ( v10 == v10 - 16 * ((unsigned int)(v13 + 1023) >> 10) )
  {
    __dmb(0xBu);
    do
      v11 = __ldrex(v7);
    while ( __strex(v11 | 2, v7) );
    __dmb(0xBu);
    if ( (v11 & 2) == 0 )
    {
      *(_DWORD *)(v6 + 28) = SmKmStoreDeleteWhenEmptyWorker;
      *(_DWORD *)(v6 + 32) = v6 + 20;
      *(_DWORD *)(v6 + 20) = 0;
      ExQueueWorkItem((_DWORD *)(v6 + 20), 1);
      v4 = 1;
    }
  }
  return v4;
}
