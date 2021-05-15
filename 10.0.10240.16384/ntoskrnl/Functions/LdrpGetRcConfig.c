// LdrpGetRcConfig 
 
int __fastcall LdrpGetRcConfig(int a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r0
  _DWORD *v7; // r4
  _DWORD *v9; // [sp+18h] [bp-30h] BYREF
  int v10; // [sp+1Ch] [bp-2Ch] BYREF
  char v11[8]; // [sp+20h] [bp-28h] BYREF
  int v12[8]; // [sp+28h] [bp-20h] BYREF

  v9 = 0;
  if ( a4 )
  {
    v6 = (_DWORD *)LdrpGetFromMUIMemCache(a1, 0);
    v7 = v6;
    v9 = v6;
    if ( v6 == (_DWORD *)-1 )
      return 0;
    if ( v6 )
      return (int)v7;
  }
  v12[0] = (int)L"MUI";
  v12[1] = 1;
  v12[2] = 0;
  if ( LdrpSearchResourceSection_U(a1, v12, 3, 48, &v10) < 0
    || LdrpAccessResourceDataNoMultipleLanguage(a1, v10, &v9, v11) < 0 )
  {
    v7 = 0;
LABEL_9:
    if ( a3 )
      LdrpSetAlternateResourceModuleHandle(a1, 0);
    return (int)v7;
  }
  v7 = v9;
  if ( *v9 == -20054323 )
    goto LABEL_9;
  return sub_54DC44();
}
