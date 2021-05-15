// SepInitializeAuthorizationCallbacks 
 
int __fastcall SepInitializeAuthorizationCallbacks(int a1, int a2)
{
  int v2; // r1
  int result; // r0
  unsigned __int16 v4; // [sp+0h] [bp-20h] BYREF
  __int16 v5; // [sp+2h] [bp-1Eh]
  __int16 v6; // [sp+4h] [bp-1Ch]
  int v7; // [sp+8h] [bp-18h]
  int v8; // [sp+Ch] [bp-14h]
  int v9; // [sp+10h] [bp-10h]
  int v10; // [sp+14h] [bp-Ch]

  v4 = 2;
  v5 = 1;
  v6 = 6;
  v7 = 1;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  if ( ExRegisterHost((void ***)&SepAuthExtensionHost, a2, &v4) < 0 )
    return sub_96C5B8();
  v4 = 3;
  v5 = 1;
  v6 = 36;
  v7 = 512;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  result = ExRegisterHost((void ***)&SepBCryptExtensionHost, v2, &v4);
  if ( result < 0 )
    SepBCryptExtensionHost = 0;
  return result;
}
