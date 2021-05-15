// PsRemoveSiloObjectFromJob 
 
int __fastcall PsRemoveSiloObjectFromJob(int a1, int a2, int a3, int a4)
{
  char v5; // r3
  int v6; // r2
  int v7; // r4
  int v8; // r3
  int v9; // r5
  int v11[4]; // [sp+8h] [bp-10h] BYREF

  v11[0] = a4;
  v5 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = ObReferenceObjectByHandle(a1, 2, PsJobType, v5, (int)v11, 0);
  if ( v7 >= 0 )
  {
    v8 = __mrc(15, 0, 13, 0, 3);
    v9 = PspReferenceJobSilo(v11[0], v8 & 0xFFFFFFC0, v6, v8);
    ObfDereferenceObject(v11[0]);
    if ( v9 )
    {
      v7 = PsRemoveSiloObjectByPointer(v9, a2);
      PspDereferenceSiloObject(v9);
    }
    else
    {
      v7 = -1073741811;
    }
  }
  return v7;
}
