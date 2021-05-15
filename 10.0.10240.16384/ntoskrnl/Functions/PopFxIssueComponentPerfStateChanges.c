// PopFxIssueComponentPerfStateChanges 
 
int __fastcall PopFxIssueComponentPerfStateChanges(int a1, int a2, char a3, unsigned int a4, int a5, int a6)
{
  int v10; // r5
  unsigned int *v11; // r6
  unsigned int v12; // r2
  int v13; // r3
  __int64 v14; // r0
  unsigned int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r1
  int v18; // r1
  int v19; // r0
  int v20; // r9
  int v21; // r4
  unsigned int v22; // r1
  unsigned int v23; // r1
  unsigned int v24; // r2
  unsigned int v25; // r2
  unsigned int v26; // r2
  int result; // r0
  unsigned int v28; // r4
  char v29[4]; // [sp+8h] [bp-28h] BYREF
  int v30; // [sp+Ch] [bp-24h]

  KeGetCurrentIrql(a1);
  v10 = *(_DWORD *)(a2 + 184);
  __dmb(0xBu);
  if ( !v10 )
    PopFxBugCheck(1563, *(_DWORD *)(a1 + 36), a1, *(_DWORD *)(a2 + 16));
  v11 = (unsigned int *)(v10 + 24);
  if ( a4 > *(_DWORD *)(v10 + 84) )
    PopFxBugCheck(1564, a1, *(_DWORD *)(a2 + 16), 0);
  do
    v12 = __ldrex(v11);
  while ( __strex(0, v11) );
  __dmb(0xBu);
  if ( (v12 & 7) != 0 )
  {
    v13 = *(_DWORD *)(v10 + 52);
    __dmb(0xBu);
    PopFxBugCheck(1565, a1, *(_DWORD *)(a2 + 16), v13);
  }
  if ( *(_BYTE *)(v10 + 50) )
  {
    memmove(*(_DWORD *)(v10 + 28), a5, 16 * a4);
    *(_DWORD *)(v10 + 32) = a4;
    *(_BYTE *)(v10 + 48) = 0;
    LODWORD(v14) = KeQueryInterruptTime();
    *(_QWORD *)(v10 + 40) = v14;
  }
  __dmb(0xBu);
  *(_DWORD *)(v10 + 52) = a6;
  KeResetEvent(v10 + 4);
  PopDiagTraceFxPerfRequest(v10, a4, a5);
  v30 = a3 & 1;
  if ( (a3 & 1) != 0 )
  {
    do
      v15 = __ldrex(v11);
    while ( __strex(v15 | 0x88000000, v11) );
  }
  else if ( (a3 & 2) != 0 )
  {
    do
      v16 = __ldrex(v11);
    while ( __strex(v16 | 0x10000000, v11) );
  }
  do
    v17 = __ldrex(v11);
  while ( __strex(v17 + 4, v11) );
  __dmb(0xFu);
  if ( *(_BYTE *)(v10 + 49) )
  {
    v18 = *(_DWORD *)(a2 + 16);
    v29[0] = 0;
    v19 = PopPluginRequestComponentPerfState(a1, v18, a4, a5, v29);
    v20 = (unsigned __int8)v29[0];
    v21 = v19;
  }
  else
  {
    v20 = 1;
    v21 = 1;
  }
  if ( v21 )
  {
    if ( v20 )
    {
      do
        v22 = __ldrex(v11);
      while ( __strex(v22 | 0x60000000, v11) );
    }
    else
    {
      do
        v23 = __ldrex(v11);
      while ( __strex(v23 | 0x20000000, v11) );
    }
    do
      v24 = __ldrex(v11);
    while ( __strex(v24 - 1, v11) );
  }
  __dmb(0xBu);
  do
  {
    v25 = __ldrex(v11);
    v26 = v25 - 1;
  }
  while ( __strex(v26, v11) );
  result = PopDiagTraceFxPerfRequestProgress(v10, v26 & 7);
  if ( v21 )
  {
    if ( (a3 & 2) != 0 )
    {
      result = PopFxQueueWorkOrder((int)&PopFxSystemWorkQueue, (_DWORD *)(v10 + 56), a1, 0);
    }
    else
    {
      do
        v28 = __ldrex(v11);
      while ( __strex(v28 | 0x80000000, v11) );
      result = PopFxCompleteComponentPerfState(a1, *(_DWORD *)(a2 + 16), v10, v20);
    }
  }
  else if ( v30 )
  {
    result = KeWaitForSingleObject(v10 + 4, 0, 0, 0, 0);
  }
  return result;
}
