// sub_8156B4 
 
int __fastcall sub_8156B4(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  unsigned int v7; // r5
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v13; // r6
  unsigned int v14; // r7
  unsigned int v15; // r8
  int v16; // r9
  _DWORD *v17; // r10
  _DWORD *v18; // r0
  int v19; // [sp+18h] [bp-28h]
  int (__fastcall *v20)(int); // [sp+3Ch] [bp-4h]

  v18 = (_DWORD *)ExAllocatePoolWithTag(1, v13, 538996553);
  v7 = (unsigned int)v18;
  if ( v18 )
  {
    v8 = v17[1];
    v9 = v17[2];
    v10 = v17[3];
    v18[4] = *v17;
    v18[5] = v8;
    v18[6] = v9;
    v18[7] = v10;
    v18[3] = a7;
    *v18 = 0;
    memmove((int)(v18 + 8), v16, v14);
    memmove(v7 + v14 + 32, a5, v15);
    *(_DWORD *)(v7 + 4) = v14 + 32;
    *(_DWORD *)(v7 + 8) = v15;
    v11 = IopIssueSystemEnvironmentRequest(5373960, 1, 0, v19, v7, v13, 0, 0, 0);
    ExFreePoolWithTag(v7);
  }
  else
  {
    v11 = -1073741670;
  }
  return v20(v11);
}
