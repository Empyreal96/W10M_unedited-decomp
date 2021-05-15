// MiCaptureProtectionFromProto 
 
int __fastcall MiCaptureProtectionFromProto(unsigned int *a1)
{
  unsigned int v2; // r2
  int v3; // r5
  int v5; // r6
  int v6; // r7
  unsigned __int8 *v7; // r1
  unsigned int v8; // r2
  unsigned int *v9; // r2
  unsigned int v10; // r4
  int v11; // r3

  v2 = *a1;
  if ( (*a1 & 2) != 0 )
  {
    v5 = MiMakeProtoAddressValid(a1);
    v3 = MiCaptureProtectionFromLockedProto(a1);
    v6 = KfRaiseIrql(2);
    v7 = (unsigned __int8 *)(v5 + 15);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 0x80, v7) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v8 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v11 = *(_DWORD *)(v5 + 12);
        __dmb(0xBu);
      }
      while ( v11 < 0 );
      do
        v8 = __ldrex(v7);
      while ( __strex(v8 | 0x80, v7) );
    }
    MiRemoveLockedPageChargeAndDecRef(v5);
    __dmb(0xBu);
    v9 = (unsigned int *)(v5 + 12);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0x7FFFFFFF, v9) );
    KfLowerIrql(v6);
  }
  else if ( (v2 & 0x400) != 0 )
  {
    v3 = (*(unsigned __int16 *)((*a1 & 0xFFFFF800 | (2 * (*a1 & 0x3FC))) + 0x10) >> 1) & 0x1F;
  }
  else
  {
    v3 = (v2 >> 5) & 0x1F;
  }
  return v3;
}
