// sub_7BDB18 
 
void sub_7BDB18(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r4
  int v9; // r6
  int v10; // r7
  int v11; // r8
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( EtwGetProviderIdFromHandle(v11, v10, 0, (int *)va) >= 0
    && (*(_DWORD *)v8
     || *(_WORD *)(v8 + 4)
     || *(_WORD *)(v8 + 6)
     || *(_BYTE *)(v8 + 8)
     || *(_BYTE *)(v8 + 9)
     || *(_BYTE *)(v8 + 10)
     || *(_BYTE *)(v8 + 11)
     || *(_BYTE *)(v8 + 12)
     || *(_BYTE *)(v8 + 13)
     || *(_BYTE *)(v8 + 14)
     || *(_BYTE *)(v8 + 15)
     || ZwTraceControl() >= 0) )
  {
    EtwWrite(v11, v10, v9, v8);
    WdipStartEndScenario((int *)va, v8, v9, 10);
  }
  JUMPOUT(0x78AEDA);
}
