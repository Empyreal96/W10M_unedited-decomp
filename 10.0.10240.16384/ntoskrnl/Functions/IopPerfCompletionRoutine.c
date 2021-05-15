// IopPerfCompletionRoutine 
 
int __fastcall IopPerfCompletionRoutine(int a1, int a2, int *a3)
{
  int v4; // r5
  BOOL v6; // r4
  int (__fastcall *v7)(int, int); // r3
  int (__fastcall *v8)(int, int); // lr
  int v9; // r8
  int v10; // r3
  int v11; // r5
  int v12; // r3
  char v13; // r2
  bool v14; // zf
  _DWORD v16[4]; // [sp+8h] [bp-38h] BYREF
  int v17[10]; // [sp+18h] [bp-28h] BYREF

  v4 = *a3;
  v6 = *(char *)(a2 + 35) == (char)(*(_BYTE *)(a2 + 34) + 1);
  *(_BYTE *)(v4 + 3) = *((_BYTE *)a3 + 16) | *(_BYTE *)(*a3 + 3) & 2;
  v7 = (int (__fastcall *)(int, int))a3[2];
  *(_DWORD *)(v4 + 32) = v7;
  v8 = v7;
  *(_DWORD *)(v4 + 36) = a3[1];
  if ( v7 )
  {
    v10 = a3[3];
    v16[0] = v8;
    v16[1] = a2;
    v16[2] = v10;
    v17[0] = (int)v16;
    v17[1] = 0;
    v17[2] = 12;
    v17[3] = 0;
    v9 = v8(a1, a2);
    EtwTraceKernelEvent(v17, 1, 0x20000010u, 293, 4200450);
    if ( v9 == -1073741802 )
      return v9;
  }
  else
  {
    if ( *(_BYTE *)(a2 + 33) && *(char *)(a2 + 35) <= *(char *)(a2 + 34) )
      *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
    v9 = 0;
  }
  if ( !v6 )
  {
    v11 = v4 + 40;
    a3[2] = 0;
    v12 = *(_DWORD *)(v11 + 36);
    *a3 = v11;
    a3[1] = v12;
    *((_BYTE *)a3 + 16) = *(_BYTE *)(v11 + 3);
    v13 = *(_BYTE *)(v11 + 3);
    if ( *(int *)(a2 + 24) < 0 )
      v14 = (v13 & 0x80) == 0;
    else
      v14 = (v13 & 0x40) == 0;
    if ( !v14 || *(_BYTE *)(a2 + 36) && (*(_BYTE *)(v11 + 3) & 0x20) != 0 )
    {
      a3[2] = *(_DWORD *)(v11 + 32);
      a3[1] = *(_DWORD *)(v11 + 36);
    }
    else
    {
      *(_BYTE *)(v11 + 3) = v13 | 0xC0;
    }
    *(_DWORD *)(v11 + 32) = IopPerfCompletionRoutine;
    *(_DWORD *)(v11 + 36) = a3;
  }
  return v9;
}
