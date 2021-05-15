// PsInsertSiloObjectFromJob 
 
int __fastcall PsInsertSiloObjectFromJob(int a1, int a2, int a3, int a4)
{
  char v6; // r3
  int v7; // r2
  int v8; // r4
  int v9; // r3
  int v10; // r5
  int v12[6]; // [sp+8h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v8 = ObReferenceObjectByHandle(a1, 2, PsJobType, v6, (int)v12, 0);
  if ( v8 >= 0 )
  {
    v9 = __mrc(15, 0, 13, 0, 3);
    v10 = PspReferenceJobSilo(v12[0], v9 & 0xFFFFFFC0, v7, v9);
    ObfDereferenceObject(v12[0]);
    if ( v10 )
    {
      v8 = PsInsertSiloObjectByPointer(v10, a2, a3);
      PspDereferenceSiloObject(v10);
    }
    else
    {
      v8 = -1073741811;
    }
  }
  return v8;
}
