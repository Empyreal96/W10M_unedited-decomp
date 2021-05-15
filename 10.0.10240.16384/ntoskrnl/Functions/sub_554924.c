// sub_554924 
 
void sub_554924()
{
  int v0; // r4
  unsigned int *v1; // r5
  unsigned int v2; // r1
  int v3; // r8
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned __int8 *v6; // r1
  int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r7
  unsigned int *v10; // r2
  unsigned int v11; // r4
  int v12; // r3

  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( __strex(0, v1) );
  v3 = KfRaiseIrql(2);
  v4 = (unsigned __int8 *)(v0 + 14);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 | 0x80, v4) );
  __dmb(0xBu);
  if ( v5 >> 7 )
  {
    v6 = (unsigned __int8 *)(v0 + 14);
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v7 = *(_DWORD *)(v0 + 11);
        __dmb(0xBu);
      }
      while ( v7 < 0 );
      do
        v8 = __ldrex(v6);
      while ( __strex(v8 | 0x80, v6) );
      __dmb(0xBu);
    }
    while ( v8 >> 7 );
  }
  v9 = MiCaptureDirtyBitToPfn(v0 - 1);
  MiRemoveLockedPageChargeAndDecRef(v0 - 1);
  __dmb(0xBu);
  v10 = (unsigned int *)(v0 + 11);
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 & 0x7FFFFFFF, v10) );
  KfLowerIrql(v3);
  if ( v9 )
    MiReleasePageFileInfo((int)MiSystemPartition, v9, 0, v12);
  JUMPOUT(0x4F66AC);
}
