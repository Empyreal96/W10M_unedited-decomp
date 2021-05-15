// PopPepPowerControlRequest 
 
int __fastcall PopPepPowerControlRequest(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r6
  int v8; // r0
  __int64 v9; // kr00_8
  int v11[6]; // [sp+0h] [bp-30h] BYREF
  int v12; // [sp+18h] [bp-18h]
  int v13; // [sp+1Ch] [bp-14h]

  v7 = -1073741637;
  if ( a7 )
    *a7 = 0;
  if ( *(_BYTE *)(a1 + 76) )
  {
    v11[2] = a3;
    v11[3] = a4;
    v8 = *(_DWORD *)(a1 + 24);
    v11[1] = a2;
    v11[4] = a5;
    v9 = *(_QWORD *)(v8 + 36);
    v7 = -1073741822;
    v11[5] = a6;
    v12 = 0;
    v11[0] = HIDWORD(v9);
    if ( (*(int (__fastcall **)(int, int *))(v9 + 64))(14, v11) == 1 )
    {
      if ( a7 )
        *a7 = v12;
      v7 = v13;
    }
  }
  return v7;
}
