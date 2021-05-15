// RtlInitializeExtendedContext 
 
int __fastcall RtlInitializeExtendedContext(int a1, int a2, char **a3, int a4)
{
  char *v7; // r4
  int result; // r0
  char *v9; // r3
  int v10; // r2
  _BYTE *v11; // r5
  int v12; // r2
  int v13; // r3
  int v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = (int)a3;
  v14[1] = a4;
  v7 = 0;
  result = RtlpValidateContextFlags(a2, v14);
  if ( result < 0 )
    return result;
  if ( (a2 & 0x10000) != 0 )
    return sub_5479D8();
  if ( (a2 & 0x100000) != 0 )
  {
    v9 = (char *)((a1 + 15) & 0xFFFFFFF0);
    *((_DWORD *)v9 + 12) = a2;
    v7 = v9 + 1232;
  }
  else
  {
    if ( (a2 & 0x200000) != 0 )
    {
      v9 = (char *)((a1 + 7) & 0xFFFFFFF8);
      v7 = v9 + 416;
    }
    else
    {
      if ( (a2 & 0x400000) == 0 )
        goto LABEL_9;
      v9 = (char *)((a1 + 15) & 0xFFFFFFF0);
      v7 = v9 + 912;
    }
    *(_DWORD *)v9 = a2;
  }
  *((_DWORD *)v7 + 3) = v7 - v9;
LABEL_9:
  v10 = *((_DWORD *)v7 + 3);
  *((_DWORD *)v7 + 2) = -v10;
  *(_DWORD *)v7 = -v10;
  *((_DWORD *)v7 + 1) = v10 + 24;
  if ( (v14[0] & 2) != 0 )
  {
    v11 = (_BYTE *)((unsigned int)(v7 + 87) & 0xFFFFFFC0);
    memset(v11, 0, 64);
    if ( (MEMORY[0xFFFF93EC] & 2) != 0 )
      *(_QWORD *)(((unsigned int)(v7 + 87) & 0xFFFFFFC0) + 8) = MEMORY[0xFFFF93D8] | 0x8000000000000000ui64;
    *((_DWORD *)v7 + 4) = v11 - v7;
    v12 = MEMORY[0xFFFF93E8] - 512;
    v13 = *(_DWORD *)v7;
    *((_DWORD *)v7 + 5) = MEMORY[0xFFFF93E8] - 512;
    *((_DWORD *)v7 + 1) = v12 - v13 + v11 - v7;
  }
  else
  {
    *((_DWORD *)v7 + 4) = 25;
    *((_DWORD *)v7 + 5) = 0;
  }
  *a3 = v7;
  return 0;
}
