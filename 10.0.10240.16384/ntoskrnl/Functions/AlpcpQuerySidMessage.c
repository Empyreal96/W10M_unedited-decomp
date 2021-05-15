// AlpcpQuerySidMessage 
 
int __fastcall AlpcpQuerySidMessage(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r4
  char v9[4]; // [sp+8h] [bp-50h] BYREF
  int v10; // [sp+Ch] [bp-4Ch] BYREF
  char v11[12]; // [sp+10h] [bp-48h] BYREF
  int v12; // [sp+1Ch] [bp-3Ch]

  v7 = AlpcpGetEffectiveTokenMessage(a1, a2, &v10, v11, v9);
  if ( v7 >= 0 )
  {
    v7 = AlpcpQuerySidToken(v10, a3, a4, a5);
    if ( v9[0] )
      ObfDereferenceObject(v12);
  }
  return v7;
}
