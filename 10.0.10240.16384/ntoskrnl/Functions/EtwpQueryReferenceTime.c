// EtwpQueryReferenceTime 
 
int __fastcall EtwpQueryReferenceTime(unsigned int a1, _DWORD *a2)
{
  unsigned int v3; // r2
  _DWORD *v4; // r0
  int v5; // r2
  int v6; // r3
  int v7; // r4
  int v8; // r4
  unsigned int v9; // r1
  __int16 v10; // r3

  if ( a1 == 0xFFFF )
    a1 = (unsigned __int16)EtwpSystemLogger[0];
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = (_DWORD *)EtwpAcquireLoggerContextByLoggerId(a1, 0);
  if ( v4 )
  {
    v5 = v4[59];
    v6 = v4[60];
    v7 = v4[61];
    *a2 = v4[58];
    a2[1] = v5;
    a2[2] = v6;
    a2[3] = v7;
    v4 = (_DWORD *)EtwpReleaseLoggerContext(v4, 0);
    v8 = 0;
  }
  else
  {
    v8 = -1073741162;
  }
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery((int)v4);
  return v8;
}
