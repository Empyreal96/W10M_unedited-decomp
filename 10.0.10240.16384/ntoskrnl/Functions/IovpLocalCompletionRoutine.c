// IovpLocalCompletionRoutine 
 
int __fastcall IovpLocalCompletionRoutine(int a1, int a2, int *a3)
{
  int v4; // r5
  int v6; // r8
  char v7; // r3
  int v8; // r1
  int v9; // r4
  int v10; // r0
  int v11; // r9
  int (*v12)(int); // r8
  int v13; // r4
  int v14; // r5
  char v15; // r2
  bool v16; // zf
  int v18; // [sp+0h] [bp-30h]
  BOOL v20; // [sp+Ch] [bp-24h]

  v4 = *a3;
  v6 = a1;
  *(_BYTE *)(v4 + 1) = *((_BYTE *)a3 + 17);
  *(_BYTE *)(v4 + 2) = *((_BYTE *)a3 + 18);
  *(_BYTE *)(v4 + 3) = *((_BYTE *)a3 + 19) | *(_BYTE *)(v4 + 3) & 2;
  *(_DWORD *)(v4 + 8) = a3[6];
  *(_DWORD *)(v4 + 12) = a3[7];
  *(_DWORD *)(v4 + 16) = a3[8];
  *(_DWORD *)(v4 + 20) = a3[9];
  *(_DWORD *)(v4 + 28) = a3[11];
  *(_DWORD *)(v4 + 32) = a3[3];
  *(_DWORD *)(v4 + 36) = a3[1];
  v20 = *(char *)(a2 + 35) == (char)(*(_BYTE *)(a2 + 34) + 1);
  IovpCompleteRequest2(a2, a3[2]);
  if ( *(_BYTE *)v4 != 22 )
  {
    v7 = *(_BYTE *)(v4 + 3);
    *(_BYTE *)(v4 + 1) = 0;
    *(_BYTE *)(v4 + 2) = 0;
    *(_BYTE *)(v4 + 3) = v7 & 2 | 0x10;
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 12) = 0;
    *(_DWORD *)(v4 + 16) = 0;
    *(_DWORD *)(v4 + 28) = 0;
  }
  v8 = *(_DWORD *)(v4 + 32);
  if ( v8 )
  {
    v10 = IovpCompleteRequest3(a2, v8, a3[2]);
    if ( (MmVerifierData & 0x10) != 0 )
      v11 = VfIoCompletionSnapState(v10);
    else
      v11 = 0;
    v12 = *(int (**)(int))(v4 + 32);
    __dmb(0xBu);
    v13 = *(_DWORD *)(v4 + 36);
    v18 = v13;
    if ( VfPendingMoreProcessingRequired(a1) )
    {
      v12 = VfPendingMoreProcessingRequired;
      v9 = -1073741802;
    }
    else
    {
      v9 = ((int (__fastcall *)(int, int, int))v12)(a1, a2, v13);
    }
    if ( v11 )
      VfIoCompletionCheckState(v11, v12);
    IovpCompleteRequest4(a2, v9, v12, a3[2], v18);
  }
  else
  {
    if ( *(_BYTE *)(a2 + 33) && *(char *)(a2 + 35) <= *(char *)(a2 + 34) )
      *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
    if ( VfPendingMoreProcessingRequired(v6) )
      v9 = -1073741802;
    else
      v9 = 0;
  }
  IovpCompleteRequest5(a3[2]);
  if ( v9 != -1073741802 && !v20 )
  {
    v14 = v4 + 40;
    *a3 = v14;
    a3[1] = *(_DWORD *)(v14 + 36);
    memmove((int)(a3 + 4), v14, 0x28u);
    v15 = *(_BYTE *)(v14 + 3);
    if ( *(int *)(a2 + 24) < 0 )
      v16 = (v15 & 0x80) == 0;
    else
      v16 = (v15 & 0x40) == 0;
    if ( !v16 || *(_BYTE *)(a2 + 36) && (*(_BYTE *)(v14 + 3) & 0x20) != 0 )
    {
      a3[3] = *(_DWORD *)(v14 + 32);
    }
    else
    {
      a3[3] = 0;
      *(_BYTE *)(v14 + 3) |= 0xE0u;
    }
    *(_DWORD *)(v14 + 32) = IovpLocalCompletionRoutine;
    *(_DWORD *)(v14 + 36) = a3;
  }
  return v9;
}
