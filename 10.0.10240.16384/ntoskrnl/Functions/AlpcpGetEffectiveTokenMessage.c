// AlpcpGetEffectiveTokenMessage 
 
int __fastcall AlpcpGetEffectiveTokenMessage(int a1, _DWORD *a2, _DWORD *a3, int a4, char *a5)
{
  int v7; // r2
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int result; // r0
  int v12; // r3
  char v13; // r2

  if ( (a2[5] & 0x80) != 0 )
    return -1073740029;
  v7 = a2[18];
  if ( v7 )
  {
    if ( *(int *)(v7 + 20) < 1 )
      return -1073741790;
    v12 = *(_DWORD *)(v7 + 28);
    goto LABEL_13;
  }
  v8 = a2[3];
  if ( (*(_DWORD *)(a1 + 244) & 6) != 2 )
    return -1073741790;
  if ( !v8 )
    return -1073741790;
  v9 = *(_DWORD *)(v8 + 244);
  if ( (v9 & 6) != 4 )
    return -1073741790;
  if ( (v9 & 0x400) == 0 )
  {
    v12 = *(_DWORD *)(v8 + 44);
    if ( !v12 )
      return -1073741790;
LABEL_13:
    v13 = 0;
    goto LABEL_10;
  }
  v10 = a2[4];
  if ( !v10 )
    return -1073741790;
  result = SeCreateClientSecurityEx(v10, v8 + 156, 0, a4);
  if ( result < 0 )
    return result;
  v12 = *(_DWORD *)(a4 + 12);
  v13 = 1;
LABEL_10:
  *a3 = v12;
  result = 0;
  *a5 = v13;
  return result;
}
