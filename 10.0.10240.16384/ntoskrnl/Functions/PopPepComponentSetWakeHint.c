// PopPepComponentSetWakeHint 
 
int __fastcall PopPepComponentSetWakeHint(int a1, int a2, int a3, unsigned __int8 a4)
{
  char v4; // r5
  int v5; // r6
  int v7; // r4
  int v8; // r0
  int result; // r0

  v4 = a3;
  v5 = a1 + 168 * a2;
  if ( a3 )
    v7 = *(_DWORD *)(v5 + 244);
  else
    v7 = *(_DWORD *)(v5 + 284) - 1;
  v8 = PopPepLockActivityLink(a1, v5 + 128, 6, 1);
  *(_BYTE *)(v5 + 240) = v4;
  if ( *(_DWORD *)(v5 + 260) == v7 )
    result = PopPepReleaseActivityLink(a1, v5 + 128, v8, a4);
  else
    result = sub_524624(v8);
  return result;
}
