// EtwpFindUserBufferSpace 
 
int __fastcall EtwpFindUserBufferSpace(int a1, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // r9
  _DWORD *v5; // r5
  int v6; // r4
  unsigned int v7; // r6
  int v8; // r0
  int v9; // r8
  int v10; // r0

  v4 = a4;
  v5 = (_DWORD *)a2;
  v6 = 0;
  *a4 = 0;
  v7 = ((a3 + 4095) & 0xFFFFF000) >> 12;
  v8 = RtlFindNextAlignedForwardRunClear((unsigned int *)(a2 + 52), a2, v7);
  v9 = v8;
  if ( v8 != -1 && RtlInterlockedSetClearRun((int)(v5 + 13), v8, v7) )
    *v4 = v5[15] + (v9 << 12);
  v5[18] += v7;
  if ( !*v4 )
  {
    v10 = ZwAllocateVirtualMemory();
    v6 = v10;
    if ( v10 < 0 )
    {
      if ( v10 == -1073741670 || v10 == -1073741523 )
        v6 = -1073741764;
    }
    else
    {
      v5[17] += v7;
    }
  }
  return v6;
}
