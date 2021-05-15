// PopConsoleSessionActiveInput 
 
__int64 __fastcall PopConsoleSessionActiveInput(unsigned int a1, int a2, int a3)
{
  __int64 v6; // kr00_8
  __int64 v8; // [sp+0h] [bp-28h] BYREF
  int v9[8]; // [sp+8h] [bp-20h] BYREF

  v8 = a1;
  v9[0] = a3;
  v9[1] = 0;
  PopRemoteSessionActiveInput(a1);
  v6 = *(_QWORD *)a3;
  v9[0] = *(_DWORD *)(a3 + 4);
  LODWORD(v8) = v6;
  byte_61DE64 = (_DWORD)v6 != 0;
  dword_61DE58 = a2;
  PopUpdateTimeouts(a1, v9, &v8);
  *(_QWORD *)a3 = v6;
  return v8;
}
