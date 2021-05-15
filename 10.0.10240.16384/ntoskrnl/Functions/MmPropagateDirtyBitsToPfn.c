// MmPropagateDirtyBitsToPfn 
 
unsigned int __fastcall MmPropagateDirtyBitsToPfn(unsigned int result)
{
  unsigned int *v1; // r5
  unsigned int v2; // r6
  unsigned int v3; // r4
  unsigned int v4; // r8
  int v5; // r7
  int v6; // r9
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r4
  int v11; // r3
  unsigned __int8 *v12; // r1
  int v13; // r3
  unsigned int v14; // r2

  v1 = (unsigned int *)(((result >> 10) & 0x3FFFFC) - 0x40000000);
  v2 = (((result + 0x3FFFF) >> 10) & 0x3FFFFC) - 0x40000000;
  while ( 1 )
  {
    v3 = *v1;
    if ( (*v1 & 2) != 0 && (v3 & 0x200) == 0 )
      break;
LABEL_3:
    ++v1;
LABEL_4:
    if ( (unsigned int)v1 > v2 )
      return result;
  }
  v4 = 0;
  result = MI_IS_PFN(v3 >> 12);
  if ( !result )
    goto LABEL_4;
  v5 = MmPfnDatabase + 24 * (v3 >> 12);
  v6 = KfRaiseIrql(2);
  v7 = (unsigned __int8 *)(v5 + 15);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
  {
    v12 = (unsigned __int8 *)(v5 + 15);
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v13 = *(_DWORD *)(v5 + 12);
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
  if ( *v1 == v3 )
  {
    if ( (*(_BYTE *)(v5 + 18) & 0x10) == 0 || (*(_DWORD *)(v5 + 8) & 0x400) == 0 )
      v4 = MiCaptureDirtyBitToPfn(v5);
    __dmb(0xBu);
    v9 = (unsigned int *)(v5 + 12);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 & 0x7FFFFFFF, v9) );
    result = KfLowerIrql(v6);
    if ( v4 )
      result = MiReleasePageFileInfo((int)MiSystemPartition, v4, 0, v11);
    goto LABEL_3;
  }
  return sub_53DE34();
}
