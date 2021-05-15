// IopInitializeAttributesAndCreateObject 
 
int __fastcall IopInitializeAttributesAndCreateObject(int a1, _DWORD *a2, _DWORD *a3)
{
  char v3; // r0

  *a2 = 24;
  a2[2] = a1;
  a2[3] = 80;
  a2[1] = 0;
  a2[4] = 0;
  a2[5] = 0;
  v3 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  return ObCreateObject(v3, (_DWORD *)IoDriverObjectType, (int)a2, 0, 0, 208, 0, 0, a3);
}
