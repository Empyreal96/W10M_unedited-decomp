// PspValidateJobLimitsDuringAssignment 
 
int __fastcall PspValidateJobLimitsDuringAssignment(_DWORD *a1, int a2)
{
  int v4; // r1
  int v5; // r3
  int result; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r0

  if ( (*(_DWORD *)(a2 + 192) & 0x4000000) != 0 && a1[49] )
    return sub_7C1C00();
  v4 = a1[44];
  if ( (v4 & 8) != 0 && (unsigned int)(a1[36] - a1[171]) > a1[45] )
  {
    RtlInterlockedSetClearBits((unsigned int *)(a2 + 188), 2);
    if ( a1[53] && (a1[107] & 8) != 0 )
      PspSendJobNotification((int)a1);
    return -1073741756;
  }
  if ( (v4 & 4) != 0 && a1[1] )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(a2 + 188);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 2, v7) );
    __dmb(0xBu);
    return -1073741756;
  }
  v5 = a1[186];
  if ( (v5 & 1) != 0 && (v4 & 0x2000) != 0 )
  {
    __dmb(0xBu);
    v9 = (unsigned int *)(a2 + 188);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 2, v9) );
    __dmb(0xBu);
    result = -1073741811;
  }
  else if ( (v5 & 0x80) != 0 )
  {
    result = -1073741558;
  }
  else
  {
    result = 0;
  }
  return result;
}
