// MiCaptureProtectionFromLockedProto 
 
int __fastcall MiCaptureProtectionFromLockedProto(unsigned int *a1)
{
  unsigned int v2; // r4
  int v3; // r6
  int v4; // r0
  int v5; // lr
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  int result; // r0
  unsigned int v9; // r2
  int v10; // r5
  unsigned int *v11; // r2
  unsigned int v12; // r4
  unsigned int *v13; // r2
  unsigned int v14; // r0

  while ( 1 )
  {
    do
    {
      v2 = *a1;
      if ( (*a1 & 2) == 0 )
      {
        if ( (v2 & 0x400) != 0 )
          result = (*(unsigned __int16 *)((*a1 & 0xFFFFF800 | (2 * (*a1 & 0x3FC))) + 0x10) >> 1) & 0x1F;
        else
          result = (v2 >> 5) & 0x1F;
        return result;
      }
    }
    while ( !MI_IS_PFN(v2 >> 12) );
    v3 = MmPfnDatabase + 24 * (v2 >> 12);
    v4 = KfRaiseIrql(2);
    v5 = v4;
    v6 = (unsigned __int8 *)(v3 + 15);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      return sub_51CB9C();
    if ( v2 == *a1 )
      break;
    __dmb(0xBu);
    v13 = (unsigned int *)(v3 + 12);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 & 0x7FFFFFFF, v13) );
    KfLowerIrql(v5);
  }
  v9 = *(_DWORD *)(v3 + 8);
  if ( (v9 & 0x400) != 0 )
    v10 = (*(unsigned __int16 *)((*(_DWORD *)(v3 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v3 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v10 = (v9 >> 5) & 0x1F;
  __dmb(0xBu);
  v11 = (unsigned int *)(v3 + 12);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 & 0x7FFFFFFF, v11) );
  KfLowerIrql(v4);
  return v10;
}
