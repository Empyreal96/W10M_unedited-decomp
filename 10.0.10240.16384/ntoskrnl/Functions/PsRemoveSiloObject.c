// PsRemoveSiloObject 
 
int __fastcall PsRemoveSiloObject(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r5
  char v7; // r3
  int v9[4]; // [sp+8h] [bp-10h] BYREF

  v9[0] = a4;
  if ( a1 != -1 )
  {
    v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v6 = ObReferenceObjectByHandle(a1, 2, PsSiloType, v7, (int)v9, 0);
    v5 = v9[0];
    if ( v6 < 0 )
      return v6;
LABEL_5:
    v6 = PsRemoveSiloObjectByPointer(v5, a2);
    PspDereferenceSiloObject(v5);
    return v6;
  }
  v5 = PsGetCurrentSilo();
  if ( v5 )
    goto LABEL_5;
  return -1073741816;
}
