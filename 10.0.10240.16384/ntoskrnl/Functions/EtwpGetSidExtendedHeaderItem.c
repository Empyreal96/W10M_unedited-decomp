// EtwpGetSidExtendedHeaderItem 
 
int __fastcall EtwpGetSidExtendedHeaderItem(_WORD *a1)
{
  unsigned int v2; // r6
  int v3; // r0
  int v4; // r7
  unsigned int v5; // r4
  unsigned int v6; // r2
  int v8; // [sp+8h] [bp-70h] BYREF
  char v9[4]; // [sp+Ch] [bp-6Ch] BYREF
  int v10; // [sp+10h] [bp-68h] BYREF
  char v11[96]; // [sp+18h] [bp-60h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = PsReferenceEffectiveToken(v2, &v10, v9, &v8, 0);
  v4 = v10;
  v5 = v3;
  if ( v10 == 2 && v8 < 2 )
    return sub_7C50E0();
  SeQueryUserSidToken(v3, v11, 68, &v8);
  if ( v4 == 1 )
  {
    ObFastDereferenceObject((_DWORD *)(*(_DWORD *)(v2 + 336) + 244), v5);
  }
  else if ( v5 )
  {
    ObfDereferenceObject(v5);
  }
  v6 = v8;
  *a1 = (v8 + 15) & 0xFFF8;
  a1[1] = 2;
  a1[3] = v6;
  a1[2] = 0;
  return memmove((int)(a1 + 4), (int)v11, v6);
}
