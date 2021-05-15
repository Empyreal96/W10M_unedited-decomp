// RtlTraceDatabaseCreate 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall RtlTraceDatabaseCreate(unsigned int a1, int a2, int a3, int a4, int (__fastcall *a5)(int a1, unsigned __int16 *a2))
{
  _DWORD *v9; // r4 OVERLAPPED
  int v10; // r0
  int v11; // r7
  int (__fastcall *v12)(int, unsigned __int16 *); // r3
  int v13; // r3
  int v14; // r2

  if ( a1 > 0x100000 )
    return 0;
  v10 = RtlpTraceDatabaseAllocate((4 * (a1 + 1068)) & 0xFFFFF000, 6, a4);
  v9 = (_DWORD *)v10;
  if ( !v10 )
    return 0;
  v11 = v10 + 148;
  *(_DWORD *)v10 = -1412576052;
  *(_DWORD *)(v10 + 16) = a2;
  *(_DWORD *)(v10 + 20) = 4096;
  *(_DWORD *)(v10 + 12) = 0;
  *(_DWORD *)(v10 + 28) = 0;
  *(_DWORD *)(v10 + 76) = 0;
  *(_DWORD *)(v10 + 80) = 0;
  *(_DWORD *)(v10 + 4) = a3 | 2;
  *(_DWORD *)(v10 + 8) = a4;
  memset((_BYTE *)(v10 + 84), 0, 64);
  if ( !RtlpTraceDatabaseInitializeLock(v9) )
  {
    ExFreePoolWithTag(v9);
    return 0;
  }
  v12 = a5;
  v9[16] = a1;
  if ( !a5 )
    v12 = RtlStackTraceHashFunction;
  v9[18] = v12;
  v13 = -1412580421;
  *(_QWORD *)v11 = *(_QWORD *)(&v9 - 1);
  *(_DWORD *)(v11 + 8) = 0;
  *(_DWORD *)(v11 + 12) = 4096;
  v14 = 4 * v9[16];
  v9[3] = v11;
  v9[17] = v11 + 28;
  memset((_BYTE *)(v11 + 28), 0, v14);
  *(_DWORD *)(v11 + 16) = v9;
  *(_DWORD *)(v11 + 20) = v9 + 1024;
  *(_DWORD *)(v11 + 24) = v11 + 4 * (v9[16] + 7);
  return v9;
}
