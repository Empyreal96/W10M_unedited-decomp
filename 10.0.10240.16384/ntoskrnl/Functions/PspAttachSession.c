// PspAttachSession 
 
int __fastcall PspAttachSession(int a1, int a2, int *a3, int a4)
{
  int v6; // r0
  int v7; // r2
  int v8; // r3
  int v9; // r5
  int v10; // r4

  v6 = MmGetSessionById(a1, a2, (int)a3, a4);
  v9 = v6;
  if ( !v6 )
    return -1073741558;
  *a3 = v6;
  v10 = MmAttachSession(v6, a2, v7, v8);
  if ( v10 < 0 )
    ObfDereferenceObject(v9);
  return v10;
}
