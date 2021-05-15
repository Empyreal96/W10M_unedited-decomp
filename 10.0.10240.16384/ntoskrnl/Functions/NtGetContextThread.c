// NtGetContextThread 
 
int __fastcall NtGetContextThread(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r5
  int v7; // r4
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 8, PsThreadType, v5, v9);
  if ( v6 >= 0 )
  {
    v7 = v9[0];
    if ( (*(_DWORD *)(v9[0] + 76) & 0x400) != 0 )
      v6 = -1073741816;
    else
      v6 = PsGetContextThread(v9[0], a2, v5);
    ObfDereferenceObject(v7);
  }
  return v6;
}
