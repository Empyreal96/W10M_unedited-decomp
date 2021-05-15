// PoStoreDiagnosticContext 
 
int __fastcall PoStoreDiagnosticContext(_DWORD *a1, int a2, unsigned int *a3, unsigned int a4)
{
  unsigned int v4; // r8
  int v8; // r0
  int v9; // r4
  int v10; // r2
  BOOL v11; // r1
  unsigned int v12; // r3
  int v13; // r0
  unsigned int v14; // r2
  unsigned int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a4;
  v4 = *a3;
  v17[0] = *a3;
  v8 = PoStoreRequester(a1, (char *)a2, v17, 0);
  v9 = v8;
  v10 = a1[3];
  v11 = v8 >= 0;
  if ( v10 )
  {
    v13 = (v17[0] + a2 + 3) & 0xFFFFFFFC;
    v14 = v10 + v13 - a2;
    *a3 = v14;
    if ( v11 && v4 >= v14 )
    {
      *(_DWORD *)(a2 + 20) = v13 - a2;
      *(_DWORD *)a2 = v14;
      memmove(v13, ((unsigned int)a1 + 19) & 0xFFFFFFFC, a1[3]);
    }
    else
    {
      v9 = -1073741789;
    }
  }
  else
  {
    v12 = v17[0];
    if ( v8 >= 0 )
    {
      *(_DWORD *)(a2 + 20) = 0;
      *(_DWORD *)a2 = v12;
    }
    *a3 = v12;
  }
  return v9;
}
