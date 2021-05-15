// FstubCopyEntryEFI 
 
int __fastcall FstubCopyEntryEFI(_DWORD *a1, int a2, unsigned int a3)
{
  __int64 v3; // kr00_8
  __int64 v5; // r4
  unsigned __int64 v6; // r2
  __int64 v9; // r0
  int v10; // r0
  int v11; // r1
  int v12; // r5
  int v13; // r4
  int v14; // r1

  v3 = *(_QWORD *)(a2 + 8);
  v5 = *(_QWORD *)(a2 + 16) + v3;
  v9 = a3;
  if ( !a3 )
    __brkdiv0();
  LODWORD(v6) = v5 - 1;
  HIDWORD(v6) = HIDWORD(v5) + ((_DWORD)v5 != 0) - 1;
  v10 = _rt_udiv64((unsigned int)v9, v6);
  v12 = v11;
  v13 = v10;
  a1[8] = _rt_sdiv64(a3, v3);
  a1[9] = v14;
  a1[10] = v13;
  a1[11] = v12;
  *a1 = *(_DWORD *)(a2 + 32);
  a1[1] = *(_DWORD *)(a2 + 36);
  a1[2] = *(_DWORD *)(a2 + 40);
  a1[3] = *(_DWORD *)(a2 + 44);
  a1[4] = *(_DWORD *)(a2 + 48);
  a1[5] = *(_DWORD *)(a2 + 52);
  a1[6] = *(_DWORD *)(a2 + 56);
  a1[7] = *(_DWORD *)(a2 + 60);
  a1[12] = *(_DWORD *)(a2 + 64);
  a1[13] = *(_DWORD *)(a2 + 68);
  return memmove((int)(a1 + 14), a2 + 72, 0x48u);
}
