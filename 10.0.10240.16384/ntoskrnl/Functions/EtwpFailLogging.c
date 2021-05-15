// EtwpFailLogging 
 
int __fastcall EtwpFailLogging(unsigned int a1, int a2, unsigned int a3, unsigned int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, char a10)
{
  unsigned int v10; // r5
  int result; // r0
  unsigned int v12; // lr
  unsigned int v13; // r6
  unsigned int v14; // r2
  unsigned int v15; // r1
  unsigned int v16; // r5
  int v17; // r4
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int v21; // [sp+8h] [bp-28h]

  v10 = a4;
  v21 = a3;
  result = a5;
  v12 = a3;
  if ( *(_DWORD *)(a6 + 192) )
    return sub_554CD4(a5);
  v13 = a7;
  v14 = __clz(__rbit(a7));
  if ( 1 != (unsigned __int8)(v14 >> 5) )
  {
    while ( 1 )
    {
      v15 = result + 32 * v14;
      v13 &= v13 + 255;
      if ( !*(_DWORD *)(v15 + 88) || a1 > *(unsigned __int8 *)(v15 + 92) && *(_BYTE *)(v15 + 92) )
        goto LABEL_26;
      if ( (*(_DWORD *)(v15 + 96) & 0x40) != 0 && !(v12 | v10) )
        goto LABEL_11;
      if ( *(_DWORD *)(v15 + 108) & v10 | *(_DWORD *)(v15 + 104) & v12 )
        break;
LABEL_26:
      v14 = __clz(__rbit(v13));
      v10 = a4;
      v12 = v21;
      if ( 1 == (unsigned __int8)(v14 >> 5) )
        return result;
    }
    if ( __PAIR64__(*(_DWORD *)(v15 + 116) & v10, *(_DWORD *)(v15 + 112) & v12) == *(_QWORD *)(v15 + 112) )
    {
LABEL_11:
      v16 = *(unsigned __int16 *)(v15 + 94);
      if ( !a10 || ExAcquireRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v16], 1) )
      {
        if ( v16 >= 0x40 )
          v17 = 1;
        else
          v17 = WmipLoggerContext[v16];
        if ( (v17 & 1) == 0 )
        {
          __dmb(0xBu);
          v18 = (unsigned int *)(v17 + 168);
          do
            v19 = __ldrex(v18);
          while ( __strex(v19 + 1, v18) );
          __dmb(0xBu);
          if ( (*(_DWORD *)(v17 + 608) & 8) != 0 )
            *(_DWORD *)(v17 + 352) = 1;
          if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_LOST_EVENT) )
            EtwpTraceLostEvent(a5 + 12, a9, v17 + 92, a8);
        }
        if ( a10 )
          ExReleaseRundownProtectionCacheAwareEx((_DWORD *)EtwpLoggerRundown[v16], 1);
      }
    }
    result = a5;
    goto LABEL_26;
  }
  return result;
}
