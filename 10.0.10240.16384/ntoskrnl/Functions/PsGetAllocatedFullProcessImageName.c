// PsGetAllocatedFullProcessImageName 
 
int __fastcall PsGetAllocatedFullProcessImageName(int a1, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v4; // r0
  _DWORD *v5; // r4
  int v6; // r3
  int v7; // r0

  v2 = *(_DWORD *)(a1 + 380);
  v4 = (_DWORD *)ExAllocatePoolWithTag(512, *(unsigned __int16 *)(v2 + 2) + 8, 1850307408);
  v5 = v4;
  if ( !v4 )
    return -1073741801;
  *v4 = *(_DWORD *)v2;
  v6 = *(_DWORD *)(v2 + 4);
  v4[1] = v6;
  if ( v6 )
  {
    v7 = (int)(v4 + 2);
    v5[1] = v7;
    memmove(v7, *(_DWORD *)(v2 + 4), *(unsigned __int16 *)(v2 + 2));
  }
  *a2 = v5;
  return 0;
}
