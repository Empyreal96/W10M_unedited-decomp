// MiRemoveImagePageFromSystemWorkingSet 
 
unsigned int __fastcall MiRemoveImagePageFromSystemWorkingSet(_DWORD *a1, int a2, int a3)
{
  unsigned int v3; // r7
  unsigned int *v6; // r9
  unsigned int v7; // r5
  unsigned int v8; // r4
  unsigned int result; // r0
  unsigned int v10; // r1
  unsigned __int8 *v11; // r1
  unsigned int v12; // r2
  int v13; // r3

  v3 = *(_DWORD *)a3;
  *(_BYTE *)(a3 + 19) |= 8u;
  __dmb(0xBu);
  v6 = (unsigned int *)(a3 + 12);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 & 0x7FFFFFFF, v6) );
  v8 = a2 << 10;
  if ( PsNtosImageBase && (v8 >= PsNtosImageBase && v8 < PsNtosImageEnd || v8 >= PsHalImageBase && v8 < PsHalImageEnd) )
    return sub_527FB4();
  do
    v10 = __ldrex((unsigned int *)&algn_632F58[4]);
  while ( __strex(v10 - 1, (unsigned int *)&algn_632F58[4]) );
  if ( (*(_DWORD *)(a3 + 20) & 0x8000000) != 0 )
  {
    v3 = MiLocateWsle(v8, (int)a1, v3);
  }
  else
  {
    --a1[16];
    if ( v8 < 0xC0000000 || v8 > 0xC03FFFFF )
      --a1[14];
  }
  MiRemoveWsle(v3, (int)a1);
  result = MiReleaseWsle(v3, a1, v8, 1);
  v11 = (unsigned __int8 *)(a3 + 15);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v12 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v13 = *v6;
      __dmb(0xBu);
    }
    while ( v13 < 0 );
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
  }
  return result;
}
