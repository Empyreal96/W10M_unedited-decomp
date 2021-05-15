// LdrpVerifyAlternateResourceModule 
 
int __fastcall LdrpVerifyAlternateResourceModule(int a1, int a2, int a3, __int16 a4)
{
  int result; // r0
  int v7; // r1
  int v8; // r5
  int v9; // r0
  int v10; // r4
  int v11; // [sp+0h] [bp-20h]
  int v12; // [sp+4h] [bp-1Ch]
  int v13; // [sp+8h] [bp-18h]
  int v14; // [sp+Ch] [bp-14h]

  if ( !a3 )
    goto LABEL_9;
  if ( (a4 & 0x1000) != 0 )
    return sub_54D910();
  v8 = LdrpGetRcConfig(a1, a2, 0, 1, a1, a2, a3, a4);
  if ( v8
    && (v9 = LdrpGetRcConfig(a2, v7, 0, 0, v11, v12, v13, v14), (v10 = v9) != 0)
    && !memcmp(v8 + 44, v9 + 44, 16)
    && !wcsicmp(a3, *(_DWORD *)(v10 + 116) + v10) )
  {
    result = 1;
  }
  else
  {
LABEL_9:
    result = 0;
  }
  return result;
}
