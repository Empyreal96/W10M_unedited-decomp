// MiMakeProtoAddressValid 
 
int __fastcall MiMakeProtoAddressValid(unsigned int a1)
{
  unsigned int *v1; // r5
  unsigned int v2; // r4
  unsigned int v3; // r6
  int v4; // r8
  int v5; // r10
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r3
  unsigned int *v10; // r2
  unsigned int v11; // r4
  unsigned __int8 *v12; // r1
  int v13; // r3
  unsigned int v14; // r2

  v1 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  do
  {
    v2 = *v1;
    if ( (*v1 & 2) == 0 )
      goto LABEL_20;
    v3 = v2 >> 12;
  }
  while ( !MI_IS_PFN(v2 >> 12) );
  if ( (v2 & 0x100) != 0 )
LABEL_20:
    JUMPOUT(0x51CC46);
  v4 = MmPfnDatabase + 24 * v3;
  v5 = KfRaiseIrql(2);
  v6 = (unsigned __int8 *)(v4 + 15);
  do
    v7 = __ldrex(v6);
  while ( __strex(v7 | 0x80, v6) );
  __dmb(0xBu);
  if ( v7 >> 7 )
  {
    v12 = (unsigned __int8 *)(v4 + 15);
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v13 = *(_DWORD *)(v4 + 12);
        __dmb(0xBu);
      }
      while ( v13 < 0 );
      do
        v14 = __ldrex(v12);
      while ( __strex(v14 | 0x80, v12) );
      __dmb(0xBu);
    }
    while ( v14 >> 7 );
  }
  v8 = *v1;
  if ( (*v1 & 2) == 0 || (v8 & 0x100) != 0 || v3 != v8 >> 12 )
    return sub_51CC10();
  MiAddLockedPageCharge(v4, 1);
  __dmb(0xBu);
  v10 = (unsigned int *)(v4 + 12);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0x7FFFFFFF, v10) );
  KfLowerIrql(v5);
  return v4;
}
