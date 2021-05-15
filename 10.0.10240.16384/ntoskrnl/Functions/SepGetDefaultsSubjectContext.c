// SepGetDefaultsSubjectContext 
 
int __fastcall SepGetDefaultsSubjectContext(int *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, int *a6, int *a7, _DWORD *a8)
{
  _DWORD *v9; // r0
  int v11; // r2
  _DWORD *v12; // r1
  int v13; // r2
  int *v14; // r0
  int v15; // r1
  int v16; // r2
  int result; // r0

  v9 = (_DWORD *)*a1;
  if ( !v9 )
    v9 = (_DWORD *)a1[2];
  v11 = v9[41];
  *a2 = *(_DWORD *)(v9[37] + 8 * v9[36]);
  v12 = (_DWORD *)a1[2];
  *a3 = v9[39];
  *a8 = v11;
  v13 = v12[39];
  *a4 = *(_DWORD *)(v12[37] + 8 * v12[36]);
  *a5 = v13;
  v14 = (int *)SepLocateTokenIntegrity((int)v9);
  if ( v14 )
    v16 = *v14;
  else
    v16 = SepDefaultMandatorySid;
  *a6 = v16;
  result = SepLocateTokenTrustLevel(a1, v15, v16, (int)a6);
  *a7 = result;
  return result;
}
