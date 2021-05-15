// _CmGetContainerBooleanPropertyCallback 
 
int __fastcall CmGetContainerBooleanPropertyCallback(int a1, int a2, int a3)
{
  int v4; // r4
  char v6[4]; // [sp+20h] [bp-18h] BYREF
  char v7[4]; // [sp+24h] [bp-14h] BYREF
  char v8[16]; // [sp+28h] [bp-10h] BYREF

  v4 = 0;
  if ( a3 && PnpGetObjectProperty(a1, a2, 1, 0, 0, *(_DWORD *)a3, (int)v8, (int)v6, 1, (int)v7, 0) >= 0 && v6[0] == -1 )
  {
    *(_BYTE *)(a3 + 4) = -1;
    v4 = 2;
  }
  return v4;
}
