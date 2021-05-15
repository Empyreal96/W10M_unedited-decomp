// EtwpTraceThreadRundownWithStack 
 
int __fastcall EtwpTraceThreadRundownWithStack(int a1, int a2)
{
  int result; // r0
  __int64 v5; // [sp+10h] [bp-58h] BYREF
  char v6[4]; // [sp+18h] [bp-50h] BYREF
  int v7; // [sp+1Ch] [bp-4Ch]
  int v8[2]; // [sp+20h] [bp-48h] BYREF
  char v9[64]; // [sp+28h] [bp-40h] BYREF

  if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    goto LABEL_7;
  if ( *(_BYTE *)(a2 + 39) )
    goto LABEL_7;
  v6[0] = 1;
  v6[1] = 0;
  v6[2] = 4;
  v7 = 0;
  v8[1] = (int)v8;
  v8[0] = (int)v8;
  KeInitializeApc((int)v9, a1, 0, (int)EtwpThreadRundownApc, 0, 0, 0, 0);
  if ( !KeInsertQueueApc((int)v9, (int)v6, a2, 0) )
    goto LABEL_7;
  v5 = *(_QWORD *)EtwpOneSecond * (unsigned int)EtwpStackCaptureTimeout;
  result = KeWaitForSingleObject((unsigned int)v6, 7, 0, 0, (int *)&v5);
  if ( result != 258 )
    return result;
  if ( KeRemoveQueueApc((int)v9) )
LABEL_7:
    result = EtwpTraceThreadRundown(a1, a2);
  else
    result = KeWaitForSingleObject((unsigned int)v6, 7, 0, 0, 0);
  return result;
}
