// EtwpAllocGuidEntry 
 
int __fastcall EtwpAllocGuidEntry(_DWORD *a1, int a2, unsigned int a3, unsigned int a4)
{
  _BYTE *v5; // r0
  _DWORD *v6; // r5
  int v7; // r1
  int v8; // r2
  int v9; // r3
  unsigned int v11; // r2
  unsigned int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  if ( EtwpCounters >= 0x8000 )
    return 0;
  v5 = (_BYTE *)ExAllocatePoolWithTag(512, 352, 1199010885);
  v6 = v5;
  if ( !v5 )
    return 0;
  memset(v5, 0, 352);
  __dmb(0xBu);
  v6[2] = 1;
  v7 = a1[1];
  v8 = a1[2];
  v9 = a1[3];
  v6[3] = *a1;
  v6[4] = v7;
  v6[5] = v8;
  v6[6] = v9;
  v6[7] = v6 + 7;
  v6[8] = v6 + 7;
  EtwpGetSecurityDescriptorByGuid(a1, v12);
  if ( ObLogSecurityDescriptor(v12[0], v6 + 9, 1) < 0 )
    return sub_808170();
  EtwpFreeSecurityDescriptor(v12);
  if ( v6 )
  {
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&EtwpCounters);
    while ( __strex(v11 + 1, (unsigned int *)&EtwpCounters) );
    __dmb(0xBu);
  }
  return (int)v6;
}
