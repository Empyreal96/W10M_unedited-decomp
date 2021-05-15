// EtwpInitializeStackTracing 
 
int __fastcall EtwpInitializeStackTracing(int a1, int a2)
{
  int v2; // r4
  int v4; // r5
  int v5; // r7
  int result; // r0

  v2 = a1;
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 52) = 0;
  v4 = a1;
  v5 = 12;
  do
  {
    *(_DWORD *)(v4 + 104) = a2;
    RtlpInterlockedPushEntrySList((unsigned __int64 *)(v2 + 48), (_DWORD *)(v4 + 56));
    v4 += 52;
    --v5;
  }
  while ( v5 );
  result = KeInitializeDpc(v2 + 12, (int)EtwpStackWalkDpc, a2);
  *(_WORD *)(v2 + 14) = a2 + 32;
  *(_BYTE *)(v2 + 13) = 2;
  return result;
}
