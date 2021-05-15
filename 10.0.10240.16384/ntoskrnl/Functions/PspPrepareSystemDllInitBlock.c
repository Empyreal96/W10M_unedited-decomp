// PspPrepareSystemDllInitBlock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PspPrepareSystemDllInitBlock(int a1, int a2)
{
  _DWORD *v2; // r8
  int v3; // r9
  int v4; // r5 OVERLAPPED
  int v5; // r6 OVERLAPPED
  int v6; // r3
  int v8; // r3
  int v9; // r0
  int v10; // r3
  int v11; // [sp+0h] [bp-20h]

  __mrc(15, 0, 13, 0, 3);
  v2 = PspSystemDllInitBlock;
  v3 = MEMORY[0xC040214C];
  v11 = MEMORY[0xC0402150];
  if ( a2 )
  {
    v4 = *(_DWORD *)(a2 + 208);
    v5 = *(_DWORD *)(a2 + 212);
  }
  else
  {
    v4 = 1118993;
    v5 = 0;
  }
  v6 = *(_DWORD *)PspSystemDllInitBlock;
  __dmb(0xBu);
  if ( v6 != 128 )
    return -1073741735;
  v8 = *((_DWORD *)PspSystemDlls + 8);
  __dmb(0xBu);
  v2[2] = v8;
  v2[3] = 0;
  __dmb(0xBu);
  v2[1] = 0;
  v9 = ExGenRandom(1);
  __dmb(0xBu);
  v2[20] = v9;
  __dmb(0xBu);
  *((_QWORD *)v2 + 11) = *(_QWORD *)&v4;
  __dmb(0xBu);
  *((_QWORD *)v2 + 12) = v3;
  v10 = v11;
  __dmb(0xBu);
  v2[26] = v10;
  v2[27] = 0;
  __dmb(0xBu);
  v2[28] = 0;
  v2[29] = 0;
  __dmb(0xBu);
  v2[30] = 0;
  v2[31] = 0;
  return 0;
}
