// PfpSectInfoHandleFullBuffer 
 
int __fastcall PfpSectInfoHandleFullBuffer(int a1, int a2, int a3, int a4)
{
  __int64 v4; // kr00_8
  __int64 v5; // r6
  int v7; // r4
  int v8; // r3

  v4 = *(_QWORD *)(a1 + 12);
  HIDWORD(v5) = *(_DWORD *)(a1 + 20);
  LODWORD(v5) = v4 - a1;
  v7 = *(_DWORD *)(a1 + 8) - a1;
  memset((_BYTE *)a1, 0, 56);
  *(_WORD *)(a1 + 8) = 45;
  *(_WORD *)(a1 + 10) = 13;
  *(_DWORD *)(a1 + 12) = 1128485697;
  *(_DWORD *)(a1 + 16) = v7 - 8;
  *(_DWORD *)(a1 + 20) = 1;
  *(_DWORD *)(a1 + 24) = 3;
  *(_DWORD *)(a1 + 28) = dword_643B14;
  v8 = dword_643B1C;
  *(_DWORD *)(a1 + 40) = HIDWORD(v4);
  *(_DWORD *)(a1 + 32) = v8;
  *(_DWORD *)(a1 + 36) = 32;
  *(_QWORD *)(a1 + 44) = v5;
  return PfTTraceListAdd((int **)a1, a1 + 24, (int)&PfTGlobals, a4);
}
