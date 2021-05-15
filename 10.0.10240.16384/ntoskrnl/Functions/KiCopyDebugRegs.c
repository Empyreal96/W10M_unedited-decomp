// KiCopyDebugRegs 
 
int __fastcall KiCopyDebugRegs(int result, int a2)
{
  int v3; // r8
  int v4; // r3
  int v5; // r4
  int v6; // r5
  int v7; // r3
  int v8; // r4
  int v9; // r5
  int *v10; // r4
  int *v11; // r5
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3

  v3 = result;
  if ( KiCP14DebugEnabled )
  {
    *(_BYTE *)(result + 18) = *(_BYTE *)(a2 + 18);
    if ( *(_BYTE *)(a2 + 18) )
    {
      v4 = *(_DWORD *)(a2 + 28);
      v5 = *(_DWORD *)(a2 + 32);
      v6 = *(_DWORD *)(a2 + 36);
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 24);
      *(_DWORD *)(result + 28) = v4;
      *(_DWORD *)(result + 32) = v5;
      *(_DWORD *)(result + 36) = v6;
      v7 = *(_DWORD *)(a2 + 44);
      v8 = *(_DWORD *)(a2 + 48);
      v9 = *(_DWORD *)(a2 + 52);
      *(_DWORD *)(result + 40) = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 44) = v7;
      *(_DWORD *)(result + 48) = v8;
      *(_DWORD *)(result + 52) = v9;
      v10 = (int *)(a2 + 56);
      v11 = (int *)(result + 56);
      v12 = *(_DWORD *)(a2 + 56);
      v13 = *(_DWORD *)(a2 + 60);
      v14 = v10[2];
      v15 = v10[3];
      v10 += 4;
      *v11 = v12;
      v11[1] = v13;
      v11[2] = v14;
      v11[3] = v15;
      v11 += 4;
      result = *v10;
      v16 = v10[1];
      v17 = v10[2];
      v18 = v10[3];
      *v11 = *v10;
      v11[1] = v16;
      v11[2] = v17;
      v11[3] = v18;
      *(_DWORD *)(v3 + 88) = *(_DWORD *)(a2 + 88);
      *(_DWORD *)(v3 + 92) = *(_DWORD *)(a2 + 92);
    }
  }
  return result;
}
