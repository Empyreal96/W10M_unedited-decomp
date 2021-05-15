// AlpcpQueryTokenModifiedIdMessage 
 
int __fastcall AlpcpQueryTokenModifiedIdMessage(int a1, _DWORD *a2, _DWORD *a3, unsigned int a4, _DWORD *a5)
{
  int v6; // r4
  char v8[4]; // [sp+8h] [bp-78h] BYREF
  int v9; // [sp+Ch] [bp-74h] BYREF
  _DWORD v10[10]; // [sp+10h] [bp-70h] BYREF
  int v11[18]; // [sp+38h] [bp-48h] BYREF

  if ( a4 >= 8 )
  {
    v6 = AlpcpGetEffectiveTokenMessage(a1, a2, &v9, (int)v11, v8);
    if ( v6 < 0 )
      return v6;
    SeGetTokenControlInformation(v9, v10);
    if ( v8[0] )
      ObfDereferenceObject(v11[3]);
  }
  else
  {
    memset(v10, 0, sizeof(v10));
    v6 = -1073741789;
  }
  if ( a5 )
    *a5 = 8;
  if ( v6 >= 0 )
  {
    *a3 = v10[4];
    a3[1] = v10[5];
  }
  return v6;
}
