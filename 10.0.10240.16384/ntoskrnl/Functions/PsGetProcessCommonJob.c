// PsGetProcessCommonJob 
 
int __fastcall PsGetProcessCommonJob(int a1, int a2)
{
  int v2; // r0
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int result; // r0

  v2 = *(_DWORD *)(a1 + 288);
  __dmb(0xBu);
  if ( !v2 )
    return 0;
  v3 = *(_DWORD *)(a2 + 288);
  __dmb(0xBu);
  if ( !v3 )
    return 0;
  v4 = *(_DWORD *)(v2 + 576);
  __dmb(0xBu);
  v5 = *(_DWORD *)(v3 + 576);
  __dmb(0xBu);
  if ( v4 != v5 )
    return 0;
  result = *(_DWORD *)(v2 + 576);
  __dmb(0xBu);
  return result;
}
