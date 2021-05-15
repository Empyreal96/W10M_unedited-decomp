// sub_96E638 
 
void __fastcall sub_96E638(__int64 a1, _QWORD *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v9; // r2
  _DWORD *v10; // r1
  char v11; // r3
  _DWORD *v12; // r5
  unsigned int v13; // r6
  unsigned int v14; // r7
  char v15; // r3
  char v16; // r3

  while ( 1 )
  {
    v13 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v14 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v13 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( a1 == *a2 )
  {
    *(_QWORD *)(v12[6] + 832) = __PAIR64__(v13, v14) - a1;
    v9 = v12[6];
    v10 = (_DWORD *)*v12;
    v10[50] = *(_DWORD *)(v9 + 200);
    v10[51] = *(_DWORD *)(v9 + 204);
    v10[206] = *(_DWORD *)(v12[6] + 824);
    v10[207] = *(_DWORD *)(v12[6] + 828);
    v10[208] = *(_DWORD *)(v12[6] + 832);
    v10[209] = *(_DWORD *)(v12[6] + 836);
    if ( PspSehValidationPolicy )
    {
      v11 = MEMORY[0xFFFF92D5] & 0xF3;
      if ( PspSehValidationPolicy == 2 )
        v15 = v11 | 8;
      else
        v15 = v11 | 4;
    }
    else
    {
      v15 = MEMORY[0xFFFF92D5] & 0xF3;
    }
    MEMORY[0xFFFF92D5] = v15;
    switch ( PspCurDirDevicesSkippedForDlls )
    {
      case 1:
        v16 = MEMORY[0xFFFF92D5] & 0xCF | 0x10;
        break;
      case 2:
        v16 = MEMORY[0xFFFF92D5] & 0xCF | 0x20;
        break;
      case -1:
        v16 = MEMORY[0xFFFF92D5] | 0x30;
        break;
      default:
        v16 = MEMORY[0xFFFF92D5] & 0xCF;
        break;
    }
    MEMORY[0xFFFF92D5] = v16;
    PspInitializeSystemDlls();
    PspInitializeProtectedProcessParameters();
    __asm { POP.W           {R4-R7,R11,PC} }
  }
  JUMPOUT(0x960EB6);
}
