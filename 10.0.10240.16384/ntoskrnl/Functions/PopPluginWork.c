// PopPluginWork 
 
int __fastcall PopPluginWork(int a1, _BYTE *a2, int a3, int a4)
{
  int result; // r0
  int (__fastcall *v7)(int, _BYTE **); // r3
  _BYTE *v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]

  v8 = (_BYTE *)a3;
  v9 = a4;
  if ( a2 )
    memset(a2, 0, 32);
  LOBYTE(v9) = 0;
  v8 = a2;
  if ( a1 )
  {
    v7 = *(int (__fastcall **)(int, _BYTE **))(a1 + 64);
    if ( !v7 || !v7(13, &v8) )
      JUMPOUT(0x53FA40);
    result = (unsigned __int8)v9;
    if ( !a2 && (_BYTE)v9 )
      JUMPOUT(0x53FA32);
  }
  else
  {
    result = PopPepWork(a2);
    if ( !a2 )
    {
      if ( result )
        sub_53FA24();
    }
  }
  return result;
}
