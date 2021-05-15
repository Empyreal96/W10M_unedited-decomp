// sub_554CD4 
 
void __fastcall sub_554CD4(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23)
{
  unsigned int v23; // r4
  int *v24; // r6
  int v25; // r7
  int v26; // r8
  int v27; // r9
  int v28; // r10
  int v29; // r5
  _DWORD *v30; // r4
  unsigned int *v31; // r2
  unsigned int v32; // r1
  __int64 v33; // kr00_8
  unsigned int v34; // r0
  unsigned int i; // r3
  unsigned int v36; // r1
  unsigned int *v37; // r2
  unsigned int v38; // r1

  while ( 1 )
  {
    v29 = v26 + 24 * v23;
    v30 = *(_DWORD **)v29;
    if ( (*(_DWORD *)(*(_DWORD *)v29 + 12) & 0x8000000) == 0 )
    {
      **(_DWORD **)(v29 + 4) = v30[6] | v30[7] & **(_DWORD **)(v29 + 4);
      __dmb(0xBu);
      v31 = v30 + 42;
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 + 1, v31) );
      __dmb(0xBu);
      if ( (v30[152] & 8) != 0 )
        v30[88] = v25;
      if ( EtwEventEnabled(*v24, v24[1], (int)ETW_EVENT_LOST_EVENT) )
        EtwpTraceLostEvent(a19 + 12, a23, v30 + 23, a22);
    }
    v33 = *(_QWORD *)(v29 + 8);
    __pld((void *)HIDWORD(v33));
    v34 = *(_DWORD *)HIDWORD(v33);
    for ( i = *(_DWORD *)HIDWORD(v33) ^ v33; ; i = v36 ^ v33 )
    {
      __dmb(0xBu);
      if ( i >= 7 )
        break;
      do
        v36 = __ldrex((unsigned int *)HIDWORD(v33));
      while ( v36 == v34 && __strex(v34 + 1, (unsigned int *)HIDWORD(v33)) );
      if ( v36 == v34 )
        goto LABEL_17;
      v34 = v36;
    }
    v37 = (unsigned int *)(*(_DWORD *)(v29 + 8) + 12);
    do
      v38 = __ldrex(v37);
    while ( __strex(v38 - 1, v37) );
    __dmb(0xBu);
LABEL_17:
    if ( v27 )
      ExReleaseRundownProtectionCacheAwareEx(*(_DWORD **)(v28 + 4 * *v30), 1);
    v24 = &EtwpEventTracingProvRegHandle;
    v23 = a5 + 1;
    a5 = v23;
    v25 = 1;
    if ( v23 >= *(_DWORD *)(v26 + 192) )
      JUMPOUT(0x4F7140);
  }
}
