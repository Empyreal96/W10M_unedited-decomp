// PspCreateMinimalProcess 
 
int __fastcall PspCreateMinimalProcess(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r6
  int v8; // r7
  int v9; // r9
  int v10; // r5
  char v11; // r1
  int v12; // r1
  unsigned int *v13; // r4
  int v14; // r0
  char v16; // [sp+4h] [bp-194h]
  unsigned int *v17; // [sp+28h] [bp-170h] BYREF
  int v18; // [sp+2Ch] [bp-16Ch] BYREF
  int var168[93]; // [sp+30h] [bp-168h] BYREF
  int varg_r1; // [sp+1A4h] [bp+Ch]
  int varg_r2; // [sp+1A8h] [bp+10h]
  int varg_r3; // [sp+1ACh] [bp+14h]

  var168[92] = (int)a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v5 = a3;
  if ( a3 )
  {
    v8 = 1;
  }
  else
  {
    v5 = PsReferencePrimaryToken((int)a1);
    v8 = 0;
  }
  v9 = a4 | 0x800;
  v10 = PspAllocateProcess(a1, 0, 0, (unsigned __int8)varg_r1, 0, 0, 0, v5, a4 | 0x800, 0, v8, &v18, &v17);
  if ( v10 >= 0 )
  {
    memset(var168, 0, 324);
    v11 = 1;
    LOBYTE(var168[79]) = 0;
    if ( v18 )
      v11 = 3;
    v16 = v11;
    v12 = (int)a1;
    v13 = v17;
    v10 = PspInsertProcess(v17, v12, 0x2000000, v9, 0, v16, 0);
    if ( v10 < 0 )
    {
      PspRundownSingleProcess(v13, 0);
    }
    else
    {
      DbgkCreateMinimalProcess((int)v13);
      var168[78] |= 0x200u;
      v14 = PspCreateObjectHandle((int)v13, (int)var168, PsProcessType);
      v10 = v14;
      if ( v14 >= 0 )
        *a5 = var168[80];
      SepDeleteAccessState((int)var168);
      SeReleaseSubjectContext((int)&var168[7]);
      if ( v10 < 0 )
        PsTerminateProcess((int)v13, v10);
    }
    if ( v13 )
      ObfDereferenceObjectWithTag((int)v13);
  }
  if ( !v8 )
    ObfDereferenceObject(v5);
  return v10;
}
