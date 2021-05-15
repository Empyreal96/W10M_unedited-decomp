// PfFbBufferListInsertInFree 
 
unsigned int __fastcall PfFbBufferListInsertInFree(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // r6
  int v8; // r5
  unsigned int *v9; // r2
  unsigned int v10; // r6
  unsigned int result; // r0
  char *v12; // r2
  int v13; // r3
  _BYTE *v14; // r0
  unsigned int v15; // r1
  _DWORD *varg_r0; // [sp+20h] [bp+8h]
  _DWORD *varg_r1; // [sp+24h] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v5 = a4;
  if ( (a4 & 1) != 0
    && *((unsigned __int16 *)a1 + 10) + (unsigned int)*((unsigned __int16 *)a1 + 6) >= KeNumberProcessors_0 + 1 )
  {
    __dmb(0xBu);
    v8 = -a3;
    v9 = a1 + 16;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 + v8, v9) );
    __dmb(0xBu);
    result = ExFreePoolWithTag(a2);
  }
  else
  {
    v12 = (char *)a2 + a3;
    a2[3] = v12;
    a2[1] = a1;
    v13 = a1[11];
    a2[5] = v5;
    a2[2] = (char *)a2 + v13;
    v14 = (_BYTE *)a2[2];
    a2[4] = 0;
    memset(v14, 0, v12 - v14);
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)a1 + 1, a2);
  }
  if ( a5 )
  {
    __pld(a1);
    result = *a1 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v15 = __ldrex(a1);
    while ( v15 == result && __strex(result - 2, a1) );
    if ( v15 != result )
      result = (unsigned int)ExfReleaseRundownProtection((unsigned __int8 *)a1);
  }
  return result;
}
